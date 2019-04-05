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

%nonassoc BATATA
%nonassoc ELSE
%right ASSIGN
%left '|'
%left '&'
%left EQ NE
%left GE LE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%nonassoc '!' INC DEC

%type <n> leftvalue ini expr exprs body bodys instr instrs args seq declaracao type ptr const pub param params  updw step


%%

file: seq
      | //empty
      ;

seq: declaracao
    | seq declaracao
    ;


declaracao  : pub const type ptr ID ';'

            | pub const type ptr ID ini ';'

            | pub const type ptr ID '(' params ')'  bodys ';'

            | pub const type ptr ID '(' ')' body ';'

            | pub const type ptr ID '(' ')' ';'
            | error ';'
            ;


bodys :
       | body
       ;

ptr	: //empty
	| '*'
	;

const	: //empty
	| CONST
	;


pub	: //empty
	| PUBLIC
	;


type: VOID
    | INTEGER
    | STRING
    | NUMBER
    ;



ini: ASSIGN INT
   | ASSIGN '-' INT
   | ASSIGN const STR
   | ASSIGN REAL
   | ASSIGN '-' REAL
   | ASSIGN ID
   ;


params: params ',' param
      | param
      ;

param: type ptr ID
     ;


args: param ';'
     | args param ';'
     ;


body: '{' '}'
     | '{' args '}'
     | '{' instrs '}'
     | '{' args instrs '}'
     ;



instrs : instr
           | instrs instr
           ;




instr : IF expr THEN instr  %prec BATATA

          | IF expr THEN instr ELSE instr


          | DO instr  WHILE expr ';'

          | FOR leftvalue IN expr updw expr step DO instr

          | expr ';'
          | body
          | BREAK INT ';'
          | CONTINUE INT ';'
          | BREAK ';'
          | CONTINUE ';'
          | leftvalue '#' expr ';'
          | error ';'
          ;

updw  :  UPTO
        | DOWNTO
        ;

step    :
        | STEP expr
        ;

exprs  : exprs ',' expr
            | expr
            ;

expr : INT
          | REAL
          | STR
          | leftvalue
          | ID '(' exprs ')'
          | ID '(' ')'
          | '(' expr ')'
          | leftvalue ASSIGN expr
          | DEC leftvalue
          | INC leftvalue
          | leftvalue INC
          | leftvalue DEC
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
          ;

leftvalue: ID

          | ID '[' expr ']'
          ;
%%


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

