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
#define PROG 288
#define DECLS 289
#define DECL 290
#define INI 291
#define NIL 292
#define EXPRS 293
#define ALLOC 294
#define ARGINST 295
#define PARAMS 296
#define PARAM 297
#define INSTRS 298
#define ARGS 299
#define BATATA 300
#define PMINUS 301
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
    3,    3,    3,    3,    1,    1,
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
    3,    3,    2,    2,    1,    4,
};
static const YYINT yydefred[] = {                         0,
    0,   18,    0,    0,    3,    0,   10,    4,   16,    0,
   19,   20,   21,   22,    0,   14,    0,    0,    0,    0,
    5,    0,   23,   26,   28,    0,    0,    0,    0,   30,
    0,    6,   24,   27,   25,    9,    0,    0,    0,    0,
    0,    0,   58,   59,    0,   60,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   34,    0,    0,   45,   38,
    0,    0,    0,    8,   31,   12,    0,   29,   51,    0,
    0,    0,    0,    0,    0,    0,    0,   48,    0,   49,
   67,   66,   84,    0,    0,   68,   69,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   83,   44,   36,   39,   35,    0,    0,   32,    7,
   63,    0,    0,    0,    0,    0,    0,   46,   47,   64,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   37,   33,   62,    0,   86,
    0,    0,    0,   50,    0,   42,    0,   52,   53,    0,
   41,    0,    0,    0,    0,    0,   43,
};
static const YYINT yydgoto[] = {                          3,
   73,   22,   58,  113,   59,   67,   60,   61,   62,    4,
    5,   29,   17,   10,    6,   30,   31,  150,  154,
};
static const YYINT yysindex[] = {                      -236,
  -40,    0,    0, -236,    0, -253,    0,    0,    0, -218,
    0,    0,    0,    0,   23,    0, -226,  -37,   80,   43,
    0,  -17,    0,    0,    0, -199, -208,  -42,   23,    0,
   -7,    0,    0,    0,    0,    0,  360,   19, -176,  -27,
 -218,   40,    0,    0,  -15,    0,  673,  395, -159,  -46,
  -43, -159, -159,  395,  395,    0,  -28,   71,    0,    0,
  603,  545,   47,    0,    0,    0,   51,    0,    0,  654,
  395, -151, -256,   99,   21, -149,   62,    0,   68,    0,
    0,    0,    0,  115,  395,    0,    0,  395,  395,  395,
  395,  395,  395,  395,  395,  395,  395,  395,  395,  395,
  395,    0,    0,    0,    0,    0,  639,   69,    0,    0,
    0,  394,    7,  131,  395,  673,  395,    0,    0,    0,
  394,  263,  429,  303,  303,  429,  422,  287,  303,  303,
   82,   82,  101,  101,  101,    0,    0,    0,  395,    0,
  329, -150,   60,    0,  394,    0,  673,    0,    0,  395,
    0,  165,  395, -123,  394,  673,    0,
};
static const YYINT yyrindex[] = {                         1,
    0,    0,    0,    6,    0, -187,    0,    0,    0,    0,
    0,    0,    0,    0, -120,    0,    0,    0, -117,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -120,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   86,
    0,    0,    0,    0,  -33,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  383,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   30,    0,    2,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   25,    0,    0,    0,    0,    0,    0,    0,    0,
  793,    0,  844,  939,  948, 1009,  479,  -23,  974,  983,
  904,  913,  455,  490,  516,    0,    0,    0,    0,    0,
    0,  584,    0,    0,   38,    0,    0,    0,    0,    0,
    0, -114,    0,    0, -111,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  544,    0, 1214,    0,   10,    0,   33,   89,    0,    0,
  151,  153,  136,  147,    0,   -9,    0,    0,    0,
};
#define YYTABLESIZE 1367
static const YYINT yytable[] = {                         85,
    2,   85,   20,   85,   85,    1,   88,   85,   85,   85,
   85,   85,   78,   85,   81,   80,   36,   81,    7,    1,
   81,   21,    9,   85,   70,   85,   85,   63,   85,   86,
   87,   68,   18,   40,   85,   81,   41,   38,   85,   85,
    2,   32,   85,   85,   85,   85,   85,  138,   85,   66,
  139,   35,  108,   11,   12,   13,   14,   33,   34,   85,
   85,   85,   61,   85,   16,   57,   61,   61,   57,   81,
   61,   61,   61,   61,   61,   71,   61,   64,   56,   72,
   37,   56,   65,   28,   15,   15,   15,   15,   61,   61,
   85,   61,  102,  105,   85,   37,  101,   94,   69,   75,
   81,   99,   97,  102,   98,  109,  100,  101,   94,  110,
  115,   71,   99,   97,  102,   98,  117,  100,  101,   96,
  118,   95,   61,   99,   26,   85,  119,  137,  100,  103,
   96,  102,   95,  102,  147,  101,   94,  156,   13,  105,
   99,   97,   15,   98,   11,  100,   54,  102,  142,   55,
  107,  101,   94,   61,    8,  120,   99,   97,   96,   98,
   95,  100,   15,  102,   39,   27,    0,  101,   94,    0,
    0,    0,   99,   97,   96,   98,   95,  100,    0,  151,
    0,    0,    0,   93,    0,    0,    0,    0,  157,    0,
   96,    0,   95,    0,   93,    0,    0,  102,    0,    0,
    0,  101,   94,    0,    0,    0,   99,   97,    0,   98,
   77,  100,    0,   79,    0,    0,    0,    0,    0,    0,
    0,    0,   93,  140,   96,    0,   95,   85,    0,    0,
   85,    0,    0,   85,   85,   85,    0,   81,   93,    0,
   81,    0,   19,   81,   81,   81,   85,   85,   85,   85,
   85,   85,   85,   85,   93,    0,    0,   86,   87,    0,
    0,    0,   85,    0,    0,   85,    0,   85,   85,   85,
   85,    0,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   85,   85,   85,   85,    0,    0,   93,    0,
   61,    0,    0,   61,    0,  102,   61,   61,   61,  101,
   94,    0,    0,    0,   99,   97,    0,   98,    0,  100,
   61,   61,   61,   61,   11,   12,   13,   14,    0,  102,
    0,  144,   96,  101,   95,    0,  148,  149,   99,   97,
    0,   98,    0,  100,    0,  102,   23,   24,   25,  101,
   89,   90,   91,   92,   99,   97,   96,   98,   95,  100,
    0,   89,   90,   91,   92,    9,    0,    0,    0,    0,
    0,  102,  116,    0,    0,  101,   94,    0,    0,    0,
   99,   97,    0,   98,    0,  100,    0,    0,    0,   89,
   90,   91,   92,    0,    0,    0,   93,  146,   96,    0,
   95,    0,    0,    0,    0,   89,   90,   91,   92,   55,
    0,    0,    0,    0,   54,    0,    0,    0,    0,    0,
    0,   89,   90,   91,   92,   61,    0,    0,    0,   61,
   61,    0,    0,    0,   61,   61,  102,   61,    0,   61,
  101,   94,    0,  153,   55,   99,   97,    0,   98,   54,
  100,   61,   61,    0,   61,   89,   90,   91,   92,    0,
    0,    0,   93,   96,  102,   95,    0,    0,  101,   94,
    0,  102,    0,   99,   97,  101,   98,    0,  100,    0,
   99,   97,    0,   98,    0,  100,    0,    0,    0,    0,
    0,   96,   37,   95,   56,    0,    0,    0,   96,    0,
   95,   70,   70,    0,    0,   70,   70,   70,   70,   70,
    0,   70,    0,    0,    0,    0,   61,    0,    0,    0,
    0,    0,    0,   70,   70,    0,   70,   93,    0,   82,
    0,    0,   82,    0,    0,    0,   71,   71,    0,    0,
   71,   71,   71,   71,   71,    0,   71,   82,    0,    0,
    0,    0,    0,   89,   90,   91,   92,   70,   71,   71,
    0,   71,   72,   72,    0,    0,   72,   72,   72,   72,
   72,    0,   72,    0,    0,    0,    0,   89,   90,   91,
   92,   82,    0,    0,   72,   72,    0,   72,   70,    0,
   57,    0,   71,    0,   55,    0,    0,    0,    0,   54,
   57,    0,   76,    0,    0,   81,   82,    0,    0,    0,
    0,    0,   82,    0,   57,   57,    0,    0,   72,   89,
   90,   91,   92,   71,    0,   42,   43,   44,   45,   46,
   47,    0,   48,   40,   49,    0,    0,    0,   40,   50,
   51,   11,   12,   13,   14,    0,    0,    0,    0,   72,
    0,    0,   55,    0,    0,   52,   53,   54,    0,    0,
   57,   43,   44,   45,   46,    0,    0,    0,    0,   57,
    0,    0,    0,   61,   61,   61,   61,   37,    0,  106,
    0,    0,    0,    0,   89,   90,   91,   92,   55,    0,
   52,   53,    0,   54,    0,    0,    0,    0,    0,    0,
   57,    0,    0,   55,  111,    0,    0,    0,   54,   57,
    0,    0,   89,   90,   91,   92,   40,    0,   40,    0,
   90,   91,   55,    0,    0,   70,    0,   54,   70,    0,
    0,   70,   70,   70,    0,   37,    0,  104,    0,    0,
    0,    0,    0,    0,    0,   70,   70,   70,   70,   82,
    0,    0,   82,    0,    0,   82,   82,   82,    0,    0,
   71,    0,    0,   71,    0,    0,   71,   71,   71,    0,
    0,   37,    0,  136,    0,    0,    0,    0,    0,    0,
   71,   71,   71,   71,    0,    0,   72,    0,    0,   72,
    0,    0,   72,   72,   72,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   37,   72,   72,   72,   72,
   42,   43,   44,   45,   46,   47,    0,   48,    0,   49,
    0,    0,    0,    0,   50,   51,   11,   12,   13,   14,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   52,   53,    0,   65,    0,    0,   65,    0,    0,   40,
   40,   40,   40,   40,   40,   40,   40,    0,   40,    0,
    0,   65,    0,   40,   40,    0,    0,    0,   42,   43,
   44,   45,   46,   47,    0,   48,    0,   49,    0,   40,
   40,    0,   50,   51,    0,    0,    0,    0,    0,    0,
    0,   78,    0,    0,   78,   65,    0,   78,   52,   53,
    0,    0,    0,    0,   42,   43,   44,   45,   46,   47,
    0,   48,   78,   49,    0,    0,    0,    0,   50,   51,
   43,   44,   45,   46,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   52,   53,    0,    0,   42,   43,
   44,   45,   46,   47,    0,   48,   78,   49,    0,   52,
   53,   73,   50,   51,   73,    0,   73,   73,   73,    0,
   74,    0,    0,   74,    0,   74,   74,   74,   52,   53,
    0,    0,   73,   73,    0,   73,    0,   78,    0,    0,
    0,   74,   74,    0,   74,    0,   79,    0,    0,   79,
    0,    0,   79,    0,    0,   80,    0,    0,   80,    0,
    0,   80,    0,    0,    0,    0,   73,   79,   79,    0,
   79,    0,    0,    0,    0,   74,   80,   80,    0,   80,
    0,   75,    0,    0,   75,    0,    0,   75,    0,    0,
   76,    0,    0,   76,    0,    0,   76,   73,    0,    0,
    0,   79,   75,   75,    0,   75,   74,    0,    0,    0,
   80,   76,   76,    0,   76,    0,   77,    0,    0,   77,
    0,    0,   77,   65,    0,    0,   65,    0,    0,   65,
   65,   65,   79,    0,    0,    0,   75,   77,    0,    0,
    0,   80,    0,    0,    0,   76,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   75,    0,    0,
    0,   77,    0,    0,   78,    0,   76,   78,    0,    0,
   78,   78,   78,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   78,    0,    0,   78,    0,    0,
    0,    0,   77,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   73,    0,    0,   73,    0,    0,
   73,   73,   73,   74,    0,    0,   74,    0,    0,   74,
   74,   74,    0,    0,   73,   73,   73,   73,    0,    0,
    0,    0,    0,   74,   74,   74,   74,    0,    0,   79,
    0,    0,   79,    0,    0,   79,   79,   79,   80,    0,
    0,   80,    0,    0,   80,   80,   80,    0,    0,   79,
   79,   79,   79,    0,    0,    0,    0,    0,   80,   80,
   80,   80,    0,    0,   75,    0,    0,   75,    0,    0,
   75,   75,   75,   76,    0,    0,   76,    0,    0,   76,
   76,   76,    0,    0,   75,   75,   75,   75,    0,    0,
    0,   74,    0,   76,   76,   76,   76,   83,   84,   77,
    0,    0,   77,    0,    0,   77,   77,   77,    0,    0,
    0,    0,    0,  112,  114,    0,    0,    0,    0,   77,
    0,    0,   77,    0,    0,    0,    0,    0,  121,    0,
    0,  122,  123,  124,  125,  126,  127,  128,  129,  130,
  131,  132,  133,  134,  135,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  141,    0,
  143,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  145,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  152,    0,    0,  155,
};
static const YYINT yycheck[] = {                         33,
    0,   35,   40,   37,   38,    0,   35,   41,   42,   43,
   44,   45,   59,   47,   38,   59,   59,   41,   59,  256,
   44,   59,  276,  280,   40,   59,   60,   37,   62,  286,
  287,   41,  259,   41,   33,   59,   44,   28,   37,   38,
  277,   59,   41,   42,   43,   44,   45,   41,   47,   40,
   44,  260,   62,  272,  273,  274,  275,  257,  258,   93,
   59,   60,   33,   62,   42,   41,   37,   38,   44,   93,
   41,   42,   43,   44,   45,   91,   47,   59,   41,   47,
  123,   44,  259,   41,  272,  273,  274,  275,   59,   60,
  124,   62,   33,   61,   93,  123,   37,   38,   59,  259,
  124,   42,   43,   33,   45,   59,   47,   37,   38,   59,
  262,   91,   42,   43,   33,   45,  266,   47,   37,   60,
   59,   62,   93,   42,   45,  124,   59,   59,   47,   59,
   60,   33,   62,   33,  285,   37,   38,  261,  259,  107,
   42,   43,  260,   45,   59,   47,  261,   33,  116,  261,
   62,   37,   38,  124,    4,   41,   42,   43,   60,   45,
   62,   47,   10,   33,   29,   19,   -1,   37,   38,   -1,
   -1,   -1,   42,   43,   60,   45,   62,   47,   -1,  147,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,  156,   -1,
   60,   -1,   62,   -1,  124,   -1,   -1,   33,   -1,   -1,
   -1,   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,
  257,   47,   -1,  257,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  124,   93,   60,   -1,   62,  261,   -1,   -1,
  264,   -1,   -1,  267,  268,  269,   -1,  261,  124,   -1,
  264,   -1,  280,  267,  268,  269,  280,  281,  282,  283,
  284,  280,  286,  287,  124,   -1,   -1,  286,  287,   -1,
   -1,   -1,  261,   -1,   -1,  264,   -1,  266,  267,  268,
  269,   -1,  272,  273,  274,  275,  276,  272,  273,  274,
  275,  276,  281,  282,  283,  284,   -1,   -1,  124,   -1,
  261,   -1,   -1,  264,   -1,   33,  267,  268,  269,   37,
   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
  281,  282,  283,  284,  272,  273,  274,  275,   -1,   33,
   -1,   59,   60,   37,   62,   -1,  267,  268,   42,   43,
   -1,   45,   -1,   47,   -1,   33,  257,  258,  259,   37,
  281,  282,  283,  284,   42,   43,   60,   45,   62,   47,
   -1,  281,  282,  283,  284,  276,   -1,   -1,   -1,   -1,
   -1,   33,  264,   -1,   -1,   37,   38,   -1,   -1,   -1,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,  281,
  282,  283,  284,   -1,   -1,   -1,  124,   59,   60,   -1,
   62,   -1,   -1,   -1,   -1,  281,  282,  283,  284,   40,
   -1,   -1,   -1,   -1,   45,   -1,   -1,   -1,   -1,   -1,
   -1,  281,  282,  283,  284,   33,   -1,   -1,   -1,   37,
   38,   -1,   -1,   -1,   42,   43,   33,   45,   -1,   47,
   37,   38,   -1,  269,   40,   42,   43,   -1,   45,   45,
   47,   59,   60,   -1,   62,  281,  282,  283,  284,   -1,
   -1,   -1,  124,   60,   33,   62,   -1,   -1,   37,   38,
   -1,   33,   -1,   42,   43,   37,   45,   -1,   47,   -1,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,   60,  123,   62,  125,   -1,   -1,   -1,   60,   -1,
   62,   37,   38,   -1,   -1,   41,   42,   43,   44,   45,
   -1,   47,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   -1,   -1,   59,   60,   -1,   62,  124,   -1,   41,
   -1,   -1,   44,   -1,   -1,   -1,   37,   38,   -1,   -1,
   41,   42,   43,   44,   45,   -1,   47,   59,   -1,   -1,
   -1,   -1,   -1,  281,  282,  283,  284,   93,   59,   60,
   -1,   62,   37,   38,   -1,   -1,   41,   42,   43,   44,
   45,   -1,   47,   -1,   -1,   -1,   -1,  281,  282,  283,
  284,   93,   -1,   -1,   59,   60,   -1,   62,  124,   -1,
   37,   -1,   93,   -1,   40,   -1,   -1,   -1,   -1,   45,
   47,   -1,   49,   -1,   -1,   52,   53,   -1,   -1,   -1,
   -1,   -1,  124,   -1,   61,   62,   -1,   -1,   93,  281,
  282,  283,  284,  124,   -1,  256,  257,  258,  259,  260,
  261,   -1,  263,   40,  265,   -1,   -1,   -1,   45,  270,
  271,  272,  273,  274,  275,   -1,   -1,   -1,   -1,  124,
   -1,   -1,   40,   -1,   -1,  286,  287,   45,   -1,   -1,
  107,  257,  258,  259,  260,   -1,   -1,   -1,   -1,  116,
   -1,   -1,   -1,  281,  282,  283,  284,  123,   -1,  125,
   -1,   -1,   -1,   -1,  281,  282,  283,  284,   40,   -1,
  286,  287,   -1,   45,   -1,   -1,   -1,   -1,   -1,   -1,
  147,   -1,   -1,   40,   41,   -1,   -1,   -1,   45,  156,
   -1,   -1,  281,  282,  283,  284,  123,   -1,  125,   -1,
  282,  283,   40,   -1,   -1,  261,   -1,   45,  264,   -1,
   -1,  267,  268,  269,   -1,  123,   -1,  125,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  281,  282,  283,  284,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,   -1,
  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,
   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,   -1,   -1,  261,   -1,   -1,  264,
   -1,   -1,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  123,  281,  282,  283,  284,
  256,  257,  258,  259,  260,  261,   -1,  263,   -1,  265,
   -1,   -1,   -1,   -1,  270,  271,  272,  273,  274,  275,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  286,  287,   -1,   41,   -1,   -1,   44,   -1,   -1,  256,
  257,  258,  259,  260,  261,  262,  263,   -1,  265,   -1,
   -1,   59,   -1,  270,  271,   -1,   -1,   -1,  256,  257,
  258,  259,  260,  261,   -1,  263,   -1,  265,   -1,  286,
  287,   -1,  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   38,   -1,   -1,   41,   93,   -1,   44,  286,  287,
   -1,   -1,   -1,   -1,  256,  257,  258,  259,  260,  261,
   -1,  263,   59,  265,   -1,   -1,   -1,   -1,  270,  271,
  257,  258,  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  286,  287,   -1,   -1,  256,  257,
  258,  259,  260,  261,   -1,  263,   93,  265,   -1,  286,
  287,   38,  270,  271,   41,   -1,   43,   44,   45,   -1,
   38,   -1,   -1,   41,   -1,   43,   44,   45,  286,  287,
   -1,   -1,   59,   60,   -1,   62,   -1,  124,   -1,   -1,
   -1,   59,   60,   -1,   62,   -1,   38,   -1,   -1,   41,
   -1,   -1,   44,   -1,   -1,   38,   -1,   -1,   41,   -1,
   -1,   44,   -1,   -1,   -1,   -1,   93,   59,   60,   -1,
   62,   -1,   -1,   -1,   -1,   93,   59,   60,   -1,   62,
   -1,   38,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,
   38,   -1,   -1,   41,   -1,   -1,   44,  124,   -1,   -1,
   -1,   93,   59,   60,   -1,   62,  124,   -1,   -1,   -1,
   93,   59,   60,   -1,   62,   -1,   38,   -1,   -1,   41,
   -1,   -1,   44,  261,   -1,   -1,  264,   -1,   -1,  267,
  268,  269,  124,   -1,   -1,   -1,   93,   59,   -1,   -1,
   -1,  124,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,
   -1,   93,   -1,   -1,  261,   -1,  124,  264,   -1,   -1,
  267,  268,  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  281,   -1,   -1,  284,   -1,   -1,
   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  261,   -1,   -1,  264,   -1,   -1,
  267,  268,  269,  261,   -1,   -1,  264,   -1,   -1,  267,
  268,  269,   -1,   -1,  281,  282,  283,  284,   -1,   -1,
   -1,   -1,   -1,  281,  282,  283,  284,   -1,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,  261,   -1,
   -1,  264,   -1,   -1,  267,  268,  269,   -1,   -1,  281,
  282,  283,  284,   -1,   -1,   -1,   -1,   -1,  281,  282,
  283,  284,   -1,   -1,  261,   -1,   -1,  264,   -1,   -1,
  267,  268,  269,  261,   -1,   -1,  264,   -1,   -1,  267,
  268,  269,   -1,   -1,  281,  282,  283,  284,   -1,   -1,
   -1,   48,   -1,  281,  282,  283,  284,   54,   55,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,   -1,
   -1,   -1,   -1,   70,   71,   -1,   -1,   -1,   -1,  281,
   -1,   -1,  284,   -1,   -1,   -1,   -1,   -1,   85,   -1,
   -1,   88,   89,   90,   91,   92,   93,   94,   95,   96,
   97,   98,   99,  100,  101,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  115,   -1,
  117,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  139,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  150,   -1,   -1,  153,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 301
#define YYUNDFTOKEN 323
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
"LE","EQ","ELSE","INC","DEC","PROG","DECLS","DECL","INI","NIL","EXPRS","ALLOC",
"ARGINST","PARAMS","PARAM","INSTRS","ARGS","BATATA","PMINUS",0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"expr : '-' expr",
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
#line 224 "diy.y"

char **names =
 #if YYDEBUG > 0
 (char**)yyname;
 #else
 0;
 #endif

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

#line 668 "y.tab.c"

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
case 1:
#line 57 "diy.y"
	{Node *n = uniNode(PROG, yystack.l_mark[0].n); printNode(n,0,names);}
break;
case 3:
#line 61 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 4:
#line 62 "diy.y"
	{yyval.n = binNode(DECLS, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 5:
#line 66 "diy.y"
	{yyval.n=uniNode(DECL, strNode(ID,yystack.l_mark[-1].s));
						IDnew(yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info+yystack.l_mark[-2].n->info,yystack.l_mark[-1].s,0);}
break;
case 6:
#line 69 "diy.y"
	{ IDnew(yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info,yystack.l_mark[-2].s,0);
            					  yyval.n=binNode(INI, strNode(ID, yystack.l_mark[-2].s), yystack.l_mark[-1].n);
            					  yyval.n->info = yystack.l_mark[-6].n->info + yystack.l_mark[-5].n->info + yystack.l_mark[-4].n->info + yystack.l_mark[-3].n->info;
            					  if(yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info != 4) {
            					     if(yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info != yystack.l_mark[-1].n->info){
            					     	yyerror("Different type assignment");
            					     }
            					  }
            					}
break;
case 9:
#line 83 "diy.y"
	{yyval.n=uniNode(DECL,strNode(ID,yystack.l_mark[-3].s));
            						IDnew(yystack.l_mark[-7].n->info+yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info,yystack.l_mark[-3].s,0);}
break;
case 10:
#line 85 "diy.y"
	{yyerrok;}
break;
case 11:
#line 89 "diy.y"
	{yyval.n= nilNode(NIL);}
break;
case 12:
#line 90 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 14:
#line 94 "diy.y"
	{yyval.n = uniNode(REAL,0); yyval.n->info = 4;}
break;
case 16:
#line 98 "diy.y"
	{yyval.n = uniNode(CONST,0); yyval.n->info = 8;}
break;
case 18:
#line 103 "diy.y"
	{yyval.n = uniNode(VOID,0); yyval.n->info = 16;}
break;
case 19:
#line 107 "diy.y"
	{yyval.n = uniNode(VOID,0); yyval.n->info = 0;}
break;
case 20:
#line 108 "diy.y"
	{yyval.n = uniNode(INTEGER,0); yyval.n->info = 1;}
break;
case 21:
#line 109 "diy.y"
	{yyval.n = uniNode(STRING,0); yyval.n->info = 2;}
break;
case 22:
#line 110 "diy.y"
	{yyval.n = uniNode(NUMBER,0); yyval.n->info = 3;}
break;
case 23:
#line 115 "diy.y"
	{yyval.n = intNode(INT,yystack.l_mark[0].i); yyval.n->info = 1;}
break;
case 24:
#line 116 "diy.y"
	{yyval.n = intNode(INT,-yystack.l_mark[0].i); yyval.n->info = 1;}
break;
case 25:
#line 117 "diy.y"
	{yyval.n = strNode(STR,yystack.l_mark[0].s); yyval.n->info = yystack.l_mark[-1].n->info+2;}
break;
case 26:
#line 118 "diy.y"
	{yyval.n = realNode(REAL,yystack.l_mark[0].r); yyval.n->info = 3;}
break;
case 27:
#line 119 "diy.y"
	{yyval.n = realNode(REAL,-yystack.l_mark[0].r); yyval.n->info = 3;}
break;
case 28:
#line 120 "diy.y"
	{yyval.n = strNode(ID, yystack.l_mark[0].s); yyval.n->info = IDfind(yystack.l_mark[0].s,0);}
break;
case 29:
#line 124 "diy.y"
	{yyval.n = binNode(PARAMS, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[0].n->info;}
break;
case 30:
#line 125 "diy.y"
	{yyval.n = uniNode(PARAMS,yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 31:
#line 128 "diy.y"
	{yyval.n = strNode(ID,yystack.l_mark[0].s); IDnew(yystack.l_mark[-2].n->info+yystack.l_mark[-1].n->info,yystack.l_mark[0].s,0);
				yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[-1].n->info;}
break;
case 32:
#line 133 "diy.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 33:
#line 134 "diy.y"
	{yyval.n = binNode(ARGS, yystack.l_mark[-2].n, yystack.l_mark[-1].n); yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[-1].n->info; }
break;
case 34:
#line 138 "diy.y"
	{yyval.n = nilNode(NIL);}
break;
case 35:
#line 139 "diy.y"
	{yyval.n = uniNode(PARAMS,yystack.l_mark[-1].n);}
break;
case 36:
#line 140 "diy.y"
	{yyval.n = uniNode(INSTRS,yystack.l_mark[-1].n);}
break;
case 37:
#line 141 "diy.y"
	{yyval.n = binNode(ARGINST, yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 38:
#line 146 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 39:
#line 147 "diy.y"
	{yyval.n = binNode(INSTRS,yystack.l_mark[-1].n,yystack.l_mark[0].n);}
break;
case 44:
#line 162 "diy.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 45:
#line 163 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 50:
#line 168 "diy.y"
	{yyval.n = binNode(ALLOC,yystack.l_mark[-3].n,yystack.l_mark[-1].n); yyval.n->info = yystack.l_mark[-3].n->info;}
break;
case 51:
#line 169 "diy.y"
	{yyerrok;}
break;
case 52:
#line 172 "diy.y"
	{yyval.n = uniNode(UPTO,0);}
break;
case 53:
#line 173 "diy.y"
	{yyval.n = uniNode(DOWNTO,0);}
break;
case 54:
#line 176 "diy.y"
	{yyval.n = nilNode(NIL);}
break;
case 55:
#line 177 "diy.y"
	{yyval.n =uniNode(STEP,yystack.l_mark[0].n);}
break;
case 56:
#line 180 "diy.y"
	{yyval.n = binNode(EXPRS, yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 57:
#line 181 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 58:
#line 185 "diy.y"
	{yyval.n = intNode(INT,yystack.l_mark[0].i); yyval.n->info = 1;}
break;
case 59:
#line 186 "diy.y"
	{yyval.n = realNode(REAL,yystack.l_mark[0].r); yyval.n->info = 3;}
break;
case 60:
#line 187 "diy.y"
	{yyval.n = strNode(STR,yystack.l_mark[0].s); yyval.n->info = 2;}
break;
case 61:
#line 188 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 64:
#line 191 "diy.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 66:
#line 193 "diy.y"
	{if(yystack.l_mark[0].n->info!=1){yyerror("Trying to decrement an invalid identifier");}
      				 yyval.n = binNode(DEC, nilNode(NIL), yystack.l_mark[0].n); yyval.n->info = 1;}
break;
case 67:
#line 195 "diy.y"
	{if(yystack.l_mark[0].n->info!=1){yyerror("Trying to increment an invalid identifier");}
                                 yyval.n = binNode(INC, nilNode(NIL), yystack.l_mark[0].n); yyval.n->info = 1;}
break;
case 68:
#line 197 "diy.y"
	{if(yystack.l_mark[-1].n->info!=1){yyerror("Trying to increment an invalid identifier");}
                                 yyval.n = binNode(INC, nilNode(NIL), yystack.l_mark[-1].n); yyval.n->info = 1;}
break;
case 69:
#line 199 "diy.y"
	{if(yystack.l_mark[-1].n->info!=1){yyerror("Trying to decrement an invalid identifier");}
                           	yyval.n = binNode(DEC, nilNode(NIL), yystack.l_mark[-1].n); yyval.n->info = 1;}
break;
case 84:
#line 215 "diy.y"
	{if(yystack.l_mark[0].n->info == 0 || yystack.l_mark[0].n->info==2){yyerror("Invalid type for symmetrical assigment");}
				yyval.n=uniNode(PMINUS, yystack.l_mark[0].n); yyval.n->info=yystack.l_mark[0].n->info;}
break;
case 85:
#line 219 "diy.y"
	{yyval.n = strNode(ID,yystack.l_mark[0].s); yyval.n->info = IDfind(yystack.l_mark[0].s,0);}
break;
#line 1102 "y.tab.c"
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
