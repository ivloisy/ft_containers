#ifndef RB_TREE_HPP

# define RB_TREE_HPP

# include <iostream>
# include "iterator.hpp"
# include "type_traits.hpp"

namespace ft
{

	enum tree_color { _S_red = false, _S_black = true };

	struct rb_tree
	{

		// struct Node {
		//   int data;
		//   Node *parent;
		//   Node *left;
		//   Node *right;
		//   int color;
		// };

		struct node_base
		{
			typedef node_base*			ptr_base;
			typedef const node_base*	const_ptr_base;

			tree_color	_color;
			ptr_base	_parents;
			ptr_base	_left;
			ptr_base	_right;
		};

		template <typename value>
		struct node : public node_base
		{
			typedef node<value>*	link;
			value					_value;
		};

		class RedBlackTree
		{
		   private:
			   NodePtr searchTreeHelper(NodePtr node, int key) {
			     if (node == TNULL || key == node->data) {
			       return node;
			     }

			     if (key < node->data) {
			       return searchTreeHelper(node->left, key);
			     }
			     return searchTreeHelper(node->right, key);
			   }
		   public:
			   NodePtr minimum(NodePtr node) {
			     while (node->left != TNULL) {
			       node = node->left;
			     }
			     return node;
			   }

			   NodePtr maximum(NodePtr node) {
			     while (node->right != TNULL) {
			       node = node->right;
			     }
			     return node;
			   }

			   NodePtr successor(NodePtr x)
			   {
			     if (x->right != TNULL)
			 	{
			       return minimum(x->right);
			     }

			     NodePtr y = x->parent;
			     while (y != TNULL && x == y->right)
			 	{
			       x = y;
			       y = y->parent;
			     }
			     return y;
			   }

			   NodePtr predecessor(NodePtr x) {
			     if (x->left != TNULL) {
			       return maximum(x->left);
			     }

			     NodePtr y = x->parent;
			     while (y != TNULL && x == y->left) {
			       x = y;
			       y = y->parent;
			     }

			     return y;
			   }

			   void leftRotate(NodePtr x) {
			     NodePtr y = x->right;
			     x->right = y->left;
			     if (y->left != TNULL) {
			       y->left->parent = x;
			     }
			     y->parent = x->parent;
			     if (x->parent == nullptr) {
			       this->root = y;
			     } else if (x == x->parent->left) {
			       x->parent->left = y;
			     } else {
			       x->parent->right = y;
			     }
			     y->left = x;
			     x->parent = y;
			   }

			   void rightRotate(NodePtr x) {
			     NodePtr y = x->left;
			     x->left = y->right;
			     if (y->right != TNULL) {
			       y->right->parent = x;
			     }
			     y->parent = x->parent;
			     if (x->parent == nullptr) {
			       this->root = y;
			     } else if (x == x->parent->right) {
			       x->parent->right = y;
			     } else {
			       x->parent->left = y;
			     }
			     y->right = x;
			     x->parent = y;
			   }

			   NodePtr getRoot() {
			     return this->root;
			   }

			   void deleteNode(int data) {
				 deleteNodeHelper(this->root, data);
			   }
	   };
	};

} // namespace ft

#endif
