//
// Created by kripe on 25.09.2026.
//
#include "Vector.h"

Vector *newVector(long long size) {
	Vector* vec = (Vector*)malloc(sizeof(Vector));
	if (vec == NULL) return NULL;

	vec->size = size;
	vec->capacity = size + 1;
	vec->data = (long long*)malloc(vec->capacity * sizeof(long long));
	if (vec->data == NULL) return NULL;
	return vec;
}

void deleteVector(Vector *vec) {
	free(vec->data);
	free(vec);
}

void removeVector(Vector *vec, long long index) {
	for (long long i = index; i < vec->size - 1; i++) vec->data[i] = vec->data[i + 1];
	vec->size--;
}

void resizeVector(Vector* vec) {
	long long* old = vec->data;
	vec->capacity *= 2;
	long long* newData = (long long*)malloc(vec->capacity * sizeof(long long));;
	vec->data = newData;
	for (int i = 0; i < vec->size; i++) vec->data[i] = old[i];
	free(old);
}

void pushBackVector(Vector *vec, long long value) {
	if (vec->capacity == vec->size) resizeVector(vec);
	vec->data[vec->size] = value;
	vec->size++;
}

long long getVector(Vector *vec, long long index) { return vec->data[index]; }

void setVector(Vector *vec, long long index, long long value) { vec->data[index] = value; }

void sort(long long* data, long long size) {
	if (size <= 1) return;
	long long mid = size / 2;
	sort(data, mid);
	sort(data + mid, size - mid);
	long long *buf = (long long*)malloc(size * sizeof(long long));
	for (int i = 0, j = mid, k = 0; i + j < size + mid; k++) {
		if (i < mid) {
			if (j >= size || data[i] < data[j]) {
				buf[k] = data[i];
				i++;
			}
			else {
				buf[k] = data[j];
				j++;
			}
		}
		else {
			buf[k] = data[j];
			j++;
		}
	}
	for (int i = 0; i < size; i++) data[i] = buf[i];
	free(buf);
}