#include <stdlib.h>
typedef struct BTree binaryTree;
struct BTree {
	int val;
	binaryTree* left;
	binaryTree* right;
};

int main() {
	
}

int find(binaryTree* tree, int value) {
	
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
