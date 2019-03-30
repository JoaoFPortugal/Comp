%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"

extern int yylex();
int yyerror(char *s);


%}

%union {
	int i;		/* integer value */
  	double d;	/* double value */
  	char *s;	/* symbol name or string literal */
};

%token <i> INT
%token <d> NUM
%token <s> ID STR
%token EQ NE LE GE
%token STRING NUMBER INTEGER VOID PUBLIC
%token FOR ASSIGN DECR INCR BREAK CONTINUE DOWNTO UPTO DO WHILE THEN ELSE STEP CONST IF IN


%%
file	: seq
	|
	;

seq: declaracao
	| seq declaracao
	;
declaracao: declaracao |  tipo;
tipo: INTEGER | STRING | NUMBER | VOID;
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

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif

