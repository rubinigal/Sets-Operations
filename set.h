#ifndef SET_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CMD_SIZE  10
#define MAXNUM 127
#define BIT 8 /*here we use the number of bits in char*/
typedef char set[16];

void read_set(set *p1,int num);
char* print_set(set *p1);
void union_set(set *p1,set *p2,set *p3);
void intersect_set(set *p1,set *p2,set *p3);
void sub_set(set *p1,set *p2,set *p3);
void symdiff_set(set *p1,set *p2,set *p3);
void stop(void);

#endif
