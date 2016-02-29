#include <iostream>
#include "Node.h"

using namespace std;

void balanceTree(Node * &node);
void rotateRight(Node * &node);
void rotateLeftRight(Node * &node);
void rotateLeft(Node * &node);
void rotateRightLeft(Node * &node);
int getHeight(Node* root);


/*
*/
Node* insert(Node* root, int val)
{

	if (root == nullptr)
		return new Node(val, nullptr, nullptr);
	else if (val > root->val)
		root->right = insert(root->right, val);
	else if (val < root->val)
		root->left = insert(root->left, val);
	else
		return root;

	balanceTree(root);
	return root;
}

/***************************************************************************//**
@author wizage
@date Feb, 28 2016
@brief Recusively gets the height of a node

@param[in, out] node - the node that is out of balance
*******************************************************************************/
int getHeight(Node* root)
{
	if (root == nullptr) return -1;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}

/***************************************************************************//**
@author wizage
@date Feb, 28 2016
@brief Rebalances the tree

@param[in, out] node - the node that is out of balance
*******************************************************************************/
void balanceTree(Node *&node)
{
	if (node == nullptr)
		return;
	if (getHeight(node->right) - getHeight(node->left) > 1)
	{
		if(getHeight(node->right->right) >= getHeight(node->right->left))
		{
			rotateRight(node);
		}
		else{
			rotateLeftRight(node);
		}
	}
	else if(getHeight(node->left) - getHeight(node->right) > 1)
	{
		if(getHeight(node->left->left) >= getHeight(node->left->right))
		{
			rotateLeft(node);
		}
		else{
			rotateRightLeft(node);
		}

	}
	if(getHeight(node->left) > getHeight(node->right))
		node->ht = getHeight(node->left) + 1;
	else
		node->ht = getHeight(node->right) + 1;
}


/***************************************************************************//**
@author wizage
@date Feb, 28 2016
@brief Preforms a single right rebalance of the root

@param[in, out] node - the node that is out of balance
*******************************************************************************/
void rotateRight(Node * &node)
{
	Node *temp = node->right;
	node->right = temp->left;
	temp->left = node;
	node->ht = max(getHeight(node->left), getHeight(node->right));
	temp->ht = max(getHeight(temp->left), getHeight(temp->right));
	node = temp;
}

/***************************************************************************//**
@author wizage
@date Feb, 28 2016
@brief Preforms a left right rebalance of the root

@param[in, out] node - the node that is out of balance
*******************************************************************************/
void rotateLeftRight(Node *&node)
{
	rotateLeft(node->right);
	rotateRight(node);
}

/***************************************************************************//**
@author wizage
@date Feb, 28 2016
@brief Preforms a single left rebalance of the root

@param[in, out] node - the node that is out of balance
*******************************************************************************/
void rotateLeft(Node * &node)
{
	Node *temp = node->left;
	node->left = temp->right;
	temp->right = node;
	node->ht = max(getHeight(node->left), getHeight(node->right));
	temp->ht = max(getHeight(temp->left), getHeight(temp->right));
	node = temp;
}

/***************************************************************************//**
@author wizage
@date Feb, 28 2016
@brief Preforms a right left rebalance of the root

@param[in, out] node - the node that is out of balance
*******************************************************************************/
void rotateRightLeft(Node *&node)
{
	rotateRight(node->left);
	rotateLeft(node);
}