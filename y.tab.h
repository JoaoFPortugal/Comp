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
#define IFX 313
#define PMINUS 314
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
extern YYSTYPE yylval;
