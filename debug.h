#ifndef DEBUG_H
#define DEBUG_H
#include <stdio.h>
#define TEST printf("[%s/%d]\n", __FILE__, __LINE__); fflush(stdin);
#define TESTn(str, i) printf("[%s/%d]%s:%d\n", __FILE__, __LINE__, (str), ((int)i)); fflush(stdin);
#define TESTp(str, i) printf("[%s/%d]%s:%p\n", __FILE__, __LINE__, (str), (i)); fflush(stdin);
#endif
