#ifndef RB_TREE_HPP

# define RB_TREE_HPP

# include <iostream>
# include "iterator.hpp"
# include "type_traits.hpp"
# include "utility.hpp"

namespace ft
{


	template <typename value>
	class node_base
	{

		public:
			typedef node_base*			ptr_base;
			typedef const node_base*	const_ptr_base;
			bool		_color;
			ptr_base	_parent;
			ptr_base	_left;
			ptr_base	_right;
			value		_value;
		private:
			ptr_base* null(ptr_base x) const
			{
				node_base* _tmp = x;
				while ( _tmp->_right )
				_tmp = _tmp->_right;
				return _tmp;
			}
		public:
			node_base(void): _color(0), _parent(NULL), _left(NULL), _right(NULL), _value(value()) {}
			node_base(const value& v): _color(0), _parent(NULL), _left(NULL), _right(NULL), _value(v) {}
			node_base(const node_base& src):
			_color(src._color), _parent(src._parent), _left(src._left), _right(src._right), _value(src._value) {}

			value & getPair() { return this->_value; }

			// ptr_base successor(ptr_base x) const
			// {
			// 	if (x->_right != null())
			// 		return minimum(x->_right);
			// 	ptr_base y = x->_parent;
			// 	while (y != null() && x == y->_right)
			// 	{
			// 		x = y;
			// 		y = y->_parent;
			// 	}
			// 	return y;
			// }
			//
			// ptr_base predecessor(ptr_base x) const
			// {
			// 	if (x->_left != null())
			// 		return maximum(x->_left);
			// 	ptr_base y = x->_parent;
			// 	while (y != null() && x == y->_left)
			// 	{
			// 		x = y;
			// 		y = y->_parent;
			// 	}
			//
			// 	return y;
			// }
			//
			// ptr_base minimum(ptr_base node) const
			// {
			// 	while (node->_left != null())
			// 		node = node->_left;
			// 	return node;
			// }
			//
			// ptr_base maximum(ptr_base node) const
			// {
			// 	while (node->_right != null())
			// 		node = node->_right;
			// 	return node;
			// }
			//
			// const_ptr_base minimum(const_ptr_base node) const
			// {
			// 	while (node->_left != null())
			// 		node = node->_left;
			// 	return node;
			// }
			//
			// const_ptr_base maximum(const_ptr_base node) const
			// {
			// 	while (node->_right != null())
			// 		node = node->_right;
			// 	return node;
			// }


	};

	template<typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc = std::allocator<node_base<_Val> > >
	class rb_tree
	{

		protected:
			typedef ft::node_base<_Val>												base;
			typedef ft::node_base<_Val>*											ptr_base;
			typedef const ft::node_base<_Val>*										constPtr_base;
			typedef _Key														key_type;
			typedef _Val														value_type;
			typedef value_type*													pointer;
			typedef const value_type*											const_pointer;
			typedef value_type&													reference;
			typedef const value_type&											const_reference;
			typedef size_t														size_type;
			typedef std::ptrdiff_t													difference_type;
			typedef _Alloc														allocator_type;

		private:
			ptr_base root;
			ptr_base TNULL;
			allocator_type _alloc;
			size_type	_size;

			void rbTransplant(ptr_base u, ptr_base v)
			{
				if (u->_parent == TNULL)
					root = v;
				else if (u == u->_parent->_left)
					u->_parent->_left = v;
				else
					u->_parent->_right = v;
				v->_parent = u->_parent;
			}

