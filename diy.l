%{
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "node.h"
#include "y.tab.h"

void yyerror(char *s);
int octal(char *text);
int nest = 0;
char buffer [100];
%}

DEC 0|[1-9][0-9]*
OCTAL 0([0-9])+
BIN (0b|0B)(0|1)+
HEXA (0x|0X)[0-9a-fA-Z]+
DIGITO [0-9]+
REAL {DIGITO}"."{DIGITO}





%x COM STRN

%%

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
"++"			return INCR;
"--"			return DECR;
":="			return ASSIGN;
"void"          return VOID;
"string"        return STRING;
"integer"       return INTEGER;
"number"        return NUMBER;
"public"        return PUBLIC;

"==".\n         ;
"=<"            BEGIN COM;

<COM>{
    "=<"        {nest++;}
    ">="        { if(nest==0) nest--; else BEGIN(INITIAL);}
    .|\n        ;
}


{DEC}					{ errno = 0; yylval.i = strtol(yytext, 0, 10);
                                if(errno != ERANGE) {
                                    return INT;
                                }
						        else {
									sprintf(buffer, "Decimal %s overflow", yytext);
									yyerror(buffer);
								}
						}



{BIN}					{ errno = 0; yylval.i = strtol(yytext, 0, 2);
                                if(errno != ERANGE) {
                                return INT;
                                }
						   		else {
										sprintf(buffer, "Binary %s overflow", yytext);
										yyerror(buffer);
								   }
							}


{HEXA}                  { errno = 0; yylval.i = strtol(yytext, 0, 16);
                                if(errno != ERANGE) {
                                    return INT;
                                }

                                else {
                                        sprintf(buffer, "Hexadecimal %s caused overflow", yytext);
                                        yyerror(buffer);
                                   }
                            }



{REAL}				    { errno = 0; yylval.d = strtod(yytext, 0);
                          if(errno != ERANGE) {
                            return NUM;
                          }
                          else {
                             sprintf(buffer, "Real %s caused overflow", yytext);
                             yyerror(buffer);
                            }
                        }



{OCTAL}				    {   errno = 0; yylval.i = strtol(octal(yytext), 0, 8);
                            if(errno != ERANGE) {
                                return INT;   /* Literal - Octal */
                            }
							else {
								 sprintf(buffer, "Octal %s caused overflow", yytext);
								 yyerror(buffer);
						    }
					    }

[A-Za-z][A-Za-z0-9_]*		{ yylval.s = strdup(yytext); return ID; /* ID */}



";"							return *yytext;
[)!]						return *yytext;
[-+*/%<>=|&~]				return *yytext;
[#\[\]{}(,]					return *yytext;

[ \t\r]+        ;


\"          BEGIN STRN;

.			yyerror("Unknown character");

%%
int yywrap(void) { return 1; }
char *getyytext() { return yytext; }

int octal(char *s)
{
  int i, a = 0, b = 0;
  s[strlen(s)-1]="\0";
  for (i = 0; i < strlen(s); i++) {
    printf("%d",i);
    printf("here is where it breaks");
    if (s[i] < '0' || s[i] > '9'){
        break;
    }
    if(s[i]==0){
        break;
    }
    b = b * 8 + s[i] - '0';
    if (b < a) {
      yyerror("octal overflow");
      break;    
    }
    a = b;
  }
  return a;
}