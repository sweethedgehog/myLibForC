//
// Created by kripe on 24.09.2026.
//

#ifndef DEQUE_H
#define DEQUE_H
#include <stdlib.h>
#include <stdio.h>

#endif //DEQUE_H

#pragma once

typedef struct NodeDeque {
	long long data;
	struct NodeDeque* next, *prev;
} NodeDeque; // node for deque

NodeDeque* newNodeDeque(long long data, NodeDeque* next, NodeDeque* prev); // function for creating node

typedef struct Deque {
	NodeDeque* head;
	NodeDeque* tail;
	long long size;
} Deque; // deque struct

Deque* newDeque(); // function for creating deque

void pushFrontDeque(Deque* deque, long long data); // adding element in front of deque

long long popFrontDeque(Deque* deque); // extracting and deleting front element from deque

void pushBackDeque(Deque* deque, long long data); // adding element in back of deque

long long popBackDeque(Deque* deque); // extracting and deleting back element from deque

void deleteNodeDeque(NodeDeque* deque); // destructor for node

void deleteDeque(Deque* deque); // destructor for deque

void printNodeDeque(NodeDeque* nodeDeque); // recursive function for printing node data

void printDeque(Deque* deque); // print all deque data

Deque emptyDeque(); // create empty deque