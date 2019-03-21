%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
extern int yylex();

extern void yyerror(char *s);


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
%token FOR ASSIGN DEC INC BREAK CONTINUE DOWNTO UPTO DO WHILE THEN ELSE STEP CONST IF IN


%%
file	:
	;
%%
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
