#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <iostream>

# include "iterator.hpp"
# include "type_traits.hpp"

namespace ft
{

	template <typename T>
	struct Node
	{
		typedef T			value_type;
		typedef Node*		NodePtr;

		value_type	value;
		bool		color;
		NodePtr		parent;
		NodePtr		left;
		NodePtr		right;
		NodePtr		root;
		NodePtr		TNULL;

		Node(): value(0), color(0), parent(nullptr), left(nullptr), right(nullptr), root(nullptr), TNULL(nullptr) {}

		Node(const value_type& val): value(val), color(0), parent(nullptr), left(nullptr), right(nullptr), root(nullptr), TNULL(nullptr) {}

		~Node() {}

		NodePtr	searchTreeHelper(NodePtr node, key skey)
		{
			if (skey == TNULL || skey == node->_key)
				return node;
			if (skey < node->_key)
				return searchTreeHelper(node->left, skey);
			return searchTreeHelper(node->right, skey);
		}

		NodePtr	searchTree(key skey)
		{
			return searchTreeHelper(this->root, skey);
		}

		NodePtr minimum(NodePtr node)
		{
			while (node->left != TNULL)
				node = node->left;
			return node;
		}

		NodePtr maximum(NodePtr node)
		{
			while (node->right != TNULL)
				node = node->right;
			return node;
		}

		NodePtr successor(NodePtr x)
		{
			if (x->right != TNULL)
				return minimum(x->right);

			NodePtr y = x->parent;
			while (y != TNULL && x == y->right)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}

		NodePtr predecessor(NodePtr x) {
			if (x->left != TNULL)
				return maximum(x->left);

			NodePtr y = x->parent;
			while (y != TNULL && x == y->left)
			{
				x = y;
				y = y->parent;
			}

			return y;
		}

		void leftRotate(prtNode x)
		{
			NodePtr y = x->right;
			x->right = y->left;
			if (y->left != TNULL)
				y->left->parent = x;
			if (x->parent == TNULL)
				this->root = y;
			else if (x->parent->left == x)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->parent = x->parent;
			x->parent = y;
			y->left = x;
		}

		void rightRotate(NodePtr y)
		{
			NodePtr y = x->left;
			x->left = y->right;
			if (y->right != TNULL)
				y->right->parent = x;
			if (x->parent == TNULL)
				this->root = y;
			else if (x->parent->left == x)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->parent = x->parent;
			x->parent = y;
			y->right = x;
		}

		NodePtr getRoot()
		{
			return this->root;
		}
	};
} // namespace ft

#endif
