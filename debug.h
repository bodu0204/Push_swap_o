#ifndef DEBUG_H
#define DEBUG_H
#include <stdio.h>
#define TEST printf("[%s/%d]\n", __FILE__, __LINE__); fflush(stdin);
#define TESTn(i) printf("[%s/%d]->%d\n", __FILE__, __LINE__, (int)i); fflush(stdin);
#endif
