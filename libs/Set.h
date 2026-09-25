//
// Created by kripe on 24.09.2026.
//

#ifndef SET_H
#define SET_H
#include <stdio.h>
#include <stdlib.h>

#endif //SET_H

#pragma once

typedef struct NodeSet {
	long long data;
	long long key;
	struct NodeSet* left;
	struct NodeSet* right;
} NodeSet; // node struct for set

typedef struct NodePair {
	NodeSet* l,* r;
} NodeSetPair; // pair of nodes for set

typedef struct Set {
	NodeSet* root;
	long long size;
} Set; // set struct

Set* newSet(); // function for creating new set

NodeSet* newNodeSet(long long data, NodeSet* left, NodeSet* right); // function for creating pair of nodes

void deleteTree(NodeSet* node); // recursive function for destruction nodes

void deleteSet(Set* set); // function for destruction set

_Bool findInTree(NodeSet* root, long long a); // recursive function for searching for element

_Bool findSet(Set* set, long long a); // function for searching in set

NodeSet* upper(NodeSet* root); // function for getting biggest element in tree

NodeSet* lower(NodeSet* root); // function for getting smallest element in tree

NodeSetPair setNodePair(NodeSet* l, NodeSet* r); // function for creating noed pair and returning it

NodeSetPair split(NodeSet* root, long long a); // recursive function for splitting tree in two by a

NodeSet* merge(NodeSet* left, NodeSet* right); // recursive function for merging two trees in one

void insert(Set* set, long long a); // function for inserting new element in set

NodeSet* removeNodeSet(NodeSet* root, long long a);  // recursive function for removing element in tree

void removeSet(Set* set, long long a); // function for deleting element in set

void printNodes(NodeSet* root); // recursive function for printing nodes and his children

void printSet(Set* set); // function for printing set