%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
#include "y.tab.h"

extern int yylex();
int yyerror(char *s);
extern void program(int enter, Node *body), declare(char *name, Node * value);
extern void function(char *name, int enter, Node *body);
int pos; /* local variable offset (no functions inside a function) */
int lbl; /* label counter for generated labels */
int cclbl; /* label counter for generated cicle labels */
char *mklbl(int n); /* generate counter based label */


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
%token ASSIGN NE GE LE EQ ELSE INC DEC
%token PROG DECLS DECL INI NIL EXPRS ALLOC ARGINST PARAMS PARAM INSTRS ARGS


%nonassoc BATATA
%nonassoc ELSE
%right ASSIGN
%left '|'
%left '&'
%left EQ NE
%left GE LE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%nonassoc '!' INC DEC PMINUS
%nonassoc '(' ')' '[' ']'

%type <n> leftvalue ini expr exprs body bodys instr instrs args seq declaracao type ptr const pub param params  updw step



%%

file: seq			{Node *n = uniNode(PROG, $1); printNode(n,0,names);}
      | //empty
      ;

seq: declaracao			{$$ = $1;}
    | seq declaracao		{$$ = binNode(DECLS, $1, $2);}
    ;


declaracao  : pub const type ptr ID ';'		{$$=uniNode(DECL, strNode(ID,$5));
						IDnew($1->info+$2->info+$3->info+$4->info,$5,0);}

            | pub const type ptr ID ini ';'	{ IDnew($1->info+$2->info+$3->info+$4->info,$5,0);
            					  $$=binNode(INI, strNode(ID, $5), $6);
            					  $$->info = $1->info + $2->info + $3->info + $4->info;
            					  if($3->info+$4->info != 4) {
            					     if($3->info+$4->info != $6->info){
            					     	yyerror("Different type assignment");
            					     }
            					  }
            					}

            | pub const type ptr ID '(' params ')'  bodys ';'

            | pub const type ptr ID '(' ')' body ';'

            | pub const type ptr ID '(' ')' ';'		{$$=uniNode(DECL,strNode(ID,$5));
            						IDnew($1->info+$2->info+$3->info+$4->info,$5,0);}
            | error ';'					{yyerrok;}
            ;


bodys :				{$$= nilNode(NIL);}
       | body			{$$ = $1;}
       ;

ptr	: //empty
	| '*'			{$$ = uniNode(REAL,0); $$->info = 4;}
	;

const	: //empty		{$$ = uniNode(NIL); $$->info = 0;}
	| CONST			{$$ = uniNode(CONST,0); $$->info = 8;}
	;


pub	: //empty		{$$ = nilNode(NIL); $$->info = 0;}
	| PUBLIC		{$$ = uniNode(VOID,0); $$->info = 16;}
	;


type: VOID			{$$ = uniNode(VOID,0); $$->info = 0;}
    | INTEGER			{$$ = uniNode(INTEGER,0); $$->info = 1;}
    | STRING			{$$ = uniNode(STRING,0); $$->info = 2;}
    | NUMBER			{$$ = uniNode(NUMBER,0); $$->info = 3;}
    ;



ini: ASSIGN INT			{$$ = intNode(INT,$2); $$->info = 1;}
   | ASSIGN '-' INT		{$$ = intNode(INT,-$3); $$->info = 1;}
   | ASSIGN const STR		{$$ = strNode(STR,$3); $$->info = $2->info+2;}
   | ASSIGN REAL		{$$ = realNode(REAL,$2); $$->info = 3;}
   | ASSIGN '-' REAL		{$$ = realNode(REAL,-$3); $$->info = 3;}
   | ASSIGN ID			{$$ = strNode(ID, $2); $$->info = IDfind($2,0);}
   ;


params: params ',' param	{$$ = binNode(PARAMS, $1, $3); $$->info = $1->info + $3->info;}
      | param			{$$ = uniNode(PARAMS,$1); $$->info = $1->info;}
      ;

param: type ptr ID		{$$ = strNode(ID,$3); IDnew($1->info+$2->info,$3,0);
				$$->info = $1->info + $2->info;}
     ;


args: param ';'			{$$ = $1;}
     | args param ';'		{$$ = binNode(ARGS, $1, $2); $$->info = $1->info + $2->info; }
     ;


body: '{' '}'			{$$ = nilNode(NIL);}
     | '{' args '}'		{$$ = uniNode(PARAMS,$2);}
     | '{' instrs '}'		{$$ = uniNode(INSTRS,$2);}
     | '{' args instrs '}'	{$$ = binNode(ARGINST, $2,$3);}
     ;



instrs : instr			{$$ = $1;}
           | instrs instr	{$$ = binNode(INSTRS,$1,$2);}
           ;




instr : IF expr THEN instr  %prec BATATA

          | IF expr THEN instr ELSE instr


          | DO instr  WHILE expr ';'

          | FOR leftvalue IN expr updw expr step DO instr

          | expr ';'		{$$ = $1;}
          | body		{$$ = $1;}
          | BREAK INT ';'
          | CONTINUE INT ';'
          | BREAK ';'
          | CONTINUE ';'
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


expr :	INT		{$$ = intNode(INT,$1); $$->info = 1;}
      | REAL		{$$ = realNode(REAL,$1); $$->info = 3;}
      | STR		{$$ = strNode(STR,$1); $$->info = 2;}
      | leftvalue	{$$ = $1;}
      | ID '(' exprs ')'
      | ID '(' ')'
      | '(' expr ')'		{$$ = $2;}
      | leftvalue ASSIGN expr
      | DEC leftvalue		{if($2->info!=1){yyerror("Trying to decrement an invalid identifier");}
      				 $$ = binNode(DEC, nilNode(NIL), $2); $$->info = 1;}
      | INC leftvalue		{if($2->info!=1){yyerror("Trying to increment an invalid identifier");}
                                 $$ = binNode(INC, nilNode(NIL), $2); $$->info = 1;}
      | leftvalue INC		{if($1->info!=1){yyerror("Trying to increment an invalid identifier");}
                                 $$ = binNode(INC, nilNode(NIL), $1); $$->info = 1;}
      | leftvalue DEC		{if($1->info!=1){yyerror("Trying to decrement an invalid identifier");}
                           	$$ = binNode(DEC, nilNode(NIL), $1); $$->info = 1;}
      | expr '*' expr
      | expr '/' expr
      | expr '%' expr
      | expr '+' expr
      | expr '-' expr
      | expr '>' expr
      | expr '<' expr
      | expr EQ expr
      | expr NE expr
      | expr GE expr
      | expr LE expr
      | expr '&' expr
      | expr '|' expr
      | expr '!'
      | '-' expr %prec PMINUS	{if($2->info == 0 || $2->info==2){yyerror("Invalid type for symmetrical assigment");}
				$$=uniNode(PMINUS, $2); $$->info=$2->info;}
      ;

leftvalue: ID			{$$ = strNode(ID,$1); $$->info = IDfind($1,0);}

          | ID '[' expr ']'
          ;
%%

char **names =
 #if YYDEBUG > 0
 (char**)yyname;
 #else
 0;
 #endif

int yyerror(char *s) { printf("%s\n",s); return 1; }
char *dupstr(const char*s) { return strdup(s); }
int main(int argc, char *argv[]) {
 extern YYSTYPE yylval;
 int tk;
 while ((tk = yylex()))
  if (tk > YYERRCODE)
   printf("%d:\t%s\n", tk, yyname[tk]);
  else
   printf("%d:\t%c\n", tk, tk);
 return 0;
}

