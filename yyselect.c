/*
generated at Mon Apr 15 04:05:37 2019
by $Id: pburg.c,v 2.5 2017/11/16 09:41:42 prs Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PBURG_PREFIX "yy"
#define PBURG_VERSION "2.5"
#define MAX_COST 0x7fff
#if defined(__STDC__) || defined(__cplusplus)
#define YYCONST const
#else
#define YYCONST
#endif

#line 1 "diy.brg"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
#include "postfix.h"
#ifndef PANIC
#define PANIC yypanic
static void yypanic(YYCONST char *rot, YYCONST char *msg, int val) {
	fprintf(stderr, "Internal Error in %s: %s %d\nexiting...\n",
		rot, msg, val);
	exit(2);
}
#endif
static void yykids(NODEPTR_TYPE, int, NODEPTR_TYPE[]);
#define yystmt_NT 1

static YYCONST char *yyntname[] = {
	0,
	"stmt",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "",
	/* 60 */ "END",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "",
	/* 258 */ "INT",
	/* 259 */ "REAL",
	/* 260 */ "ID",
	/* 261 */ "STR",
	/* 262 */ "DO",
	/* 263 */ "WHILE",
	/* 264 */ "IF",
	/* 265 */ "THEN",
	/* 266 */ "FOR",
	/* 267 */ "IN",
	/* 268 */ "UPTO",
	/* 269 */ "DOWNTO",
	/* 270 */ "STEP",
	/* 271 */ "BREAK",
	/* 272 */ "CONTINUE",
	/* 273 */ "VOID",
	/* 274 */ "INTEGER",
	/* 275 */ "STRING",
	/* 276 */ "NUMBER",
	/* 277 */ "CONST",
	/* 278 */ "PUBLIC",
	/* 279 */ "INCR",
	/* 280 */ "DECR",
	/* 281 */ "ASSIGN",
	/* 282 */ "NE",
	/* 283 */ "GE",
	/* 284 */ "LE",
	/* 285 */ "EQ",
	/* 286 */ "ELSE",
	/* 287 */ "PROG",
	/* 288 */ "DECLS",
	/* 289 */ "DECL",
	/* 290 */ "INI",
	/* 291 */ "NIL",
	/* 292 */ "EXPRS",
	/* 293 */ "ALLOC",
	/* 294 */ "ARGINST",
	/* 295 */ "PARAMS",
	/* 296 */ "PARAM",
	/* 297 */ "INSTRS",
	/* 298 */ "ARGS",
	/* 299 */ "POINTER",
	/* 300 */ "SUM",
	/* 301 */ "SUBT",
	/* 302 */ "MUL",
	/* 303 */ "DIV",
	/* 304 */ "MOD",
	/* 305 */ "GT",
	/* 306 */ "LT",
	/* 307 */ "AND",
	/* 308 */ "OR",
	/* 309 */ "FAC",
	/* 310 */ "ARR",
	/* 311 */ "FUNC",
	/* 312 */ "NEG",
	/* 313 */ "PNTR",
	/* 314 */ "LOC",
	/* 315 */ "PUB",
	/* 316 */ "IFX",
	/* 317 */ "INC",
	/* 318 */ "DEC",
	/* 319 */ "PMINUS",
	""
};

struct yystate {
	short cost[2];
	struct {
		unsigned int yystmt:1;
	} rule;
};

static short yynts_0[] = { 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"stmt: END",
};

#ifndef TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	fprintf(stderr, "0x%lx:%s matched %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
}
#endif

static short yydecode_stmt[] = {
	0,
	1,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 1)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yystmt_NT:	return yydecode_stmt[((struct yystate *)state)->rule.yystmt];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}


