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
		private:
			pointer _first;
			size_type _size;
		public:

		/* =========================== Constructors/Destructors ========================= */

		/* ===== default constructor ====== */

		// explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
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
