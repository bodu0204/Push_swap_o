#ifndef DEBUG_H
#define DEBUG_H
#include <stdio.h>
#define TEST printf("[(%s/%d) %s ]\n", __FILE__, __LINE__, __func__); fflush(stdin);
#define TEST_ printf("---------------------------------------------[(%s/%d) %s ]\n", __FILE__, __LINE__, __func__); fflush(stdin);
#define TESTn(str, i) printf("[(%s/%d) %s ]%s:%d\n", __FILE__, __LINE__, __func__, (str), (int)(i)); fflush(stdin);
#define TESTp(str, i) printf("[(%s/%d) %s ]%s:%p\n", __FILE__, __LINE__, __func__, (str), (i)); fflush(stdin);
#ifndef PUSH_SWAP_H
#include "push_swap.h"
#endif


void tests(t_situ *s);
void showstack(t_stack *s, char c);

#endif
//* test */static	size_t stc = 0;
//* test */const int stc_max = 10000;
//* test */const int onoff = 1;
//* test */stc++;
//* test */if (stc > stc_max && onoff)
//* test */{
//* test */	printf("the number is too big"); TEST
//* test */	exit(0);
//* test */}

/*




TESTn("s->len", s->len)
TESTn("s->grd", s->grd)
TESTn("s->udr", s->udr)












 */