			int deleteNodeHelper(ptr_base node, _Key key)
			{
				ptr_base z = TNULL;
				ptr_base x, y;
				while (node != TNULL)
				{
					if (node->_value.first == key)
						z = node;
					if (node->_value.first <= key)
						node = node->_right;
					else
						node = node->_left;
				}

				if (z == TNULL)
				{
					std::cout << "Key not found in the tree" << std::endl;
					return 0;
				}
				this->_size--;
				y = z;
				int y_original_color = y->_color;
				if (z->_left == TNULL)
				{
					x = z->_right;
					rbTransplant(z, z->_right);
				}
				else if (z->_right == TNULL)
				{
					x = z->_left;
					rbTransplant(z, z->_left);
				}
				else
				{
					y = minimum(z->_right);
					y_original_color = y->_color;
					x = y->_right;
					if (y->_parent == z)
						x->_parent = y;
					else
					{
						rbTransplant(y, y->_right);
						y->_right = z->_right;
						y->_right->_parent = y;
					}

					rbTransplant(z, y);
					y->_left = z->_left;
					y->_left->_parent = y;
					y->_color = z->_color;
				}
				delete z;
				if (y_original_color == 0) {
				  deleteFix(x);
				}
				return 1;
			}

			void insertFix(ptr_base k)
			{
				ptr_base u;
				while (k->_parent->_color == 1)
				{
					if (k->_parent == k->_parent->_parent->_right)
					{
						u = k->_parent->_parent->_left;
						if (u->_color == 1)
						{
							u->_color = 0;
							k->_parent->_color = 0;
							k->_parent->_parent->_color = 1;
							k = k->_parent->_parent;
						}
						else
						{
							if (k == k->_parent->_left)
							{
								k = k->_parent;
								rightRotate(k);
							}
							k->_parent->_color = 0;
							k->_parent->_parent->_color = 1;
							leftRotate(k->_parent->_parent);
						}
					}
					else
					{
						u = k->_parent->_parent->_right;

						if (u->_color == 1)
						{
							u->_color = 0;
							k->_parent->_color = 0;
							k->_parent->_parent->_color = 1;
							k = k->_parent->_parent;
						}
						else
						{
							if (k == k->_parent->_right)
							{
								k = k->_parent;
								leftRotate(k);
							}
							k->_parent->_color = 0;
							k->_parent->_parent->_color = 1;
							rightRotate(k->_parent->_parent);
						}
					}
					if (k == root)
						break;
				}
				root->_color = 0;
			}

			void deleteFix(ptr_base x)
			{
				ptr_base s;
				while (x != root && x->_color == 0)
				{
					if (x == x->_parent->_left)
					{
						s = x->_parent->_right;
						if (s->_color == 1)
						{
							s->_color = 0;
							x->_parent->_color = 1;
							leftRotate(x->_parent);
							s = x->_parent->_right;
						}

						if (s->_left->_color == 0 && s->_right->_color == 0)
						{
							s->_color = 1;
							x = x->_parent;
						}
						else
						{
							if (s->_right->_color == 0)
							{
								s->_left->_color = 0;
								s->_color = 1;
								rightRotate(s);
								s = x->_parent->_right;
							}

							s->_color = x->_parent->_color;
							x->_parent->_color = 0;
							s->_right->_color = 0;
							leftRotate(x->_parent);
							x = root;
						}
					}
					else
					{
						s = x->_parent->_left;
						if (s->_color == 1)
						{
							s->_color = 0;
							x->_parent->_color = 1;
							rightRotate(x->_parent);
							s = x->_parent->_left;
						}

						if (s->_right->_color == 0 && s->_right->_color == 0)
						{
							s->_color = 1;
							x = x->_parent;
						}
						else
						{
							if (s->_left->_color == 0)
							{
								s->_right->_color = 0;
								s->_color = 1;
								leftRotate(s);
								s = x->_parent->_left;
							}

							s->_color = x->_parent->_color;
							x->_parent->_color = 0;
							s->_left->_color = 0;
							rightRotate(x->_parent);
							x = root;
						}
					}
				}
				x->_color = 0;
			}

			ptr_base searchTreeHelper(ptr_base node, _Key key)
			{
				if (node == TNULL || key == node->_value.first)
				{
					return node;
				}

				if (key < node->_value.first)
				{
					return searchTreeHelper(node->_left, key);
				}
				return searchTreeHelper(node->_right, key);
			}