static void yylabel(NODEPTR_TYPE a, NODEPTR_TYPE u) {
	int c;
	struct yystate *p;

	if (!a)
		PANIC("yylabel", "Null tree in", OP_LABEL(u));
	STATE_LABEL(a) = p = (struct yystate *)malloc(sizeof *p);
	memset(p, 0, sizeof *p);
	p->cost[1] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 59: /* END */
		/* stmt: END */
		yytrace(a, 1, 1 + 0, p->cost[yystmt_NT]);
		if (1 + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = 1 + 0;
			p->rule.yystmt = 1;
		}
		break;
	case 257: /* INT */
		return;
	case 258: /* REAL */
		return;
	case 259: /* ID */
		return;
	case 260: /* STR */
		return;
	case 261: /* DO */
		return;
	case 262: /* WHILE */
		return;
	case 263: /* IF */
		return;
	case 264: /* THEN */
		return;
	case 265: /* FOR */
		return;
	case 266: /* IN */
		return;
	case 267: /* UPTO */
		return;
	case 268: /* DOWNTO */
		return;
	case 269: /* STEP */
		return;
	case 270: /* BREAK */
		return;
	case 271: /* CONTINUE */
		return;
	case 272: /* VOID */
		return;
	case 273: /* INTEGER */
		return;
	case 274: /* STRING */
		return;
	case 275: /* NUMBER */
		return;
	case 276: /* CONST */
		return;
	case 277: /* PUBLIC */
		return;
	case 278: /* INCR */
		return;
	case 279: /* DECR */
		return;
	case 280: /* ASSIGN */
		return;
	case 281: /* NE */
		return;
	case 282: /* GE */
		return;
	case 283: /* LE */
		return;
	case 284: /* EQ */
		return;
	case 285: /* ELSE */
		return;
	case 286: /* PROG */
		return;
	case 287: /* DECLS */
		return;
	case 288: /* DECL */
		return;
	case 289: /* INI */
		return;
	case 290: /* NIL */
		return;
	case 291: /* EXPRS */
		return;
	case 292: /* ALLOC */
		return;
	case 293: /* ARGINST */
		return;
	case 294: /* PARAMS */
		return;
	case 295: /* PARAM */
		return;
	case 296: /* INSTRS */
		return;
	case 297: /* ARGS */
		return;
	case 298: /* POINTER */
		return;
	case 299: /* SUM */
		return;
	case 300: /* SUBT */
		return;
	case 301: /* MUL */
		return;
	case 302: /* DIV */
		return;
	case 303: /* MOD */
		return;
	case 304: /* GT */
		return;
	case 305: /* LT */
		return;
	case 306: /* AND */
		return;
	case 307: /* OR */
		return;
	case 308: /* FAC */
		return;
	case 309: /* ARR */
		return;
	case 310: /* FUNC */
		return;
	case 311: /* NEG */
		return;
	case 312: /* PNTR */
		return;
	case 313: /* LOC */
		return;
	case 314: /* PUB */
		return;
	case 315: /* IFX */
		return;
	case 316: /* INC */
		return;
	case 317: /* DEC */
		return;
	case 318: /* PMINUS */
		return;
	default:
		PANIC("yylabel", "Bad terminal", OP_LABEL(a));
	}
}

static void yykids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	if (!p)
		PANIC("yykids", "Null tree in rule", eruleno);
	if (!kids)
		PANIC("yykids", "Null kids in", OP_LABEL(p));
	switch (eruleno) {
	case 1: /* stmt: END */
		break;
	default:
		PANIC("yykids", "Bad rule number", eruleno);
	}
}

static void yyreduce(NODEPTR_TYPE p, int goalnt)
{
  int eruleno = yyrule(STATE_LABEL(p), goalnt);
  short *nts = yynts[eruleno];
  NODEPTR_TYPE kids[0];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* stmt: END */
#line 13 "diy.brg"
{	}
		break;
	default: break;
  }
}

int yyselect(NODEPTR_TYPE p)
{
	yylabel(p,p);
	if (((struct yystate *)STATE_LABEL(p))->rule.yystmt == 0) {
		fprintf(stderr, "No match for start symbol (%s).\n", yyntname[1]);
		return 1;
	}
	yyreduce(p, 1);
	return 0;
}


#line 14 "diy.brg"

#include "y.tab.h"
extern void yyerror(const char*);
extern char **yynames;
extern int trace;
