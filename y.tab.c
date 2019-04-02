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
#include <string.h>
extern int yylex();
int yyerror(char *s);

#line 9 "diy.y"
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
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 41 "y.tab.c"

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
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    1,    2,    2,    2,    2,    2,    2,
    3,    3,    4,    4,    6,    6,    5,    5,    5,    5,
    9,    9,   10,    7,    7,    7,    7,    7,    7,    8,
    8,    8,    8,   12,   12,   11,   11,   13,   13,   13,
   13,   13,   13,   13,   13,   13,   13,   13,   13,   16,
   16,   17,   17,   15,   15,   18,   18,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,
};
static const YYINT yylen[] = {                            2,
    1,    0,    1,    2,    7,    6,    8,   11,   12,    2,
    0,    1,    0,    1,    0,    1,    1,    1,    1,    1,
    3,    1,    3,    2,    3,    2,    3,    2,    3,    0,
    1,    1,    2,    2,    3,    1,    2,    4,    6,    5,
    9,    2,    3,    3,    2,    3,    2,    4,    2,    1,
    1,    0,    2,    1,    4,    3,    1,    1,    1,    1,
    1,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    2,    2,    2,    2,    3,
    4,    3,    2,
};
static const YYINT yydefred[] = {                         0,
    0,   12,    0,    0,    3,    0,   10,    4,   14,    0,
   20,   17,   18,   19,    0,   16,    0,    0,    0,    6,
    0,    0,   24,   26,   28,    0,    0,    0,    0,    0,
   22,    5,   25,   27,   29,    7,    0,    0,    0,    0,
    0,   58,   59,    0,   60,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   36,
    0,    0,   23,    0,   21,   49,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   45,    0,   47,   76,   77,
    0,    0,    0,    0,   34,   37,    0,   33,    0,    0,
    0,    0,   42,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   78,   79,    0,    0,    0,   80,    0,    0,
    0,    0,    0,    0,    0,   44,   46,   82,   43,    8,
   35,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   81,    0,   55,
    0,    0,   38,    0,   48,    9,    0,   40,    0,   50,
   51,    0,   39,    0,    0,    0,    0,    0,   41,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,    6,   10,   29,   17,   22,   56,   30,   57,
   58,   59,   60,   61,   72,  152,  156,  110,
};
static const YYINT yysindex[] = {                      -249,
  -40,    0,    0, -249,    0, -235,    0,    0,    0, -241,
    0,    0,    0,    0,  -21,    0, -217,  -37,  141,    0,
   98,  -11,    0,    0,    0, -222, -203,  -43,  -21,   63,
    0,    0,    0,    0,    0,    0,  285, -201,  -64, -241,
    4,    0,    0,  -23,    0,  315,   83, -192,  -59,  -46,
 -192, -192,  168,  285,  168,  -51,   19,  315,  285,    0,
   55,  -20,    0,  285,    0,    0,  156,  168, -183, -181,
   82, -255,   -6, -177,   35,    0,   37,    0,    0,    0,
   93,  -22,  307,   57,    0,    0,   59,    0,  168,  168,
  168,  168,    0,  168,  168,  168,  168,  168,  168,  168,
  168,  168,    0,    0,  168,  168,    7,    0,  307,   67,
  128,  168,  315,  315,  168,    0,    0,    0,    0,    0,
    0,  307,  307,  307,  307,  307,  307,  307,  307,  307,
  307,  307,  307,  307,  307,  140,   74,    0,  168,    0,
  167, -163,    0,   39,    0,    0,  307,    0,  315,    0,
    0,  168,    0,  195,  168, -124,  307,  315,    0,
};
static const YYINT yyrindex[] = {                         1,
    0,    0,    0,    6,    0, -220,    0,    0,    0,    0,
    0,    0,    0,    0, -116,    0,    0,    0, -115,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -116,    0,
    0,    0,    0,    0,    0,    0,   21,    0,    0,    0,
    0,    0,    0,  -33,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   21,    0,    0,    0,   22,   23,    0,
    0,  256,    0,   21,    0,    0,    0,    0,    0,  341,
    0,   28,    2,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  346,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   68,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  396,  412,  422,  431,  441,  454,  468,  477,  508,
  524,  538,  559,  568,  585,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   69,    0,    0,    0,
    0,    0,    0, -112,    0,    0, -110,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  150,    0,  137,  147,  129,    0,  -34,    0,   -3,
    0,    0,   -8,  795,  702,    0,    0,    0,
};
#define YYTABLESIZE 950
static const YYINT yytable[] = {                         76,
    2,   54,   21,   54,   54,    1,    1,   54,   54,   54,
   54,   54,   78,   54,  106,   36,   67,   31,    7,   82,
   16,   20,  103,  104,  105,   54,   54,    2,   54,  107,
   11,   12,   13,   14,   33,   34,   65,   69,   54,   54,
    9,   18,   54,   54,   54,   54,   54,   32,   54,   86,
   88,   13,   13,   13,   13,   87,   35,   63,   64,   54,
   54,   54,   66,   54,   61,   61,   73,   68,   61,   61,
   61,   61,   61,   84,   61,   98,  101,   85,  112,   37,
   94,   96,  113,   95,   68,   97,   61,   61,  115,   61,
   54,   98,  101,  116,   54,  117,   94,   96,  100,   95,
   99,   97,  119,   39,  142,  143,   40,  138,   57,   56,
  139,   57,   56,   93,  100,  120,   99,  121,   98,  101,
   61,  149,   53,   94,   96,   54,   95,   55,   97,   98,
  101,  137,  146,  118,   94,   96,  158,   95,   28,   97,
  153,  100,   15,   99,   13,   30,   31,   32,   52,  159,
   53,   61,  100,    8,   99,   27,   15,   38,    0,    0,
    0,    0,  102,    0,   98,  101,    0,    0,    0,   94,
   96,    0,   95,    0,   97,    0,   98,  101,  102,    0,
    0,   94,   96,    0,   95,   26,   97,  100,    0,   99,
    0,    0,    0,    0,    0,   53,  108,   75,  145,  100,
   55,   99,    0,   98,  101,  102,    0,   53,   94,   96,
   77,   95,   55,   97,    0,    0,  102,    0,    0,    0,
  140,    0,    0,    0,    0,  148,  100,   54,   99,    0,
   54,   98,  101,   54,   54,   54,   94,   96,    0,   95,
    0,   97,   19,    0,   54,   54,   54,   54,   54,   54,
   54,  102,    0,    0,  100,    0,   99,  103,  104,  105,
    0,    0,   54,  102,    0,   54,    0,   54,   54,   54,
   54,    0,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   54,   54,   54,   54,    0,    0,   61,    0,
  102,   61,   61,   61,   61,   61,   61,   61,   61,    0,
   61,    0,   61,    0,    0,  150,  151,    0,   61,   61,
   61,   61,    0,    0,   61,   61,    0,   61,  102,   89,
   90,   91,   92,    0,   53,    0,    0,    0,    0,   55,
    0,    0,    0,    0,    0,   89,   90,   91,   92,   70,
   43,   44,   45,   98,  101,  114,    0,    0,   94,   96,
    0,   95,    0,   97,   53,    0,    0,    0,    0,   55,
   51,   52,   89,   90,   91,   92,  100,    0,   99,   11,
   12,   13,   14,   89,   90,   91,   92,   58,   58,   61,
    0,    0,   58,   58,    0,   58,   83,   58,    0,   83,
    0,    0,    0,    0,    0,    0,    0,   23,   24,   25,
   58,    0,   58,    0,   83,    0,    0,   54,   89,   90,
   91,   92,   42,   43,   44,   45,    9,    0,    0,    0,
   89,   90,   91,   92,   42,   43,   44,   45,    0,    0,
  102,    0,    0,   51,   52,    0,   70,   54,   83,   70,
    0,    0,    0,    0,    0,   51,   52,   89,   90,   91,
   92,    0,   71,    0,   70,   71,    0,    0,    0,    0,
    0,    0,   72,  155,   58,   72,    0,    0,    0,    0,
   71,   69,    0,    0,   69,   89,   90,   91,   92,    0,
   72,   64,    0,    0,   64,    0,    0,    0,   70,   69,
    0,    0,    0,    0,   63,    0,    0,   63,    0,   64,
    0,    0,    0,    0,   71,    0,    0,    0,   62,    0,
    0,   62,   63,    0,   72,    0,    0,   65,    0,    0,
   65,    0,    0,   69,    0,    0,   62,    0,    0,    0,
    0,    0,    0,   64,    0,   65,   61,   61,   61,   61,
   41,   42,   43,   44,   45,   46,   63,   47,   66,   48,
    0,   66,    0,    0,   49,   50,   11,   12,   13,   14,
   62,    0,   51,   52,   67,    0,   66,   67,    0,   65,
   41,   42,   43,   44,   45,   46,    0,   47,   68,   48,
    0,   68,   67,    0,   49,   50,    0,   89,   90,   91,
   92,    0,   51,   52,    0,    0,   68,    0,    0,   73,
   66,    0,   73,    0,    0,    0,   83,    0,   74,   83,
    0,   74,   83,   83,   83,    0,   67,   73,    0,    0,
    0,   58,   58,   58,   58,   75,   74,    0,   75,    0,
   68,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   75,    0,    0,    0,    0,    0,    0,
    0,   73,    0,    0,    0,    0,   70,    0,    0,   70,
   74,    0,   70,   70,   70,    0,    0,    0,    0,    0,
    0,    0,   71,    0,    0,   71,    0,   75,   71,   71,
   71,    0,   72,    0,    0,   72,    0,    0,   72,   72,
   72,   69,    0,    0,   69,    0,    0,   69,   69,   69,
    0,   64,    0,    0,   64,    0,    0,   64,   64,   64,
    0,    0,    0,    0,   63,    0,    0,   63,    0,    0,
   63,   63,   63,    0,    0,    0,    0,    0,   62,    0,
    0,   62,    0,    0,   62,   62,   62,   65,   62,    0,
   65,    0,    0,   65,   65,   65,    0,   62,    0,   74,
    0,    0,   79,   80,    0,   62,    0,    0,    0,   62,
   62,    0,    0,    0,    0,   62,    0,    0,   66,    0,
    0,   66,    0,    0,   66,   66,   66,    0,    0,    0,
    0,    0,    0,    0,   67,    0,    0,   67,    0,    0,
   67,   67,   67,    0,    0,    0,    0,    0,   68,    0,
    0,   68,    0,    0,   68,   68,   68,    0,    0,    0,
    0,    0,    0,    0,   62,   62,    0,    0,    0,   73,
    0,    0,   73,    0,    0,   73,   73,   73,   74,    0,
    0,   74,    0,    0,   74,   74,   74,    0,    0,    0,
    0,   71,    0,    0,    0,   75,    0,   81,   75,   83,
   62,   75,   75,   75,    0,    0,    0,    0,    0,   62,
    0,  109,  111,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  122,  123,  124,  125,    0,  126,  127,
  128,  129,  130,  131,  132,  133,  134,    0,    0,  135,
  136,    0,    0,    0,    0,    0,  141,    0,    0,  144,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  147,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  154,    0,    0,  157,
};
static const YYINT yycheck[] = {                         59,
    0,   35,   40,   37,   38,    0,  256,   41,   42,   43,
   44,   45,   59,   47,   35,   59,   40,   21,   59,   54,
   42,   59,  278,  279,  280,   59,   60,  277,   62,   64,
  272,  273,  274,  275,  257,  258,   40,   46,   37,   38,
  276,  259,   41,   42,   43,   44,   45,   59,   47,   58,
   59,  272,  273,  274,  275,   59,  260,  259,  123,   93,
   59,   60,   59,   62,   37,   38,  259,   91,   41,   42,
   43,   44,   45,  125,   47,   37,   38,   59,  262,  123,
   42,   43,  264,   45,   91,   47,   59,   60,  266,   62,
  124,   37,   38,   59,   93,   59,   42,   43,   60,   45,
   62,   47,  125,   41,  113,  114,   44,   41,   41,   41,
   44,   44,   44,   59,   60,   59,   62,   59,   37,   38,
   93,  285,   40,   42,   43,  124,   45,   45,   47,   37,
   38,  125,   59,   41,   42,   43,  261,   45,   41,   47,
  149,   60,  259,   62,  260,  125,  125,  125,  261,  158,
  261,  124,   60,    4,   62,   19,   10,   29,   -1,   -1,
   -1,   -1,  124,   -1,   37,   38,   -1,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   37,   38,  124,   -1,
   -1,   42,   43,   -1,   45,   45,   47,   60,   -1,   62,
   -1,   -1,   -1,   -1,   -1,   40,   41,  257,   59,   60,
   45,   62,   -1,   37,   38,  124,   -1,   40,   42,   43,
  257,   45,   45,   47,   -1,   -1,  124,   -1,   -1,   -1,
   93,   -1,   -1,   -1,   -1,   59,   60,  261,   62,   -1,
  264,   37,   38,  267,  268,  269,   42,   43,   -1,   45,
   -1,   47,  280,   -1,  278,  279,  280,  281,  282,  283,
  284,  124,   -1,   -1,   60,   -1,   62,  278,  279,  280,
   -1,   -1,  261,  124,   -1,  264,   -1,  266,  267,  268,
  269,   -1,  272,  273,  274,  275,  276,  272,  273,  274,
  275,  276,  281,  282,  283,  284,   -1,   -1,  261,   -1,
  124,  264,   37,   38,  267,  268,  269,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,  267,  268,   -1,  281,  282,
  283,  284,   -1,   -1,   59,   60,   -1,   62,  124,  281,
  282,  283,  284,   -1,   40,   -1,   -1,   -1,   -1,   45,
   -1,   -1,   -1,   -1,   -1,  281,  282,  283,  284,  257,
  258,  259,  260,   37,   38,  264,   -1,   -1,   42,   43,
   -1,   45,   -1,   47,   40,   -1,   -1,   -1,   -1,   45,
  278,  279,  281,  282,  283,  284,   60,   -1,   62,  272,
  273,  274,  275,  281,  282,  283,  284,   37,   38,  124,
   -1,   -1,   42,   43,   -1,   45,   41,   47,   -1,   44,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
   60,   -1,   62,   -1,   59,   -1,   -1,  123,  281,  282,
  283,  284,  257,  258,  259,  260,  276,   -1,   -1,   -1,
  281,  282,  283,  284,  257,  258,  259,  260,   -1,   -1,
  124,   -1,   -1,  278,  279,   -1,   41,  123,   93,   44,
   -1,   -1,   -1,   -1,   -1,  278,  279,  281,  282,  283,
  284,   -1,   41,   -1,   59,   44,   -1,   -1,   -1,   -1,
   -1,   -1,   41,  269,  124,   44,   -1,   -1,   -1,   -1,
   59,   41,   -1,   -1,   44,  281,  282,  283,  284,   -1,
   59,   41,   -1,   -1,   44,   -1,   -1,   -1,   93,   59,
   -1,   -1,   -1,   -1,   41,   -1,   -1,   44,   -1,   59,
   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,   41,   -1,
   -1,   44,   59,   -1,   93,   -1,   -1,   41,   -1,   -1,
   44,   -1,   -1,   93,   -1,   -1,   59,   -1,   -1,   -1,
   -1,   -1,   -1,   93,   -1,   59,  281,  282,  283,  284,
  256,  257,  258,  259,  260,  261,   93,  263,   41,  265,
   -1,   44,   -1,   -1,  270,  271,  272,  273,  274,  275,
   93,   -1,  278,  279,   41,   -1,   59,   44,   -1,   93,
  256,  257,  258,  259,  260,  261,   -1,  263,   41,  265,
   -1,   44,   59,   -1,  270,  271,   -1,  281,  282,  283,
  284,   -1,  278,  279,   -1,   -1,   59,   -1,   -1,   41,
   93,   -1,   44,   -1,   -1,   -1,  261,   -1,   41,  264,
   -1,   44,  267,  268,  269,   -1,   93,   59,   -1,   -1,
   -1,  281,  282,  283,  284,   41,   59,   -1,   44,   -1,
   93,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   93,   -1,   -1,   -1,   -1,  261,   -1,   -1,  264,
   93,   -1,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  261,   -1,   -1,  264,   -1,   93,  267,  268,
  269,   -1,  261,   -1,   -1,  264,   -1,   -1,  267,  268,
  269,  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,
   -1,  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,
   -1,   -1,   -1,   -1,  261,   -1,   -1,  264,   -1,   -1,
  267,  268,  269,   -1,   -1,   -1,   -1,   -1,  261,   -1,
   -1,  264,   -1,   -1,  267,  268,  269,  261,   37,   -1,
  264,   -1,   -1,  267,  268,  269,   -1,   46,   -1,   48,
   -1,   -1,   51,   52,   -1,   54,   -1,   -1,   -1,   58,
   59,   -1,   -1,   -1,   -1,   64,   -1,   -1,  261,   -1,
   -1,  264,   -1,   -1,  267,  268,  269,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  261,   -1,   -1,  264,   -1,   -1,
  267,  268,  269,   -1,   -1,   -1,   -1,   -1,  261,   -1,
   -1,  264,   -1,   -1,  267,  268,  269,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  113,  114,   -1,   -1,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,  261,   -1,
   -1,  264,   -1,   -1,  267,  268,  269,   -1,   -1,   -1,
   -1,   47,   -1,   -1,   -1,  261,   -1,   53,  264,   55,
  149,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,  158,
   -1,   67,   68,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   89,   90,   91,   92,   -1,   94,   95,
   96,   97,   98,   99,  100,  101,  102,   -1,   -1,  105,
  106,   -1,   -1,   -1,   -1,   -1,  112,   -1,   -1,  115,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  139,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  152,   -1,   -1,  155,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 285
#define YYUNDFTOKEN 306
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,
0,0,0,0,0,"';'","'<'",0,"'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'","'|'","'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","REAL","ID","STR","DO","WHILE",
"IF","THEN","FOR","IN","UPTO","DOWNTO","STEP","BREAK","CONTINUE","VOID",
"INTEGER","STRING","NUMBER","CONST","PUBLIC","INCR","DECR","ASSIGN","NE","GE",
"LE","EQ","ELSE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : seq",
"file :",
"seq : declaracao",
"seq : seq declaracao",
"declaracao : pub const type ptr ID ini ';'",
"declaracao : pub const type ptr ID ';'",
"declaracao : pub const type ptr ID '(' ')' ';'",
"declaracao : pub const type ptr ID '(' ')' '{' body '}' ';'",
"declaracao : pub const type ptr ID '(' params ')' '{' body '}' ';'",
"declaracao : error ';'",
"pub :",
"pub : PUBLIC",
"const :",
"const : CONST",
"ptr :",
"ptr : '*'",
"type : INTEGER",
"type : STRING",
"type : NUMBER",
"type : VOID",
"params : params ',' param",
"params : param",
"param : type ptr ID",
"ini : ASSIGN INT",
"ini : ASSIGN '-' INT",
"ini : ASSIGN REAL",
"ini : ASSIGN '-' REAL",
"ini : ASSIGN ID",
"ini : ASSIGN const STR",
"body :",
"body : instrs",
"body : args",
"body : args instr",
"args : param ';'",
"args : args param ';'",
"instrs : instr",
"instrs : instrs instr",
"instr : IF expr THEN instr",
"instr : IF INT THEN instr ELSE instr",
"instr : DO instr WHILE expr ';'",
"instr : FOR leftvalue IN expr updw expr step DO instr",
"instr : expr ';'",
"instr : '{' body '}'",
"instr : BREAK INT ';'",
"instr : BREAK ';'",
"instr : CONTINUE INT ';'",
"instr : CONTINUE ';'",
"instr : leftvalue '#' expr ';'",
"instr : error ';'",
"updw : UPTO",
"updw : DOWNTO",
"step :",
"step : STEP expr",
"leftvalue : ID",
"leftvalue : ID '[' expr ']'",
"exprs : exprs ',' expr",
"exprs : expr",
"expr : INT",
"expr : REAL",
"expr : STR",
"expr : leftvalue",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '>' expr",
"expr : expr '<' expr",
"expr : expr EQ expr",
"expr : expr NE expr",
"expr : expr GE expr",
"expr : expr LE expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : leftvalue ASSIGN expr",
"expr : INCR leftvalue",
"expr : DECR leftvalue",
"expr : leftvalue INCR",
"expr : leftvalue DECR",
"expr : ID '(' ')'",
"expr : ID '(' exprs ')'",
"expr : '(' expr ')'",
"expr : '-' expr",

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
#line 149 "diy.y"

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
#line 542 "y.tab.c"

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
