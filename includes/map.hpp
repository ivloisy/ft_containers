#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <cstddef>
# include <cmath>
# include <memory>
# include <limits>
# include <exception>

# include "iterator.hpp"
# include "type_traits.hpp"
# include "algorithm.hpp"

namespace ft
{
	template <class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T>>>
	class map
	{
		public:
			typedef _Key                                          	key_type;
       		typedef _Tp                                           	mapped_type;
       		typedef std::pair<const _Key, _Tp>                    	value_type;
       		typedef _Compare                                      	key_compare;
       		typedef _Alloc                                        	allocator_type;



		private:

			key_compare				_key_cmp;
			allocator_type			_alloc;
			// alloc_node				_alloc_node;
			typedef _Rb_tree<key_type, value_type, _Select1st<value_type>, key_compare, _Pair_alloc_type> _Rep_type;

	       _Rep_type _M_t;  /// The actual tree structure.

		public:

			typedef typename _Pair_alloc_type::pointer        		pointer;
			typedef typename _Pair_alloc_type::const_pointer  		const_pointer;
			typedef typename _Pair_alloc_type::reference      		reference;
			typedef typename _Pair_alloc_type::const_reference		const_reference;
			typedef typename _Rep_type::iterator              		iterator;
			typedef typename _Rep_type::const_iterator        		const_iterator;
			typedef typename _Rep_type::size_type             		size_type;
			typedef typename _Rep_type::difference_type       		difference_type;
			typedef typename _Rep_type::reverse_iterator      		reverse_iterator;
			typedef typename _Rep_type::const_reverse_iterator		const_reverse_iterator;

		private:
			// pointeur				_root;
			// pointeur				_first;
			// pointeur				_null;
			size_type				_size;

		public:

		/* =========================== Constructors/Destructors ========================= */

		/* ===== default constructor ====== */

		// explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _M_t(comp, alloc)
		// {
		//
		// }

		/* ====== range constructor ======= */

		// template <class InputIterator>
		//   map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		// {
		//
		// }

		/* ===== copy constructor ========= */

		// map (const map& x)
		// {
		//
		// }

		/* ========= destructor =========== */

		// ~map(){}


		/* =========== Operator =========== */

		// map& operator= (const map& x)
		// {
		//
		// }

		/* =========================== Iterators ======================================== */

		// iterator	begin()
		// {
		// 	return iterator(this->_first);
		// }
		//
		// const_iterator	begin() const
		// {
		// 	return const_iterator(this->_first);
		// }
		//
		// iterator	end()
		// {
		// 	return iterator(this->_first + this->_size);
		// }
		//
		// const_iterator	end() const
		// {
		// 	return const_iterator(this->_first + this->_size);
		// }
		//
		// reverse_iterator	rbegin()
		// {
		// 	return reverse_iterator(this->_first + (this->_size - 1));
		// }
		//
		// const_reverse_iterator	rbegin() const
		// {
		// 	return const_reverse_iterator(this->_first + (this->_size - 1));
		// }
		//
		// reverse_iterator	rend()
		// {
		// 	return reverse_iterator(this->_first - 1);
		// }
		//
		// const_reverse_iterator	rend() const
		// {
		// 	return const_reverse_iterator(this->_first - 1);
		// }

		/* =========================== Capacity ========================================= */

		// bool	empty() const
		// {
		// 	return this->_size == false;
		// }
		//
		// size_type	size() const
		// {
		// 	return this->_size;
		// }
		//
		// size_type	max_size() const
		// {
		// 	return allocator_type().max_size();
		// }


		/* =========================== Element access =================================== */

		// mapped_type& operator[] (const key_type& k)
		// {
		//
		// }


		/* =========================== Modifiers ======================================== */

		/* ============ Insert ============ */

		// pair<iterator,bool> insert (const value_type& val)
		// {
		//
		// }
		//
		//
		// iterator insert (iterator position, const value_type& val)
		// {
		//
		// }
		//
		// template <class InputIterator>
		//   void insert (InputIterator first, InputIterator last)
		//   {
		//
		//   }

		/* ============= Erase ============ */

		// void erase (iterator position)
		// {
		//
		// }
		//
		// size_type erase (const key_type& k)
		// {
		//
		// }
		//
		// void erase (iterator first, iterator last)
		// {
		//
		// }

		/* ============= Swap ============= */

		// void swap (map& x)
		// {
		//
		// }

		/* ============= Clear ============ */

		// void clear()
		// {
		//
		// }

		/* =========================== Observers ======================================== */

		// key_compare key_comp() const
		// {
		//
		// }
		//
		// value_compare value_comp() const
		// {
		//
		// }

		/* =========================== Operations ======================================= */

		// iterator find (const key_type& k)
		// {
		//
		// }
		//
		// const_iterator find (const key_type& k) const
		// {
		//
		// }
		//
		// size_type count (const key_type& k) const
		// {
		//
		// }
		//
		// iterator lower_bound (const key_type& k)
		// {
		//
		// }
		//
		// const_iterator lower_bound (const key_type& k) const
		// {
		//
		// }
		//
		// iterator upper_bound (const key_type& k)
		// {
		//
		// }
		//
		// const_iterator upper_bound (const key_type& k) const
		// {
		//
		// }
		//
		// pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		// {
		//
		// }
		//
		// pair<iterator,iterator>             equal_range (const key_type& k)
		// {
		//
		// }

		/* =========================== Allocator ======================================== */

		// allocator_type get_allocator() const
		// {
		//
		// }



	};
} // namespace ft

#endif
