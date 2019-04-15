%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
#include "y.tab.h"
#define IINTEGER 1
#define ISTRING 2
#define INUMBER 3
#define IVOID -2

extern int yylex();
int yyerror(char *s);
extern void program(int enter, Node *body), declare(char *name, Node * value);
extern void function(char *name, int enter, Node *body);
int pos; /* local variable offset (no functions inside a function) */
int lbl; /* label counter for generated labels */
int cclbl; /* label counter for generated cicle labels */
char *mklbl(int n); /* generate counter based label */
int ciclo=0;


%}

%union {
  int i;      /* integer value */
  double r;    /* double value */
  char *s;    /* symbol name or string literal */
  Node *n ;
};


%token <i> INT
%token <r> REAL
%token <s> ID STR
%token DO WHILE IF THEN FOR IN UPTO DOWNTO STEP BREAK CONTINUE
%token VOID INTEGER STRING NUMBER CONST PUBLIC INCR DECR
%token ASSIGN NE GE LE EQ ELSE
%token PROG DECLS DECL INI NIL EXPRS ALLOC ARGINST PARAMS PARAM INSTRS ARGS POINTER
%token SUM SUBT MUL DIV MOD GT LT AND OR FAC ARR FUNC NEG PNTR LOC PUB

%nonassoc IFX
%nonassoc ELSE
%right ASSIGN
%left '|'
%left '&'
%left EQ NE
%left GE LE '>' '<'
%left '+' '-'
%left '*' '/' '%' '~'
%nonassoc '!' INC DEC PMINUS
%nonassoc '(' ')' '[' ']'

%type <n> leftvalue ini expr exprs body bodys instr instrs args seq declaracao type ptr const pub param params file updw step



%%

file: seq			{$$ = uniNode(PROG, $1); printNode($1,0,names);}
      | //empty			{$$ = nilNode(NIL);}
      ;

seq: declaracao			{$$ = $1;}
    | seq declaracao		{$$ = binNode(DECLS, $1, $2);}
    ;


declaracao  : pub const type ptr ID ';'		{$$=uniNode(DECL, strNode(ID,$5));
						IDnew($3->info,$5,0);}

            | pub const type ptr ID ini ';'	{$$=binNode(DECL, strNode(ID, $5), $6);
						 IDnew($3->info,$5,0);
            					  $$->info =$3->info;
            					  if($3->info!= $6->info) {
            					  	yyerror("Different type assignment");
            					  }
            					}

            | pub const type ptr ID  '('  {IDnew($3->info,$5,0); IDpush();}  params ')'  bodys ';'	{IDpop(); $$ = binNode(DECL, strNode(ID,$5),binNode(ARGS,$8,$10));}


            | pub const type ptr ID '(' ')' {IDnew($3->info,$5,0);
            				     IDpush();
            			     }  body ';' {IDpop();$$ = binNode(DECL,strNode(ID,$5),$9);}

            | pub const type ptr ID '(' ')' ';'		{$$=uniNode(DECL,strNode(ID,$5));
            						IDnew($3->info,$5,0);}
            | error ';'					{yyerrok; $$ = nilNode(NIL);}
            ;


bodys :				{$$= nilNode(NIL);}
       | body			{$$ = $1;}
       ;

ptr	: 			{$$ = nilNode(NIL);}
	| '*'			{$$ = uniNode(POINTER,0);}
	;

const	:			{$$ = nilNode(NIL);}
	| CONST			{$$ = uniNode(CONST,0);}
	;


pub	: 			{$$ = nilNode(NIL);}
	| PUBLIC		{$$ = uniNode(PUB,0);}
	;


type: VOID			{$$ = uniNode(VOID,0); $$->info = IVOID;}
    | INTEGER			{$$ = uniNode(INTEGER,0); $$->info = IINTEGER;}
    | STRING			{$$ = uniNode(STRING,0); $$->info = ISTRING;}
    | NUMBER			{$$ = uniNode(NUMBER,0); $$->info = INUMBER;}
    ;


ini: ASSIGN INT			{$$ = intNode(INT,$2); $$->info = IINTEGER;}
   | ASSIGN '-' INT		{$$ = intNode(INT,-$3); $$->info = IINTEGER;}
   | ASSIGN const STR		{$$ = strNode(STR,$3); $$->info =  ISTRING;}
   | ASSIGN REAL		{$$ = realNode(REAL,$2); $$->info = INUMBER;}
   | ASSIGN '-' REAL		{$$ = realNode(REAL,-$3); $$->info = INUMBER;}
   | ASSIGN ID			{$$ = strNode(ID, $2); $$->info = IDfind($2,0);}
   ;


