#ifndef __BASE_H__
#define __BASE_H__

#include <stdio.h>
#include <stdlib.h>

#define ABS(a)      ((a) < 0 ? -(a) : (a))
#define MAX(a, b)   ((a + b + ABS(a-b)) / 2)
#define MIN(a, b)   ((a) < (b) ? (a) : (b))
#define SWAP(a, b, T)  {T tmp = a; a = b; b = tmp;}

#ifdef DEBUG
#define DEBUGPRINT(_msg, ...) fprintf(stderr, ".\\%s:%d " _msg, __FILE__, __LINE__, ##__VA_ARGS__);
#else
#define DEBUGPRINT(_msg, ...) // do nothing
#endif

/**
 * @param value int - Les informations sur lesquelles on travaille
 */
typedef struct {
    int value;
} Data;
// structure à personnaliser pour chaque usage


#endif
