// #include "libs/allKirills.h"
#include <stdio.h>

#include "arrays.h"

int main(void) {
	double arrA[ARRAY_CAPACITY], arrB[ARRAY_CAPACITY];
	short sizeA = readArr(arrA);
	if (!sizeA) return 1;
	short sizeB = getSize('B');
	if (!sizeB) return 1;
	double a, x, h;
	if (!readParams(&a, &x, &h)) return 1;

	makeB(arrB, sizeB, a, x, h);
	printf("Array A:\n");
	printArr(arrA, sizeA);
	printf("Array B:\n");
	printArr(arrB, sizeB);

	removeAllNegAfterMin(arrB, &sizeB);
	printf("Array B after deleting:\n");
	printArr(arrB, sizeB);

	if (insertMinAtZero(arrA, &sizeA)) return 1;
	printf("Array A after inserting:\n");
	printArr(arrA, sizeA);

	replaceOddToZero(arrA, sizeA);
	printf("Array A after replacing:\n");
	printArr(arrA, sizeA);

	printf("that is all!\nhave a good day! :)");

	return 0;
}
