//
// Created by kripe on 25.09.2026.
//
#include "Set.h"

Set* newSet() {
	Set* set = (Set*)malloc(sizeof(Set));
	set->root = NULL;
	set->size = 0;
	return set;
}

NodeSet* newNodeSet(long long data, NodeSet* left, NodeSet* right) {
	NodeSet* node = (NodeSet*)malloc(sizeof(NodeSet));
	node->data = data;
	node->left = left;
	node->right = right;
	node->key = rand();
	return node;
}

void deleteTree(NodeSet* node) {
	if (node == NULL) return;
	if (node->left) deleteTree(node->left);
	if (node->right) deleteTree(node->right);
}

void deleteSet(Set* set) {
	deleteTree(set->root);
	free(set);
}

_Bool findInTree(NodeSet* root, long long a) {
	if (root == NULL) return 0;
	if (a == root->data) return 1;
	if (root->data > a) return findInTree(root->left, a);
	return findInTree(root->right, a);
}

_Bool findSet(Set* set, long long a) { return findInTree(set->root, a); }

NodeSet* upper(NodeSet* root) {
	if (root == NULL) return NULL;
	NodeSet* buf = upper(root->right);
	if (!buf) return root;
	return buf;
}

NodeSet* lower(NodeSet* root) {
	if (root == NULL) return NULL;
	NodeSet* buf = lower(root->left);
	if (!buf) return root;
	return buf;
}

NodeSetPair setNodePair(NodeSet* l, NodeSet* r) {
	NodeSetPair nodePair;
	nodePair.l = l;
	nodePair.r = r;
	return nodePair;
}

NodeSetPair split(NodeSet* root, long long a) {
	if (root == NULL) return setNodePair(NULL, NULL);
	if (root->data <= a) {
		NodeSetPair buf = split(root->right, a);
		NodeSet* left = buf.l, *right = buf.r;
		root->right = left;
		return setNodePair(root, right);
	}
	NodeSetPair buf = split(root->left, a);
	NodeSet* left = buf.l, *right = buf.r;
	root->left = right;
	return setNodePair(left, root);
}

NodeSet* merge(NodeSet* left, NodeSet* right) {
	if (left == NULL) return right;
	if (right == NULL) return left;
	if (left->key > right->key) {
		left->right = merge(left->right, right);
		return left;
	}
	right->left = merge(left, right->left);
	return right;
}

void insert(Set* set, long long a) {
	if (findInTree(set->root, a)) return;
	set->size++;
	NodeSetPair buf = split(set->root, a);
	NodeSet* node = newNodeSet(a, NULL, NULL);
	set->root = merge(merge(buf.l, node), buf.r);
}

NodeSet* removeNodeSet(NodeSet* root, long long a) {
	if (!root) return NULL;
	if (root->data == a) {
		NodeSet* buf = merge(root->left, root->right);
		free(root);
		return buf;
	}
	if (root->data < a) root->right = removeNodeSet(root->right, a);
	else root->left = removeNodeSet(root->left, a);
	return root;
}

void removeSet(Set* set, long long a) { set->root = removeNodeSet(set->root, a); }

void printNodes(NodeSet* root) {
	if (root == NULL) return;
	printNodes(root->left);
	printf("%lld ", root->data);
	printNodes(root->right);
}

void printSet(Set* set) {
	printNodes(set->root);
	printf("\n");
}