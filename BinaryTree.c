#include <stdlib.h>
#include "sort.h"
typedef struct BTree binaryTree;
struct BTree {
	int val;
	binaryTree* left;
	binaryTree* right;
};

int main() {

}

int find(binaryTree* tree, int value) {
	if (tree == NULL)
		return 0;
	if (tree->val == value)
		return 1;
	if (tree->val >= value)
		return find(tree->left, value);
	return find(tree->right, value);
}

void insert(binaryTree* tree, int toInsert) {
	if (tree == NULL) {
		tree->left = NULL;
		tree->right = NULL;
		tree->val = toInsert;
	}
	if (toInsert > tree->val) {
		insert(tree->right, toInsert);
	} else {
		insert(tree->left, toInsert);
	}
}

binaryTree* build(int* arr, int size) {
	inPlaceQuickSort(arr, size);
	printf("hehe");
}
