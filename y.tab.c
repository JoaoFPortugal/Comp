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
int ciclo=0;


#line 23 "diy.y"
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
#line 55 "y.tab.c"

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
#define POINTER 300
#define SUM 301
#define SUBT 302
#define MUL 303
#define DIV 304
#define MOD 305
#define GT 306
#define LT 307
#define AND 308
#define OR 309
#define FAC 310
#define ARR 311
#define FUNC 312
#define NEG 313
#define IFX 314
#define PMINUS 315
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   10,   10,   11,   11,   11,   20,   11,   11,
   11,    6,    6,   13,   13,   14,   14,   15,   15,   12,
   12,   12,   12,    2,    2,    2,    2,    2,    2,   17,
   17,   16,    9,    9,    5,    5,   21,    5,    5,    8,
    8,    7,    7,   22,   23,    7,   24,    7,    7,    7,
    7,    7,    7,    7,    7,    7,   18,   18,   19,   19,
    4,    4,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    1,    1,
};
static const YYINT yylen[] = {                            2,
    1,    0,    1,    2,    6,    7,   10,    0,   10,    8,
    2,    0,    1,    0,    1,    0,    1,    0,    1,    1,
    1,    1,    1,    2,    3,    3,    2,    3,    2,    3,
    1,    3,    2,    3,    2,    3,    0,    4,    4,    1,
    2,    4,    6,    0,    0,    7,    0,   10,    2,    1,
    3,    3,    2,    2,    4,    2,    1,    1,    0,    2,
    3,    1,    1,    1,    1,    1,    4,    3,    3,    3,
    2,    2,    2,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    2,    2,
    1,    4,
};
static const YYINT yydefred[] = {                         0,
    0,   19,    0,    0,    3,    0,   11,    4,   17,    0,
   20,   21,   22,   23,    0,   15,    0,    0,    0,    0,
    5,    0,   24,   27,   29,    0,    0,    0,    0,   31,
    0,    6,   25,   28,   26,   10,    0,    0,    0,    0,
    0,    0,   32,   13,    0,   30,    0,   63,   64,    0,
   65,   44,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   35,    0,    0,   50,   40,    0,    0,    0,    9,
    7,   56,    0,    0,    0,    0,    0,    0,    0,    0,
   53,    0,   54,   72,   71,   89,    0,    0,    0,   73,
   74,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   88,   49,   37,   41,   36,
    0,    0,   33,   68,    0,    0,    0,    0,    0,    0,
   51,   52,   69,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   38,   39,
   34,   67,    0,   92,   45,    0,    0,   55,    0,    0,
    0,   57,   58,    0,    0,   43,    0,   46,    0,    0,
    0,   47,    0,   48,
};
static const YYINT yydgoto[] = {                          3,
   76,   22,   64,  116,   65,   45,   66,   67,   68,    4,
    5,   29,   17,   10,    6,   30,   31,  154,  160,   37,
  139,   75,  150,  163,
};
static const YYINT yysindex[] = {                      -239,
  -18,    0,    0, -239,    0, -224,    0,    0,    0, -216,
    0,    0,    0,    0,   23,    0, -177,  -37,   80,   43,
    0,   27,    0,    0,    0, -238, -173,   29,   23,    0,
  -11,    0,    0,    0,    0,    0,  -29, -163,  -29, -216,
  360,   40,    0,    0,   41,    0,   47,    0,    0,  -15,
    0,    0,  395, -149,  -46,  -43, -149, -149,  395,  395,
  395,    0,  -28,   71,    0,    0,  639,  584,   52,    0,
    0,    0,  629,  395,  750, -232,   99,   21, -151,   58,
    0,   62,    0,    0,    0,    0,   86,  115,  395,    0,
    0,  395,  395,  395,  395,  395,  395,  395,  395,  395,
  395,  395,  395,  395,  395,    0,    0,    0,    0,    0,
  681,   65,    0,    0,  394,  -10,  131, -135,  750,  395,
    0,    0,    0,  394,  263,  429,  303,  303,  429,  422,
  287,  303,  303,   -5,   -5,   86,   86,   86,    0,    0,
    0,    0,  395,    0,    0, -157,   60,    0,  394,  395,
  750,    0,    0,  395,  329,    0,  165,    0,  395, -132,
  394,    0,  750,    0,
};
static const YYINT yyrindex[] = {                         1,
    0,    0,    0,    6,    0, -194,    0,    0,    0,    0,
    0,    0,    0,    0, -125,    0,    0,    0, -122,    0,
    0,    0,    0,    0,    0,    0,    0,   12, -125,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   81,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -33,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  383,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   30,    0,    2,    0,    0,
    0,    0,    0,    0,    0,    0,  455,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    9,    0,    0,    0,    0,    0,
    0,    0,    0,  906,    0, 1020,  708,  873, 1029,  862,
  -23,  985,  994,  919,  957,  490,  516,  544,    0,    0,
    0,    0,    0,    0,    0,  604,    0,    0,   25,    0,
    0,    0,    0,    0,    0,    0, -118,    0,    0,    0,
 -116,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  973,    0, 1246,    0,   46,    0,  445,   79,    0,    0,
  135,  139,  121,  132,    0,  -17,    0,    0,    0,    0,
    0,    0,    0,    0,
};
#define YYTABLESIZE 1405
static const YYINT yytable[] = {                         91,
    2,   91,   20,   91,   91,    1,   92,   91,   91,   91,
   91,   91,   81,   91,   86,   83,    1,   86,   33,   34,
   86,   21,   46,   69,   73,   91,   91,  106,   91,   39,
  142,  105,   40,  143,   91,   86,  103,    2,   91,   91,
    7,  104,   91,   91,   91,   91,   91,   89,   91,   62,
  112,    9,   62,   90,   91,   11,   12,   13,   14,   91,
   91,   91,   66,   91,   16,   61,   66,   66,   61,   86,
   66,   66,   66,   66,   66,   74,   66,   16,   16,   16,
   16,   18,   42,   28,   44,   32,   35,   36,   66,   66,
   91,   66,  106,   41,   91,   43,  105,   98,   70,   71,
   86,  103,  101,  106,  102,   72,  104,  105,   98,   78,
  113,   74,  103,  101,  120,  102,  121,  104,  106,  100,
  122,   99,   66,  141,   26,   91,  145,  151,  162,  107,
  100,  106,   99,   14,    8,  105,   98,   16,    8,   12,
  103,  101,   59,  102,   60,  104,  111,  106,   15,   38,
   27,  105,   98,   66,    0,  123,  103,  101,  100,  102,
   99,  104,    0,  106,    0,    0,    0,  105,   98,    0,
    0,    0,  103,  101,  100,  102,   99,  104,    0,    0,
    0,    0,    0,   97,    0,    0,    0,    0,    0,    0,
  100,    0,   99,    0,   97,    0,    0,  106,    0,    0,
    0,  105,   98,    0,    0,    0,  103,  101,    0,  102,
   80,  104,    0,   82,    0,    0,    0,    0,    0,    0,
    0,    0,   97,  144,  100,    0,   99,   91,    0,    0,
   91,    0,    0,   91,   91,   91,    0,   86,   97,    0,
   86,    0,   19,   86,   86,   86,   91,   91,   91,   91,
   91,   89,   91,   91,   97,    0,    0,   90,   91,    0,
    0,    0,   91,    0,    0,   91,    0,   91,   91,   91,
   91,    0,   18,   18,   18,   18,   18,   18,   18,   18,
   18,   18,   91,   91,   91,   91,    0,    0,   97,    0,
   66,    0,    0,   66,    0,  106,   66,   66,   66,  105,
   98,    0,    0,    0,  103,  101,    0,  102,    0,  104,
   66,   66,   66,   66,   11,   12,   13,   14,    0,  106,
    0,  148,  100,  105,   99,    0,  152,  153,  103,  101,
    0,  102,    0,  104,    0,  106,   23,   24,   25,  105,
   93,   94,   95,   96,  103,  101,  100,  102,   99,  104,
    0,   93,   94,   95,   96,    9,    0,    0,    0,    0,
    0,  106,  119,    0,    0,  105,   98,    0,    0,    0,
  103,  101,    0,  102,    0,  104,    0,    0,    0,   93,
   94,   95,   96,    0,    0,    0,   97,  158,  100,    0,
   99,    0,    0,    0,    0,   93,   94,   95,   96,   61,
    0,    0,    0,    0,   59,    0,    0,    0,    0,    0,
    0,   93,   94,   95,   96,   66,    0,    0,    0,   66,
   66,    0,    0,    0,   66,   66,  106,   66,    0,   66,
  105,   98,    0,  159,   61,  103,  101,    0,  102,   59,
  104,   66,   66,    0,   66,   93,   94,   95,   96,    0,
    0,    0,   97,  100,  106,   99,    0,    0,  105,   98,
    0,  106,    0,  103,  101,  105,  102,    0,  104,    0,
  103,  101,    0,  102,    0,  104,    0,    0,    0,    0,
    0,  100,   41,   99,   62,   60,    0,    0,  100,    0,
   99,   90,   90,    0,    0,   90,   90,   90,   90,   90,
    0,   90,    0,    0,    0,    0,   66,    0,    0,    0,
    0,  109,    0,   90,   90,    0,   90,   97,    0,  118,
   60,    0,    0,    0,    0,    0,   75,   75,    0,    0,
   75,   75,   75,   75,   75,    0,   75,    0,    0,    0,
    0,    0,    0,   93,   94,   95,   96,   90,   75,   75,
    0,   75,   76,   76,    0,  109,   76,   76,   76,   76,
   76,    0,   76,  146,    0,    0,    0,   93,   94,   95,
   96,    0,    0,    0,   76,   76,    0,   76,   90,    0,
   77,   77,   75,    0,   77,   77,   77,   77,   77,    0,
   77,    0,    0,    0,    0,  156,    0,    0,    0,    0,
    0,    0,   77,   77,    0,   77,    0,  164,   76,   93,
   94,   95,   96,   75,    0,   47,   48,   49,   50,   51,
   52,    0,   53,   61,   54,    0,    0,    0,   59,   55,
   56,   11,   12,   13,   14,    0,   77,    0,    0,   76,
    0,    0,    0,   42,    0,   57,   58,    0,   42,    0,
    0,   48,   49,   50,   51,    0,    0,    0,    0,    0,
    0,    0,    0,   66,   66,   66,   66,   77,   61,  114,
    0,    0,    0,   59,   93,   94,   95,   96,   61,    0,
   57,   58,    0,   59,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   93,   94,   95,   96,   41,    0,  110,   60,
   94,   95,    0,    0,    0,   90,    0,    0,   90,    0,
   61,   90,   90,   90,    0,   59,   42,    0,   42,   42,
    0,    0,    0,    0,    0,   90,   90,   90,   90,    0,
    0,    0,    0,    0,    0,   82,    0,    0,   82,    0,
   75,   82,    0,   75,   60,    0,   75,   75,   75,    0,
    0,   41,    0,  108,   60,    0,   82,   82,    0,   82,
   75,   75,   75,   75,    0,    0,   76,    0,    0,   76,
    0,    0,   76,   76,   76,    0,    0,    0,    0,   61,
    0,    0,    0,    0,   59,    0,   76,   76,   76,   76,
   82,    0,    0,   41,   77,  140,   60,   77,    0,    0,
   77,   77,   77,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   77,   77,   77,   77,    0,    0,
    0,   82,    0,    0,    0,    0,    0,    0,    0,   47,
   48,   49,   50,   51,   52,    0,   53,    0,   54,    0,
    0,    0,    0,   55,   56,   11,   12,   13,   14,   42,
   42,   42,   42,   42,   42,   42,   42,    0,   42,   57,
   58,    0,   41,   42,   42,   60,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   48,   49,   50,   51,   42,
   42,    0,    0,    0,   47,   48,   49,   50,   51,   52,
    0,   53,   87,   54,    0,   87,    0,    0,   55,   56,
   83,    0,    0,   83,   57,   58,   83,    0,    0,    0,
   87,    0,    0,    0,   57,   58,    0,    0,    0,    0,
    0,   83,   83,    0,   83,    0,   47,   48,   49,   50,
   51,   52,    0,   53,    0,   54,   70,    0,    0,   70,
   55,   56,    0,    0,   87,    0,   78,    0,    0,   78,
    0,   78,   78,   78,   70,   83,   57,   58,   82,    0,
    0,   82,    0,    0,   82,   82,   82,   78,   78,    0,
   78,    0,    0,    0,    0,   87,    0,    0,   82,   82,
   82,   82,    0,    0,   79,    0,   83,   79,   70,   79,
   79,   79,    0,    0,    0,   47,   48,   49,   50,   51,
   52,   78,   53,   63,   54,   79,   79,    0,   79,   55,
   56,    0,   84,    0,    0,   84,   79,    0,   84,   84,
   85,   85,    0,    0,   85,   57,   58,   85,    0,   63,
   63,    0,   78,   84,   84,    0,   84,   63,    0,   79,
    0,    0,   85,   85,    0,   85,    0,   81,    0,    0,
   81,    0,    0,   81,    0,    0,   80,    0,    0,   80,
    0,    0,   80,    0,    0,    0,    0,   84,   81,    0,
   79,    0,    0,   63,    0,    0,   85,   80,    0,    0,
    0,   63,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   84,    0,
    0,    0,   81,    0,    0,    0,    0,   85,    0,    0,
    0,   80,   87,   63,    0,   87,    0,    0,   87,   87,
   87,    0,    0,   83,    0,   63,   83,    0,    0,   83,
   83,   83,    0,   81,    0,    0,    0,    0,    0,    0,
    0,    0,   80,   83,   83,   83,   83,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   70,    0,    0,   70,
    0,    0,   70,   70,   70,    0,    0,    0,    0,   78,
    0,    0,   78,    0,    0,   78,   78,   78,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   78,
   78,   78,   78,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   79,    0,    0,
   79,    0,    0,   79,   79,   79,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   79,   79,   79,
   79,    0,    0,    0,    0,   84,    0,    0,   84,    0,
    0,   84,   84,   84,   85,    0,    0,   85,    0,    0,
   85,   85,   85,    0,    0,   84,   84,   84,   84,    0,
    0,    0,    0,    0,   85,   85,   85,   85,    0,    0,
   81,    0,    0,   81,    0,    0,   81,   81,   81,   80,
    0,    0,   80,    0,    0,   80,   80,   80,   77,    0,
   81,    0,    0,   81,   86,   87,   88,    0,    0,   80,
    0,    0,   80,    0,    0,    0,    0,    0,  115,  117,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  124,    0,    0,  125,  126,  127,
  128,  129,  130,  131,  132,  133,  134,  135,  136,  137,
  138,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  147,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  149,    0,
    0,    0,    0,    0,    0,  155,    0,    0,    0,  157,
    0,    0,    0,    0,  161,
};
static const YYINT yycheck[] = {                         33,
    0,   35,   40,   37,   38,    0,   35,   41,   42,   43,
   44,   45,   59,   47,   38,   59,  256,   41,  257,  258,
   44,   59,   40,   41,   40,   59,   60,   33,   62,   41,
   41,   37,   44,   44,   33,   59,   42,  277,   37,   38,
   59,   47,   41,   42,   43,   44,   45,  280,   47,   41,
   68,  276,   44,  286,  287,  272,  273,  274,  275,   93,
   59,   60,   33,   62,   42,   41,   37,   38,   44,   93,
   41,   42,   43,   44,   45,   91,   47,  272,  273,  274,
  275,  259,   37,   41,   39,   59,  260,   59,   59,   60,
  124,   62,   33,  123,   93,  259,   37,   38,   59,   59,
  124,   42,   43,   33,   45,   59,   47,   37,   38,  259,
   59,   91,   42,   43,  266,   45,   59,   47,   33,   60,
   59,   62,   93,   59,   45,  124,  262,  285,  261,   59,
   60,   33,   62,  259,  123,   37,   38,  260,    4,   59,
   42,   43,  261,   45,  261,   47,   68,   33,   10,   29,
   19,   37,   38,  124,   -1,   41,   42,   43,   60,   45,
   62,   47,   -1,   33,   -1,   -1,   -1,   37,   38,   -1,
   -1,   -1,   42,   43,   60,   45,   62,   47,   -1,   -1,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
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
   -1,   60,  123,   62,  125,  126,   -1,   -1,   60,   -1,
   62,   37,   38,   -1,   -1,   41,   42,   43,   44,   45,
   -1,   47,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   67,   -1,   59,   60,   -1,   62,  124,   -1,   75,
  126,   -1,   -1,   -1,   -1,   -1,   37,   38,   -1,   -1,
   41,   42,   43,   44,   45,   -1,   47,   -1,   -1,   -1,
   -1,   -1,   -1,  281,  282,  283,  284,   93,   59,   60,
   -1,   62,   37,   38,   -1,  111,   41,   42,   43,   44,
   45,   -1,   47,  119,   -1,   -1,   -1,  281,  282,  283,
  284,   -1,   -1,   -1,   59,   60,   -1,   62,  124,   -1,
   37,   38,   93,   -1,   41,   42,   43,   44,   45,   -1,
   47,   -1,   -1,   -1,   -1,  151,   -1,   -1,   -1,   -1,
   -1,   -1,   59,   60,   -1,   62,   -1,  163,   93,  281,
  282,  283,  284,  124,   -1,  256,  257,  258,  259,  260,
  261,   -1,  263,   40,  265,   -1,   -1,   -1,   45,  270,
  271,  272,  273,  274,  275,   -1,   93,   -1,   -1,  124,
   -1,   -1,   -1,   40,   -1,  286,  287,   -1,   45,   -1,
   -1,  257,  258,  259,  260,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  281,  282,  283,  284,  124,   40,   41,
   -1,   -1,   -1,   45,  281,  282,  283,  284,   40,   -1,
  286,  287,   -1,   45,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,  284,  123,   -1,  125,  126,
  282,  283,   -1,   -1,   -1,  261,   -1,   -1,  264,   -1,
   40,  267,  268,  269,   -1,   45,  123,   -1,  125,  126,
   -1,   -1,   -1,   -1,   -1,  281,  282,  283,  284,   -1,
   -1,   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,
  261,   44,   -1,  264,  126,   -1,  267,  268,  269,   -1,
   -1,  123,   -1,  125,  126,   -1,   59,   60,   -1,   62,
  281,  282,  283,  284,   -1,   -1,  261,   -1,   -1,  264,
   -1,   -1,  267,  268,  269,   -1,   -1,   -1,   -1,   40,
   -1,   -1,   -1,   -1,   45,   -1,  281,  282,  283,  284,
   93,   -1,   -1,  123,  261,  125,  126,  264,   -1,   -1,
  267,  268,  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  281,  282,  283,  284,   -1,   -1,
   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  256,
  257,  258,  259,  260,  261,   -1,  263,   -1,  265,   -1,
   -1,   -1,   -1,  270,  271,  272,  273,  274,  275,  256,
  257,  258,  259,  260,  261,  262,  263,   -1,  265,  286,
  287,   -1,  123,  270,  271,  126,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,  286,
  287,   -1,   -1,   -1,  256,  257,  258,  259,  260,  261,
   -1,  263,   41,  265,   -1,   44,   -1,   -1,  270,  271,
   38,   -1,   -1,   41,  286,  287,   44,   -1,   -1,   -1,
   59,   -1,   -1,   -1,  286,  287,   -1,   -1,   -1,   -1,
   -1,   59,   60,   -1,   62,   -1,  256,  257,  258,  259,
  260,  261,   -1,  263,   -1,  265,   41,   -1,   -1,   44,
  270,  271,   -1,   -1,   93,   -1,   38,   -1,   -1,   41,
   -1,   43,   44,   45,   59,   93,  286,  287,  261,   -1,
   -1,  264,   -1,   -1,  267,  268,  269,   59,   60,   -1,
   62,   -1,   -1,   -1,   -1,  124,   -1,   -1,  281,  282,
  283,  284,   -1,   -1,   38,   -1,  124,   41,   93,   43,
   44,   45,   -1,   -1,   -1,  256,  257,  258,  259,  260,
  261,   93,  263,   41,  265,   59,   60,   -1,   62,  270,
  271,   -1,   38,   -1,   -1,   41,   54,   -1,   44,   57,
   58,   38,   -1,   -1,   41,  286,  287,   44,   -1,   67,
   68,   -1,  124,   59,   60,   -1,   62,   75,   -1,   93,
   -1,   -1,   59,   60,   -1,   62,   -1,   38,   -1,   -1,
   41,   -1,   -1,   44,   -1,   -1,   38,   -1,   -1,   41,
   -1,   -1,   44,   -1,   -1,   -1,   -1,   93,   59,   -1,
  124,   -1,   -1,  111,   -1,   -1,   93,   59,   -1,   -1,
   -1,  119,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,
   -1,   -1,   93,   -1,   -1,   -1,   -1,  124,   -1,   -1,
   -1,   93,  261,  151,   -1,  264,   -1,   -1,  267,  268,
  269,   -1,   -1,  261,   -1,  163,  264,   -1,   -1,  267,
  268,  269,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  124,  281,  282,  283,  284,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  261,   -1,   -1,  264,
   -1,   -1,  267,  268,  269,   -1,   -1,   -1,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,
  282,  283,  284,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  261,   -1,   -1,
  264,   -1,   -1,  267,  268,  269,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,  282,  283,
  284,   -1,   -1,   -1,   -1,  261,   -1,   -1,  264,   -1,
   -1,  267,  268,  269,  261,   -1,   -1,  264,   -1,   -1,
  267,  268,  269,   -1,   -1,  281,  282,  283,  284,   -1,
   -1,   -1,   -1,   -1,  281,  282,  283,  284,   -1,   -1,
  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   53,   -1,
  281,   -1,   -1,  284,   59,   60,   61,   -1,   -1,  281,
   -1,   -1,  284,   -1,   -1,   -1,   -1,   -1,   73,   74,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   89,   -1,   -1,   92,   93,   94,
   95,   96,   97,   98,   99,  100,  101,  102,  103,  104,
  105,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  120,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  143,   -1,
   -1,   -1,   -1,   -1,   -1,  150,   -1,   -1,   -1,  154,
   -1,   -1,   -1,   -1,  159,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 315
#define YYUNDFTOKEN 342
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'",0,"'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","REAL","ID","STR","DO",
"WHILE","IF","THEN","FOR","IN","UPTO","DOWNTO","STEP","BREAK","CONTINUE","VOID",
"INTEGER","STRING","NUMBER","CONST","PUBLIC","INCR","DECR","ASSIGN","NE","GE",
"LE","EQ","ELSE","INC","DEC","PROG","DECLS","DECL","INI","NIL","EXPRS","ALLOC",
"ARGINST","PARAMS","PARAM","INSTRS","ARGS","POINTER","SUM","SUBT","MUL","DIV",
"MOD","GT","LT","AND","OR","FAC","ARR","FUNC","NEG","IFX","PMINUS",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"$$1 :",
"declaracao : pub const type ptr ID '(' ')' $$1 body ';'",
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
"$$2 :",
"body : '{' instrs '}' $$2",
"body : '{' args instrs '}'",
"instrs : instr",
"instrs : instrs instr",
"instr : IF expr THEN instr",
"instr : IF expr THEN instr ELSE instr",
"$$3 :",
"$$4 :",
"instr : DO $$3 instr WHILE $$4 expr ';'",
"$$5 :",
"instr : FOR leftvalue IN expr updw expr step DO $$5 instr",
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
"expr : expr EQ expr",
"expr : expr NE expr",
"expr : expr GE expr",
"expr : expr LE expr",
"expr : expr '>' expr",
"expr : expr '<' expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : expr '!'",
"expr : '-' expr",
"expr : '~' expr",
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
#line 231 "diy.y"

int checkOp(Node *op1, Node *op2){
     if(op1->info==0 || op2->info == 0){
     	yyerror("Invalid argument type for operation: can't cast void");
     }

     if(op1->info == 2 || op2->info == 2){
     	yyerror("Invalid argument type for operation: can't cast string");
     }

     if(op1->info == 3 || op2->info == 3){
     	return 3;
     }
     return 1;
}

int checkCompOp(Node *op1, Node *op2){
	if(op1->info == 0 || op2->info == 0){
	  yyerror("Invalid argument type for operation: can't compare void");
	}

	if(op1->info == 2 && op2->info !=2){
	  yyerror("Invalid argument type for operation: can't compare string to non-string");
	}

    return 1;
}

void checkLogicOp(Node *op1, Node *op2){
	if(op1->info != 1 || op2->info != 2){
	   yyerror("Invalid argument type for logic operation");
	}
}

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

#line 738 "y.tab.c"

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
#line 58 "diy.y"
	{yyval.n = uniNode(PROG, yystack.l_mark[0].n); printNode(yystack.l_mark[0].n,0,names);}
break;
case 3:
#line 62 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 4:
#line 63 "diy.y"
	{yyval.n = binNode(DECLS, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 5:
#line 67 "diy.y"
	{yyval.n=uniNode(DECL, strNode(ID,yystack.l_mark[-1].s));
						IDnew(yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info+yystack.l_mark[-2].n->info,yystack.l_mark[-1].s,0);}
break;
case 6:
#line 70 "diy.y"
	{ IDnew(yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info,yystack.l_mark[-2].s,0);
            					  yyval.n=binNode(DECL, strNode(ID, yystack.l_mark[-2].s), yystack.l_mark[-1].n);
            					  yyval.n->info = yystack.l_mark[-6].n->info + yystack.l_mark[-5].n->info + yystack.l_mark[-4].n->info + yystack.l_mark[-3].n->info;
            					  if(yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info != 4) {
            					     if(yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info != yystack.l_mark[-1].n->info){
            					     	yyerror("Different type assignment");
            					     }
            					  }
            					}
break;
case 8:
#line 82 "diy.y"
	{IDnew(yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info + yystack.l_mark[-4].n->info + yystack.l_mark[-3].n->info,yystack.l_mark[-2].s,0); IDpush();
            				     if(yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info !=0 ){ IDnew(yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info,yystack.l_mark[-2].s,0); IDpush();
            			     }}
break;
case 9:
#line 84 "diy.y"
	{yyval.n = binNode(DECL,strNode(ID,yystack.l_mark[-5].s),yystack.l_mark[-1].n); IDpop();}
break;
case 10:
#line 86 "diy.y"
	{yyval.n=uniNode(DECL,strNode(ID,yystack.l_mark[-3].s));
            						IDnew(yystack.l_mark[-7].n->info+yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info,yystack.l_mark[-3].s,0);}
break;
case 11:
#line 88 "diy.y"
	{yyerrok;}
break;
case 12:
#line 92 "diy.y"
	{yyval.n= nilNode(NIL);}
break;
case 13:
#line 93 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 14:
#line 96 "diy.y"
	{yyval.n = nilNode(NIL); yyval.n->info = 0;}
break;
case 15:
#line 97 "diy.y"
	{yyval.n = uniNode(POINTER,0); yyval.n->info = 4;}
break;
case 16:
#line 100 "diy.y"
	{yyval.n = nilNode(NIL); yyval.n->info = 0;}
break;
case 17:
#line 101 "diy.y"
	{yyval.n = uniNode(CONST,0); yyval.n->info = 8;}
break;
case 18:
#line 105 "diy.y"
	{yyval.n = nilNode(NIL); yyval.n->info = 0;}
break;
case 19:
#line 106 "diy.y"
	{yyval.n = uniNode(VOID,0); yyval.n->info = 16;}
break;
case 20:
#line 110 "diy.y"
	{yyval.n = uniNode(VOID,0); yyval.n->info = 0;}
break;
case 21:
#line 111 "diy.y"
	{yyval.n = uniNode(INTEGER,0); yyval.n->info = 1;}
break;
case 22:
#line 112 "diy.y"
	{yyval.n = uniNode(STRING,0); yyval.n->info = 2;}
break;
case 23:
#line 113 "diy.y"
	{yyval.n = uniNode(NUMBER,0); yyval.n->info = 3;}
break;
case 24:
#line 118 "diy.y"
	{yyval.n = intNode(INT,yystack.l_mark[0].i); yyval.n->info = 1;}
break;
case 25:
#line 119 "diy.y"
	{yyval.n = intNode(INT,-yystack.l_mark[0].i); yyval.n->info = 1;}
break;
case 26:
#line 120 "diy.y"
	{yyval.n = strNode(STR,yystack.l_mark[0].s); yyval.n->info = yystack.l_mark[-1].n->info+2;}
break;
case 27:
#line 121 "diy.y"
	{yyval.n = realNode(REAL,yystack.l_mark[0].r); yyval.n->info = 3;}
break;
case 28:
#line 122 "diy.y"
	{yyval.n = realNode(REAL,-yystack.l_mark[0].r); yyval.n->info = 3;}
break;
case 29:
#line 123 "diy.y"
	{yyval.n = strNode(ID, yystack.l_mark[0].s); yyval.n->info = IDfind(yystack.l_mark[0].s,0);}
break;
case 30:
#line 127 "diy.y"
	{yyval.n = binNode(PARAMS, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[0].n->info;}
break;
case 31:
#line 128 "diy.y"
	{yyval.n = uniNode(PARAMS,yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 32:
#line 131 "diy.y"
	{yyval.n = strNode(ID,yystack.l_mark[0].s); IDnew(yystack.l_mark[-2].n->info+yystack.l_mark[-1].n->info,yystack.l_mark[0].s,0);
				yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[-1].n->info;}
break;
case 33:
#line 136 "diy.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 34:
#line 137 "diy.y"
	{yyval.n = binNode(ARGS, yystack.l_mark[-2].n, yystack.l_mark[-1].n); yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[-1].n->info; }
break;
case 35:
#line 141 "diy.y"
	{yyval.n = nilNode(NIL);IDpop();}
break;
case 36:
#line 142 "diy.y"
	{yyval.n = uniNode(PARAMS,yystack.l_mark[-1].n); IDpop();}
break;
case 37:
#line 143 "diy.y"
	{IDpop();}
break;
case 38:
#line 143 "diy.y"
	{yyval.n = uniNode(INSTRS,yystack.l_mark[-2].n); IDpop();}
break;
case 39:
#line 144 "diy.y"
	{yyval.n = binNode(ARGINST, yystack.l_mark[-2].n,yystack.l_mark[-1].n);IDpop();}
break;
case 40:
#line 149 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 41:
#line 150 "diy.y"
	{yyval.n = binNode(INSTRS,yystack.l_mark[-1].n,yystack.l_mark[0].n);}
break;
case 42:
#line 156 "diy.y"
	{yyval.n = binNode(THEN,binNode(IF,yystack.l_mark[-2].n,nilNode(NIL)),yystack.l_mark[0].n);}
break;
case 43:
#line 158 "diy.y"
	{yyval.n = binNode(ELSE,binNode(THEN,binNode(IF,yystack.l_mark[-4].n,nilNode(NIL)),yystack.l_mark[-2].n),yystack.l_mark[0].n);}
break;
case 44:
#line 161 "diy.y"
	{ciclo++;}
break;
case 45:
#line 161 "diy.y"
	{ciclo--;}
break;
case 46:
#line 161 "diy.y"
	{yyval.n = binNode(DO, binNode(WHILE,yystack.l_mark[-2].n,nilNode(PROG)),yystack.l_mark[-4].n);}
break;
case 47:
#line 163 "diy.y"
	{ciclo++;}
break;
case 48:
#line 163 "diy.y"
	{ciclo--;}
break;
case 49:
#line 165 "diy.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 50:
#line 166 "diy.y"
	{yyval.n = yystack.l_mark[0].n; IDpush();}
break;
case 51:
#line 167 "diy.y"
	{if(ciclo==0){yyerror("Error; Break outside of a loop");} yyval.n = uniNode(BREAK,intNode(INT,yystack.l_mark[-1].i));}
break;
case 52:
#line 168 "diy.y"
	{if(ciclo==0){yyerror("Error; Continue outside of a loop");} yyval.n = uniNode(CONTINUE, intNode(INT,yystack.l_mark[-1].i));}
break;
case 53:
#line 169 "diy.y"
	{if(ciclo==0){yyerror("Error; Break outside of a loop");}  yyval.n = uniNode(BREAK,intNode(INT,1));}
break;
case 54:
#line 170 "diy.y"
	{if(ciclo==0){yyerror("Error; Continue outside of a loop");}  yyval.n = uniNode(CONTINUE,intNode(INT,1));}
break;
case 55:
#line 171 "diy.y"
	{yyval.n = binNode(ALLOC,yystack.l_mark[-3].n,yystack.l_mark[-1].n); yyval.n->info = yystack.l_mark[-3].n->info;}
break;
case 56:
#line 172 "diy.y"
	{yyerrok;}
break;
case 57:
#line 175 "diy.y"
	{yyval.n = uniNode(UPTO,0);}
break;
case 58:
#line 176 "diy.y"
	{yyval.n = uniNode(DOWNTO,0);}
break;
case 59:
#line 179 "diy.y"
	{yyval.n = nilNode(NIL);}
break;
case 60:
#line 180 "diy.y"
	{yyval.n =uniNode(STEP,yystack.l_mark[0].n);}
break;
case 61:
#line 183 "diy.y"
	{yyval.n = binNode(EXPRS, yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 62:
#line 184 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 63:
#line 188 "diy.y"
	{yyval.n = intNode(INT,yystack.l_mark[0].i); yyval.n->info = 1;}
break;
case 64:
#line 189 "diy.y"
	{yyval.n = realNode(REAL,yystack.l_mark[0].r); yyval.n->info = 3;}
break;
case 65:
#line 190 "diy.y"
	{yyval.n = strNode(STR,yystack.l_mark[0].s); yyval.n->info = 2;}
break;
case 66:
#line 191 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 67:
#line 192 "diy.y"
	{yyval.n = binNode(FUNC, strNode(ID,yystack.l_mark[-3].s),yystack.l_mark[-1].n); IDfind(yystack.l_mark[-3].s,0);}
break;
case 68:
#line 193 "diy.y"
	{yyval.n = strNode(ID, yystack.l_mark[-2].s); IDfind(yystack.l_mark[-2].s,0);}
break;
case 69:
#line 194 "diy.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 70:
#line 195 "diy.y"
	{yyval.n = binNode(ASSIGN, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; if(yystack.l_mark[-2].n->info != yystack.l_mark[0].n->info) {
      				yyerror("Type error: cant assign different types");
      				 }
      				}
break;
case 71:
#line 199 "diy.y"
	{if(yystack.l_mark[0].n->info!=1){yyerror("Trying to decrement an invalid identifier");}
      				 yyval.n = binNode(DEC, nilNode(NIL), yystack.l_mark[0].n); yyval.n->info = 1;}
break;
case 72:
#line 201 "diy.y"
	{if(yystack.l_mark[0].n->info!=1){yyerror("Trying to increment an invalid identifier");}
                                 yyval.n = binNode(INC, nilNode(NIL), yystack.l_mark[0].n); yyval.n->info = 1;}
break;
case 73:
#line 203 "diy.y"
	{if(yystack.l_mark[-1].n->info!=1){yyerror("Trying to increment an invalid identifier");}
                                 yyval.n = binNode(INC, nilNode(NIL), yystack.l_mark[-1].n); yyval.n->info = 1;}
break;
case 74:
#line 205 "diy.y"
	{if(yystack.l_mark[-1].n->info!=1){yyerror("Trying to decrement an invalid identifier");}
                           	yyval.n = binNode(DEC, nilNode(NIL), yystack.l_mark[-1].n); yyval.n->info = 1;}
break;
case 75:
#line 207 "diy.y"
	{yyval.n = binNode(MUL, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 76:
#line 208 "diy.y"
	{yyval.n = binNode(DIV, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 77:
#line 209 "diy.y"
	{yyval.n = binNode(MOD, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 78:
#line 210 "diy.y"
	{yyval.n = binNode(SUM, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkOp(yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 79:
#line 211 "diy.y"
	{yyval.n = binNode(SUBT , yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 80:
#line 212 "diy.y"
	{yyval.n = binNode(EQ, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkCompOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 81:
#line 213 "diy.y"
	{yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkCompOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 82:
#line 214 "diy.y"
	{yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkCompOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 83:
#line 215 "diy.y"
	{yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkCompOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 84:
#line 216 "diy.y"
	{yyval.n = binNode(GT, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkCompOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 85:
#line 217 "diy.y"
	{yyval.n = binNode(LT, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkCompOp(yystack.l_mark[-2].n,yystack.l_mark[0].n); }
break;
case 86:
#line 218 "diy.y"
	{yyval.n = binNode(AND, yystack.l_mark[-2].n, yystack.l_mark[0].n); checkLogicOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 87:
#line 219 "diy.y"
	{yyval.n = binNode(OR, yystack.l_mark[-2].n, yystack.l_mark[0].n); checkLogicOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 88:
#line 220 "diy.y"
	{yyval.n = uniNode(FAC, yystack.l_mark[-1].n); if(yystack.l_mark[-1].n->info != 1){yyerror("Factorial error: Not an integer");}}
break;
case 89:
#line 221 "diy.y"
	{if(yystack.l_mark[0].n->info == 0 || yystack.l_mark[0].n->info==2){yyerror("Invalid type for symmetrical assigment");}
				yyval.n=uniNode(PMINUS, yystack.l_mark[0].n); yyval.n->info=yystack.l_mark[0].n->info;}
break;
case 90:
#line 223 "diy.y"
	{yyval.n = uniNode(NEG,yystack.l_mark[0].n); if(yystack.l_mark[0].n->info!=1){yyerror("Error: not an integer");}}
break;
case 91:
#line 226 "diy.y"
	{yyval.n = strNode(ID,yystack.l_mark[0].s); yyval.n->info = IDfind(yystack.l_mark[0].s,0);}
break;
case 92:
#line 228 "diy.y"
	{yyval.n = binNode(ARR,strNode(ID, yystack.l_mark[-3].s), yystack.l_mark[-1].n); IDfind(yystack.l_mark[-3].s,0); if(yystack.l_mark[-1].n->info!=1){yyerror("Index needs to be an integer");}}
break;
#line 1321 "y.tab.c"
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
