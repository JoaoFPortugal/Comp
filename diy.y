%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex();
int yyerror(char *s);

%}
%union {
	int i;			/* integer value */
	double r;		/* real value */
	char *s;		/* symbol name or string literal */
};
%token <i> INT
%token <r> REAL
%token <s> ID STR
%token DO WHILE IF THEN FOR IN UPTO DOWNTO STEP BREAK CONTINUE
%token VOID INTEGER STRING NUMBER CONST PUBLIC INCR DECR
%token ASSIGN NE GE LE EQ ELSE

%%
file: seq
      | //empty
      ;

seq: declaracao
	| seq declaracao
	;

declaracao :
	  pub const type ptr ID ini ';'
	| pub const type ptr ID ';'
	| pub const type ptr ID '(' ')' ';'
	| pub const type ptr ID '('  ')' '{' body '}' ';'
	| pub const type ptr ID '(' params ')' '{' bodys '}' ';'
	| error ';'
	;

pub	: //empty
	| PUBLIC
	;

const	: //empty
	| CONST
	;

ptr	: //empty
	| '*'
	;


type: INTEGER
    | STRING
    | NUMBER
    | VOID;


params: params ',' param
      | param
      ;


param: type ptr ID
     ;


ini: ASSIGN INT
   | ASSIGN '-' INT
   | ASSIGN REAL
   | ASSIGN '-' REAL
   | ASSIGN ID
   | ASSIGN const STR
   ;

bodys:
     | body;

body:
     | instrs
     | args
     | args instr
     ;

args: param ';'
     | args param ';'
     ;

instrs: instr
      | instrs instr
      ;

instr: IF expr THEN instr
     | IF expr THEN instr ELSE instr
     | DO instr WHILE expr ';'
     | FOR leftvalue IN expr updw expr step DO instr
     | expr ';'
     | '{' body '}'
     | BREAK INT ';'
     | BREAK ';'
     | CONTINUE INT ';'
     | CONTINUE ';'
     | leftvalue '#' expr ';'
     | error ';'
     ;


updw: UPTO
    | DOWNTO
    ;


step: //empty
    | STEP expr
    ;

leftvalue: ID
	  | ID '[' expr ']'

exprs: exprs ',' expr
     | expr
     ;

expr: INT
    | REAL
    | STR
    | leftvalue
    | expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | expr '%' expr
    | expr '>' expr
    | expr '<' expr
    | expr EQ expr
    | expr NE expr
    | expr GE expr
    | expr LE expr
    | expr '&' expr
    | expr '|' expr
    | leftvalue ASSIGN expr
    | INCR leftvalue
    | DECR leftvalue
    | leftvalue INCR
    | leftvalue DECR
    | ID '(' ')'
    | ID '(' exprs ')'
    | '(' expr ')'
    | '-' expr
    | expr '!'
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
