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
#define IINTEGER 1
#define ISTRING 2
#define INUMBER 3
#define IVOID -2

extern int yylex();
int yyerror(char *s);
extern void program(int enter, Node *body), declare(char *name, Node * value);
extern void function(char *name, int enter, Node *body);
int pos; /* local variable offset (no functions inside a function) */
int lbl; /* label counter for generated labels */
int cclbl; /* label counter for generated cicle labels */
char *mklbl(int n); /* generate counter based label */
int ciclo=0;


#line 27 "diy.y"
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
#line 59 "y.tab.c"

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
#define PROG 286
#define DECLS 287
#define DECL 288
#define INI 289
#define NIL 290
#define EXPRS 291
#define ALLOC 292
#define ARGINST 293
#define PARAMS 294
#define PARAM 295
#define INSTRS 296
#define ARGS 297
#define POINTER 298
#define SUM 299
#define SUBT 300
#define MUL 301
#define DIV 302
#define MOD 303
#define GT 304
#define LT 305
#define AND 306
#define OR 307
#define FAC 308
#define ARR 309
#define FUNC 310
#define NEG 311
#define PNTR 312
#define LOC 313
#define PUB 314
#define IFX 315
#define INC 316
#define DEC 317
#define PMINUS 318
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   10,   10,   11,   11,   20,   11,   21,   11,
   11,   11,    6,    6,   13,   13,   14,   14,   15,   15,
   12,   12,   12,   12,    2,    2,    2,    2,    2,    2,
   17,   17,   16,    9,    9,    5,    5,    5,    5,    8,
    8,    7,    7,   22,   23,    7,   24,   25,    7,    7,
    7,    7,    7,    7,    7,    7,    7,   18,   18,   19,
   19,    4,    4,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    1,    1,
};
static const YYINT yylen[] = {                            2,
    1,    0,    1,    2,    6,    7,    0,   11,    0,   10,
    8,    2,    0,    1,    0,    1,    0,    1,    0,    1,
    1,    1,    1,    1,    2,    3,    3,    2,    3,    2,
    3,    1,    3,    2,    3,    2,    3,    3,    4,    1,
    2,    4,    6,    0,    0,    7,    0,    0,   11,    2,
    1,    3,    3,    2,    2,    4,    2,    1,    1,    0,
    2,    3,    1,    1,    1,    1,    1,    4,    3,    3,
    3,    2,    2,    2,    2,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    2,    2,
    2,    2,    2,    1,    4,
};
static const YYINT yydefred[] = {                         0,
    0,   20,    0,    0,    3,    0,   12,    4,   18,    0,
   21,   22,   23,   24,    0,   16,    0,    0,    0,    0,
    5,    0,   25,   28,   30,    0,    0,    0,    0,    6,
   26,   29,   27,   11,    0,    0,   32,    0,    0,    0,
    0,    0,    0,    0,   64,   65,    0,   66,   44,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   36,    0,    0,   51,   40,    0,    0,    0,   10,   33,
   14,    0,   31,   57,    0,    0,    0,    0,    0,    0,
    0,    0,   54,    0,   55,   73,   72,    0,   90,    0,
    0,    0,   74,   75,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   89,
   50,   38,   41,   37,    0,    0,   34,    8,   69,    0,
    0,    0,    0,    0,    0,   52,   53,   70,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   39,   35,   68,    0,   95,   45,    0,
    0,   56,    0,    0,    0,   58,   59,    0,    0,   43,
    0,   46,    0,    0,    0,   47,    0,   48,   49,
};
static const YYINT yydgoto[] = {                          3,
   78,   22,   63,  121,   64,   72,   65,   66,   67,    4,
    5,   36,   17,   10,    6,   37,   38,  158,  164,   29,
   35,   77,  154,  167,  169,
};
static const YYINT yysindex[] = {                      -239,
  -36,    0,    0, -239,    0, -255,    0,    0,    0, -222,
    0,    0,    0,    0,   -6,    0, -183,  -37,  -38,   24,
    0,  -18,    0,    0,    0, -199, -177,   35, -222,    0,
    0,    0,    0,    0,  -39,   -6,    0,  -11,  910,   37,
 -160,  -39, -222,   42,    0,    0,  -21,    0,    0,   79,
 -159,  -44,  -43, -159, -159,   79,   79,   79,   79,   79,
    0,  -22,   71,    0,    0, 1029,  940,   47,    0,    0,
    0,   51,    0,    0,  468,   79, 1201, -192,   99,   20,
 -154,   56,    0,   66,    0,    0,    0,  287,    0,   94,
   94,  115,    0,    0,   79,   79,   79,   79,   79,   79,
   79,   79,   79,   79,   79,   79,   79,   79,   79,    0,
    0,    0,    0,    0, 1134,   69,    0,    0,    0,  394,
  -10,  131, -133, 1201,   79,    0,    0,    0,  394,  263,
  429,  650,  650,  429,  422,  287,  650,  650,   -5,   -5,
   94,   94,   94,    0,    0,    0,   79,    0,    0, -151,
   60,    0,  394,   79, 1201,    0,    0,   79,  329,    0,
  165,    0,   79, -126,  394,    0, 1201,    0,    0,
};
static const YYINT yyrindex[] = {                         1,
    0,    0,    0,    6,    0, -218,    0,    0,    0,    0,
    0,    0,    0,    0, -121,    0,    0,    0, -120, -194,
    0,    0,    0,    0,    0,    0,    0,   16,    0,    0,
    0,    0,    0,    0,    0, -121,    0,    0,    0,    0,
    0,   84,    0,    0,    0,    0,  -33,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  383,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   30,    0,    2,
    0,    0,    0,    0,    0,    0,    0, 1014,    0,  455,
  490,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   25,
    0,    0,    0,    0,    0,    0,    0,    0, 1037,    0,
  748,  597,  844,  818, 1220, 1209,  853,  879,  481,  778,
  516,  544,  586,    0,    0,    0,    0,    0,    0,  966,
    0,    0,   41,    0,    0,    0,    0,    0,    0,    0,
 -116,    0,    0,    0, -114,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  663,    0, 1260,    0,  -17,    0,  576,   82,    0,    0,
  146,  141,  119,  144,    0,  -19,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1489
static const YYINT yytable[] = {                         94,
    2,   94,   20,   94,   94,    1,   26,   94,   94,   94,
   94,   94,   96,   94,   83,   85,    1,   40,   75,   68,
    9,   21,    7,   73,   71,   94,   94,  110,   94,   42,
  146,  109,   43,  147,   94,   16,  107,    2,   94,   94,
   30,  108,   94,   94,   94,   94,   94,  116,   94,   11,
   12,   13,   14,   17,   17,   17,   17,   31,   32,   94,
   94,   94,   67,   94,   28,   63,   67,   67,   63,   76,
   67,   67,   67,   67,   67,   18,   67,    7,    7,    7,
    7,   62,   33,   39,   62,   93,   94,   95,   67,   67,
   94,   67,  110,   34,   94,   69,  109,  102,   70,   80,
   74,  107,  105,  110,  106,  117,  108,  109,  102,  118,
   76,  125,  107,  105,  126,  106,   56,  108,   60,  104,
   58,  103,   67,   57,  127,   94,  110,  145,  149,  111,
  104,  110,  103,  155,  166,  109,  102,   15,    9,   17,
  107,  105,   13,  106,   60,  108,   61,  110,  115,    8,
   15,  109,  102,   67,   41,  128,  107,  105,  104,  106,
  103,  108,   27,  110,    0,    0,    0,  109,  102,    0,
    0,    0,  107,  105,  104,  106,  103,  108,    0,    0,
    0,    0,    0,  101,    0,    0,    0,    0,    0,    0,
  104,    0,  103,    0,  101,    0,    0,  110,    0,    0,
    0,  109,  102,    0,   59,    0,  107,  105,    0,  106,
    0,  108,   82,   84,    0,    0,    0,    0,   23,   24,
   25,    0,  101,  148,  104,    0,  103,   94,    0,    0,
   94,    0,    0,   94,   94,   94,    0,    9,  101,    0,
    0,    0,   19,    0,   94,   94,   94,   94,   94,   94,
   94,    0,    0,    0,  101,   93,   94,   95,    0,    0,
    0,    0,   94,    0,    0,   94,    0,   94,   94,   94,
   94,    0,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   94,   94,   94,   94,    0,    0,  101,    0,
   67,    0,    0,   67,    0,  110,   67,   67,   67,  109,
  102,    0,    0,    0,  107,  105,    0,  106,    0,  108,
   67,   67,   67,   67,    0,    0,    0,    0,    0,  110,
    0,  152,  104,  109,  103,    0,  156,  157,  107,  105,
    0,  106,    0,  108,    0,   45,   46,   47,   48,    0,
   97,   98,   99,  100,    0,    0,  104,    0,  103,    0,
    0,   97,   98,   99,  100,    0,   54,   55,    0,    0,
    0,  110,  124,    0,    0,  109,  102,    0,    0,    0,
  107,  105,    0,  106,    0,  108,    0,    0,    0,   97,
   98,   99,  100,    0,    0,    0,  101,  162,  104,    0,
  103,    0,    0,    0,    0,   97,   98,   99,  100,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   97,   98,   99,  100,   67,    0,    0,    0,   67,
   67,    0,    0,    0,   67,   67,  110,   67,    0,   67,
  109,  102,    0,  163,    0,  107,  105,    0,  106,    0,
  108,   67,   67,    0,   67,   97,   98,   99,  100,    0,
    0,    0,  101,  104,  110,  103,    0,    0,  109,  102,
    0,  110,    0,  107,  105,  109,  106,    0,  108,    0,
  107,  105,    0,  106,    0,  108,    0,    0,    0,    0,
    0,  104,    0,  103,    0,    0,    0,    0,  104,    0,
  103,   92,   92,    0,    0,   92,   92,   92,   92,   92,
    0,   92,    0,    0,    0,   56,   67,   60,  119,   58,
    0,    0,   57,   92,   92,    0,   92,  101,   79,    0,
    0,   79,    0,   79,   79,   79,   91,   91,    0,    0,
   91,   91,   91,   91,   91,    0,   91,    0,    0,   79,
   79,    0,   79,   97,   98,   99,  100,   92,   91,   91,
    0,   91,   76,   76,    0,    0,   76,   76,   76,   76,
   76,    0,   76,    0,    0,    0,    0,   97,   98,   99,
  100,    0,    0,   79,   76,   76,    0,   76,   92,    0,
   77,   77,   91,    0,   77,   77,   77,   77,   77,    0,
   77,    0,    0,   59,    0,    0,    0,    0,    0,    0,
    0,    0,   77,   77,   79,   77,    0,    0,   76,   97,
   98,   99,  100,   91,    0,    0,    0,    0,    0,    0,
    0,    0,   78,   78,    0,    0,   78,   78,   78,   78,
   78,    0,   78,    0,   83,    0,   77,   83,    0,   76,
   83,  113,    0,    0,   78,   78,    0,   78,    0,    0,
    0,    0,  123,    0,    0,   83,   83,    0,   83,    0,
    0,    0,    0,   67,   67,   67,   67,   77,    0,    0,
    0,    0,    0,    0,   97,   98,   99,  100,   78,    0,
    0,    0,  110,    0,    0,    0,  109,    0,    0,   83,
  113,  107,  105,    0,  106,    0,  108,    0,    0,  150,
    0,   62,   97,   98,   99,  100,    0,    0,    0,   78,
   98,   99,    0,   81,    0,   92,   86,   87,   92,    0,
   83,   92,   92,   92,   45,   46,   47,   48,   62,   62,
  160,    0,    0,    0,    0,   92,   92,   92,   92,   62,
    0,   79,  168,    0,   79,   54,   55,   79,   79,   79,
   91,    0,    0,   91,    0,    0,   91,   91,   91,    0,
    0,   79,   79,   79,   79,    0,    0,    0,    0,    0,
   91,   91,   91,   91,    0,    0,   76,   62,    0,   76,
    0,    0,   76,   76,   76,   82,   62,    0,   82,    0,
    0,   82,    0,    0,    0,    0,   76,   76,   76,   76,
    0,    0,    0,    0,   77,    0,   82,   77,    0,    0,
   77,   77,   77,    0,    0,   80,    0,   62,   80,    0,
   80,   80,   80,    0,   77,   77,   77,   77,    0,   62,
    0,    0,    0,    0,    0,    0,   80,   80,    0,   80,
   82,    0,    0,    0,    0,    0,   78,    0,    0,   78,
    0,    0,   78,   78,   78,   81,    0,   83,   81,    0,
   83,   81,    0,   83,   83,   83,   78,   78,   78,   78,
   80,   82,    0,    0,    0,    0,   81,   83,   83,   83,
   83,   84,    0,    0,   84,    0,    0,   84,    0,    0,
   85,    0,    0,   85,    0,    0,   85,    0,    0,    0,
    0,   80,   84,   84,    0,   84,    0,    0,    0,    0,
   81,   85,   85,    0,   85,    0,   86,    0,    0,   86,
    0,    0,   86,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   84,   86,   86,    0,
   86,   81,    0,    0,    0,   85,    0,   56,    0,   60,
    0,   58,    0,    0,   57,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   84,    0,    0,
    0,   86,    0,    0,    0,    0,   85,   56,    0,   60,
    0,   58,    0,    0,   57,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   86,   42,    0,   42,    0,   42,   82,    0,
   42,   82,    0,    0,   82,   82,   82,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   82,    0,
    0,   82,   39,    0,   61,   59,    0,    0,   80,    0,
    0,   80,    0,    0,   80,   80,   80,    0,    0,    0,
    0,   93,    0,    0,   93,    0,    0,   93,   80,   80,
   80,   80,   39,    0,  114,   59,   56,    0,   60,    0,
   58,    0,   93,   57,    0,    0,    0,   71,   81,    0,
   71,   81,    0,    0,   81,   81,   81,    0,   42,    0,
   42,   42,    0,    0,    0,   71,    0,    0,   81,    0,
    0,   81,    0,    0,   84,    0,   93,   84,    0,    0,
   84,   84,   84,   85,    0,    0,   85,    0,    0,   85,
   85,   85,    0,    0,   84,   84,   84,   84,    0,   71,
    0,    0,    0,   85,   85,   85,   85,   93,    0,   86,
    0,    0,   86,    0,    0,   86,   86,   86,    0,    0,
    0,   39,    0,  112,   59,    0,    0,    0,    0,   86,
   86,   86,   86,    0,    0,   44,   45,   46,   47,   48,
   49,   56,   50,   60,   51,   58,    0,    0,   57,   52,
   53,   11,   12,   13,   14,    0,    0,   54,   55,    0,
    0,    0,    0,    0,    0,   44,   45,   46,   47,   48,
   49,    0,   50,    0,   51,    0,    0,    0,    0,   52,
   53,   11,   12,   13,   14,    0,    0,   54,   55,    0,
    0,   42,   42,   42,   42,   42,   42,   42,   42,    0,
   42,    0,    0,    0,    0,   42,   42,    0,   56,    0,
   60,    0,   58,   42,   42,   57,   87,    0,    0,   87,
    0,    0,   87,    0,    0,    0,   39,    0,  144,   59,
   88,    0,    0,   88,    0,    0,    0,   87,    0,    0,
    0,    0,    0,    0,   93,    0,    0,   93,   88,    0,
   93,   93,   93,    0,   44,   45,   46,   47,   48,   49,
    0,   50,    0,   51,    0,    0,    0,   71,   52,   53,
   71,   87,    0,   71,   71,   71,   54,   55,    0,   79,
    0,    0,   88,    0,    0,   88,   89,   90,   91,   92,
    0,    0,    0,   39,    0,    0,   59,    0,    0,    0,
    0,    0,   87,    0,  120,  122,    0,    0,    0,    0,
    0,    0,    0,   88,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  129,  130,  131,  132,  133,  134,
  135,  136,  137,  138,  139,  140,  141,  142,  143,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  151,    0,    0,    0,    0,   44,
   45,   46,   47,   48,   49,    0,   50,    0,   51,    0,
    0,    0,    0,   52,   53,    0,  153,    0,    0,    0,
    0,   54,   55,  159,    0,    0,    0,  161,    0,    0,
    0,    0,  165,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   44,   45,   46,   47,
   48,   49,    0,   50,    0,   51,    0,    0,    0,   87,
   52,   53,   87,    0,    0,   87,   87,   87,   54,   55,
   88,    0,    0,   88,    0,    0,   88,   88,   88,
};
static const YYINT yycheck[] = {                         33,
    0,   35,   40,   37,   38,    0,   45,   41,   42,   43,
   44,   45,   35,   47,   59,   59,  256,   35,   40,   39,
  276,   59,   59,   43,   42,   59,   60,   33,   62,   41,
   41,   37,   44,   44,   33,   42,   42,  277,   37,   38,
   59,   47,   41,   42,   43,   44,   45,   67,   47,  272,
  273,  274,  275,  272,  273,  274,  275,  257,  258,   93,
   59,   60,   33,   62,   41,   41,   37,   38,   44,   91,
   41,   42,   43,   44,   45,  259,   47,  272,  273,  274,
  275,   41,  260,  123,   44,  278,  279,  280,   59,   60,
  124,   62,   33,   59,   93,   59,   37,   38,  259,  259,
   59,   42,   43,   33,   45,   59,   47,   37,   38,   59,
   91,  266,   42,   43,   59,   45,   38,   47,   40,   60,
   42,   62,   93,   45,   59,  124,   33,   59,  262,   59,
   60,   33,   62,  285,  261,   37,   38,  259,  123,  260,
   42,   43,   59,   45,  261,   47,  261,   33,   67,    4,
   10,   37,   38,  124,   36,   41,   42,   43,   60,   45,
   62,   47,   19,   33,   -1,   -1,   -1,   37,   38,   -1,
   -1,   -1,   42,   43,   60,   45,   62,   47,   -1,   -1,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
   60,   -1,   62,   -1,  124,   -1,   -1,   33,   -1,   -1,
   -1,   37,   38,   -1,  126,   -1,   42,   43,   -1,   45,
   -1,   47,  257,  257,   -1,   -1,   -1,   -1,  257,  258,
  259,   -1,  124,   93,   60,   -1,   62,  261,   -1,   -1,
  264,   -1,   -1,  267,  268,  269,   -1,  276,  124,   -1,
   -1,   -1,  280,   -1,  278,  279,  280,  281,  282,  283,
  284,   -1,   -1,   -1,  124,  278,  279,  280,   -1,   -1,
   -1,   -1,  261,   -1,   -1,  264,   -1,  266,  267,  268,
  269,   -1,  272,  273,  274,  275,  276,  272,  273,  274,
  275,  276,  281,  282,  283,  284,   -1,   -1,  124,   -1,
  261,   -1,   -1,  264,   -1,   33,  267,  268,  269,   37,
   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
  281,  282,  283,  284,   -1,   -1,   -1,   -1,   -1,   33,
   -1,   59,   60,   37,   62,   -1,  267,  268,   42,   43,
   -1,   45,   -1,   47,   -1,  257,  258,  259,  260,   -1,
  281,  282,  283,  284,   -1,   -1,   60,   -1,   62,   -1,
   -1,  281,  282,  283,  284,   -1,  278,  279,   -1,   -1,
   -1,   33,  264,   -1,   -1,   37,   38,   -1,   -1,   -1,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,  281,
  282,  283,  284,   -1,   -1,   -1,  124,   59,   60,   -1,
   62,   -1,   -1,   -1,   -1,  281,  282,  283,  284,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  281,  282,  283,  284,   33,   -1,   -1,   -1,   37,
   38,   -1,   -1,   -1,   42,   43,   33,   45,   -1,   47,
   37,   38,   -1,  269,   -1,   42,   43,   -1,   45,   -1,
   47,   59,   60,   -1,   62,  281,  282,  283,  284,   -1,
   -1,   -1,  124,   60,   33,   62,   -1,   -1,   37,   38,
   -1,   33,   -1,   42,   43,   37,   45,   -1,   47,   -1,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,   60,   -1,   62,   -1,   -1,   -1,   -1,   60,   -1,
   62,   37,   38,   -1,   -1,   41,   42,   43,   44,   45,
   -1,   47,   -1,   -1,   -1,   38,  124,   40,   41,   42,
   -1,   -1,   45,   59,   60,   -1,   62,  124,   38,   -1,
   -1,   41,   -1,   43,   44,   45,   37,   38,   -1,   -1,
   41,   42,   43,   44,   45,   -1,   47,   -1,   -1,   59,
   60,   -1,   62,  281,  282,  283,  284,   93,   59,   60,
   -1,   62,   37,   38,   -1,   -1,   41,   42,   43,   44,
   45,   -1,   47,   -1,   -1,   -1,   -1,  281,  282,  283,
  284,   -1,   -1,   93,   59,   60,   -1,   62,  124,   -1,
   37,   38,   93,   -1,   41,   42,   43,   44,   45,   -1,
   47,   -1,   -1,  126,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   59,   60,  124,   62,   -1,   -1,   93,  281,
  282,  283,  284,  124,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   37,   38,   -1,   -1,   41,   42,   43,   44,
   45,   -1,   47,   -1,   38,   -1,   93,   41,   -1,  124,
   44,   66,   -1,   -1,   59,   60,   -1,   62,   -1,   -1,
   -1,   -1,   77,   -1,   -1,   59,   60,   -1,   62,   -1,
   -1,   -1,   -1,  281,  282,  283,  284,  124,   -1,   -1,
   -1,   -1,   -1,   -1,  281,  282,  283,  284,   93,   -1,
   -1,   -1,   33,   -1,   -1,   -1,   37,   -1,   -1,   93,
  115,   42,   43,   -1,   45,   -1,   47,   -1,   -1,  124,
   -1,   39,  281,  282,  283,  284,   -1,   -1,   -1,  124,
  282,  283,   -1,   51,   -1,  261,   54,   55,  264,   -1,
  124,  267,  268,  269,  257,  258,  259,  260,   66,   67,
  155,   -1,   -1,   -1,   -1,  281,  282,  283,  284,   77,
   -1,  261,  167,   -1,  264,  278,  279,  267,  268,  269,
  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,
   -1,  281,  282,  283,  284,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,   -1,   -1,  261,  115,   -1,  264,
   -1,   -1,  267,  268,  269,   38,  124,   -1,   41,   -1,
   -1,   44,   -1,   -1,   -1,   -1,  281,  282,  283,  284,
   -1,   -1,   -1,   -1,  261,   -1,   59,  264,   -1,   -1,
  267,  268,  269,   -1,   -1,   38,   -1,  155,   41,   -1,
   43,   44,   45,   -1,  281,  282,  283,  284,   -1,  167,
   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,   62,
   93,   -1,   -1,   -1,   -1,   -1,  261,   -1,   -1,  264,
   -1,   -1,  267,  268,  269,   38,   -1,  261,   41,   -1,
  264,   44,   -1,  267,  268,  269,  281,  282,  283,  284,
   93,  124,   -1,   -1,   -1,   -1,   59,  281,  282,  283,
  284,   38,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,
   38,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,
   -1,  124,   59,   60,   -1,   62,   -1,   -1,   -1,   -1,
   93,   59,   60,   -1,   62,   -1,   38,   -1,   -1,   41,
   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   93,   59,   60,   -1,
   62,  124,   -1,   -1,   -1,   93,   -1,   38,   -1,   40,
   -1,   42,   -1,   -1,   45,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,
   -1,   93,   -1,   -1,   -1,   -1,  124,   38,   -1,   40,
   -1,   42,   -1,   -1,   45,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  124,   38,   -1,   40,   -1,   42,  261,   -1,
   45,  264,   -1,   -1,  267,  268,  269,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,   -1,
   -1,  284,  123,   -1,  125,  126,   -1,   -1,  261,   -1,
   -1,  264,   -1,   -1,  267,  268,  269,   -1,   -1,   -1,
   -1,   38,   -1,   -1,   41,   -1,   -1,   44,  281,  282,
  283,  284,  123,   -1,  125,  126,   38,   -1,   40,   -1,
   42,   -1,   59,   45,   -1,   -1,   -1,   41,  261,   -1,
   44,  264,   -1,   -1,  267,  268,  269,   -1,  123,   -1,
  125,  126,   -1,   -1,   -1,   59,   -1,   -1,  281,   -1,
   -1,  284,   -1,   -1,  261,   -1,   93,  264,   -1,   -1,
  267,  268,  269,  261,   -1,   -1,  264,   -1,   -1,  267,
  268,  269,   -1,   -1,  281,  282,  283,  284,   -1,   93,
   -1,   -1,   -1,  281,  282,  283,  284,  124,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,   -1,
   -1,  123,   -1,  125,  126,   -1,   -1,   -1,   -1,  281,
  282,  283,  284,   -1,   -1,  256,  257,  258,  259,  260,
  261,   38,  263,   40,  265,   42,   -1,   -1,   45,  270,
  271,  272,  273,  274,  275,   -1,   -1,  278,  279,   -1,
   -1,   -1,   -1,   -1,   -1,  256,  257,  258,  259,  260,
  261,   -1,  263,   -1,  265,   -1,   -1,   -1,   -1,  270,
  271,  272,  273,  274,  275,   -1,   -1,  278,  279,   -1,
   -1,  256,  257,  258,  259,  260,  261,  262,  263,   -1,
  265,   -1,   -1,   -1,   -1,  270,  271,   -1,   38,   -1,
   40,   -1,   42,  278,  279,   45,   38,   -1,   -1,   41,
   -1,   -1,   44,   -1,   -1,   -1,  123,   -1,  125,  126,
   41,   -1,   -1,   44,   -1,   -1,   -1,   59,   -1,   -1,
   -1,   -1,   -1,   -1,  261,   -1,   -1,  264,   59,   -1,
  267,  268,  269,   -1,  256,  257,  258,  259,  260,  261,
   -1,  263,   -1,  265,   -1,   -1,   -1,  261,  270,  271,
  264,   93,   -1,  267,  268,  269,  278,  279,   -1,   50,
   -1,   -1,   93,   -1,   -1,   56,   57,   58,   59,   60,
   -1,   -1,   -1,  123,   -1,   -1,  126,   -1,   -1,   -1,
   -1,   -1,  124,   -1,   75,   76,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   95,   96,   97,   98,   99,  100,
  101,  102,  103,  104,  105,  106,  107,  108,  109,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,  256,
  257,  258,  259,  260,  261,   -1,  263,   -1,  265,   -1,
   -1,   -1,   -1,  270,  271,   -1,  147,   -1,   -1,   -1,
   -1,  278,  279,  154,   -1,   -1,   -1,  158,   -1,   -1,
   -1,   -1,  163,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  256,  257,  258,  259,
  260,  261,   -1,  263,   -1,  265,   -1,   -1,   -1,  261,
  270,  271,  264,   -1,   -1,  267,  268,  269,  278,  279,
  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 318
#define YYUNDFTOKEN 346
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
"LE","EQ","ELSE","PROG","DECLS","DECL","INI","NIL","EXPRS","ALLOC","ARGINST",
"PARAMS","PARAM","INSTRS","ARGS","POINTER","SUM","SUBT","MUL","DIV","MOD","GT",
"LT","AND","OR","FAC","ARR","FUNC","NEG","PNTR","LOC","PUB","IFX","INC","DEC",
"PMINUS",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : seq",
"file :",
"seq : declaracao",
"seq : seq declaracao",
"declaracao : pub const type ptr ID ';'",
"declaracao : pub const type ptr ID ini ';'",
"$$1 :",
"declaracao : pub const type ptr ID '(' $$1 params ')' bodys ';'",
"$$2 :",
"declaracao : pub const type ptr ID '(' ')' $$2 body ';'",
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
"$$3 :",
"$$4 :",
"instr : DO $$3 instr WHILE $$4 expr ';'",
"$$5 :",
"$$6 :",
"instr : FOR leftvalue IN expr updw expr step DO $$5 instr $$6",
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
"expr : DECR leftvalue",
"expr : INCR leftvalue",
"expr : leftvalue INCR",
"expr : leftvalue DECR",
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
"expr : '*' expr",
"expr : '&' expr",
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

	if(op1->info == IVOID || op2->info == IVOID){
	  yyerror("Invalid argument type for operation: can't compare void");
	}

	printf("%d\n%d\n",op1->info,op2->info);

	if(op1->info == ISTRING && op2->info !=ISTRING){
	  yyerror("Invalid argument type for operation: can't compare string to non-string");
	}

    return 1;
}

void checkLogicOp(Node *op1, Node *op2){
	if(op1->info != IINTEGER || op2->info != IINTEGER){
	   yyerror("Invalid argument type for logic operation");
	}
}

void checkAtrib(Node *op1, Node *op2){
	if(op1->info == 1){
	   if(op2->info != 1 && op2->info != 3){
	   	yyerror("Invalid assignment");
	   }
	   else{
	   	return;
	   }
	}
	if(op1->info == 3){
	   if(op2->info != 1 && op2->info != 3){
	   	yyerror("Invalid assignment");
	   }
	   else{
	     return;
	   }
	}
	yyerror("Invalid type assignment");
}


char **names =
 #if YYDEBUG > 0
 (char**)yyname;
 #else
 0;
 #endif
#line 774 "y.tab.c"

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
#line 62 "diy.y"
	{yyval.n = uniNode(PROG, yystack.l_mark[0].n); printNode(yystack.l_mark[0].n,0,names);}
break;
case 3:
#line 66 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 4:
#line 67 "diy.y"
	{yyval.n = binNode(DECLS, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 5:
#line 71 "diy.y"
	{yyval.n=uniNode(DECL, strNode(ID,yystack.l_mark[-1].s));
						IDnew(yystack.l_mark[-3].n->info,yystack.l_mark[-1].s,0);}
break;
case 6:
#line 74 "diy.y"
	{yyval.n=binNode(DECL, strNode(ID, yystack.l_mark[-2].s), yystack.l_mark[-1].n);
						 IDnew(yystack.l_mark[-4].n->info,yystack.l_mark[-2].s,0);
            					  yyval.n->info =yystack.l_mark[-4].n->info;
            					  if(yystack.l_mark[-4].n->info!= yystack.l_mark[-1].n->info) {
            					  	yyerror("Different type assignment");
            					  }
            					}
break;
case 7:
#line 82 "diy.y"
	{IDnew(yystack.l_mark[-3].n->info,yystack.l_mark[-1].s,0); IDpush();}
break;
case 8:
#line 82 "diy.y"
	{IDpop(); yyval.n = binNode(DECL, strNode(ID,yystack.l_mark[-6].s),binNode(ARGS,yystack.l_mark[-3].n,yystack.l_mark[-1].n));}
break;
case 9:
#line 85 "diy.y"
	{IDnew(yystack.l_mark[-4].n->info,yystack.l_mark[-2].s,0);
            				     IDpush();
            			     }
break;
case 10:
#line 87 "diy.y"
	{IDpop();yyval.n = binNode(DECL,strNode(ID,yystack.l_mark[-5].s),yystack.l_mark[-1].n);}
break;
case 11:
#line 89 "diy.y"
	{yyval.n=uniNode(DECL,strNode(ID,yystack.l_mark[-3].s));
            						IDnew(yystack.l_mark[-5].n->info,yystack.l_mark[-3].s,0);}
break;
case 12:
#line 91 "diy.y"
	{yyerrok; yyval.n = nilNode(NIL);}
break;
case 13:
#line 95 "diy.y"
	{yyval.n= nilNode(NIL);}
break;
case 14:
#line 96 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 15:
#line 99 "diy.y"
	{yyval.n = nilNode(NIL);}
break;
case 16:
#line 100 "diy.y"
	{yyval.n = uniNode(POINTER,0);}
break;
case 17:
#line 103 "diy.y"
	{yyval.n = nilNode(NIL);}
break;
case 18:
#line 104 "diy.y"
	{yyval.n = uniNode(CONST,0);}
break;
case 19:
#line 108 "diy.y"
	{yyval.n = nilNode(NIL);}
break;
case 20:
#line 109 "diy.y"
	{yyval.n = uniNode(PUB,0);}
break;
case 21:
#line 113 "diy.y"
	{yyval.n = uniNode(VOID,0); yyval.n->info = IVOID;}
break;
case 22:
#line 114 "diy.y"
	{yyval.n = uniNode(INTEGER,0); yyval.n->info = IINTEGER;}
break;
case 23:
#line 115 "diy.y"
	{yyval.n = uniNode(STRING,0); yyval.n->info = ISTRING;}
break;
case 24:
#line 116 "diy.y"
	{yyval.n = uniNode(NUMBER,0); yyval.n->info = INUMBER;}
break;
case 25:
#line 120 "diy.y"
	{yyval.n = intNode(INT,yystack.l_mark[0].i); yyval.n->info = IINTEGER;}
break;
case 26:
#line 121 "diy.y"
	{yyval.n = intNode(INT,-yystack.l_mark[0].i); yyval.n->info = IINTEGER;}
break;
case 27:
#line 122 "diy.y"
	{yyval.n = strNode(STR,yystack.l_mark[0].s); yyval.n->info =  ISTRING;}
break;
case 28:
#line 123 "diy.y"
	{yyval.n = realNode(REAL,yystack.l_mark[0].r); yyval.n->info = INUMBER;}
break;
case 29:
#line 124 "diy.y"
	{yyval.n = realNode(REAL,-yystack.l_mark[0].r); yyval.n->info = INUMBER;}
break;
case 30:
#line 125 "diy.y"
	{yyval.n = strNode(ID, yystack.l_mark[0].s); yyval.n->info = IDfind(yystack.l_mark[0].s,0);}
break;
case 31:
#line 129 "diy.y"
	{yyval.n = binNode(PARAMS, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[0].n->info;}
break;
case 32:
#line 130 "diy.y"
	{yyval.n = uniNode(PARAMS,yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 33:
#line 133 "diy.y"
	{yyval.n = strNode(ID,yystack.l_mark[0].s); IDnew(yystack.l_mark[-2].n->info,yystack.l_mark[0].s,0);
				yyval.n->info = yystack.l_mark[-2].n->info;}
break;
case 34:
#line 138 "diy.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 35:
#line 139 "diy.y"
	{yyval.n = binNode(ARGS, yystack.l_mark[-2].n, yystack.l_mark[-1].n); yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[-1].n->info; }
break;
case 36:
#line 142 "diy.y"
	{yyval.n = nilNode(NIL);}
break;
case 37:
#line 143 "diy.y"
	{yyval.n = uniNode(PARAMS,yystack.l_mark[-1].n);}
break;
case 38:
#line 144 "diy.y"
	{yyval.n = uniNode(INSTRS,yystack.l_mark[-1].n);}
break;
case 39:
#line 145 "diy.y"
	{yyval.n = binNode(ARGINST, yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
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
#line 154 "diy.y"
	{yyval.n = binNode(THEN,binNode(IF,yystack.l_mark[-2].n,nilNode(NIL)),yystack.l_mark[0].n);}
break;
case 43:
#line 156 "diy.y"
	{yyval.n = binNode(ELSE,binNode(THEN,binNode(IF,yystack.l_mark[-4].n,nilNode(NIL)),yystack.l_mark[-2].n),yystack.l_mark[0].n);}
break;
case 44:
#line 159 "diy.y"
	{ciclo++;}
break;
case 45:
#line 159 "diy.y"
	{ciclo--;}
break;
case 46:
#line 159 "diy.y"
	{yyval.n = binNode(DO, binNode(WHILE,yystack.l_mark[-2].n,nilNode(PROG)),yystack.l_mark[-4].n);}
break;
case 47:
#line 161 "diy.y"
	{ciclo++;}
break;
case 48:
#line 161 "diy.y"
	{ciclo--;}
break;
case 49:
#line 161 "diy.y"
	{yyval.n = binNode(DO, binNode(FOR,binNode(IN,binNode(STEP,yystack.l_mark[-5].n,yystack.l_mark[-4].n),yystack.l_mark[-7].n),yystack.l_mark[-9].n),yystack.l_mark[-2].n);}
break;
case 50:
#line 163 "diy.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 51:
#line 164 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 52:
#line 165 "diy.y"
	{if(ciclo==0){yyerror("Error; Break outside of a loop");} yyval.n = uniNode(BREAK,intNode(INT,yystack.l_mark[-1].i));}
break;
case 53:
#line 166 "diy.y"
	{if(ciclo==0){yyerror("Error; Continue outside of a loop");} yyval.n = uniNode(CONTINUE, intNode(INT,yystack.l_mark[-1].i));}
break;
case 54:
#line 167 "diy.y"
	{if(ciclo==0){yyerror("Error; Break outside of a loop");}  yyval.n = uniNode(BREAK,intNode(INT,1));}
break;
case 55:
#line 168 "diy.y"
	{if(ciclo==0){yyerror("Error; Continue outside of a loop");}  yyval.n = uniNode(CONTINUE,intNode(INT,1));}
break;
case 56:
#line 169 "diy.y"
	{yyval.n = binNode(ALLOC,yystack.l_mark[-3].n,yystack.l_mark[-1].n); yyval.n->info = yystack.l_mark[-3].n->info;}
break;
case 57:
#line 170 "diy.y"
	{yyerrok;}
break;
case 58:
#line 173 "diy.y"
	{yyval.n = uniNode(UPTO,0);}
break;
case 59:
#line 174 "diy.y"
	{yyval.n = uniNode(DOWNTO,0);}
break;
case 60:
#line 177 "diy.y"
	{yyval.n = nilNode(NIL);}
break;
case 61:
#line 178 "diy.y"
	{yyval.n =uniNode(STEP,yystack.l_mark[0].n);}
break;
case 62:
#line 181 "diy.y"
	{yyval.n = binNode(EXPRS, yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 63:
#line 182 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 64:
#line 186 "diy.y"
	{yyval.n = intNode(INT,yystack.l_mark[0].i); yyval.n->info = IINTEGER;}
break;
case 65:
#line 187 "diy.y"
	{yyval.n = realNode(REAL,yystack.l_mark[0].r); yyval.n->info = INUMBER;}
break;
case 66:
#line 188 "diy.y"
	{yyval.n = strNode(STR,yystack.l_mark[0].s); yyval.n->info = ISTRING;}
break;
case 67:
#line 189 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 68:
#line 190 "diy.y"
	{yyval.n = binNode(FUNC, strNode(ID,yystack.l_mark[-3].s),yystack.l_mark[-1].n); yyval.n->info=IDfind(yystack.l_mark[-3].s,0);}
break;
case 69:
#line 191 "diy.y"
	{yyval.n = strNode(ID, yystack.l_mark[-2].s); yyval.n->info = IDfind(yystack.l_mark[-2].s,0);}
break;
case 70:
#line 192 "diy.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 71:
#line 193 "diy.y"
	{yyval.n = binNode(ASSIGN, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; checkAtrib(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 72:
#line 195 "diy.y"
	{ yyval.n = uniNode(DECR, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;
      				if(yystack.l_mark[0].n->info!=IINTEGER && yystack.l_mark[0].n->info!=INUMBER){yyerror("Trying to decrement an invalid identifier");}}
break;
case 73:
#line 197 "diy.y"
	{yyval.n = uniNode(INCR, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;
      				if(yystack.l_mark[0].n->info!=IINTEGER && yystack.l_mark[0].n->info!=INUMBER){yyerror("Trying to increment an invalid identifier");}}
break;
case 74:
#line 200 "diy.y"
	{ yyval.n = uniNode(INCR,yystack.l_mark[-1].n); yyval.n->info = yystack.l_mark[-1].n->info;
      				if(yystack.l_mark[-1].n->info!=IINTEGER && yystack.l_mark[-1].n->info !=INUMBER){yyerror("Trying to increment an invalid identifier");}}
break;
case 75:
#line 202 "diy.y"
	{yyval.n = uniNode(DECR,yystack.l_mark[-1].n);
      				if(yystack.l_mark[-1].n->info!=IINTEGER && yystack.l_mark[-1].n->info!=INUMBER){yyerror("Trying to decrement an invalid identifier");}
                           	yyval.n->info = yystack.l_mark[-1].n->info;}
break;
case 76:
#line 205 "diy.y"
	{yyval.n = binNode(MUL, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 77:
#line 206 "diy.y"
	{yyval.n = binNode(DIV, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 78:
#line 207 "diy.y"
	{yyval.n = binNode(MOD, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 79:
#line 208 "diy.y"
	{yyval.n = binNode(SUM, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkOp(yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 80:
#line 209 "diy.y"
	{yyval.n = binNode(SUBT , yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 81:
#line 210 "diy.y"
	{yyval.n = binNode(EQ, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkCompOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 82:
#line 211 "diy.y"
	{yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkCompOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 83:
#line 212 "diy.y"
	{yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkCompOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 84:
#line 213 "diy.y"
	{yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkCompOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 85:
#line 214 "diy.y"
	{yyval.n = binNode(GT, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkCompOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 86:
#line 215 "diy.y"
	{yyval.n = binNode(LT, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkCompOp(yystack.l_mark[-2].n,yystack.l_mark[0].n); }
break;
case 87:
#line 216 "diy.y"
	{yyval.n = binNode(AND, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 88:
#line 217 "diy.y"
	{yyval.n = binNode(OR, yystack.l_mark[-2].n, yystack.l_mark[0].n); checkLogicOp(yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 89:
#line 218 "diy.y"
	{yyval.n = uniNode(FAC, yystack.l_mark[-1].n); if(yystack.l_mark[-1].n->info != 1){yyerror("Factorial error: Not an integer");}}
break;
case 90:
#line 219 "diy.y"
	{if(yystack.l_mark[0].n->info == 0 || yystack.l_mark[0].n->info==2){yyerror("Invalid type for symmetrical assigment");}
				yyval.n=uniNode(PMINUS, yystack.l_mark[0].n); yyval.n->info=yystack.l_mark[0].n->info;}
break;
case 91:
#line 221 "diy.y"
	{yyval.n = uniNode(NEG,yystack.l_mark[0].n); if(yystack.l_mark[0].n->info!=1){yyerror("Error: not an integer");}}
break;
case 92:
#line 222 "diy.y"
	{yyval.n = uniNode(PNTR,yystack.l_mark[0].n);}
break;
case 93:
#line 223 "diy.y"
	{yyval.n = uniNode(LOC,yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 94:
#line 226 "diy.y"
	{yyval.n = strNode(ID,yystack.l_mark[0].s); yyval.n->info = IDfind(yystack.l_mark[0].s,0);}
break;
case 95:
#line 228 "diy.y"
	{yyval.n = binNode(ARR,strNode(ID, yystack.l_mark[-3].s), yystack.l_mark[-1].n);IDfind(yystack.l_mark[-3].s,0); yyval.n->info = IINTEGER; if(yystack.l_mark[-1].n->info!=IINTEGER){yyerror("Index needs to be an integer");}}
break;
#line 1369 "y.tab.c"
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
