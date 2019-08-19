#pragma once

#include <iostream>
#include <vector>

#define RED 1
#define BLACK 0

#define LEFT 1
#define RIGHT 0

struct  RedBlackNode
{
	bool color;
	int key;
	RedBlackNode* left = NULL;
	RedBlackNode* right = NULL;
	RedBlackNode* parent = NULL;

	RedBlackNode(int k);
};

class Tree
{
public:
	Tree();
	Tree(int k);
	~Tree();
	void Insert(int k);
	void Delete(int k);
	void Print();
	void Print(RedBlackNode* node);
	RedBlackNode* Search(int k);
	
	
private:
	RedBlackNode* root;
	int size;
	void delete_node(RedBlackNode* node);
	void Rotate(RedBlackNode* node, bool direction);
	void Insert_Fixup(RedBlackNode* node);
	void Transplant(RedBlackNode* x, RedBlackNode* y);
	void Delete_Fixup(RedBlackNode* node);
	RedBlackNode* Minimum(RedBlackNode* node);
	RedBlackNode* Search(int k, RedBlackNode* node);

};