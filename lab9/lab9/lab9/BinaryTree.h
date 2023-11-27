#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include<cmath>
#include<vector>
#include"Word.h"
using namespace std;

template<typename T>
struct TreeNode
{
	T value; // The value in the node
	TreeNode<T>* left; // Pointer to left child node
	TreeNode<T>* right; // Pointer to right child node
	int height;
};

// BinaryTree template
template < class T>
class BinaryTree
{
private:
	

	TreeNode<T>* root; // Pointer to the root node

	// Private member functions
	TreeNode<T>* insert(TreeNode<T>*&, TreeNode<T>*&);
	void destroySubTree(TreeNode<T>*);
	TreeNode<T>* deleteNode(T, TreeNode<T>*&);
	void makeDeletion(TreeNode<T>*&);
	void displayOrderAscending(TreeNode<T>*, vector<TreeNode<T>*>&) const;
	void displayOrderDescending(TreeNode<T>*, vector<TreeNode<T>*>&) const;
	void updateHeight(TreeNode<T>* );
	int height(TreeNode<T>*);
	int balanceFactor(TreeNode<T>*);
	TreeNode<T>* rotateLeft(TreeNode<T>*&);
	TreeNode<T>* rotateRight(TreeNode<T>*&);
	TreeNode<T>* rotateRightLeft(TreeNode<T>*);
	TreeNode<T>* rotateLeftRight(TreeNode<T>*);
	TreeNode<T>* rebalance(TreeNode<T>*);

	class AlreadyExistsError {};

public:
	// Constructor
	BinaryTree() { root = nullptr; }

	// Destructor
	~BinaryTree()
	{
		destroySubTree(root);
	}

	// Binary tree operations
	void insertNode(T);
	TreeNode<T>* searchNode(T);
	TreeNode<T>* remove(T);

	vector<TreeNode<T>*> displayOrderAscending() const 
	{ 
		vector<TreeNode<T>*> sorted_list;
		displayOrderAscending(root, sorted_list);
		return sorted_list;
	}
	vector<TreeNode<T>*> displayOrderDescending() const
	{
		vector<TreeNode<T>*> sorted_list;
		displayOrderDescending(root, sorted_list);
		return sorted_list;
	}
};

//*************************************************************
// insert accepts a TreeNode<T> pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by *
// the TreeNode<T> pointer. This function is called recursively. *
//*************************************************************
template < class T>
TreeNode<T>* BinaryTree<T>::insert(TreeNode<T>*& nodePtr, TreeNode<T>*& newNode)
{
	if (nodePtr == nullptr)
	{
		nodePtr = newNode; // Insert the node
	}
	else if (nodePtr->value == newNode->value)
	{
		throw AlreadyExistsError();
	}
	else if (newNode->value < nodePtr->value)
	{
		nodePtr->left = insert(nodePtr->left, newNode); // Search the left branch
	}
	else
	{
		nodePtr->right = insert(nodePtr->right, newNode); // Search the right branch
	}
	return rebalance(nodePtr);
}

