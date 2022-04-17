#ifndef DEBUG_H
#define DEBUG_H
#include <stdio.h>
#define TEST printf("[%s/%d]\n", __FILE__, __LINE__); fflush(stdin);
#define TESTn(i) printf("[%s/%d]%s:%d\n", __FILE__, __LINE__, "i", ((int)i)); fflush(stdin);
#define TESTp(i) printf("[%s/%d]%s:%p\n", __FILE__, __LINE__, "i", (i)); fflush(stdin);
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
