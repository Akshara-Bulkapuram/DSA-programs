// C++ program to implement
// level order traversal
#include <bits/stdc++.h>
using namespace std;

// Given Node node
struct node {
	int key;
	struct node *left, *right;
};

// Function to create a new BST node
struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(
			sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Function to insert a new node with
// given key in BST
struct node* insert(struct node* node, int key)
{
	// If the tree is empty, return a new node
	if (node == NULL)
		return newNode(key);

	// Otherwise, recur down the tree
	if (key < node->key) {
		node->left = insert(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert(node->right, key);
	}

	// Return the node pointer
	return node;
}

// Returns height of the BST
int height(struct node* node)
{
	if (node == NULL)
		return 0;
	else {

		// Compute the depth of each subtree
		int lDepth = height(node->left);
		int rDepth = height(node->right);

		// Use the larger one
		if (lDepth > rDepth)
			return (lDepth + 1);
		else
			return (rDepth + 1);
	}
}

// Print nodes at a given level
void printGivenLevel(struct node* root,
					int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout <<" "<< root->key;
	else if (level > 1) {

		// Recursive Call
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

// Function to line by line print
// level order traversal a tree
void printLevelOrder(struct node* root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++) {
		printGivenLevel(root, i);
		cout <<"\n";
	}
}

// Driver Code
int main()
{
	/* Let us create following BST
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80
*/
	struct node* root = NULL;

	// Creating the BST
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	// Function Call
	printLevelOrder(root);

	return 0;
}