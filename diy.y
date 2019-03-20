%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
extern int yylex();
void yyerror(char *s);
%}

%union {
	int i;		/* integer value */
  	double d;	/* double value */
  	char *s;	/* symbol name or string literal */
};

%token <i> INT
%token <d> NUM
%token <s> ID STR
%token FOR
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