			ptr_base searchTreeHelper(ptr_base node, _Key key) const
			{
				if (node == TNULL || key == node->_value.first)
				{
					return node;
				}

				if (key < node->_value.first)
				{
					return searchTreeHelper(node->_left, key);
				}
				return searchTreeHelper(node->_right, key);
			}


			ft::rb_tree_iterator<_Val, base> checkIfExistP(ptr_base node, _Key key)
			{
				if (node == TNULL || key == node->_value.first)
					return ft::rb_tree_iterator<_Val, base>(node);
				if (key < node->_value.first)
					return checkIfExistP(node->_left, key);
				return checkIfExistP(node->_right, key);
			}

			ft::rb_tree_iterator<_Val, base> checkIfExistP(ptr_base node, _Key key) const
			{
				if (node == TNULL || key == node->_value.first)
					return ft::rb_tree_iterator<_Val, base>(node);
				if (key < node->_value.first)
					return checkIfExistP(node->_left, key);
				return checkIfExistP(node->_right, key);
			}

			ptr_base keyIsExist(ptr_base node, _Key key) const
			{
				if (node == TNULL || key == node->_value.first)
					return node;
				if (key < node->_value.first)
					return keyIsExist(node->_left, key);
				return keyIsExist(node->_right, key);
			}

		public:

		/* =========================== Constructors/Destructors ========================= */

		ptr_base searchTreeHelper(_Key key) const
		{
			ptr_base node = this->getRoot();
			if (node == TNULL || key == node->_value.first)
			{
				return node;
			}
			if (key < node->_value.first)
				return this->searchTreeHelper(node->_left, key);
			return this->searchTreeHelper(node->_right, key);
		}

		rb_tree()
		{
			TNULL = _alloc.allocate(1);
			_alloc.construct(TNULL, base());
			root = TNULL;
			_size = 0;
		}

		rb_tree(const _Compare& comp, const allocator_type& a = allocator_type())
		{
			(void)comp;
			(void)a;
			TNULL = _alloc.allocate(1);
			_alloc.construct(TNULL, base());
			root = TNULL;
			_size = 0;
		}

		~rb_tree()
		{
			this->_alloc.destroy(TNULL);
			this->_alloc.deallocate(TNULL, 1);
		}

		ft::pair<rb_tree_iterator<_Val, base>, bool>
		insert(const _Val& v)
		{
			ft::pair<rb_tree_iterator<_Val, base>, bool> it;
			ft::pair<int, int> test;
			if ((it.first = checkIfExistP(this->root, v.first)) != ft::rb_tree_iterator<_Val, base>(TNULL))
			{
				it.second = false;
				return (it);
			}
			this->_size++;
			ptr_base node = this->_alloc.allocate(1);
			this->_alloc.construct(node, base(v));
			node->_parent = TNULL;
			node->_left = TNULL;
			node->_right = TNULL;
			node->_color = true;

			ptr_base y = TNULL;
			ptr_base x = this->root;

			while (x != TNULL)
			{
				y = x;
				if (node->_value < x->_value)
					x = x->_left;
				else
					x = x->_right;
			}

			node->_parent = y;
			if (y == TNULL)
				root = node;
			else if (node->_value < y->_value)
				y->_left = node;
			else
				y->_right = node;

			if (node->_parent == TNULL)
			{
				node->_color = 0;
				it.first = rb_tree_iterator<_Val, base>(y);
				it.second = true;
				return (it);
			}

			if (node->_parent->_parent == TNULL)
			{
				it.first = ft::rb_tree_iterator<_Val, base>(y);
				it.second = true;
				return (it);
			}

			insertFix(node);

			it.first = ft::rb_tree_iterator<_Val, base>(node);
			it.second = true;
			return (it);
		}

		ptr_base successor(ptr_base x)
		{
			if (x == TNULL)
				return minimum(getRoot());
			if (x->_right != TNULL)
				return minimum(x->_right);
			ptr_base y = x->_parent;
			while (y != TNULL && x == y->_right)
			{
				x = y;
				y = y->_parent;
			}
			return y;
		}

