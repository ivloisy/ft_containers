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
			node_base(void): _value(value()) {}
			node_base(const value& v): _value(v) {}
			node_base(const node_base& src):
			_color(src._color), _parent(src._parent), _left(src._left), _right(src._right), _value(src._value) {}
			bool		_color;
			ptr_base	_parent;
			ptr_base	_left;
			ptr_base	_right;
			value		_value;

	};

	template<typename _Tp>
	struct rb_tree_iterator
	{
		typedef _Tp  value_type;
		typedef _Tp& reference;
		typedef _Tp* pointer;

		typedef std::bidirectional_iterator_tag				iterator_category;
		typedef ptrdiff_t									difference_type;

		typedef rb_tree_iterator<_Tp>       			 	rb_iterator;
		typename node_base<_Tp>::ptr_base					current_node;

		rb_tree_iterator()
		: current_node() { }

		explicit
		rb_tree_iterator(node_base<_Tp>* x)
		: current_node(x) { }

		reference	operator*() const
		{
			return static_cast<node_base<_Tp>*>(current_node)->_value;
			// return *(current_node)->_value;
		}

		// pointer
		// operator->() const
		// {
		//    return std::__addressof(static_cast<node_base<_Val>*>
		//           (current_node)->_value);
		// }

		rb_iterator & operator++()
		{
			current_node = current_node.successor(current_node);
			return *this;
		}

		rb_iterator operator++(int)
		{
			rb_iterator __tmp = *this;
			current_node = current_node.successor(current_node);
			return __tmp;
		}

		rb_iterator&
		operator--()
		{
			current_node = current_node.predecessor(current_node);
			return *this;
		}

		rb_iterator
		operator--(int)
		{
			rb_iterator __tmp = *this;
			current_node = current_node.predecessor(current_node);
			return __tmp;
		}

		bool
		operator==(const rb_iterator& x) const
		{
			return current_node == x.current_node;
		}

		bool
		operator!=(const rb_iterator& x) const
		{
			return current_node != x.current_node;
		}

	};

	template<typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc = std::allocator<node_base<_Val> > >
	class rb_tree
	{

		protected:
			typedef ft::node_base<_Val>												base;
			typedef ft::node_base<_Val>*											ptr_base;
			typedef const node_base<_Val>*										constPtr_base;
			typedef _Key														key_type;
			typedef _Val														value_type;
			typedef value_type*													pointer;
			typedef const value_type*											const_pointer;
			typedef value_type&													reference;
			typedef const value_type&											const_reference;
			typedef size_t														size_type;
			typedef ptrdiff_t													difference_type;
			typedef _Alloc														allocator_type;

		private:
			ptr_base root;
			ptr_base TNULL;
			allocator_type _alloc;

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

			void deleteNodeHelper(ptr_base node, int key)
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
					return;
				}

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
				// if (y_original_color == 0) {
				//   deleteFix(x);
				// }
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

			ptr_base searchTreeHelper(ptr_base node, int key)
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

			ft::rb_tree_iterator<_Val> checkIfExist(ptr_base node, int key)
			{
				if (node == TNULL || key == node->_value.first)
					return ft::rb_tree_iterator<_Val>(node);
				if (key < node->_value.first)
					return checkIfExist(node->_left, key);
				return checkIfExist(node->_right, key);
			}

		public:

		/* =========================== Constructors/Destructors ========================= */

		rb_tree()
		{
			TNULL = this->_alloc.allocate(1);
			this->_alloc.construct(TNULL, base());
			TNULL->_color = false;
			TNULL->_left = TNULL;
			TNULL->_right = TNULL;
			TNULL->_parent = TNULL;
			root = TNULL;
		}

		rb_tree(const _Compare& comp, const allocator_type& a = allocator_type())
		{
			(void)comp;
			(void)a;
			TNULL = this->_alloc.allocate(1);
			this->_alloc.construct(TNULL, base());
			TNULL->_color = false;
			TNULL->_left = TNULL;
			TNULL->_right = TNULL;
			TNULL->_parent = TNULL;
			root = TNULL;
		}

		ft::pair<rb_tree_iterator<_Val>, bool>
		insert(const _Val& v)
		{
			ft::pair<rb_tree_iterator<_Val>, bool> it;
			ft::pair<int, int> test;
			if ((it.first = checkIfExist(this->root, v.first)) != rb_tree_iterator<_Val>(TNULL))
			{
				it.second = false;
				return (it);
			}
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
				it.first = rb_tree_iterator<_Val>(y);
				it.second = true;
				return (it);
			}

			if (node->_parent->_parent == TNULL)
			{
				it.first = rb_tree_iterator<_Val>(y);
				it.second = true;
				return (it);
			}

			insertFix(node);

			it.first = rb_tree_iterator<_Val>(node);
			it.second = true;
			return (it);
		}

		ptr_base successor(ptr_base x)
		{
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

		ptr_base minimum(ptr_base node)
		{
			while (node->_left != TNULL)
				node = node->_left;
			return node;
		}

		ptr_base maximum(ptr_base node)
		{
			while (node->_right != TNULL)
				node = node->_right;
			return node;
		}

		constPtr_base minimum(constPtr_base node)
		{
			while (node->_left != TNULL)
				node = node->_left;
			return node;
		}

		constPtr_base maximum(constPtr_base node)
		{
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

		ptr_base getRoot()
		{
			return this->root;
		}

		void deleteNode(int data)
		{
			deleteNodeHelper(this->root, data);
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

		void printTree()
		{
			if (root)
				printHelper(this->root, "", true);
		}

	};

} // namespace ft

#endif
