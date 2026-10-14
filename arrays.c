#include "arrays.h"

short getSize(char arrName) {
	short n = 0;
	printf("Enter size of ");
	printf("%c", arrName);
	printf(" array: \n");
	if (scanf("%hd", &n) != 1 || n > ARRAY_CAPACITY || n < 1) {
		WI;
		return 0;
	}
	return n;
}
short readArr(double* arr) {
	short n = getSize('A');
	printf("Enter elements for A: \n");
	for (int i = 0; i < n; i++) if(scanf("%lf", &arr[i]) != 1) { WI; return 0; }
	return n;
}
short readParams(double *a, double *x, double *h) {
	printf("Enter a, x, h separated by spaces: \n");
	if (scanf("%lf %lf %lf", a, x, h) != 3) {
		WI;
		return 0;
	}
	return 1;
}

void makeB(double *arr, short size, double a, double x, double h) {
	forn(i, size) arr[i] = 3 * sin(a * x + i * h) - cos(i * h);
}
short getMin(const double *arr, short size) {
	short min = 0;
	double minVal = arr[0];
	forn(i, size) if(arr[i] < minVal) { minVal = arr[i]; min = i; }
	return min;
}
void removeAllNegAfterMin(double *arr, short *size) {
	short min = getMin(arr, *size);
	for (short i = min, j = min, n = *size; i < n; i++) {
		if (arr[i] < 0) {
			(*size)--;
			continue;
		}
		arr[j] = arr[i];
		j++;
	}
}
char insertMinAtZero(double *arr, short *size) {
	if (*size == 20) {
		printf("ERROR\ncannot insert new data in A, because max size is reached, no empty space");
		return 1;
	}
	forn(i, *size) arr[*size - i] = arr[*size - i - 1];
	(*size)++;
	short ind = getMin(arr, *size);
	arr[0] = arr[ind];
	return 0;
}
void replaceOddToZero(double *arr, short size) { forn(i, size) if (i % 2) arr[i] = 0; }

void printArr(const double *arr, short size) { forn(i, size) printf("%lf ", arr[i]); printf("\n"); }