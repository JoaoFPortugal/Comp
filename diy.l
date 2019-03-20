%{
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "node.h"
#include "y.tab.h"
void yyerror(char *s);
int nest = 0;
%}

DEC 0|[1-9][0-9]*
OCTAL 0([0-9])+
BIN (0b|0B)(0|1)+

DIGIT [0-9]+
EXP [Ee][+-]?{DIGIT}
REAL {DIGIT}"."{DIGIT}({EXP})?
HEXA (0x|0X)[0-9a-fA-Z]+


%x COM

%%
<COM>{
    "=<"        {nest++;}
    ">="        { if(nest==0) nest--; else BEGIN(INITIAL);}
    .|\n        ;
}

"=<"            BEGIN COM;

"for"			return FOR;
"in"            return IN;
"step"          return STEP;
"const"         return CONST;
"if"			return IF;
"then"          return THEN;
"else"			return ELSE;
"while"			return WHILE;
"do"            return DO;
"upto"          return UPTO;
"downto"        return DOWNTO;
"continue"      return CONTINUE;
"break"         return BREAK;
"<="			return LE;
">="			return GE;
"=" 			return EQ;
"<>"			return NE;
"++"			return INC;
"--"			return DEC;
":="			return ASSIGN;
"void"          return  VOID;
"string"        return STRING;
"integer"       return INTEGER;
"number"        return NUMBER;




[0-9]+			yylval.i = strtol(yytext, 0, 10); return INT;


.			yyerror("Unknown character");
%%
int yywrap(void) { return 1; }
char *getyytext() { return yytext; }
void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }