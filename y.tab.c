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
/* $Id: diy.y,v 1.0 2019/02/06 17:25:13 prs Exp $ */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"

extern int yylex();	
void yyerror(char *s);
void declare(int pub, int cnst, Node *type, char *name, Node *value);
void enter(int pub, int typ, char *name);
int checkargs(char *name, Node *args);
int nostring(Node *arg1, Node *arg2);
int intonly(Node *arg, int);
int noassign(Node *arg1, Node *arg2);
static int ncicl;
static char *fpar;
#line 22 "diy.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int i;			/* integer value */
	double r;		/* real value */
	char *s;		/* symbol name or string literal */
	Node *n;		/* node pointer */
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
#define EQ 280
#define IFX 281
#define ELSE 282
#define ATR 283
#define NE 284
#define GE 285
#define LE 286
#define UMINUS 287
#define NOT 288
#define REF 289
#define LOCAL 290
#define POSINC 291
#define POSDEC 292
#define PTR 293
#define CALL 294
#define START 295
#define PARAM 296
#define NIL 297
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,   21,    0,   22,    0,
   20,   20,   18,   18,    1,    1,    1,    2,    2,    2,
    2,    2,    2,    2,    3,    3,    4,    4,    5,    5,
   23,    6,    7,    7,    8,   10,   10,    9,   24,    9,
   25,    9,   26,    9,    9,    9,    9,    9,    9,    9,
   14,   14,   15,   15,   11,   11,   19,   19,   13,   13,
   12,   12,   16,   16,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,
};
static const YYINT yylen[] = {                            2,
    0,    3,    5,    6,    5,    6,    0,    6,    0,    6,
    0,    1,    0,    1,    2,    2,    2,    3,    3,    4,
    3,    4,    3,    4,    4,    3,    1,    2,    1,    3,
    0,    6,    0,    3,    2,    1,    1,    1,    0,    6,
    0,   10,    0,   10,    4,    6,    2,    1,    4,    2,
    0,    1,    3,    3,    0,    2,    0,    1,    1,    2,
    1,    3,    1,    4,    1,    2,    3,    1,    1,    1,
    2,    2,    2,    2,    2,    2,    2,    2,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    4,    3,
};
static const YYINT yydefred[] = {                         1,
    0,    0,   12,    0,    2,    0,    0,    0,    0,    0,
    0,    9,   14,   15,   16,   17,    0,    0,    0,    0,
    0,    3,    5,    0,    0,   10,    4,    6,    0,    0,
    0,    0,    0,    0,    8,    0,    0,    0,   29,   19,
   23,   18,   21,    0,    0,    0,   27,   31,   26,    0,
   35,    0,    0,   22,   20,   24,   33,   28,   25,   30,
    0,    0,   68,   70,    0,   69,   39,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   38,   48,    0,   59,
    0,    0,    0,   50,    0,    0,    0,    0,    0,    0,
    0,   75,   76,   73,   72,   71,   66,    0,   34,    0,
    0,   60,    0,   52,   77,   78,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   74,   47,    0,   94,    0,    0,   36,    0,   37,
    0,    0,   92,   58,    0,    0,   32,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   64,   93,    0,    0,    0,    0,   53,   54,
   49,    0,    0,    0,    0,    0,   40,   46,    0,    0,
    0,    0,    0,    0,   41,   43,    0,    0,   42,   44,
};
static const YYINT yydgoto[] = {                          1,
   37,   23,   26,   49,   38,   78,   61,   39,  128,  129,
  172,  126,   81,  103,  130,   88,   83,   14,  135,    4,
   24,   19,   57,   87,  177,  178,
};
static const YYINT yysindex[] = {                         0,
 -236,  -38,    0, -195,    0, -213,  -19,  -19,  -19, -200,
 -211,    0,    0,    0,    0,    0, -207,  -56,   19,  -42,
  -44,    0,    0,   19,  -35,    0,    0,    0,    6,   23,
   35,   47, -159, -227,    0,  -52, -151,    9,    0,    0,
    0,    0,    0,   52,   54,   58,    0,    0,    0,   64,
    0,  -52, -200,    0,    0,    0,    0,    0,    0,    0,
  798,   65,    0,    0,  -27,    0,    0,  847, -132, -132,
 -132, -132,  847,  847, -132,  847,    0,    0,   69,    0,
  831,  -13,   88,    0,  847,  807,  831, -234,   99,   38,
 -128,    0,    0,    0,    0,    0,    0,  125,    0, -123,
 -123,    0,   18,    0,    0,    0,  847,  847,  847,  847,
  847,  847,  847,  847,  847,  847,  847,  847,  847,  847,
  847,    0,    0,  136,    0,   42,  305,    0, -122,    0,
  831,  847,    0,    0,   80,   86,    0,  305,  240,  381,
  344,  370,  381,   67,   67,   67,   67,   14,   14,  123,
  123,  123,    0,    0,  847,  847, -125,   60,    0,    0,
    0,  305,  270,  831,  847,  847,    0,    0,  164,  164,
  847, -101,  -97,  305,    0,    0,  831,  831,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
 -121,    0,    0,    0,    0,    0,  -94,  -94,  -94,    0,
    0,    0,    0,    0,    0,    0,    0,  131,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -33,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   50,  333,    0,    0,    0,    0,    0,   25,    0,   -5,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  117,
  117,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   51,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  178,    0,  566,
  529,  866,  676,  598,  633,  702,  732,  499,  538,  417,
  443,  470,    0,    0,    0,    0,  770,    0,    0,    0,
    0,   55,    0,    0,    0,    0,    0,    0,  -84,  -84,
    0,    0,    0,  -81,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   15,  162,  165,  134,    0,  -18,    0,  -37,  -46,  -88,
   20,    0,    0,    0,  110, 1042, 1068,  107,   87,    0,
    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1239
static const YYINT yytable[] = {                         63,
   34,   63,   22,   63,   63,   36,   47,   63,   63,   63,
   63,   63,   86,   63,   80,   60,   27,   50,   11,    2,
    5,  108,   13,   79,   17,   63,   63,   63,   63,   45,
   46,   63,   63,   50,  102,   63,   63,   63,   63,   63,
    3,   63,  157,  105,  106,   12,  122,   18,  107,   52,
  121,   20,   53,   63,   63,  119,   63,   65,   25,   63,
  120,   65,   65,   85,   40,   65,   65,   65,   65,   65,
   48,   65,    7,    8,    9,  168,    6,    7,    8,    9,
   10,   41,  154,   65,   65,  155,   65,   63,  179,  180,
   63,   61,  122,   42,   61,   62,  121,  111,   62,  122,
   44,  119,  117,  121,  118,   43,  120,   51,  119,  117,
   54,  118,   55,  120,   15,   16,   56,   65,   63,  116,
  122,  115,   58,   84,  121,  111,   90,   99,   85,  119,
  117,  122,  118,  134,  120,  121,  111,  132,  159,  156,
  119,  117,  137,  118,  160,  120,  123,  116,   65,  115,
   11,   11,   11,   11,   11,  122,  164,  122,  116,  175,
  115,  121,  111,  176,   13,  133,  119,  117,  122,  118,
    7,  120,  121,  111,   51,   57,   55,  119,  117,   56,
  118,   28,  120,  110,  116,   59,  115,  136,   35,  173,
  104,    0,    0,    0,    0,  116,  122,  115,    0,    0,
  121,  111,    0,    0,    0,  119,  117,    0,  118,    0,
  120,  110,   29,   30,   31,   32,    0,    0,   67,    0,
    0,   67,  110,  116,    0,  115,   21,   63,  153,    0,
   63,   33,    0,   63,   63,   63,   67,    7,    8,    9,
   21,    0,    0,    0,   63,   63,   63,    0,  110,   63,
   63,   63,   63,    0,    0,   63,    0,    0,   63,  110,
   63,   63,   63,   63,  105,  106,    0,    0,    0,  107,
   67,    0,  122,    0,   63,    0,  121,  111,   63,   63,
   63,  119,  117,    0,  118,   65,  120,  110,   65,    0,
    0,   65,   65,   65,    0,    0,    0,    0,  161,  116,
    0,  115,  122,    0,   65,    0,  121,  111,   65,   65,
   65,  119,  117,    0,  118,    0,  120,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  165,  166,  167,  116,
    0,  115,    0,    0,    0,    0,    0,  122,    0,  109,
    0,  121,  111,  112,  113,  114,  119,  117,    0,  118,
    0,  120,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  131,  110,  116,   65,  115,  109,    0,   65,
   65,  112,  113,  114,   65,   65,  122,   65,  109,   65,
  121,  111,  112,  113,  114,  119,  117,    0,  118,    0,
  120,   65,   65,  110,   65,    0,    0,    0,    0,    0,
    0,    0,  122,  116,  109,  115,  121,    0,  112,  113,
  114,  119,  117,  122,  118,  109,  120,  121,    0,  112,
  113,  114,  119,  117,    0,  118,    0,  120,  110,  116,
    0,  115,  171,    0,    0,    0,    0,    0,   67,    0,
  116,   67,  115,  109,   67,   67,   67,  112,  113,  114,
    0,    0,    0,   81,   81,    0,   65,   81,   81,   81,
   81,   81,    0,   81,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   81,   81,    0,   81,   82,
   82,    0,    0,   82,   82,   82,   82,   82,    0,   82,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   82,   82,    0,   82,    0,   83,   83,    0,   81,
   83,   83,   83,   83,   83,    0,   83,    0,    0,  109,
    0,    0,    0,  112,  113,  114,    0,    0,   83,   83,
    0,   83,    0,    0,    0,   82,   79,    0,    0,   79,
   81,   79,   79,   79,    0,    0,    0,    0,    0,  109,
    0,    0,    0,  112,  113,  114,    0,   79,   79,    0,
   79,    0,   83,    0,    0,    0,   82,    0,    0,   91,
    0,    0,   91,    0,    0,   80,    0,    0,   80,    0,
   80,   80,   80,    0,  109,    0,    0,   91,  112,  113,
  114,   79,    0,   83,    0,    0,   80,   80,    0,   80,
    0,    0,    0,   89,    0,    0,   89,    0,    0,   89,
    0,    0,   65,    0,    0,    0,   65,   65,   65,    0,
    0,   91,   79,  109,   89,    0,    0,  112,  113,  114,
   80,    0,    0,    0,    0,   86,    0,    0,   86,    0,
    0,   86,    0,    0,    0,    0,    0,    0,    0,  109,
    0,    0,   91,  112,  113,  114,   86,   86,   89,   86,
    0,   80,    0,    0,    0,  113,  114,    0,    0,    0,
   87,    0,    0,   87,    0,    0,   87,   81,    0,    0,
   81,    0,    0,   81,   81,   81,    0,    0,    0,   89,
   86,   87,   87,    0,   87,    0,   81,    0,    0,    0,
   81,   81,   81,   82,    0,    0,   82,    0,    0,   82,
   82,   82,    0,   88,    0,    0,   88,    0,    0,   88,
    0,   86,   82,    0,    0,   87,   82,   82,   82,    0,
   83,    0,    0,   83,   88,    0,   83,   83,   83,   85,
    0,    0,   85,    0,    0,   85,    0,    0,    0,   83,
    0,    0,    0,   83,   83,   83,   87,    0,    0,   79,
   85,   85,   79,   85,    0,   79,   79,   79,   88,   84,
    0,    0,   84,    0,    0,   84,    0,    0,   79,    0,
    0,    0,   79,   79,   79,    0,    0,    0,    0,   91,
   84,   84,   91,   84,   85,   91,   91,   91,   80,   88,
    0,   80,    0,    0,   80,   80,   80,   45,    0,   45,
    0,   45,    0,    0,   45,    0,    0,   80,    0,    0,
    0,   80,   80,   80,   84,   85,   89,    0,   45,   89,
    0,    0,   89,   89,   89,   72,    0,   76,    0,   75,
    0,    0,   74,    0,   72,   89,   76,  125,   75,   89,
    0,   74,    0,    0,    0,   84,   77,    0,   86,    0,
    0,   86,    0,    0,   86,   86,   86,    0,   72,    0,
   76,    0,   75,    0,    0,   74,    0,   86,    0,    0,
    0,   86,   86,   86,   72,    0,   76,    0,   75,   77,
    0,   74,   45,   87,   45,   45,   87,    0,    0,   87,
   87,   87,    0,   90,    0,    0,   90,    0,    0,   90,
    0,    0,   87,    0,    0,    0,   87,   87,   87,    0,
   48,    0,    0,   73,   90,    0,    0,    0,    0,    0,
    0,    0,   73,    0,    0,    0,   88,    0,    0,   88,
    0,    0,   88,   88,   88,    0,    0,    0,    0,    0,
    0,    0,    0,   48,    0,   88,   73,    0,   90,   88,
    0,    0,   85,    0,    0,   85,    0,    0,   85,   85,
   85,    0,   73,    0,    0,    0,    0,    0,    0,    0,
    0,   85,    0,    0,    0,   85,   85,   85,    0,   90,
    0,    0,   84,    0,    0,   84,    0,    0,   84,   84,
   84,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   84,    0,    0,    0,   84,   84,   84,    0,    0,
    0,    0,    0,    0,    0,   45,   45,   45,   45,   45,
   45,   45,   45,    0,   45,    0,    0,    0,    0,   45,
   45,    0,    0,    0,    0,    0,    0,   45,   45,    0,
    0,    0,    0,   62,   63,   64,   65,   66,   67,    0,
   68,    0,   69,   63,   64,   65,   66,    0,    0,    0,
    7,    8,    9,    0,    0,   70,   71,    0,    0,    0,
    0,    0,    0,    0,   70,   71,   62,   63,   64,   65,
   66,   67,    0,   68,    0,   69,    0,    0,    0,    0,
  100,  101,   82,   63,   64,   65,   66,    0,   70,   71,
   91,   92,   93,   94,    0,    0,   97,    0,    0,    0,
    0,    0,   82,    0,   70,   71,   90,    0,   82,   90,
    0,    0,   90,   90,   90,   89,    0,    0,    0,    0,
   95,   96,    0,   98,    0,    0,    0,    0,    0,    0,
    0,    0,  124,  127,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   82,    0,  138,  139,  140,  141,  142,  143,
  144,  145,  146,  147,  148,  149,  150,  151,  152,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  158,
    0,    0,    0,    0,    0,   82,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   82,   82,
    0,    0,  162,  163,    0,    0,    0,    0,    0,    0,
    0,    0,  169,  170,    0,    0,    0,    0,  174,
};
static const YYINT yycheck[] = {                         33,
   45,   35,   59,   37,   38,   41,   59,   41,   42,   43,
   44,   45,   40,   47,   61,   53,   59,   36,    4,  256,
   59,   35,   42,   61,   10,   59,   60,   33,   62,  257,
  258,   37,   38,   52,   81,   41,   42,   43,   44,   45,
  277,   47,  131,  278,  279,  259,   33,  259,  283,   41,
   37,  259,   44,   59,   60,   42,   62,   33,   40,   93,
   47,   37,   38,   91,   59,   41,   42,   43,   44,   45,
  123,   47,  273,  274,  275,  164,  272,  273,  274,  275,
  276,   59,   41,   59,   60,   44,   62,   93,  177,  178,
  124,   41,   33,   59,   44,   41,   37,   38,   44,   33,
  260,   42,   43,   37,   45,   59,   47,  259,   42,   43,
   59,   45,   59,   47,    8,    9,   59,   93,  124,   60,
   33,   62,   59,   59,   37,   38,  259,   59,   91,   42,
   43,   33,   45,  257,   47,   37,   38,  266,   59,  262,
   42,   43,  125,   45,   59,   47,   59,   60,  124,   62,
  272,  273,  274,  275,  276,   33,  282,   33,   60,  261,
   62,   37,   38,  261,  259,   41,   42,   43,   33,   45,
   40,   47,   37,   38,  125,   59,  261,   42,   43,  261,
   45,   20,   47,  124,   60,   52,   62,  101,   24,  170,
   81,   -1,   -1,   -1,   -1,   60,   33,   62,   -1,   -1,
   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,
   47,  124,  257,  258,  259,  260,   -1,   -1,   41,   -1,
   -1,   44,  124,   60,   -1,   62,  283,  261,   93,   -1,
  264,  276,   -1,  267,  268,  269,   59,  273,  274,  275,
  283,   -1,   -1,   -1,  278,  279,  280,   -1,  124,  283,
  284,  285,  286,   -1,   -1,  261,   -1,   -1,  264,  124,
  266,  267,  268,  269,  278,  279,   -1,   -1,   -1,  283,
   93,   -1,   33,   -1,  280,   -1,   37,   38,  284,  285,
  286,   42,   43,   -1,   45,  261,   47,  124,  264,   -1,
   -1,  267,  268,  269,   -1,   -1,   -1,   -1,   59,   60,
   -1,   62,   33,   -1,  280,   -1,   37,   38,  284,  285,
  286,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,   59,   60,
   -1,   62,   -1,   -1,   -1,   -1,   -1,   33,   -1,  280,
   -1,   37,   38,  284,  285,  286,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  264,  124,   60,   33,   62,  280,   -1,   37,
   38,  284,  285,  286,   42,   43,   33,   45,  280,   47,
   37,   38,  284,  285,  286,   42,   43,   -1,   45,   -1,
   47,   59,   60,  124,   62,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   33,   60,  280,   62,   37,   -1,  284,  285,
  286,   42,   43,   33,   45,  280,   47,   37,   -1,  284,
  285,  286,   42,   43,   -1,   45,   -1,   47,  124,   60,
   -1,   62,  269,   -1,   -1,   -1,   -1,   -1,  261,   -1,
   60,  264,   62,  280,  267,  268,  269,  284,  285,  286,
   -1,   -1,   -1,   37,   38,   -1,  124,   41,   42,   43,
   44,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,   62,   37,
   38,   -1,   -1,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   59,   60,   -1,   62,   -1,   37,   38,   -1,   93,
   41,   42,   43,   44,   45,   -1,   47,   -1,   -1,  280,
   -1,   -1,   -1,  284,  285,  286,   -1,   -1,   59,   60,
   -1,   62,   -1,   -1,   -1,   93,   38,   -1,   -1,   41,
  124,   43,   44,   45,   -1,   -1,   -1,   -1,   -1,  280,
   -1,   -1,   -1,  284,  285,  286,   -1,   59,   60,   -1,
   62,   -1,   93,   -1,   -1,   -1,  124,   -1,   -1,   41,
   -1,   -1,   44,   -1,   -1,   38,   -1,   -1,   41,   -1,
   43,   44,   45,   -1,  280,   -1,   -1,   59,  284,  285,
  286,   93,   -1,  124,   -1,   -1,   59,   60,   -1,   62,
   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,   -1,   44,
   -1,   -1,  280,   -1,   -1,   -1,  284,  285,  286,   -1,
   -1,   93,  124,  280,   59,   -1,   -1,  284,  285,  286,
   93,   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,
   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  280,
   -1,   -1,  124,  284,  285,  286,   59,   60,   93,   62,
   -1,  124,   -1,   -1,   -1,  285,  286,   -1,   -1,   -1,
   38,   -1,   -1,   41,   -1,   -1,   44,  261,   -1,   -1,
  264,   -1,   -1,  267,  268,  269,   -1,   -1,   -1,  124,
   93,   59,   60,   -1,   62,   -1,  280,   -1,   -1,   -1,
  284,  285,  286,  261,   -1,   -1,  264,   -1,   -1,  267,
  268,  269,   -1,   38,   -1,   -1,   41,   -1,   -1,   44,
   -1,  124,  280,   -1,   -1,   93,  284,  285,  286,   -1,
  261,   -1,   -1,  264,   59,   -1,  267,  268,  269,   38,
   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,  280,
   -1,   -1,   -1,  284,  285,  286,  124,   -1,   -1,  261,
   59,   60,  264,   62,   -1,  267,  268,  269,   93,   38,
   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,  280,   -1,
   -1,   -1,  284,  285,  286,   -1,   -1,   -1,   -1,  261,
   59,   60,  264,   62,   93,  267,  268,  269,  261,  124,
   -1,  264,   -1,   -1,  267,  268,  269,   38,   -1,   40,
   -1,   42,   -1,   -1,   45,   -1,   -1,  280,   -1,   -1,
   -1,  284,  285,  286,   93,  124,  261,   -1,   59,  264,
   -1,   -1,  267,  268,  269,   38,   -1,   40,   -1,   42,
   -1,   -1,   45,   -1,   38,  280,   40,   41,   42,  284,
   -1,   45,   -1,   -1,   -1,  124,   59,   -1,  261,   -1,
   -1,  264,   -1,   -1,  267,  268,  269,   -1,   38,   -1,
   40,   -1,   42,   -1,   -1,   45,   -1,  280,   -1,   -1,
   -1,  284,  285,  286,   38,   -1,   40,   -1,   42,   59,
   -1,   45,  123,  261,  125,  126,  264,   -1,   -1,  267,
  268,  269,   -1,   38,   -1,   -1,   41,   -1,   -1,   44,
   -1,   -1,  280,   -1,   -1,   -1,  284,  285,  286,   -1,
  123,   -1,   -1,  126,   59,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  126,   -1,   -1,   -1,  261,   -1,   -1,  264,
   -1,   -1,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  123,   -1,  280,  126,   -1,   93,  284,
   -1,   -1,  261,   -1,   -1,  264,   -1,   -1,  267,  268,
  269,   -1,  126,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  280,   -1,   -1,   -1,  284,  285,  286,   -1,  124,
   -1,   -1,  261,   -1,   -1,  264,   -1,   -1,  267,  268,
  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  280,   -1,   -1,   -1,  284,  285,  286,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  256,  257,  258,  259,  260,
  261,  262,  263,   -1,  265,   -1,   -1,   -1,   -1,  270,
  271,   -1,   -1,   -1,   -1,   -1,   -1,  278,  279,   -1,
   -1,   -1,   -1,  256,  257,  258,  259,  260,  261,   -1,
  263,   -1,  265,  257,  258,  259,  260,   -1,   -1,   -1,
  273,  274,  275,   -1,   -1,  278,  279,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  278,  279,  256,  257,  258,  259,
  260,  261,   -1,  263,   -1,  265,   -1,   -1,   -1,   -1,
  270,  271,   61,  257,  258,  259,  260,   -1,  278,  279,
   69,   70,   71,   72,   -1,   -1,   75,   -1,   -1,   -1,
   -1,   -1,   81,   -1,  278,  279,  261,   -1,   87,  264,
   -1,   -1,  267,  268,  269,   68,   -1,   -1,   -1,   -1,
   73,   74,   -1,   76,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   85,   86,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  131,   -1,  107,  108,  109,  110,  111,  112,
  113,  114,  115,  116,  117,  118,  119,  120,  121,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  132,
   -1,   -1,   -1,   -1,   -1,  164,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  177,  178,
   -1,   -1,  155,  156,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  165,  166,   -1,   -1,   -1,   -1,  171,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 297
#define YYUNDFTOKEN 326
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","REAL","ID","STR",
"DO","WHILE","IF","THEN","FOR","IN","UPTO","DOWNTO","STEP","BREAK","CONTINUE",
"VOID","INTEGER","STRING","NUMBER","CONST","PUBLIC","INCR","DECR","EQ","IFX",
"ELSE","ATR","NE","GE","LE","UMINUS","NOT","REF","LOCAL","POSINC","POSDEC",
"PTR","CALL","START","PARAM","NIL",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file :",
"file : file error ';'",
"file : file public tipo ID ';'",
"file : file public CONST tipo ID ';'",
"file : file public tipo ID init",
"file : file public CONST tipo ID init",
"$$1 :",
"file : file public tipo ID $$1 finit",
"$$2 :",
"file : file public VOID ID $$2 finit",
"public :",
"public : PUBLIC",
"ptr :",
"ptr : '*'",
"tipo : INTEGER ptr",
"tipo : STRING ptr",
"tipo : NUMBER ptr",
"init : ATR ID ';'",
"init : ATR INT ';'",
"init : ATR '-' INT ';'",
"init : ATR STR ';'",
"init : ATR CONST STR ';'",
"init : ATR REAL ';'",
"init : ATR '-' REAL ';'",
"finit : '(' params ')' blocop",
"finit : '(' ')' blocop",
"blocop : ';'",
"blocop : bloco ';'",
"params : param",
"params : params ',' param",
"$$3 :",
"bloco : '{' $$3 decls list end '}'",
"decls :",
"decls : decls param ';'",
"param : tipo ID",
"stmt : base",
"stmt : brk",
"base : ';'",
"$$4 :",
"base : DO $$4 stmt WHILE expr ';'",
"$$5 :",
"base : FOR lv IN expr UPTO expr step DO $$5 stmt",
"$$6 :",
"base : FOR lv IN expr DOWNTO expr step DO $$6 stmt",
"base : IF expr THEN stmt",
"base : IF expr THEN stmt ELSE stmt",
"base : expr ';'",
"base : bloco",
"base : lv '#' expr ';'",
"base : error ';'",
"end :",
"end : brk",
"brk : BREAK intp ';'",
"brk : CONTINUE intp ';'",
"step :",
"step : STEP expr",
"intp :",
"intp : INT",
"list : base",
"list : list base",
"args : expr",
"args : args ',' expr",
"lv : ID",
"lv : ID '[' expr ']'",
"expr : lv",
"expr : '*' lv",
"expr : lv ATR expr",
"expr : INT",
"expr : STR",
"expr : REAL",
"expr : '-' expr",
"expr : '~' expr",
"expr : '&' lv",
"expr : expr '!'",
"expr : INCR lv",
"expr : DECR lv",
"expr : lv INCR",
"expr : lv DECR",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr GE expr",
"expr : expr LE expr",
"expr : expr NE expr",
"expr : expr EQ expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : '(' expr ')'",
"expr : ID '(' args ')'",
"expr : ID '(' ')'",

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
#line 204 "diy.y"
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif

void declare(int pub, int cnst, Node *type, char *name, Node *value)
{
  int typ;
  if (!value) {
    if (!pub && cnst) yyerror("local constants must be initialised");
    return;
  }
  if (value->attrib = INT && value->value.i == 0 && type->value.i > 10)
  	return; /* NULL pointer */
  if ((typ = value->info) % 10 > 5) typ -= 5;
  if (type->value.i != typ)
    yyerror("wrong types in initialization");
}
void enter(int pub, int typ, char *name) {
	fpar = malloc(32); /* 31 arguments, at most */
	fpar[0] = 0; /* argument count */
	if (IDfind(name, (long*)IDtest) < 20)
		IDnew(typ+20, name, (long)fpar);
	IDpush();
	if (typ != 4) IDnew(typ, name, 0);
}

int checkargs(char *name, Node *args) {
	char *arg;
	int typ;
        if ((typ = IDsearch(name, (long*)&arg,IDlevel(),1)) < 20) {
		yyerror("ident not a function");
		return 0;
	}
	if (args == 0 && arg[0] == 0)
		;
	else if (args == 0 && arg[0] != 0)
		yyerror("function requires no arguments");
	else if (args != 0 && arg[0] == 0)
		yyerror("function requires arguments");
	else {
		int err = 0, null, i = arg[0], typ;
		do {
			Node *n;
			if (i == 0) {
				yyerror("too many arguments.");
				err = 1;
				break;
			}
			n = RIGHT_CHILD(args);
			typ = n->info;
			if (typ % 10 > 5) typ -= 5; /* remove CONST */
			null =  (n->attrib == INT && n->value.i == 0 && arg[i] > 10) ? 1 : 0;
			if (!null && arg[i] != typ) {
				yyerror("wrong argument type");
				err = 1;
				break;
			}
			args = LEFT_CHILD(args);
			i--;
		} while (args->attrib != NIL);
		if (!err && i > 0)
			yyerror("missing arguments");
	}
	return typ % 20;
}

int nostring(Node *arg1, Node *arg2) {
	if (arg1->info % 5 == 2 || arg2->info % 5 == 2)
		yyerror("can not use strings");
	return arg1->info % 5 == 3 || arg2->info % 5 == 3 ? 3 : 1;
}

int intonly(Node *arg, int novar) {
	if (arg->info % 5 != 1)
		yyerror("only integers can be used");
	if (arg->info % 10 > 5)
		yyerror("argument is constant");
	return 1;
}

int noassign(Node *arg1, Node *arg2) {
	int t1 = arg1->info, t2 = arg2->info;
	if (t1 == t2) return 0;
	if (t1 == 3 && t2 == 1) return 0; /* real := int */
	if (t1 == 1 && t2 == 3) return 0; /* int := real */
	if (t1 == 2 && t2 == 11) return 0; /* string := int* */
	if (t1 == 2 && arg2->attrib == INT && arg2->value.i == 0)
		return 0; /* string := 0 */
	if (t1 > 10 && t1 < 20 && arg2->attrib == INT && arg2->value.i == 0)
		return 0; /* pointer := 0 */
	return 1;
}

char *mklbl(int n) {
  char buf[20];
  sprintf(buf, "_i%d", n);
  return strdup(buf);
}

void function(int pub, Node *type, char *name, Node *body)
{
	Node *bloco = LEFT_CHILD(body);
	IDpop();
	if (bloco != 0) { /* not a forward declaration */
		long par;
		int fwd = IDfind(name, &par);
		if (fwd > 40) yyerror("duplicate function");
		else IDreplace(fwd+40, name, par);
	}
}
#line 748 "y.tab.c"

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
case 3:
#line 57 "diy.y"
	{ IDnew(yystack.l_mark[-2].n->value.i, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-3].i, 0, yystack.l_mark[-2].n, yystack.l_mark[-1].s, 0); }
break;
case 4:
#line 58 "diy.y"
	{ IDnew(yystack.l_mark[-2].n->value.i+5, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-4].i, 1, yystack.l_mark[-2].n, yystack.l_mark[-1].s, 0); }
break;
case 5:
#line 59 "diy.y"
	{ IDnew(yystack.l_mark[-2].n->value.i, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-3].i, 0, yystack.l_mark[-2].n, yystack.l_mark[-1].s, yystack.l_mark[0].n); }
break;
case 6:
#line 60 "diy.y"
	{ IDnew(yystack.l_mark[-2].n->value.i+5, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-4].i, 1, yystack.l_mark[-2].n, yystack.l_mark[-1].s, yystack.l_mark[0].n); }
break;
case 7:
#line 61 "diy.y"
	{ enter(yystack.l_mark[-2].i, yystack.l_mark[-1].n->value.i, yystack.l_mark[0].s); }
break;
case 8:
#line 61 "diy.y"
	{ function(yystack.l_mark[-4].i, yystack.l_mark[-3].n, yystack.l_mark[-2].s, yystack.l_mark[0].n); }
break;
case 9:
#line 62 "diy.y"
	{ enter(yystack.l_mark[-2].i, 4, yystack.l_mark[0].s); }
break;
case 10:
#line 62 "diy.y"
	{ function(yystack.l_mark[-4].i, intNode(VOID, 4), yystack.l_mark[-2].s, yystack.l_mark[0].n); }
break;
case 11:
#line 65 "diy.y"
	{ yyval.i = 0; }
break;
case 12:
#line 66 "diy.y"
	{ yyval.i = 1; }
break;
case 13:
#line 69 "diy.y"
	{ yyval.i = 0; }
break;
case 14:
#line 70 "diy.y"
	{ yyval.i = 10; }
break;
case 15:
#line 73 "diy.y"
	{ yyval.n = intNode(INTEGER, 1+yystack.l_mark[0].i); }
break;
case 16:
#line 74 "diy.y"
	{ yyval.n = intNode(STRING, 2+yystack.l_mark[0].i); }
break;
case 17:
#line 75 "diy.y"
	{ yyval.n = intNode(NUMBER, 3+yystack.l_mark[0].i); }
break;
case 18:
#line 78 "diy.y"
	{ yyval.n = strNode(ID, yystack.l_mark[-1].s); yyval.n->info = IDfind(yystack.l_mark[-1].s, 0) + 10; }
break;
case 19:
#line 79 "diy.y"
	{ yyval.n = intNode(INT, yystack.l_mark[-1].i); yyval.n->info = 1; }
break;
case 20:
#line 80 "diy.y"
	{ yyval.n = intNode(INT, -yystack.l_mark[-1].i); yyval.n->info = 1; }
break;
case 21:
#line 81 "diy.y"
	{ yyval.n = strNode(STR, yystack.l_mark[-1].s); yyval.n->info = 2; }
