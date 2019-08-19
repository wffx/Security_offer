#include "redblacktree.h"

RedBlackNode::RedBlackNode(int k)
{
	this->key = k;
	color = RED;
}

Tree::Tree()
{
	this->root = NULL;
	this->size = 0;
}

Tree::Tree(int k) {
	this->root = new RedBlackNode(k);
	this->size = 1;
}

Tree::~Tree()
{
	delete_node(root);
}

void Tree::delete_node(RedBlackNode* node) {
	if (node->left != NULL) {
		delete_node(node->left);
	}
	if (node->right != NULL) {
		delete_node(node->right);
	}
	delete(node);
}

void Tree::Insert(int k)
{
	RedBlackNode* node = new RedBlackNode(k);
	RedBlackNode* x = root;
	RedBlackNode* y = NULL;

	while (x != NULL) {
		y = x;
		if (node->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	node->parent = y;
	if (y == NULL) {
		root = node;
	}
	else if (node->key < y->key) {
		y->left = node;
	}
	else {
		y->right = node;
	}
	node->left = NULL;
	node->right = NULL;
	node->color = RED;
	size++;
	Insert_Fixup(node);
}

void Tree::Delete(int k)
{
	RedBlackNode* z = Search(k);
	RedBlackNode* y = z;
	RedBlackNode* x;
	
	if (z == NULL) {
		std::cout << "Not Exist!\n" << std::endl;
		return;
	}
	bool origin_color = y->color;

	if (z->left == NULL) {							// no left child
		x = z->left;
		Transplant(z, z->right);
	}
	else if (z->right == NULL) {					// left child, no right child
		x = z->left;
		Transplant(z, z->left);
	}
	else {											// left child and right child 
		y = Minimum(z->right);
		origin_color = y->color;
		x = y->right;
		if (x != NULL && y->parent == z) {			// y is right child of z, it is excess
			x->parent = z;
		}
		else {										// y is not right child of z
			Transplant(y, y->right);
			y->right = z->right;
			if (y->right != NULL) {
				y->right->parent = y;
			}
		}
		Transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	if (origin_color == BLACK) {
		Delete_Fixup(x);
	}
	size--;
	delete(z);
}

void Tree::Print()
{
	Print(root);
	std::cout << "\n";
}

void Tree::Print(RedBlackNode* node)
{
	if (node == NULL) return;
	if (node->left != NULL) {
		Print(node->left);
	}

	std::cout << node->key << "\t" << (node->color ? "Red" : "Black") << "\t" << (node->parent ? node->parent->key : -1) << "\t";
	if (node->left != NULL) {
		std::cout << node->left->key << "\t";
	}
	else {
		std::cout << "NULL" << "\t";
	}

	if (node->right != NULL) {
		std::cout << node->right->key << "\t";
	}
	else {
		std::cout << "NULL" << "\t";
	}

	//if (node->parent != NULL && node->parent->left == node) {
	//	std::cout << "Left";
	//}
	//else if (node->parent != NULL) {
	//	std::cout << "Right";
	//}
	//else {
	//	std::cout << "Root";
	//}
	std::cout << "\n";

	if (node->right != NULL) {
		Print(node->right);
	}
}

void Tree::Rotate(RedBlackNode* node, bool direction)
{
	RedBlackNode* temp;
	if (direction == LEFT) {							//left-rotate
		temp = node->right;
		node->right = temp->left;
		if (temp->left != NULL) {
			temp->left->parent = node;
		}
		temp->parent = node->parent;
		if (node->parent == NULL) {
			root = temp;
		}
		else if (node->parent->left == node) {
			node->parent->left = temp;
		}
		else {
			node->parent->right = temp;
		}
		temp->left = node;
		node->parent = temp;
	}
	else {												//right-rotate
		temp = node->left;
		node->left = temp->right;
		if (temp->right != NULL) {

			temp->right->parent = node;
		}
		temp->parent = node->parent;
		if (node->parent == NULL) {
			root = temp;
		}
		else if (node->parent->left == node) {
			node->parent->left = temp;
		}
		else {
			node->parent->right = temp;
		}
		temp->right = node;
		node->parent = temp;
	}
}

RedBlackNode* Tree::Search(int k, RedBlackNode* node)
{
	if (node->key == k) return node;
	if (node->left == NULL && node->right == NULL) {
		return NULL;		// leaf node, and not found yet
	}
	if (node->key > k && node->left != NULL) {
		//std::cout << node->left->key << "-->";
		Search(k, node->left);
	}
	else if(node->key <= k && node->right != NULL) {
		//std::cout << node->right->key << "-->";
		Search(k, node->right);
	}
}

RedBlackNode* Tree::Search(int k)
{
	return Search(k, root);
}

void Tree::Insert_Fixup(RedBlackNode* node)
{
	RedBlackNode* y;
	if (node->parent == NULL) {
		node->color = BLACK;
		return;
	}
	while (node->parent != NULL && node->parent->color == RED)
	{
		if (node->parent->parent != NULL && node->parent == node->parent->parent->left) {		// parent is left child 
			y = node->parent->parent->right;					// uncle node
			if (y != NULL && y->color == RED) {					//case 1, uncle is red
				node->parent->color = BLACK;
				y->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;					// note that node pointer has been raised 2 layers
			}
			else {
				if (node == node->parent->right) {				//case 2, uncle is black, node is right child
					node = node->parent;
					Rotate(node, LEFT);
				}
				if (node->parent != NULL) {
					node->parent->color = BLACK;				//case 3, uncle is black, node is left child
					node->parent->parent->color = RED;
					Rotate(node->parent->parent, RIGHT);
				}
			}
		}
		else if (node->parent->parent != NULL)					// node->parent == node->parent->parent->right, parent is right child
		{
			y = node->parent->parent->left;						// uncle node
			if (y != NULL && y->color == RED) {
				node->parent->color = BLACK;
				y->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;					// note that node pointer has been raised 2 layers
			}
			else {
				if (node == node->parent->left) {				// case 2, uncle is black, node is left child
					node = node->parent;
					Rotate(node, RIGHT);
				}
				if (node->parent != NULL) {
					node->parent->color = BLACK;				//case 3, uncle is black, node is right child
					node->parent->parent->color = RED;
					Rotate(node->parent->parent, LEFT);
				}
			}
		}
	}
	/*if (node->parent == NULL) {
		root = node->parent;*/
	root->color = BLACK;
	/*}*/
	return;
}

void Tree::Transplant(RedBlackNode* x, RedBlackNode* y)
{
	if (x->parent == NULL) {
		root = y;
	}
	else if (x == x->parent->left) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	if (y != NULL) {
		y->parent = x->parent;
	}
	
}

void Tree::Delete_Fixup(RedBlackNode* node)
{
	RedBlackNode* w;

	if (node == NULL) return;

	while (node != root && node->color == BLACK) {
		if (node == node->parent->left) {
			w = node->parent->right;		// bro node
			if (w->color == RED) {													
				w->color = BLACK;													// case 1
				node->parent->color = RED;											// case 1
				Rotate(node->parent, LEFT);											// case 1
				w = node->parent->right;											// case 1
			}
			if ((w->left->color == BLACK && w->right->color == BLACK)) {
				w->color = RED;														// case 2
				node = node->parent;												// case 2
			}
			else {
				if (w->right->color == BLACK) {
					w->left->color = BLACK;										// case 3
					w->color = RED;													// case 3
					Rotate(w, RIGHT);												// case 3
					w = node->parent->right;										// case 3
				}
				w->color = node->parent->color;										// case 4
				node->parent->color = BLACK;										// case 4
				w->right->color = BLACK;											// case 4
				Rotate(node->parent, LEFT);											// case 4
				node = root;														// case 4
			} 
		}
		else {
			w = node->parent->left;
			if (w->color == RED) {
				w->color = BLACK;
				node->parent->color = RED;
				Rotate(node->parent, RIGHT);
				w = node->parent->left;
			}
			if ((w->right->color == BLACK && w->left->color == BLACK)) {
				w->color = RED;
				node = node->parent;
			}
			else {
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					Rotate(w, LEFT);
					w = node->parent->left;
				}
				w->color = node->parent->color;
				node->parent->color = BLACK;
				w->left->color = BLACK;
				Rotate(node->parent, RIGHT);
				node = root;
			}
		}
	}
	node->color = BLACK;
}

RedBlackNode* Tree::Minimum(RedBlackNode* node)
{
	while (node->left != NULL) {
		node = node->left;
	}
	return node;
}


