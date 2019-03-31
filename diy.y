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
%token ASSIGN NE GE LE ELSE

%%
file: seq
      | //empty
      ;

seq: declaracao
	| seq declaracao
	;

declaracao :  pub const type ptr ID ';'
	| pub const type ptr ID ini ';'
	| pub const type ptr ID '(' ')' ';'
	| pub const type ptr ID '('  ')' '{' body '}' ';'
	| pub const type ptr ID '(' ')' ';'
	| error ';'

pub	: //empty
	| PUBLIC
	;

const	: //empty
	| CONST
	;

ptr	: //empty
	| '*'
	;


type: INTEGER | STRING | NUMBER | VOID;


ini: ASSIGN INT
   | ASSIGN '-' INT
   | ASSIGN NUMBER
   | ASSIGN '-' NUMBER
   | ASSIGN ID
   | ASSIGN cons STR
   ;

body: //empty
     | instr
     | args
     | args instr
     ;

args: //empty
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
