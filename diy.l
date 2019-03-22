%{
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "node.h"
#include "y.tab.h"

void yyerror(char *s);
int octal(char *s);
int nest = 0;
int nova_linha = 0,str_begin=0;
char buffer [100];
char *string;
%}

DEC 0|[1-9][0-9]*
OCTAL 0([0-9])+
BIN (0b|0B)(0|1)+
HEXA (0x|0X)[0-9a-fA-Z]+
DIGITO [0-9]+
REAL {DIGITO}"."{DIGITO}



%x COM STRN

%%

"for"			nova_linha = 0; return FOR;
"in"            nova_linha = 0; return IN;
"step"          nova_linha = 0; return STEP;
"const"         nova_linha = 0; return CONST;
"if"			nova_linha = 0; return IF;
"then"          nova_linha = 0; return THEN;
"else"			nova_linha = 0; return ELSE;
"while"			nova_linha = 0; return WHILE;
"do"            nova_linha = 0; return DO;
"upto"          nova_linha = 0; return UPTO;
"downto"        nova_linha = 0; return DOWNTO;
"continue"      nova_linha = 0; return CONTINUE;
"break"         nova_linha = 0; return BREAK;
"<="			nova_linha = 0; return LE;
">="			nova_linha = 0; return GE;
"=" 			nova_linha = 0; return EQ;
"<>"			nova_linha = 0; return NE;
"++"			nova_linha = 0; return INCR;
"--"			nova_linha = 0; return DECR;
":="			nova_linha = 0; return ASSIGN;
"void"          nova_linha = 0; return VOID;
"string"        nova_linha = 0; return STRING;
"integer"       nova_linha = 0; return INTEGER;
"number"        nova_linha = 0; return NUMBER;
"public"        nova_linha = 0; return PUBLIC;

"==".\n         nova_linha = 0;
"=<"            BEGIN COM; nova_linha = 0; nest = 0;

<COM>{
    "=<"        {nest++;}
    ">="        { if(nest!=0) nest--; else BEGIN(INITIAL);}
    <<EOF>>      {yyerror("Comment reached EOF"); yyterminate();}
    .|\n        ;
}


{DEC}		    { nova_linha = 1; errno = 0; yylval.i = strtol(yytext, 0, 10);
                  if(errno != ERANGE) {
                     return INT;
                  }
	              else {
						sprintf(buffer, "Decimal %s overflow", yytext);
						yyerror(buffer);
						}
				}



{BIN}			{ nova_linha = 1; errno = 0; yylval.i = strtol(yytext, 0, 2);
                  if(errno != ERANGE) {
                    return INT;
                  }
				  else {
					sprintf(buffer, "Binary %s overflow", yytext);
					yyerror(buffer);
				  }
				  }


{HEXA}          { nova_linha = 1; errno = 0; yylval.i = strtol(yytext, 0, 16);
                   if(errno != ERANGE) {
                     return INT;
                   }

                   else {
                     sprintf(buffer, "Hexadecimal %s caused overflow", yytext);
                     yyerror(buffer);
                   }
                 }


{REAL}          { nova_linha = 1; errno = 0; yylval.d = strtod(yytext, 0);
                  if(errno != ERANGE) {
                     return NUM;
                }
                  else {
                      sprintf(buffer, "Real %s caused overflow", yytext);
                      yyerror(buffer);
                  }
                }


{OCTAL}		    {   errno = 0; yylval.i = octal(yytext);
                    if(errno != ERANGE) {
                       return INT;   /* Literal - Octal */
                    }
				    else {
					   sprintf(buffer, "Octal %s caused overflow", yytext);
					   yyerror(buffer);
					}
			    }


[A-Za-z][A-Za-z0-9_]*		{ nova_linha = 1; yylval.s = strdup(yytext); return ID; /* ID */}

"\n"        {
            if(nova_linha==1){
                nova_linha=0;
                return ';';
                }
            }

\"          {   BEGIN STRN;
                str_begin = 0;
                nova_linha = 1;
                string = (char *) malloc(sizeof(char));
                string[0] = '\0';
            }

<STRN>\\n          {
                    string = (char *) realloc(string, sizeof(char) * (strlen(string)+2));
                    strcat(string, "\n");
                    }

<STRN>\\t           {
                    string = (char *) realloc(string, sizeof(char) * (strlen(string)+2));
                    strcat(string, "\t");
                    }

<STRN>\\r           {
                    string = (char *) realloc(string, sizeof(char) * (strlen(string)+2));
                    strcat(string, "\r");
                    }

<STRN>(\\[0-9a-fA-F][0-9a-fA-F]?)|([^"\\]) {
                    str_begin = 1;
                    string = (char *) realloc(string, sizeof(char) * (strlen(string) + strlen(yytext)+1));
                    strcat(string, yytext);
                    }

<STRN>\\\"			{
                    str_begin = 1;
                    string = (char *) realloc(string, sizeof(char) * (strlen(string) + 2));
                    strcat(string, "\"");
                    }

<STRN>\"			{
                    BEGIN 0;
                    yytext[yyleng-1] = 0;  /* remove " */
					string = (char *) realloc(string, sizeof(char) * (strlen(string) + strlen(yytext) + 1));
					strcat(string, yytext);
					yylval.s = strdup(string);
					if(str_begin == 0){
					    yyerror("String cannot be null");
					}
					return STR;
					}

<STRN>.             {
                    yyerror("Character unknown");
                    }

";"					    nova_linha = 0; return *yytext;
[!)]					nova_linha = 1;  return *yytext;
[-+*/%<>=|&~]			nova_linha = 0; return *yytext;
[#\[\]{}(,]				nova_linha = 0; return *yytext;

[ \t\r]+        ;

.			yyerror("Unknown character");

%%
int yywrap(void) { return 1; }
char *getyytext() { return yytext; }


int octal(char *s)
{
  int i=0, a = 0, b = 0;
  for (i = 0; i < strlen(s); i++) {
    if (s[i] < '0' || s[i] > '9') break;
    b = b * 8 + s[i] - '0';
    if (b < a) {
      yyerror("octal overflow");
      break;
    }
    a = b;
  }
  return a;
}
