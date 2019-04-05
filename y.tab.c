/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "diy.y"
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


#line 22 "diy.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int i;      /* integer value */
  double r;    /* double value */
  char *s;    /* symbol name or string literal */
  Node *n ;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 54 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INT 257
#define REAL 258
#define ID 259
#define STR 260
#define DO 261
#define WHILE 262
#define IF 263
#define THEN 264
#define FOR 265
#define IN 266
#define UPTO 267
#define DOWNTO 268
#define STEP 269
#define BREAK 270
#define CONTINUE 271
#define VOID 272
#define INTEGER 273
#define STRING 274
#define NUMBER 275
#define CONST 276
#define PUBLIC 277
#define INCR 278
#define DECR 279
#define ASSIGN 280
#define NE 281
#define GE 282
#define LE 283
#define EQ 284
#define ELSE 285
#define INC 286
#define DEC 287
#define BATATA 288
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   10,   10,   11,   11,   11,   11,   11,   11,
    6,    6,   13,   13,   14,   14,   15,   15,   12,   12,
   12,   12,    2,    2,    2,    2,    2,    2,   17,   17,
   16,    9,    9,    5,    5,    5,    5,    8,    8,    7,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,   18,   18,   19,   19,    4,    4,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    1,    1,
};
static const YYINT yylen[] = {                            2,
    1,    0,    1,    2,    6,    7,   10,    9,    8,    2,
    0,    1,    0,    1,    0,    1,    0,    1,    1,    1,
    1,    1,    2,    3,    3,    2,    3,    2,    3,    1,
    3,    2,    3,    2,    3,    3,    4,    1,    2,    4,
    6,    5,    9,    2,    1,    3,    3,    2,    2,    4,
    2,    1,    1,    0,    2,    3,    1,    1,    1,    1,
    1,    4,    3,    3,    3,    2,    2,    2,    2,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    1,    4,
};
static const YYINT yydefred[] = {                         0,
    0,   18,    0,    0,    3,    0,   10,    4,   16,    0,
   19,   20,   21,   22,    0,   14,    0,    0,    0,    5,
    0,    0,   23,   26,   28,    0,    0,    0,    0,   30,
    0,    6,   24,   27,   25,    9,    0,    0,    0,    0,
    0,    0,   58,   59,    0,   60,    0,    0,    0,    0,
    0,    0,    0,    0,   34,    0,    0,   45,   38,    0,
    0,    0,    8,   31,   12,    0,   29,   51,    0,    0,
    0,    0,    0,    0,    0,    0,   48,    0,   49,   67,
   66,    0,    0,   68,   69,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   83,
   44,   36,   39,   35,    0,    0,   32,    7,   63,    0,
    0,    0,    0,    0,    0,   46,   47,   64,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   37,   33,   62,    0,   85,    0,    0,
    0,   50,    0,   42,    0,   52,   53,    0,   41,    0,
    0,    0,    0,    0,   43,
};
static const YYINT yydgoto[] = {                          3,
   72,   22,   57,  111,   58,   66,   59,   60,   61,    4,
    5,   29,   17,   10,    6,   30,   31,  148,  152,
};
static const YYINT yysindex[] = {                      -236,
  -36,    0,    0, -236,    0, -244,    0,    0,    0, -221,
    0,    0,    0,    0,   -4,    0, -217,  -37,  102,    0,
   65,   21,    0,    0,    0, -179, -201,  -42,   -4,    0,
  -11,    0,    0,    0,    0,    0,  360,   27, -194,  -35,
 -221,   28,    0,    0,  -15,    0,  640,  252, -165,  -46,
  -43, -165, -165,  252,    0,  -28,   71,    0,    0,  575,
  398,   37,    0,    0,    0,   51,    0,    0,   59,  252,
 -151, -230,   99,   26, -154,   62,    0,   69,    0,    0,
    0,  115,  252,    0,    0,  252,  252,  252,  252,  252,
  252,  252,  252,  252,  252,  252,  252,  252,  252,    0,
    0,    0,    0,    0,  608,   75,    0,    0,    0,  394,
   -7,  131,  252,  640,  252,    0,    0,    0,  394,  263,
  429,   82,   82,  429,  422,  287,   82,   82,  150,  150,
  105,  105,  105,    0,    0,    0,  252,    0,  329, -150,
   60,    0,  394,    0,  640,    0,    0,  252,    0,  165,
  252, -122,  394,  640,    0,
};
static const YYINT yyrindex[] = {                         1,
    0,    0,    0,    6,    0, -190,    0,    0,    0,    0,
    0,    0,    0,    0, -119,    0,    0,    0, -117,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -119,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   86,
    0,    0,    0,    0,  -33,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  383,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   30,    0,    2,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   14,
    0,    0,    0,    0,    0,    0,    0,    0,  688,    0,
  481,  847,  874,  920,  942,  -23,  884,  910,  748,  815,
  455,  490,  516,    0,    0,    0,    0,    0,    0,  556,
    0,    0,   25,    0,    0,    0,    0,    0,    0, -112,
    0,    0, -111,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  913,    0, 1148,    0,   -9,    0,  483,   90,    0,    0,
  151,  153,  136,  147,    0,  -13,    0,    0,    0,
};
#define YYTABLESIZE 1299
static const YYINT yytable[] = {                         84,
    2,   84,   21,   84,   84,    1,   86,   84,   84,   84,
   84,   84,   77,   84,   81,   79,   36,   81,   38,    1,
   81,   20,    7,   62,   69,   84,   84,   67,   84,   40,
   65,    9,   41,  136,   84,   81,  137,   16,   84,   84,
    2,   18,   84,   84,   84,   84,   84,  106,   84,   83,
   11,   12,   13,   14,   57,   84,   85,   57,   35,   84,
   84,   84,   61,   84,   64,   56,   61,   61,   56,   81,
   61,   61,   61,   61,   61,   70,   61,   33,   34,   32,
   37,   15,   15,   15,   15,   63,   68,   37,   61,   61,
   84,   61,  100,   74,   84,  107,   99,   92,   54,  109,
   81,   97,   95,  100,   96,   28,   98,   99,   92,  108,
  113,  115,   97,   95,  100,   96,   70,   98,   99,   94,
  116,   93,   61,   97,   95,   84,   96,  117,   98,  101,
   94,  100,   93,  135,  145,   99,   92,  100,  154,   13,
   97,   95,   15,   96,   11,   98,   26,  100,   54,   55,
  105,   99,   92,   61,    8,  118,   97,   95,   94,   96,
   93,   98,   15,  100,   39,   27,    0,   99,   92,    0,
    0,    0,   97,   95,   94,   96,   93,   98,    0,    0,
    0,    0,  100,   91,    0,    0,   99,    0,    0,    0,
   94,   97,   93,    0,   91,    0,   98,  100,    0,    0,
    0,   99,   92,    0,    0,    0,   97,   95,    0,   96,
   76,   98,    0,   78,    0,    0,    0,    0,    0,    0,
    0,    0,   91,  138,   94,    0,   93,   84,    0,    0,
   84,    0,    0,   84,   84,   84,    0,   81,   91,    0,
   81,    0,   19,   81,   81,   81,   84,   84,   84,   84,
   84,   83,   84,   84,   91,    0,    0,   84,   85,    0,
    0,    0,   84,    0,    0,   84,    0,   84,   84,   84,
   84,    0,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   84,   84,   84,   84,    0,    0,   91,    0,
   61,   54,    0,   61,    0,  100,   61,   61,   61,   99,
   92,    0,    0,    0,   97,   95,    0,   96,    0,   98,
   61,   61,   61,   61,    0,   43,   44,   45,   46,  100,
    0,  142,   94,   99,   93,    0,  146,  147,   97,   95,
    0,   96,    0,   98,    0,    0,   11,   12,   13,   14,
   87,   88,   89,   90,   52,   53,   94,    0,   93,    0,
    0,   87,   88,   89,   90,    0,    0,    0,   23,   24,
   25,  100,  114,    0,    0,   99,   92,    0,    0,    0,
   97,   95,    0,   96,    0,   98,    0,    9,    0,   87,
   88,   89,   90,    0,    0,    0,   91,  144,   94,    0,
   93,    0,    0,    0,    0,   87,   88,   89,   90,   54,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   87,   88,   89,   90,   61,    0,    0,    0,   61,
   61,    0,    0,    0,   61,   61,  100,   61,    0,   61,
   99,   92,    0,  151,    0,   97,   95,   54,   96,    0,
   98,   61,   61,    0,   61,   87,   88,   89,   90,    0,
    0,    0,   91,   94,  100,   93,    0,    0,   99,   92,
    0,  100,    0,   97,   95,   99,   96,    0,   98,    0,
   97,   95,    0,   96,    0,   98,    0,    0,    0,    0,
    0,   94,   37,   93,   55,    0,    0,    0,   94,    0,
   93,   70,   70,    0,    0,   70,   70,   70,   70,   70,
    0,   70,    0,    0,    0,    0,   61,    0,   43,   44,
   45,   46,    0,   70,   70,    0,   70,   91,   78,    0,
   37,   78,  104,    0,   78,    0,   71,   71,    0,   71,
   71,   71,   71,   71,   71,    0,   71,   52,   53,   78,
    0,    0,  103,   87,   88,   89,   90,   70,   71,   71,
    0,   71,   72,   72,    0,    0,   72,   72,   72,   72,
   72,    0,   72,    0,    0,    0,    0,   87,   88,   89,
   90,    0,    0,   78,   72,   72,    0,   72,   70,    0,
    0,    0,   71,    0,    0,    0,    0,  103,    0,    0,
    0,    0,    0,    0,    0,   40,  140,    0,    0,    0,
    0,    0,    0,    0,   78,    0,    0,    0,   72,   87,
   88,   89,   90,   71,   54,   42,   43,   44,   45,   46,
   47,    0,   48,    0,   49,    0,    0,  149,    0,   50,
   51,   11,   12,   13,   14,    0,  155,    0,    0,   72,
    0,    0,    0,    0,    0,   52,   53,   54,    0,    0,
    0,    0,    0,   42,   43,   44,   45,   46,   47,    0,
   48,    0,   49,   61,   61,   61,   61,   50,   51,   11,
   12,   13,   14,    0,   87,   88,   89,   90,   40,   54,
   40,    0,    0,   52,   53,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   37,    0,  102,
    0,    0,   87,   88,   89,   90,    0,    0,    0,    0,
   88,   89,    0,    0,    0,   70,    0,    0,   70,    0,
    0,   70,   70,   70,    0,    0,    0,    0,   65,    0,
   37,   65,  134,    0,    0,   70,   70,   70,   70,    0,
    0,   78,    0,    0,   78,    0,   65,   78,   78,   78,
   71,    0,    0,   71,    0,    0,   71,   71,   71,    0,
    0,   78,   37,    0,   78,    0,    0,    0,    0,    0,
   71,   71,   71,   71,    0,    0,   72,    0,    0,   72,
   65,    0,   72,   72,   72,   73,    0,    0,   73,    0,
   73,   73,   73,    0,    0,    0,   72,   72,   72,   72,
    0,    0,    0,    0,    0,    0,   73,   73,    0,   73,
    0,   40,   40,   40,   40,   40,   40,   40,   40,    0,
   40,    0,    0,    0,    0,   40,   40,    0,    0,    0,
   42,   43,   44,   45,   46,   47,    0,   48,    0,   49,
   73,   40,   40,    0,   50,   51,    0,    0,    0,    0,
    0,    0,   74,    0,    0,   74,    0,   74,   74,   74,
   52,   53,    0,   42,   43,   44,   45,   46,   47,    0,
   48,   73,   49,   74,   74,    0,   74,   50,   51,    0,
    0,    0,    0,    0,   79,    0,    0,   79,    0,    0,
   79,    0,    0,   52,   53,   42,   43,   44,   45,   46,
   47,    0,   48,    0,   49,   79,   79,   74,   79,   50,
   51,   80,    0,    0,   80,    0,    0,   80,    0,    0,
    0,   75,    0,    0,   75,   52,   53,   75,    0,    0,
    0,    0,   80,   80,    0,   80,    0,    0,   74,   79,
    0,    0,   75,   75,    0,   75,    0,   76,   65,   56,
   76,   65,    0,   76,   65,   65,   65,   77,    0,   56,
   77,   75,    0,   77,   80,   81,   80,    0,   76,   76,
   79,   76,   56,   56,    0,    0,   75,    0,   77,    0,
    0,    0,   82,    0,    0,   82,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   80,    0,    0,
   82,    0,   76,    0,    0,    0,    0,   75,   73,    0,
    0,   73,   77,    0,   73,   73,   73,   56,    0,    0,
    0,    0,    0,    0,    0,    0,   56,    0,   73,   73,
   73,   73,    0,   76,   82,    0,    0,    0,    0,    0,
    0,    0,    0,   77,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   56,    0,    0,
    0,    0,    0,    0,    0,   82,   56,    0,    0,    0,
    0,    0,    0,    0,    0,   74,    0,    0,   74,    0,
    0,   74,   74,   74,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   74,   74,   74,   74,    0,
    0,    0,    0,    0,    0,    0,    0,   79,    0,    0,
   79,    0,    0,   79,   79,   79,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   79,   79,   79,
   79,    0,    0,    0,   80,    0,    0,   80,    0,    0,
   80,   80,   80,    0,   75,    0,    0,   75,    0,    0,
   75,   75,   75,    0,   80,   80,   80,   80,    0,    0,
    0,    0,    0,    0,   75,   75,   75,   75,    0,    0,
   76,    0,    0,   76,    0,    0,   76,   76,   76,    0,
   77,    0,    0,   77,    0,    0,   77,   77,   77,    0,
   76,   76,   76,   76,    0,   73,    0,    0,    0,    0,
   77,   82,   82,   77,    0,   82,    0,    0,   82,   82,
   82,    0,    0,    0,    0,    0,  110,  112,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  119,    0,    0,  120,  121,  122,  123,  124,  125,  126,
  127,  128,  129,  130,  131,  132,  133,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  139,    0,  141,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  143,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  150,    0,    0,  153,
};
static const YYINT yycheck[] = {                         33,
    0,   35,   40,   37,   38,    0,   35,   41,   42,   43,
   44,   45,   59,   47,   38,   59,   59,   41,   28,  256,
   44,   59,   59,   37,   40,   59,   60,   41,   62,   41,
   40,  276,   44,   41,   33,   59,   44,   42,   37,   38,
  277,  259,   41,   42,   43,   44,   45,   61,   47,  280,
  272,  273,  274,  275,   41,  286,  287,   44,  260,   93,
   59,   60,   33,   62,  259,   41,   37,   38,   44,   93,
   41,   42,   43,   44,   45,   91,   47,  257,  258,   59,
  123,  272,  273,  274,  275,   59,   59,  123,   59,   60,
  124,   62,   33,  259,   93,   59,   37,   38,   40,   41,
  124,   42,   43,   33,   45,   41,   47,   37,   38,   59,
  262,  266,   42,   43,   33,   45,   91,   47,   37,   60,
   59,   62,   93,   42,   43,  124,   45,   59,   47,   59,
   60,   33,   62,   59,  285,   37,   38,   33,  261,  259,
   42,   43,  260,   45,   59,   47,   45,   33,  261,  261,
   61,   37,   38,  124,    4,   41,   42,   43,   60,   45,
   62,   47,   10,   33,   29,   19,   -1,   37,   38,   -1,
   -1,   -1,   42,   43,   60,   45,   62,   47,   -1,   -1,
   -1,   -1,   33,  124,   -1,   -1,   37,   -1,   -1,   -1,
   60,   42,   62,   -1,  124,   -1,   47,   33,   -1,   -1,
   -1,   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,
  257,   47,   -1,  257,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  124,   93,   60,   -1,   62,  261,   -1,   -1,
  264,   -1,   -1,  267,  268,  269,   -1,  261,  124,   -1,
  264,   -1,  280,  267,  268,  269,  280,  281,  282,  283,
  284,  280,  286,  287,  124,   -1,   -1,  286,  287,   -1,
   -1,   -1,  261,   -1,   -1,  264,   -1,  266,  267,  268,
  269,   -1,  272,  273,  274,  275,  276,  272,  273,  274,
  275,  276,  281,  282,  283,  284,   -1,   -1,  124,   -1,
  261,   40,   -1,  264,   -1,   33,  267,  268,  269,   37,
   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
  281,  282,  283,  284,   -1,  257,  258,  259,  260,   33,
   -1,   59,   60,   37,   62,   -1,  267,  268,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,  272,  273,  274,  275,
  281,  282,  283,  284,  286,  287,   60,   -1,   62,   -1,
   -1,  281,  282,  283,  284,   -1,   -1,   -1,  257,  258,
  259,   33,  264,   -1,   -1,   37,   38,   -1,   -1,   -1,
   42,   43,   -1,   45,   -1,   47,   -1,  276,   -1,  281,
  282,  283,  284,   -1,   -1,   -1,  124,   59,   60,   -1,
   62,   -1,   -1,   -1,   -1,  281,  282,  283,  284,   40,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  281,  282,  283,  284,   33,   -1,   -1,   -1,   37,
   38,   -1,   -1,   -1,   42,   43,   33,   45,   -1,   47,
   37,   38,   -1,  269,   -1,   42,   43,   40,   45,   -1,
   47,   59,   60,   -1,   62,  281,  282,  283,  284,   -1,
   -1,   -1,  124,   60,   33,   62,   -1,   -1,   37,   38,
   -1,   33,   -1,   42,   43,   37,   45,   -1,   47,   -1,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,   60,  123,   62,  125,   -1,   -1,   -1,   60,   -1,
   62,   37,   38,   -1,   -1,   41,   42,   43,   44,   45,
   -1,   47,   -1,   -1,   -1,   -1,  124,   -1,  257,  258,
  259,  260,   -1,   59,   60,   -1,   62,  124,   38,   -1,
  123,   41,  125,   -1,   44,   -1,   37,   38,   -1,   47,
   41,   42,   43,   44,   45,   -1,   47,  286,  287,   59,
   -1,   -1,   60,  281,  282,  283,  284,   93,   59,   60,
   -1,   62,   37,   38,   -1,   -1,   41,   42,   43,   44,
   45,   -1,   47,   -1,   -1,   -1,   -1,  281,  282,  283,
  284,   -1,   -1,   93,   59,   60,   -1,   62,  124,   -1,
   -1,   -1,   93,   -1,   -1,   -1,   -1,  105,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   40,  114,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,   93,  281,
  282,  283,  284,  124,   40,  256,  257,  258,  259,  260,
  261,   -1,  263,   -1,  265,   -1,   -1,  145,   -1,  270,
  271,  272,  273,  274,  275,   -1,  154,   -1,   -1,  124,
   -1,   -1,   -1,   -1,   -1,  286,  287,   40,   -1,   -1,
   -1,   -1,   -1,  256,  257,  258,  259,  260,  261,   -1,
  263,   -1,  265,  281,  282,  283,  284,  270,  271,  272,
  273,  274,  275,   -1,  281,  282,  283,  284,  123,   40,
  125,   -1,   -1,  286,  287,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,
   -1,   -1,  281,  282,  283,  284,   -1,   -1,   -1,   -1,
  282,  283,   -1,   -1,   -1,  261,   -1,   -1,  264,   -1,
   -1,  267,  268,  269,   -1,   -1,   -1,   -1,   41,   -1,
  123,   44,  125,   -1,   -1,  281,  282,  283,  284,   -1,
   -1,  261,   -1,   -1,  264,   -1,   59,  267,  268,  269,
  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,
   -1,  281,  123,   -1,  284,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,   -1,   -1,  261,   -1,   -1,  264,
   93,   -1,  267,  268,  269,   38,   -1,   -1,   41,   -1,
   43,   44,   45,   -1,   -1,   -1,  281,  282,  283,  284,
   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,   62,
   -1,  256,  257,  258,  259,  260,  261,  262,  263,   -1,
  265,   -1,   -1,   -1,   -1,  270,  271,   -1,   -1,   -1,
  256,  257,  258,  259,  260,  261,   -1,  263,   -1,  265,
   93,  286,  287,   -1,  270,  271,   -1,   -1,   -1,   -1,
   -1,   -1,   38,   -1,   -1,   41,   -1,   43,   44,   45,
  286,  287,   -1,  256,  257,  258,  259,  260,  261,   -1,
  263,  124,  265,   59,   60,   -1,   62,  270,  271,   -1,
   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,   -1,
   44,   -1,   -1,  286,  287,  256,  257,  258,  259,  260,
  261,   -1,  263,   -1,  265,   59,   60,   93,   62,  270,
  271,   38,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,
   -1,   38,   -1,   -1,   41,  286,  287,   44,   -1,   -1,
   -1,   -1,   59,   60,   -1,   62,   -1,   -1,  124,   93,
   -1,   -1,   59,   60,   -1,   62,   -1,   38,  261,   37,
   41,  264,   -1,   44,  267,  268,  269,   38,   -1,   47,
   41,   49,   -1,   44,   52,   53,   93,   -1,   59,   60,
  124,   62,   60,   61,   -1,   -1,   93,   -1,   59,   -1,
   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,
   59,   -1,   93,   -1,   -1,   -1,   -1,  124,  261,   -1,
   -1,  264,   93,   -1,  267,  268,  269,  105,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  114,   -1,  281,  282,
  283,  284,   -1,  124,   93,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  145,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  124,  154,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  261,   -1,   -1,  264,   -1,
   -1,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  281,  282,  283,  284,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  261,   -1,   -1,
  264,   -1,   -1,  267,  268,  269,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,  282,  283,
  284,   -1,   -1,   -1,  261,   -1,   -1,  264,   -1,   -1,
  267,  268,  269,   -1,  261,   -1,   -1,  264,   -1,   -1,
  267,  268,  269,   -1,  281,  282,  283,  284,   -1,   -1,
   -1,   -1,   -1,   -1,  281,  282,  283,  284,   -1,   -1,
  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,
  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,
  281,  282,  283,  284,   -1,   48,   -1,   -1,   -1,   -1,
  281,   54,  261,  284,   -1,  264,   -1,   -1,  267,  268,
  269,   -1,   -1,   -1,   -1,   -1,   69,   70,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   83,   -1,   -1,   86,   87,   88,   89,   90,   91,   92,
   93,   94,   95,   96,   97,   98,   99,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  113,   -1,  115,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  137,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  148,   -1,   -1,  151,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 288
#define YYUNDFTOKEN 310
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'",0,"'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'{'","'|'","'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","REAL","ID","STR","DO",
"WHILE","IF","THEN","FOR","IN","UPTO","DOWNTO","STEP","BREAK","CONTINUE","VOID",
"INTEGER","STRING","NUMBER","CONST","PUBLIC","INCR","DECR","ASSIGN","NE","GE",
"LE","EQ","ELSE","INC","DEC","BATATA",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : seq",
"file :",
"seq : declaracao",
"seq : seq declaracao",
"declaracao : pub const type ptr ID ';'",
"declaracao : pub const type ptr ID ini ';'",
"declaracao : pub const type ptr ID '(' params ')' bodys ';'",
"declaracao : pub const type ptr ID '(' ')' body ';'",
"declaracao : pub const type ptr ID '(' ')' ';'",
"declaracao : error ';'",
"bodys :",
"bodys : body",
"ptr :",
"ptr : '*'",
"const :",
"const : CONST",
"pub :",
"pub : PUBLIC",
"type : VOID",
"type : INTEGER",
"type : STRING",
"type : NUMBER",
"ini : ASSIGN INT",
"ini : ASSIGN '-' INT",
"ini : ASSIGN const STR",
"ini : ASSIGN REAL",
"ini : ASSIGN '-' REAL",
"ini : ASSIGN ID",
"params : params ',' param",
"params : param",
"param : type ptr ID",
"args : param ';'",
"args : args param ';'",
"body : '{' '}'",
"body : '{' args '}'",
"body : '{' instrs '}'",
"body : '{' args instrs '}'",
"instrs : instr",
"instrs : instrs instr",
"instr : IF expr THEN instr",
"instr : IF expr THEN instr ELSE instr",
"instr : DO instr WHILE expr ';'",
"instr : FOR leftvalue IN expr updw expr step DO instr",
"instr : expr ';'",
"instr : body",
"instr : BREAK INT ';'",
"instr : CONTINUE INT ';'",
"instr : BREAK ';'",
"instr : CONTINUE ';'",
"instr : leftvalue '#' expr ';'",
"instr : error ';'",
"updw : UPTO",
"updw : DOWNTO",
"step :",
"step : STEP expr",
"exprs : exprs ',' expr",
"exprs : expr",
"expr : INT",
"expr : REAL",
"expr : STR",
"expr : leftvalue",
"expr : ID '(' exprs ')'",
"expr : ID '(' ')'",
"expr : '(' expr ')'",
"expr : leftvalue ASSIGN expr",
"expr : DEC leftvalue",
"expr : INC leftvalue",
"expr : leftvalue INC",
"expr : leftvalue DEC",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '>' expr",
"expr : expr '<' expr",
"expr : expr EQ expr",
"expr : expr NE expr",
"expr : expr GE expr",
"expr : expr LE expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : expr '!'",
"leftvalue : ID",
"leftvalue : ID '[' expr ']'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 202 "diy.y"


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

#line 633 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
