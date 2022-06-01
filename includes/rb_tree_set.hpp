#ifndef RB_TREE_SET_HPP
# define RB_TREE_SET_HPP

# include <iostream>
// # include <iomanip>
// # include <sstream>
// # include <algorithm>

# include "iterator.hpp"
# include "type_traits.hpp"
# include "utility.hpp"
# include "node.hpp"

namespace ft
{
	template<typename Key, typename T/*, typename key_typeOfValue*/, typename Compare = std::less<Key>, typename Alloc = std::allocator<node<T> > >
	class rb_tree_set
	{
	protected:
		typedef ft::node<T>				base;
		typedef ft::node<T> *			ptr_base;
		typedef const ft::node<T> *		const_ptr_base;
		typedef Key						key_type;
		typedef T						value_type;
		typedef value_type *			pointer;
		typedef const value_type *		const_pointer;
		typedef value_type &			reference;
		typedef const value_type &		const_reference;
		typedef size_t					size_type;
		typedef std::ptrdiff_t			difference_type;
		typedef Compare					compare_type;
		typedef Alloc					allocator_type;

	private:
		ptr_base		_root;
		ptr_base		_null;
		allocator_type	_alloc;
		compare_type	_comp;
		size_type		_size;

		void	rbTransplant(ptr_base u, ptr_base v)
		{
			if (u->_parent == this->_null)
				this->_root = v;
			else if (u == u->_parent->_left)
				u->_parent->_left = v;
			else
				u->_parent->_right = v;
			v->_parent = u->_parent;
		}

		int deleteNodeHelper(ptr_base node, key_type key)
		{
			ptr_base z = this->_null;
			ptr_base x, y;

			while (node != this->_null)
			{
				if (node->_value == key)
					z = node;
				if (node->_value <= key)
					node = node->_right;
				else
					node = node->_left;
			}

			if (z == this->_null)
				return 0;
			this->_size--;
			y = z;
			int y_original_color = y->_color;
			if (z->_left == this->_null)
			{
				x = z->_right;
				rbTransplant(z, z->_right);
			}
			else if (z->_right == this->_null)
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
				if (k == this->_root)
					break;
			}
			this->_root->_color = 0;
		}

		void deleteFix(ptr_base x)
		{
			ptr_base s;
			while (x != this->_root && x->_color == 0)
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
						x = this->_root;
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
						x = this->_root;
					}
				}
			}
			x->_color = false;
		}

		ptr_base searchTreeHelper(ptr_base node, key_type key)
		{
			if (node == this->_null || key == node->_value.first)
			{
				return node;
			}

			if (_comp(key, node->_value.first))
			{
				return searchTreeHelper(node->_left, key);
			}
			return searchTreeHelper(node->_right, key);
		}

		ptr_base searchTreeHelper(ptr_base node, key_type key) const
		{
			if (node == this->_null || key == node->_value.first)
			{
				return node;
			}

			if (_comp(key, node->_value.first))
			{
				return searchTreeHelper(node->_left, key);
			}
			return searchTreeHelper(node->_right, key);
		}


		ft::rb_tree_iterator<T, base> checkIfExistP(ptr_base node, key_type key)
		{
			if (node == this->_null || key == node->_value)
				return ft::rb_tree_iterator<T, base>(node, this->_root, this->_null);
			if (_comp(key, node->_value))
				return checkIfExistP(node->_left, key);
			return checkIfExistP(node->_right, key);
		}

		ft::rb_tree_iterator<T, base> checkIfExistP(ptr_base node, key_type key) const
		{
			if (node == this->_null || key == node->_value.first)
				return ft::rb_tree_iterator<T, base>(node, this->_root, this->_null);
			if (_comp(key, node->_value.first))
				return checkIfExistP(node->_left, key);
			return checkIfExistP(node->_right, key);
		}

		ptr_base keyIsExist(ptr_base node, key_type key) const
		{
			if (node == this->_null || key == node->_value)
				return node;
			if (_comp(key, node->_value))
				return keyIsExist(node->_left, key);
			return keyIsExist(node->_right, key);
		}

	public:

		/* =========================== Constructors/Destructors ========================= */

		ptr_base searchTreeHelper(key_type key) const
		{
			ptr_base node = this->getRoot();
			if (node == this->_null || key == node->_value)
			{
				return node;
			}
			if (_comp(key, node->_value))
				return this->searchTreeHelper(node->_left, key);
			return this->searchTreeHelper(node->_right, key);
		}

		rb_tree_set(const Compare& comp, const allocator_type& a = allocator_type()): _comp(comp)
		{
			(void)comp;
			(void)a;
			this->_null = this->_alloc.allocate(1);
			this->_alloc.construct(this->_null, base());
			this->_null->_parent = this->_null;
			this->_null->_left = this->_null;
			// _null->_right = _null;
			this->_root = this->_null;
			this->_size = 0;
		}

		void clear()
		{
			ptr_base node = this->_root;
			while (node != this->_null)
			{
				deleteNode(node->_value);
				node = this->_root;
			}
		}

		void copy( base *& node, base * prev, base * other_node, base * other_null )
		{
			if (other_node == other_null) {
				node = this->_null;
			}
			else {
				base * new_node = _alloc.allocate(1);
				if ( !prev )
					this->_alloc.construct(new_node, base(other_node->_value));
				else
					this->_alloc.construct(new_node, base(other_node->_value, prev));
				new_node->_right = this->_null;
				new_node->_left = this->_null;
				this->_null->_parent = new_node;
				node = new_node;
				copy(node->_left, node, other_node->_left, other_null);
				copy(node->_right, node, other_node->_right, other_null);
			}
		}


		rb_tree_set &	operator=(const rb_tree_set & other)
		{
			if ( this != &other ) {
				if (this->_root != this->_null)
					clear();
				copy(this->_root, this->_null, other.root, other._null);
			}
			return *this;
		}

		~rb_tree_set()
		{
			this->_alloc.destroy(this->_null);
			this->_alloc.deallocate(this->_null, 1);
		}

		ft::pair<rb_tree_iterator<T, base>, bool> insert(const T & v)
		{
			ft::pair<rb_tree_iterator<T, base>, bool> it;
			if ((it.first = checkIfExistP(this->_root, v)) != ft::rb_tree_iterator<T, base>(this->_null, this->_root, this->_null))
			{
				it.second = false;
				return (it);
			}
			this->_size++;
			ptr_base node = this->_alloc.allocate(1);
			this->_alloc.construct(node, base(v));
			node->_parent = this->_null;
			node->_left = this->_null;
			node->_right = this->_null;
			node->_color = true;

			ptr_base y = this->_null;
			ptr_base x = this->_root;

			while (x != this->_null)
			{
				y = x;
				if (_comp(node->_value, x->_value))
					x = x->_left;
				else
					x = x->_right;
			}

			node->_parent = y;
			if (y == this->_null)
				this->_root = node;
			else if (_comp(node->_value, y->_value))
				y->_left = node;
			else
				y->_right = node;

			if (node->_parent == this->_null)
			{
				node->_color = false;
				it.first = ft::rb_tree_iterator<T, base>(node, this->_root, this->_null);
				// it.first =  checkIfExist(node->_value.first);
				it.second = true;
				return (it);
			}

			if (node->_parent->_parent == this->_null)
			{
				// it.first =  checkIfExist(y->_value.first);
				it.first = ft::rb_tree_iterator<T, base>(node, this->_root, this->_null);
				it.second = true;
				return (it);
			}

			insertFix(node);

			// it.first =  checkIfExist(y->_value.first);
			it.first = ft::rb_tree_iterator<T, base>(node, this->_root, this->_null);
			it.second = true;
			return (it);
		}

		ptr_base successor(ptr_base x)
		{
			if (x == this->_null)
				return minimum(getRoot());
			if (x->_right != this->_null)
				return minimum(x->_right);
			ptr_base y = x->_parent;
			while (y != this->_null && x == y->_right)
			{
				x = y;
				y = y->_parent;
			}
			return y;
		}

		ptr_base constSuccessor(ptr_base x) const
		{
			if (x == this->_null)
				return minimum(getRoot());
			if (x->_right != this->_null)
				return minimum(x->_right);
			ptr_base y = x->_parent;
			while (y != this->_null && x == y->_right)
			{
				x = y;
				y = y->_parent;
			}
			return y;
		}

		ptr_base predecessor(ptr_base x)
		{
			if (x == this->_null)
				return minimum(getRoot());
			if (x->_left != this->_null)
				return maximum(x->_left);
			ptr_base y = x->_parent;
			while (y != this->_null && x == y->_left)
			{
				x = y;
				y = y->_parent;
			}

			return y;
		}

		ptr_base constPredecessor(ptr_base x) const
		{
			if (x == this->_null)
				return minimum(getRoot());
			if (x->_left != this->_null)
				return maximum(x->_left);
			ptr_base y = x->_parent;
			while (y != this->_null && x == y->_left)
			{
				x = y;
				y = y->_parent;
			}

			return y;
		}

		ptr_base lower_bound(key_type key) const
		{
			ptr_base ret = keyIsExist(getRoot(), key);
			if (ret == this->_null)
			{
				if (key > maximum(getRoot())->_value)
					return this->_null;
				else
					return minimum(getRoot());
			}
			return ret;
		}

		ptr_base upper_bound(key_type key) const
		{
			ptr_base ret = keyIsExist(getRoot(), key);
			if (ret == this->_null)
			{
				if (key > maximum(getRoot())->_value)
					return this->_null;
				else
					return minimum(getRoot());
			}
			ret = constSuccessor(ret);
			return ret;
		}

		ptr_base minimum(ptr_base node) const
		{
			if (node == this->_null)
			{
				node = getRoot();
				if (node == this->_null)
					return this->_null;
			}
			while (node->_left != this->_null)
				node = node->_left;
			return node;
		}

		ptr_base maximum(ptr_base node) const
		{
			if (node == this->_null)
			{
				node = getRoot();
				if (node == this->_null)
					return this->_null;
			}
			while (node->_right != this->_null)
				node = node->_right;
			return node;
		}

		void leftRotate(ptr_base x)
		{
			ptr_base y = x->_right;
			x->_right = y->_left;
			if (y->_left != this->_null)
				y->_left->_parent = x;
			y->_parent = x->_parent;
			if (x->_parent == this->_null)
				this->_root = y;
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
			if (y->_right != this->_null)
				y->_right->_parent = x;
			y->_parent = x->_parent;
			if (x->_parent == this->_null)
				this->_root = y;
			else if (x == x->_parent->_right)
				x->_parent->_right = y;
			else
				x->_parent->_left = y;
			y->_right = x;
			x->_parent = y;
		}

		ptr_base getRoot() const
		{
			return this->_root;
		}

		void setRoot(ptr_base newRoot) const
		{
			this->_root->_parent = newRoot->_parent;
			this->_root->_left = newRoot->_left;
			this->_root->_right = newRoot->_right;
		}

		ptr_base end() const
		{
			return this->_null;
		}

		void swap(rb_tree_set & x)
		{
			std::swap(this->_root, x._root);
			std::swap(this->_null, x._null);
			std::swap(this->_alloc, x._alloc);
			std::swap(this->_comp, x._comp);
			std::swap(this->_size, x._size);

		}

		size_type getSize() const
		{
			return this->_size;
		}

		size_type deleteNode(key_type k)
		{
			return deleteNodeHelper(this->_root, k);
		}

		key_type getKey(const_ptr_base nd) const
		{
			return nd->_value;
		}

		void printHelper(ptr_base root, std::string indent, bool last)
		{
			if (root != this->_null)
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

		ft::rb_tree_iterator<T, base> checkIfExist(key_type k) const
		{
			return checkIfExistP(getRoot(), k);
		}

		void printTree()
		{
			if (this->_root)
				printHelper(this->_root, "", true);
		}
	};
} // namespace ft

#endif
