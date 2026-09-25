//
// Created by kripe on 25.09.2026.
//

#include "Deque.h"

NodeDeque* newNodeDeque(long long data, NodeDeque* next, NodeDeque* prev) {
	NodeDeque* newNode = (NodeDeque*)malloc(sizeof(NodeDeque));
	newNode->data = data;
	newNode->next = next;
	newNode->prev = prev;
	return newNode;
}

Deque* newDeque() {
	Deque* newDeque = (Deque*)malloc(sizeof(Deque));
	newDeque->head = NULL;
	newDeque->tail = NULL;
	newDeque->size = 0;
	return newDeque;
}

void pushFrontDeque(Deque* deque, long long data) {
	NodeDeque* nodeDeque = newNodeDeque(data, deque->head, NULL);
	if (deque->head) deque->head->prev = nodeDeque;
	deque->head = nodeDeque;
	if (deque->tail == NULL) deque->tail = nodeDeque;
	deque->size++;
}

long long popFrontDeque(Deque* deque) {
	long long data = deque->head->data;
	NodeDeque* nodeDeque = deque->head;
	deque->head = nodeDeque->next;
	free(nodeDeque);
	deque->size--;
	return data;
}

void pushBackDeque(Deque* deque, long long data) {
	NodeDeque* nodeDeque = newNodeDeque(data, NULL, deque->tail);
	if(deque->tail) deque->tail->next = nodeDeque;
	deque->tail = nodeDeque;
	if (deque->head == NULL) deque->head = nodeDeque;
	deque->size++;
}

long long popBackDeque(Deque* deque) {
	long long data = deque->tail->data;
	NodeDeque* nodeDeque = deque->tail;
	deque->tail = nodeDeque->prev;
	free(nodeDeque);
	deque->size--;
	return data;
}

void deleteNodeDeque(NodeDeque* nodeDeque) {
	if (nodeDeque == NULL) return;
	deleteNodeDeque(nodeDeque->next);
	free(nodeDeque);
}

void deleteDeque(Deque* deque) {
	deleteNodeDeque(deque->head);
	free(deque);
}

void printNodeDeque(NodeDeque* nodeDeque) {
	if (nodeDeque == NULL) return;
	printf("%lld ", nodeDeque->data);
	printNodeDeque(nodeDeque->next);
}

void printDeque(Deque* deque) {
	printNodeDeque(deque->head);
	printf("\n");
}