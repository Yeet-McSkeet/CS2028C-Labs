#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include<cmath>
using namespace std;

template<typename T>
struct TreeNode
{
	T value; // The value in the node
	int frequency;
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
	void deleteNode(T, TreeNode<T>*&);
	void makeDeletion(TreeNode<T>*&);
	void displayInOrder(TreeNode<T>*) const;
	void displayPreOrder(TreeNode<T>*) const;
	void displayPostOrder(TreeNode<T>*) const;
	void updateHeight(TreeNode<T>* );
	int height(TreeNode<T>*);
	int balanceFactor(TreeNode<T>*);
	TreeNode<T>* rotateLeft(TreeNode<T>*);
	TreeNode<T>* rotateRight(TreeNode<T>*);
	TreeNode<T>* rotateRightLeft(TreeNode<T>*);
	TreeNode<T>* rotateLeftRight(TreeNode<T>*);
	TreeNode<T>* rebalance(TreeNode<T>*);

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
	bool searchNode(T);
	void remove(T);

	void displayInOrder() const { displayInOrder(root); }
	void displayPreOrder() const { displayPreOrder(root); }
	void displayPostOrder() const { displayPostOrder(root); }
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
	else if (newNode->value == nodePtr->value)
	{	// Item already exists, frequency updated
		++nodePtr->frequency;
		return nullptr;
	}
	else if (newNode->value < nodePtr->value)
	{
		insert(nodePtr->left, newNode); // Search the left branch
	}
	else
	{
		insert(nodePtr->right, newNode); // Search the right branch
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
bool BinaryTree<T>::searchNode(T item)
{
	TreeNode<T>* nodePtr = root;
	while (nodePtr)
	{
		if (nodePtr->value == item)
			return true;
		else if (item < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

//***********************************************
// remove calls deleteNode to delete the *
// // node whose value member is the same as num. *
//***********************************************
template < class T>
void BinaryTree<T>::remove(T item)
{
	deleteNode(item, root);
}

//********************************************
// deleteNode deletes the node whose value *
// member is the same as num. *
//********************************************
template < class T>
void BinaryTree<T>::deleteNode(T item, TreeNode<T>*& nodePtr)
{
	if (item < nodePtr->value)
		deleteNode(item, nodePtr->left);
	else if (item > nodePtr->value)
		deleteNode(item, nodePtr->right);
	else
		makeDeletion(nodePtr);
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
// The displayInOrder member function displays the values *
// in the subtree pointed to by nodePtr, via inorder traversal. *
//*************************************************************
template < class T>
void BinaryTree<T>::displayInOrder(TreeNode<T>* nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

//*************************************************************
// The displayPreOrder member function displays the values *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//*************************************************************
template < class T>
void BinaryTree<T>::displayPreOrder(TreeNode<T>* nodePtr) const
{
	if (nodePtr)
	{
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

//*************************************************************
// The displayPostOrder member function displays the values *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//*************************************************************
template < class T>
void BinaryTree<T>::displayPostOrder(TreeNode<T>* nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}

/********************************************************
* Updates the height value of the node at the pointer	|
********************************************************/
template<typename T>
void BinaryTree<T>::updateHeight(TreeNode<T>* node) 
{
	node.height = max(height(node.left), height(node.right)) + 1;
}

template<typename T>
int BinaryTree<T>::height(TreeNode<T>* node) {
	return node == nullptr ? -1 : node.height;
}

template<typename T>
int BinaryTree<T>::balanceFactor(TreeNode<T>* node) 
	{ return height(node->right) - height(node->left); }

template <typename T>
TreeNode<T>* BinaryTree<T>::rotateLeft(TreeNode<T>* node) // right single rotation
{
	TreeNode<T>* nodeLeft = node->right;
	node->right = nodeLeft->left; // swap inner child
	nodeLeft->left = node; // bring nodeLeft above node
	updateHeight(node); // update subtree heights
	updateHeight(nodeLeft);
	return nodeLeft;
}

template<class T>
TreeNode<T>* BinaryTree<T>::rotateRight(TreeNode<T>* node)
{
	TreeNode<T>* nodeRight = node->left;
	node->left = nodeRight->right; // swap inner child
	nodeRight->right = node; // bring nodeRight above node
	updateHeight(node); // update subtree heights
	updateHeight(nodeRight);
	return nodeRight;
}
template<typename T>
TreeNode<T>* BinaryTree<T>::rotateRightLeft(TreeNode<T>* node) // right left double rotation
{
	node->right = TreeNode<T>::rotateLeft(node->right);
	return rotateLeft(node);
}

template<typename T>
TreeNode<T>* BinaryTree<T>::rotateLeftRight(TreeNode<T>* node) // left-right double rotation
{
	node->left = rotateRight(node->left);
	return rotateRight(node);
}

template<typename T>
TreeNode<T>* BinaryTree<T>::rebalance(TreeNode<T>* node)
{
	if (node == nullptr)
	{
		return node; // null - nothing to do
	}
	if (balanceFactor(node) < 1)  // left heavy?
	{

		if (height(node->left->left) >= height(node->left->right)) // left-left heavy?
		{
			node = rotateRight(node); // fix with single rotation
		}
		else if (balanceFactor(node) > 1)  // right heavy?
		{
			if (height(node->right->right) >= height(node->right->left))
			{ // right-right heavy?
				node = rotateLeft(node); // fix with single rotation
			}
			else // right-left heavy?
			{
				node = rotateRightLeft(node); // fix with double rotation
			}
			updateHeight(node); // update node's height
			return node; // return link to updated subtree
		}

		else // left-right heavy?
		{
			node = rotateLeftRight(node); // fix with double rotation
		}
	}
}


#endif