//***********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function. *
//***********************************************************
template < class T>
void BinaryTree<T>::insertNode(T item)
{
	TreeNode<T>* newNode = nullptr; // Pointer to a new node

	// Create a new node and store num in it.
	newNode = new TreeNode<T>;
	newNode->value = item;
	newNode->height = 0;
	newNode->left = newNode->right = nullptr;

	// Insert the node.
	insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It *
// deletes all nodes in the tree. *
//***************************************************
template < class T>
void BinaryTree<T>::destroySubTree(TreeNode<T>* nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

//***************************************************
// searchNode determines if a value is present in *
// the tree. If so, the function returns true. *
// Otherwise, it returns false. *
//***************************************************
template < class T>
TreeNode<T>* BinaryTree<T>::searchNode(T item)
{
	TreeNode<T>* nodePtr = root;
	while (nodePtr)
	{
		if (nodePtr->value == item)
			return nodePtr;
		else if (item < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return nullptr;
}

//***********************************************
// remove calls deleteNode to delete the *
// // node whose value member is the same as num. *
//***********************************************
template < class T>
TreeNode<T>* BinaryTree<T>::remove(T item)
{
	deleteNode(item, root);
}

//********************************************
// deleteNode deletes the node whose value *
// member is the same as num. *
//********************************************
template < class T>
TreeNode<T>* BinaryTree<T>::deleteNode(T item, TreeNode<T>*& nodePtr)
{
	if (item < nodePtr->value)
	{
		deleteNode(item, nodePtr->left);
	}
	else if (item > nodePtr->value)
	{
		deleteNode(item, nodePtr->right);
	}
	else
	{
		makeDeletion(nodePtr);
	}
	return rebalance(nodePtr);
}

//***********************************************************
// makeDeletion takes a reference to a pointer to the node *
// that is to be deleted. The node is removed and the *
// branches of the tree below the node are reattached. *
//***********************************************************
template < class T>
void BinaryTree<T>::makeDeletion(TreeNode<T>*& nodePtr)
{
	// Define a temporary pointer to use in reattaching
	// the left subtree.
	TreeNode<T>* tempNodePtr = nullptr;
	if (nodePtr == nullptr)
		cout << "Cannot delete empty node.\n";
	else if (nodePtr->right == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left; // Reattach the left child
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right; // Reattach the right child
		delete tempNodePtr;
	}
	// If the node has two children.
	else
	{
		// Move one node to the right.
		tempNodePtr = nodePtr->right;
		// Go to the end left node.
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		// Reattach the left subtree.
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		// Reattach the right subtree.
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}


//*************************************************************
// The displayPostOrder member function displays the values *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//*************************************************************
template < class T>
void BinaryTree<T>::displayOrderAscending(TreeNode<T>* nodePtr, vector<TreeNode<T>*>& sorted_list) const
{
	if (nodePtr)
	{
		displayOrderAscending(nodePtr->left, sorted_list);
		displayOrderAscending(nodePtr->right, sorted_list);
		sorted_list.push_back(nodePtr);
	}
}
template < class T>
void BinaryTree<T>::displayOrderDescending(TreeNode<T>* nodePtr, vector<TreeNode<T>*>& sorted_list) const
{
	if (nodePtr)
	{
		displayOrderDescending(nodePtr->right, sorted_list);
		displayOrderDescending(nodePtr->left, sorted_list);
		sorted_list.push_back(nodePtr);
	}
}

/********************************************************
* Updates the height value of the node at the pointer	|
********************************************************/
template<typename T>
void BinaryTree<T>::updateHeight(TreeNode<T>* node) 
{
	node->height = max(height(node->left), height(node->right)) + 1;
}

template<typename T>
int BinaryTree<T>::height(TreeNode<T>* node) {
	return node == nullptr ? -1 : node->height;
}

template<typename T>
int BinaryTree<T>::balanceFactor(TreeNode<T>* node) 
	{ return height(node->right) - height(node->left); }

template <typename T>
TreeNode<T>* BinaryTree<T>::rotateLeft(TreeNode<T>*& node) // right single rotation
{
	
	TreeNode<T>* x = node->right;	// new subtree root
	TreeNode<T>* y = x->left;		// Left branch of new subtree root
	if (node == root)
		root = x;
	x->left = node;					// Set the new subtree root as x
	node->right = y;				// ??
	updateHeight(node); // update subtree heights
	updateHeight(x);
	return x;
}

template<class T>
TreeNode<T>* BinaryTree<T>::rotateRight(TreeNode<T>*& node)
{
	TreeNode<T>* x = node->left;	// new subtree root
	TreeNode<T>* y = x->right;		// Left branch of new subtree root
	if (node == root)
		root = x;
	x->right = node;					// Set the new subtree root as x
	node->left = y;				// ??
	updateHeight(node); // update subtree heights
	updateHeight(x);
	return x;
}
template<typename T>
TreeNode<T>* BinaryTree<T>::rotateRightLeft(TreeNode<T>* node) // right left double rotation
{
	node->right = rotateRight(node->right);
	return rotateLeft(node);
}

template<typename T>
TreeNode<T>* BinaryTree<T>::rotateLeftRight(TreeNode<T>* node) // left-right double rotation
{
	node->left = rotateLeft(node->left);
	return rotateRight(node);
}

template<typename T>
TreeNode<T>* BinaryTree<T>::rebalance(TreeNode<T>* node)
{
	int balance = balanceFactor(node);
	if (node == nullptr)
	{
		return node; // null - nothing to do
	} 
	if (balance < 0)  // left heavy?
	{
		if (height(node->left->left) >= height(node->left->right))
		{	// left-left heavy?
			node = rotateRight(node); // fix with single rotation
		}
		else
		{	// left-right heavy
			node = rotateLeftRight(node);
		}
	}
	else if (balance > 0)  // right heavy?
	{
		if (height(node->right->right) >= height(node->right->left))
		{ // right-right heavy?
			node = rotateLeft(node); // fix with single rotation
		}
		else // right-left heavy?
		{
			node = rotateRightLeft(node); // fix with double rotation
		}
	}
	updateHeight(node); // update node's height
	return node; // return link to updated subtree
}


#endif