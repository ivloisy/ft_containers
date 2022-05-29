#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <functional>

# include "iterator.hpp"
# include "type_traits.hpp"
# include "utility.hpp"
# include "rb_tree.hpp"

namespace ft
{

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef Key															key_type;
			typedef T															mapped_type;

			typedef ft::pair<const Key, T>							value_type;

			typedef Compare														key_compare;
			// class																value_compare;
			typedef Alloc														allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename ft::rb_tree_iterator<value_type, node_base<value_type> >								iterator;
			typedef typename ft::rb_tree_iterator<const value_type, node_base<value_type> >							const_iterator;
			typedef ft::ReverseIterator<iterator>								reverse_iterator;
			typedef ft::ReverseIterator<const_iterator>							const_reverse_iterator;
			typedef std::ptrdiff_t												difference_type;
			typedef size_t														size_type;


			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map;

				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}

				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

		private:

			key_compare			_key_cmp;
			allocator_type		_alloc;
			size_type			_size;
			rb_tree<Key, value_type, Key, Compare>		_tree;

		public:

		/* =========================== Constructors/Destructors ========================= */

		/* ===== default constructor ====== */

		explicit map (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) : _tree(comp, alloc)
		{
		}

		void printTree()
		{
			this->_tree.printTree();
		}

		/* ====== range constructor ======= */

		template <class InputIterator>
		  map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{

			map ret(comp, alloc);
			insert(first, last);
		}

		/* ===== copy constructor ========= */

		map (const map& x)
		{
			map(x.begin(), x.end());
		}

		/* ========= destructor =========== */

		~map()
		{
			clear();
		}


		/* =========== Operator =========== */

		map& operator= (const map& x)
		{
			this->clear();
			this->insert(x.begin(), x.end());
			return *this;
		}

		/* =========================== Iterators ======================================== */

		iterator	begin()
		{
			return iterator(this->_tree.minimum(this->_tree.getRoot()));
		}

		const_iterator	begin() const
		{
			return const_iterator(this->_tree.minimum(this->_tree.getRoot()));
		}

		iterator	end()
		{
			return iterator(this->_tree.end());
		}

		const_iterator	end() const
		{
			return const_iterator(this->_tree.end());
		}

		reverse_iterator	rbegin()
		{
			return reverse_iterator(this->_tree.maximum(this->_tree.getRoot()));
		}

		const_reverse_iterator	rbegin() const
		{
			return const_reverse_iterator(this->_tree.maximum(this->_tree.getRoot()));
		}

		reverse_iterator	rend()
		{
			return reverse_iterator(this->_tree.minimum(this->_tree.getRoot()) - 1);
		}

		const_reverse_iterator	rend() const
		{
			return const_reverse_iterator(this->_tree.minimum(this->_tree.getRoot()) - 1);
		}

		/* =========================== Capacity ========================================= */

		bool	empty() const
		{
			return !size() ;
		}

		size_type	size() const
		{
			return this->_tree.getSize();
		}

		size_type	max_size() const
		{
			return ((allocator_type().max_size() * sizeof(value_type)) / sizeof(ft::node_base<value_type>));
		}


		/* =========================== Element access =================================== */

		mapped_type& operator[] (const key_type & k)
		{
			return (this->_tree.searchTreeHelper(k))->_value.second;
		}


		/* =========================== Modifiers ======================================== */

		/* ============ Insert ============ */

		pair<iterator,bool> insert (const value_type& val)
		{
			return this->_tree.insert(val);
		}


		iterator insert (iterator position, const value_type& val)
		{
			(void) position;
			ft::pair<iterator, bool> p = insert(val);
			return p.first;
		}

		template <class InputIterator>
		  void insert (InputIterator first, InputIterator last)
		  {
			  while(first != last)
				  insert(*first++);
		  }

		/* ============= Erase ============ */

		void erase (iterator position)
		{
			this->_tree.deleteNode(position->first);
		}

		size_type erase (const key_type& k)
		{
			return this->_tree.deleteNode(k);
		}

		void erase (iterator first, iterator last)
		{
			while (first != last)
			{
				this->_tree.deleteNode(first->first);
				first++;
			}
		}

		/* ============= Swap ============= */

		void swap (map& x)
		{
			(void)x;
			// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
			// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
			// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
		}

		/* ============= Clear ============ */

		void clear()
		{
			while (!this->empty())
			{
				this->_tree.deleteNode(this->_tree.getKey(this->_tree.getRoot()));
			}
		}

		/* =========================== Observers ======================================== */

		key_compare	key_comp( void ) const { return key_compare(); }

		value_compare	value_comp( void ) const { return value_compare(key_comp()); }

		/* =========================== Operations ======================================= */

		iterator find (const key_type& k)
		{
			return iterator(this->_tree.searchTreeHelper(k));
		}

		const_iterator find (const key_type& k) const
		{
			return this->_tree.checkIfExist(k);
		}

		size_type count (const key_type& k) const
		{
			if (find(k) != end())
				return 1;
			return 0;
		}

		iterator lower_bound (const key_type& k)
		{
			return iterator(this->_tree.lower_bound(k));
		}

		const_iterator lower_bound (const key_type& k) const
		{
			return const_iterator(this->_tree.lower_bound(k));
		}

		iterator upper_bound (const key_type& k)
		{
			return iterator(this->_tree.upper_bound(k));
		}

		const_iterator upper_bound (const key_type& k) const
		{
			return const_iterator(this->_tree.upper_bound(k));
		}

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return ft::make_pair(lower_bound(k), upper_bound(k));
		}

		pair<iterator,iterator>             equal_range (const key_type& k)
		{
			return ft::make_pair(lower_bound(k), upper_bound(k));
		}

		/* =========================== Allocator ======================================== */

		allocator_type get_allocator() const
		{
			return this->_alloc;
		}




	};
} // namespace ft


#endif