params: params ',' param	{$$ = binNode(PARAMS, $1, $3); $$->info = $1->info + $3->info;}
      | param			{$$ = uniNode(PARAMS,$1); $$->info = $1->info;}
      ;

param: type ptr ID		{$$ = strNode(ID,$3); IDnew($1->info,$3,0);
				$$->info = $1->info;}
     ;


args: param ';'			{$$ = $1;}
     | args param ';'		{$$ = binNode(ARGS, $1, $2); $$->info = $1->info + $2->info; }
     ;

body: '{' '}'			{$$ = nilNode(NIL);}
     | '{' args '}' 		{$$ = uniNode(PARAMS,$2);}
     | '{' instrs '}' 		{$$ = uniNode(INSTRS,$2);}
     | '{' args instrs '}'	{$$ = binNode(ARGINST, $2,$3);}
     ;


instrs : instr			{$$ = $1;}
       | instrs instr		{$$ = binNode(INSTRS,$1,$2);}
       ;


instr : IF expr THEN instr  %prec IFX				 {$$ = binNode(THEN,binNode(IF,$2,nilNode(NIL)),$4);}

       | IF expr THEN instr ELSE instr				 {$$ = binNode(ELSE,binNode(THEN,binNode(IF,$2,nilNode(NIL)),$4),$6);}


       | DO {ciclo++;} instr  WHILE {ciclo--;} expr ';'		{$$ = binNode(DO, binNode(WHILE,$5,nilNode(PROG)),$3);}

       | FOR leftvalue IN expr updw expr step DO {ciclo++;} instr {ciclo--;} {$$ = binNode(DO, binNode(FOR,binNode(IN,binNode(STEP,$6,$7),$4),$2),$9);}

       | expr ';'		{$$ = $1;}
       | body			{$$ = $1;}
       | BREAK INT ';'		{if(ciclo==0){yyerror("Error; Break outside of a loop");} $$ = uniNode(BREAK,intNode(INT,$2));}
       | CONTINUE INT ';'	{if(ciclo==0){yyerror("Error; Continue outside of a loop");} $$ = uniNode(CONTINUE, intNode(INT,$2));}
       | BREAK ';'		{if(ciclo==0){yyerror("Error; Break outside of a loop");}  $$ = uniNode(BREAK,intNode(INT,1));}
       | CONTINUE ';'		{if(ciclo==0){yyerror("Error; Continue outside of a loop");}  $$ = uniNode(CONTINUE,intNode(INT,1));}
       | leftvalue '#' expr ';'	{$$ = binNode(ALLOC,$1,$3); $$->info = $1->info;}
       | error ';'		{yyerrok;}
       ;

updw  :  UPTO			{$$ = uniNode(UPTO,0);}
        | DOWNTO		{$$ = uniNode(DOWNTO,0);}
        ;

step    :			{$$ = nilNode(NIL);}
        | STEP expr		{$$ =uniNode(STEP,$2);}
        ;

exprs  : exprs ',' expr		{$$ = binNode(EXPRS, $1, $3);}
       | expr			{$$ = $1;}
       ;


