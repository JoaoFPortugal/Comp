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
