//
// Created by kripe on 24.09.2026.
//

#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>

#endif //VECTOR_H

#pragma once

typedef struct Vector {
	long long size;
	long long capacity;
	long long *data;
} Vector; // vector struct

Vector *newVector(long long size); // function for creating vector

void deleteVector(Vector *vec); // function for creating vector

void removeVector(Vector *vec, long long index); // function far removing element by index

void resizeVector(Vector* vec); // function for multiplying size of vector

void pushBackVector(Vector *vec, long long value); // function for adding element in back of vector

long long getVector(Vector *vec, long long index); // function for getting element from vector (you also ca write vector->data[i])

void setVector(Vector *vec, long long index, long long value); // function for setting element to vector (you also ca write vector->data[i] = value)

void sort(long long* data, long long size); // function which sorting vector by mergesort

void radixSort(unsigned long long* data, long long size); // function which sorting vector by radix sort (only for N digits)