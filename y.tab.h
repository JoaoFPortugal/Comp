#define INT 257
#define NUM 258
#define ID 259
#define STR 260
#define EQ 261
#define NE 262
#define LE 263
#define GE 264
#define STRING 265
#define NUMBER 266
#define INTEGER 267
#define VOID 268
#define PUBLIC 269
#define FOR 270
#define ASSIGN 271
#define DEC 272
#define INC 273
#define BREAK 274
#define CONTINUE 275
#define DOWNTO 276
#define UPTO 277
#define DO 278
#define WHILE 279
#define THEN 280
#define ELSE 281
#define STEP 282
#define CONST 283
#define IF 284
#define IN 285
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int i;		/* integer value */
  	double d;	/* double value */
  	char *s;	/* symbol name or string literal */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