		ptr_base constSuccessor(ptr_base x) const
		{
			if (x == TNULL)
				return minimum(getRoot());
			if (x->_right != TNULL)
				return minimum(x->_right);
			ptr_base y = x->_parent;
			while (y != TNULL && x == y->_right)
			{
				x = y;
				y = y->_parent;
			}
			return y;
		}

		ptr_base predecessor(ptr_base x)
		{
			if (x == TNULL)
				return minimum(getRoot());
			if (x->_left != TNULL)
				return maximum(x->_left);
			ptr_base y = x->_parent;
			while (y != TNULL && x == y->_left)
			{
				x = y;
				y = y->_parent;
			}

			return y;
		}

		ptr_base constPredecessor(ptr_base x) const
		{
			if (x == TNULL)
				return minimum(getRoot());
			if (x->_left != TNULL)
				return maximum(x->_left);
			ptr_base y = x->_parent;
			while (y != TNULL && x == y->_left)
			{
				x = y;
				y = y->_parent;
			}

			return y;
		}

		ptr_base lower_bound(_Key key) const
		{
			ptr_base ret = keyIsExist(getRoot(), key);
			if (ret == TNULL)
			{
				if (key > maximum(getRoot())->_value.first)
					return TNULL;
				else
					return minimum(getRoot());
			}
			return ret;
		}

		ptr_base upper_bound(_Key key) const
		{
			ptr_base ret = keyIsExist(getRoot(), key);
			if (ret == TNULL)
			{
				if (key > maximum(getRoot())->_value.first)
					return TNULL;
				else
					return minimum(getRoot());
			}
			ret = constSuccessor(ret);
			return ret;
		}

		ptr_base minimum(ptr_base node) const
		{
			if (node == TNULL)
				return minimum(getRoot());
			while (node->_left != TNULL)
				node = node->_left;
			return node;
		}

		ptr_base maximum(ptr_base node) const
		{
			if (node == TNULL)
				return maximum(getRoot());
			while (node->_right != TNULL)
				node = node->_right;
			return node;
		}

		void leftRotate(ptr_base x)
		{
			ptr_base y = x->_right;
			x->_right = y->_left;
			if (y->_left != TNULL)
				y->_left->_parent = x;
			y->_parent = x->_parent;
			if (x->_parent == TNULL)
				this->root = y;
			else if (x == x->_parent->_left)
				x->_parent->_left = y;
			else
				x->_parent->_right = y;
			y->_left = x;
			x->_parent = y;
		}

		void rightRotate(ptr_base x)
		{
			ptr_base y = x->_left;
			x->_left = y->_right;
			if (y->_right != TNULL)
				y->_right->_parent = x;
			y->_parent = x->_parent;
			if (x->_parent == TNULL)
				this->root = y;
			else if (x == x->_parent->_right)
				x->_parent->_right = y;
			else
				x->_parent->_left = y;
			y->_right = x;
			x->_parent = y;
		}

		ptr_base getRoot() const
		{
			return this->root;
		}

		ptr_base end() const
		{
			return this->TNULL;
		}

		// constPtr_base getConstRoot() const
		// {
		// 	return this->root;
		// }

		size_type getSize() const
		{
			return this->_size;
		}

		size_type deleteNode(_Key data)
		{
			return deleteNodeHelper(this->root, data);
		}

		_Key getKey(constPtr_base target) const
		{
			return target->_value.first;
		}

		void printHelper(ptr_base root, std::string indent, bool last)
		{
			if (root != TNULL)
			{
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "   ";
				}
				else
				{
					std::cout << "L----";
					indent += "|  ";
				}

				std::string sColor = root->_color ? "RED" : "BLACK";
				std::cout << root->_value.first << "(" << sColor << ")" << std::endl;
				printHelper(root->_left, indent, false);
				printHelper(root->_right, indent, true);
			}
		}

		ft::rb_tree_iterator<_Val, base> checkIfExist(_Key k) const
		{
			return checkIfExistP(getRoot(), k);
		}

		void printTree()
		{
			if (root)
				printHelper(this->root, "", true);
		}

	};

} // namespace ft

#endif
