#pragma once
#include <math.h>
#include <stdio.h>

#define ARRAY_CAPACITY 20
#define WI printf("Wrong input\n")
#define forn(i, n) for(int i = 0; i < n; i++)

/* data enter. If error returns 0 */
short readArr(double *arr);
short getSize(char arrName);
short readParams(double *a, double *x, double *vh);

/* modify arrays */
void makeB(double *arr, short size, double a, double x, double h);
void removeAllNegAfterMin(double *arr, short *size);
short getMin(const double *arr, short size);
char insertMinAtZero(double *arr, short *size);
void replaceOddToZero(double *arr, short size);

/* print to console */
void printArr(const double *arr, short size);