break;
case 22:
#line 82 "diy.y"
	{ yyval.n = strNode(CONST, yystack.l_mark[-1].s); yyval.n->info = 2+5; }
break;
case 23:
#line 83 "diy.y"
	{ yyval.n = realNode(REAL, yystack.l_mark[-1].r); yyval.n->info = 3; }
break;
case 24:
#line 84 "diy.y"
	{ yyval.n = realNode(REAL, -yystack.l_mark[-1].r); yyval.n->info = 3; }
break;
case 25:
#line 87 "diy.y"
	{ yyval.n = binNode('(', yystack.l_mark[0].n, yystack.l_mark[-2].n); }
break;
case 26:
#line 88 "diy.y"
	{ yyval.n = binNode('(', yystack.l_mark[0].n, 0); }
break;
case 27:
#line 91 "diy.y"
	{ yyval.n = 0; }
break;
case 28:
#line 92 "diy.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 30:
#line 96 "diy.y"
	{ yyval.n = binNode(',', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 31:
#line 99 "diy.y"
	{ IDpush(); }
break;
case 32:
#line 99 "diy.y"
	{ yyval.n = binNode('{', yystack.l_mark[-1].n ? binNode(';', yystack.l_mark[-2].n, yystack.l_mark[-1].n) : yystack.l_mark[-2].n, yystack.l_mark[-3].n); IDpop(); }
break;
case 33:
#line 102 "diy.y"
	{ yyval.n = 0; }
break;
case 34:
#line 103 "diy.y"
	{ yyval.n = binNode(';', yystack.l_mark[-2].n, yystack.l_mark[-1].n); }
break;
case 35:
#line 106 "diy.y"
	{ yyval.n = binNode(PARAM, yystack.l_mark[-1].n, strNode(ID, yystack.l_mark[0].s));
                                  IDnew(yystack.l_mark[-1].n->value.i, yystack.l_mark[0].s, 0);
                                  if (IDlevel() == 1) fpar[++fpar[0]] = yystack.l_mark[-1].n->value.i;
                                }
break;
case 38:
#line 116 "diy.y"
	{ yyval.n = nilNode(VOID); }
break;
case 39:
#line 117 "diy.y"
	{ ncicl++; }
break;
case 40:
#line 117 "diy.y"
	{ yyval.n = binNode(WHILE, binNode(DO, nilNode(START), yystack.l_mark[-3].n), yystack.l_mark[-1].n); ncicl--; }
break;
case 41:
#line 118 "diy.y"
	{ ncicl++; }
break;
case 42:
#line 118 "diy.y"
	{ yyval.n = binNode(';', binNode(ATR, yystack.l_mark[-6].n, yystack.l_mark[-8].n), binNode(FOR, binNode(IN, nilNode(START), binNode(LE, uniNode(PTR, yystack.l_mark[-8].n), yystack.l_mark[-4].n)), binNode(';', yystack.l_mark[0].n, binNode(ATR, binNode('+', uniNode(PTR, yystack.l_mark[-8].n), yystack.l_mark[-3].n), yystack.l_mark[-8].n)))); ncicl--; }
break;
case 43:
#line 119 "diy.y"
	{ ncicl++; }
break;
case 44:
#line 119 "diy.y"
	{ yyval.n = binNode(';', binNode(ATR, yystack.l_mark[-6].n, yystack.l_mark[-8].n), binNode(FOR, binNode(IN, nilNode(START), binNode(GE, uniNode(PTR, yystack.l_mark[-8].n), yystack.l_mark[-4].n)), binNode(';', yystack.l_mark[0].n, binNode(ATR, binNode('-', uniNode(PTR, yystack.l_mark[-8].n), yystack.l_mark[-3].n), yystack.l_mark[-8].n)))); ncicl--; }
break;
case 45:
#line 120 "diy.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 46:
#line 121 "diy.y"
	{ yyval.n = binNode(ELSE, binNode(IF, yystack.l_mark[-4].n, yystack.l_mark[-2].n), yystack.l_mark[0].n); }
break;
case 47:
#line 122 "diy.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 48:
#line 123 "diy.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 49:
#line 124 "diy.y"
	{ yyval.n = binNode('#', yystack.l_mark[-1].n, yystack.l_mark[-3].n); }
break;
case 50:
#line 125 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 51:
#line 128 "diy.y"
	{ yyval.n = 0; }
break;
case 53:
#line 131 "diy.y"
	{ yyval.n = intNode(BREAK, yystack.l_mark[-1].i); if (yystack.l_mark[-1].i <= 0 || yystack.l_mark[-1].i > ncicl) yyerror("invalid break argument"); }
break;
case 54:
#line 132 "diy.y"
	{ yyval.n = intNode(CONTINUE, yystack.l_mark[-1].i); if (yystack.l_mark[-1].i <= 0 || yystack.l_mark[-1].i > ncicl) yyerror("invalid continue argument"); }
break;
case 55:
#line 135 "diy.y"
	{ yyval.n = intNode(INT, 1); }
break;
case 56:
#line 136 "diy.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 57:
#line 139 "diy.y"
	{ yyval.i = 1; }
break;
case 60:
#line 144 "diy.y"
	{ yyval.n = binNode(';', yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 61:
#line 147 "diy.y"
	{ yyval.n = binNode(',', nilNode(NIL), yystack.l_mark[0].n); }
break;
case 62:
#line 148 "diy.y"
	{ yyval.n = binNode(',', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 63:
#line 151 "diy.y"
	{ long pos; int typ = IDfind(yystack.l_mark[0].s, &pos);
                          if (pos == 0) yyval.n = strNode(ID, yystack.l_mark[0].s);
                          else yyval.n = intNode(LOCAL, pos);
			  yyval.n->info = typ;
			}
break;
case 64:
#line 156 "diy.y"
	{ Node *n;
                            long pos; int siz, typ = IDfind(yystack.l_mark[-3].s, &pos);
                            if (typ / 10 != 1 && typ % 5 != 2) yyerror("not a pointer");
                            if (pos == 0) n = strNode(ID, yystack.l_mark[-3].s);
                            else n = intNode(LOCAL, pos);
                            yyval.n = binNode('[', n, yystack.l_mark[-1].n);
			    if (typ >= 10) typ -= 10;
                            else if (typ % 5 == 2) typ = 1;
			    if (typ >= 5) typ -= 5;
			    yyval.n->info = typ;
			  }
break;
case 65:
#line 169 "diy.y"
	{ yyval.n = uniNode(PTR, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 66:
#line 170 "diy.y"
	{ yyval.n = uniNode(PTR, uniNode(PTR, yystack.l_mark[0].n)); if (yystack.l_mark[0].n->info % 5 == 2) yyval.n->info = 1; else if (yystack.l_mark[0].n->info / 10 == 1) yyval.n->info = yystack.l_mark[0].n->info % 10; else yyerror("can dereference lvalue"); }
break;
case 67:
#line 171 "diy.y"
	{ yyval.n = binNode(ATR, yystack.l_mark[0].n, yystack.l_mark[-2].n); if (yyval.n->info % 10 > 5) yyerror("constant value to assignment"); if (noassign(yystack.l_mark[-2].n, yystack.l_mark[0].n)) yyerror("illegal assignment"); yyval.n->info = yystack.l_mark[-2].n->info; }
break;
case 68:
#line 172 "diy.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); yyval.n->info = 1; }
break;
case 69:
#line 173 "diy.y"
	{ yyval.n = strNode(STR, yystack.l_mark[0].s); yyval.n->info = 2; }
break;
case 70:
#line 174 "diy.y"
	{ yyval.n = realNode(REAL, yystack.l_mark[0].r); yyval.n->info = 3; }
break;
case 71:
#line 175 "diy.y"
	{ yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; nostring(yystack.l_mark[0].n, yystack.l_mark[0].n);}
break;
case 72:
#line 176 "diy.y"
	{ yyval.n = uniNode(NOT, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[0].n, 0); }
break;
case 73:
#line 177 "diy.y"
	{ yyval.n = uniNode(REF, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info + 10; }
break;
case 74:
#line 178 "diy.y"
	{ yyval.n = uniNode('!', yystack.l_mark[-1].n); yyval.n->info = 3; intonly(yystack.l_mark[-1].n, 0); }
break;
case 75:
#line 179 "diy.y"
	{ yyval.n = uniNode(INCR, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[0].n, 1); }
break;
case 76:
#line 180 "diy.y"
	{ yyval.n = uniNode(DECR, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[0].n, 1); }
break;
case 77:
#line 181 "diy.y"
	{ yyval.n = uniNode(POSINC, yystack.l_mark[-1].n); yyval.n->info = intonly(yystack.l_mark[-1].n, 1); }
break;
case 78:
#line 182 "diy.y"
	{ yyval.n = uniNode(POSDEC, yystack.l_mark[-1].n); yyval.n->info = intonly(yystack.l_mark[-1].n, 1); }
break;
case 79:
#line 183 "diy.y"
	{ yyval.n = binNode('+', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = nostring(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 80:
#line 184 "diy.y"
	{ yyval.n = binNode('-', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = nostring(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 81:
#line 185 "diy.y"
	{ yyval.n = binNode('*', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = nostring(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 82:
#line 186 "diy.y"
	{ yyval.n = binNode('/', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = nostring(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 83:
#line 187 "diy.y"
	{ yyval.n = binNode('%', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n, 0); intonly(yystack.l_mark[0].n, 0); }
break;
case 84:
#line 188 "diy.y"
	{ yyval.n = binNode('<', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 85:
#line 189 "diy.y"
	{ yyval.n = binNode('>', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 86:
#line 190 "diy.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 87:
#line 191 "diy.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 88:
#line 192 "diy.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 89:
#line 193 "diy.y"
	{ yyval.n = binNode('=', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 90:
#line 194 "diy.y"
	{ yyval.n = binNode('&', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n, 0); intonly(yystack.l_mark[0].n, 0); }
break;
case 91:
#line 195 "diy.y"
	{ yyval.n = binNode('|', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n, 0); intonly(yystack.l_mark[0].n, 0); }
break;
case 92:
#line 196 "diy.y"
	{ yyval.n = yystack.l_mark[-1].n; yyval.n->info = yystack.l_mark[-1].n->info; }
break;
case 93:
#line 197 "diy.y"
	{ yyval.n = binNode(CALL, strNode(ID, yystack.l_mark[-3].s), yystack.l_mark[-1].n);
                            yyval.n->info = checkargs(yystack.l_mark[-3].s, yystack.l_mark[-1].n); }
break;
case 94:
#line 199 "diy.y"
	{ yyval.n = binNode(CALL, strNode(ID, yystack.l_mark[-2].s), nilNode(VOID));
                          yyval.n->info = checkargs(yystack.l_mark[-2].s, 0); }
break;
#line 1313 "y.tab.c"
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