expr :	INT		{$$ = intNode(INT,$1); $$->info = IINTEGER;}
      | REAL		{$$ = realNode(REAL,$1); $$->info = INUMBER;}
      | STR		{$$ = strNode(STR,$1); $$->info = ISTRING;}
      | leftvalue	{$$ = $1;}
      | ID '(' exprs ')'	{$$ = binNode(FUNC, strNode(ID,$1),$3); $$->info=IDfind($1,0);}
      | ID '(' ')'		{$$ = strNode(ID, $1); $$->info = IDfind($1,0);}
      | '(' expr ')'		{$$ = $2;}
      | leftvalue ASSIGN expr	{$$ = binNode(ASSIGN, $1, $3); $$->info = $3->info; checkAtrib($1,$3);}

      | DECR leftvalue		{ $$ = uniNode(DECR, $2); $$->info = $2->info;
      				if($2->info!=IINTEGER && $2->info!=INUMBER){yyerror("Trying to decrement an invalid identifier");}}
      | INCR leftvalue		{$$ = uniNode(INCR, $2); $$->info = $2->info;
      				if($2->info!=IINTEGER && $2->info!=INUMBER){yyerror("Trying to increment an invalid identifier");}}

      | leftvalue INCR		{ $$ = uniNode(INCR,$1); $$->info = $1->info;
      				if($1->info!=IINTEGER && $1->info !=INUMBER){yyerror("Trying to increment an invalid identifier");}}
      | leftvalue DECR		{$$ = uniNode(DECR,$1);
      				if($1->info!=IINTEGER && $1->info!=INUMBER){yyerror("Trying to decrement an invalid identifier");}
                           	$$->info = $1->info;}
      | expr '*' expr		{$$ = binNode(MUL, $1, $3); $$->info = checkOp($1,$3);}
      | expr '/' expr		{$$ = binNode(DIV, $1, $3); $$->info = checkOp($1,$3);}
      | expr '%' expr		{$$ = binNode(MOD, $1, $3); $$->info = checkOp($1,$3);}
      | expr '+' expr		{$$ = binNode(SUM, $1, $3); $$->info = checkOp($1, $3);}
      | expr '-' expr		{$$ = binNode(SUBT , $1, $3); $$->info = checkOp($1,$3);}
      | expr EQ expr		{$$ = binNode(EQ, $1, $3); $$->info = checkCompOp($1,$3);}
      | expr NE expr		{$$ = binNode(NE, $1, $3); $$->info = checkCompOp($1,$3);}
      | expr GE expr		{$$ = binNode(GE, $1, $3); $$->info = checkCompOp($1,$3);}
      | expr LE expr		{$$ = binNode(LE, $1, $3); $$->info = checkCompOp($1,$3);}
      | expr '>' expr		{$$ = binNode(GT, $1, $3); $$->info = checkCompOp($1,$3);}
      | expr '<' expr		{$$ = binNode(LT, $1, $3); $$->info = checkCompOp($1,$3); }
      | expr '&' expr		{$$ = binNode(AND, $1, $3); }
      | expr '|' expr		{$$ = binNode(OR, $1, $3); checkLogicOp($1,$3);}
      | expr '!'		{$$ = uniNode(FAC, $1); if($1->info != 1){yyerror("Factorial error: Not an integer");}}
      | '-' expr %prec PMINUS	{if($2->info == 0 || $2->info==2){yyerror("Invalid type for symmetrical assigment");}
				$$=uniNode(PMINUS, $2); $$->info=$2->info;}
      | '~' expr		{$$ = uniNode(NEG,$2); if($2->info!=1){yyerror("Error: not an integer");}}
      | '*' expr		{$$ = uniNode(PNTR,$2);}
      | '&' expr		{$$ = uniNode(LOC,$2); $$->info = $2->info;}
      ;

leftvalue: ID			{$$ = strNode(ID,$1); $$->info = IDfind($1,0);}

          | ID '[' expr ']'	{$$ = binNode(ARR,strNode(ID, $1), $3);IDfind($1,0); $$->info = IINTEGER; if($3->info!=IINTEGER){yyerror("Index needs to be an integer");}}
          ;
%%

int checkOp(Node *op1, Node *op2){
     if(op1->info==0 || op2->info == 0){
     	yyerror("Invalid argument type for operation: can't cast void");
     }

     if(op1->info == 2 || op2->info == 2){
     	yyerror("Invalid argument type for operation: can't cast string");
     }

     if(op1->info == 3 || op2->info == 3){
     	return 3;
     }
     return 1;
}

int checkCompOp(Node *op1, Node *op2){

	if(op1->info == IVOID || op2->info == IVOID){
	  yyerror("Invalid argument type for operation: can't compare void");
	}

	printf("%d\n%d\n",op1->info,op2->info);

	if(op1->info == ISTRING && op2->info !=ISTRING){
	  yyerror("Invalid argument type for operation: can't compare string to non-string");
	}

    return 1;
}

void checkLogicOp(Node *op1, Node *op2){
	if(op1->info != IINTEGER || op2->info != IINTEGER){
	   yyerror("Invalid argument type for logic operation");
	}
}

void checkAtrib(Node *op1, Node *op2){
	if(op1->info == 1){
	   if(op2->info != 1 && op2->info != 3){
	   	yyerror("Invalid assignment");
	   }
	   else{
	   	return;
	   }
	}
	if(op1->info == 3){
	   if(op2->info != 1 && op2->info != 3){
	   	yyerror("Invalid assignment");
	   }
	   else{
	     return;
	   }
	}
	yyerror("Invalid type assignment");
}


char **names =
 #if YYDEBUG > 0
 (char**)yyname;
 #else
 0;
 #endif
