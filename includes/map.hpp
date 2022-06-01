#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <functional>
// # include <iomanip>
// # include <sstream>
// # include <algorithm>

# include "iterator.hpp"
# include "type_traits.hpp"
# include "utility.hpp"
# include "rb_tree.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class	map
	{
	public:
		typedef Key																		key_type;
		typedef T																		mapped_type;
		typedef ft::pair<const key_type, mapped_type>									value_type;
		typedef Compare																	key_compare;

		class	value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;

		private:
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

		typedef Alloc																	allocator_type;
		typedef typename allocator_type::reference										reference;
		typedef typename allocator_type::const_reference								const_reference;
		typedef typename allocator_type::pointer										pointer;
		typedef typename allocator_type::const_pointer									const_pointer;
		typedef typename ft::rb_tree_iterator<value_type, ft::node<value_type> >		iterator;
		typedef typename ft::rb_tree_iterator<const value_type, ft::node<value_type> >	const_iterator;
		typedef ft::ReverseIterator<iterator>											reverse_iterator;
		typedef ft::ReverseIterator<const_iterator>										const_reverse_iterator;
		typedef std::ptrdiff_t															difference_type;
		typedef size_t																	size_type;

	private:
		key_compare												_comp;
		allocator_type											_alloc;
		size_type												_size;
		rb_tree<key_type, value_type/*, key_type*/, key_compare>	_tree;

	public:
		/* ================== Constructors/Destructors ================== */

		/* ==================== default constructor ===================== */

		explicit map(const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) : _tree(comp, alloc) {}

		/* ===================== range constructor ====================== */

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) : _tree(comp, alloc)
		{
			insert(first, last);
		}

		/* ====================== copy constructor ====================== */

		map(const map & x) : _tree(x._comp, x._alloc)
		{
			insert(x.begin(), x.end());
		}

		/* ========================= destructor ========================= */

		~map()
		{
			clear();
		}


		/* ========================== Operator ========================== */

		map &	operator= (const map & x)
		{
			this->clear();
			this->insert(x.begin(), x.end());
			return *this;
		}

		/* ========================= Iterators ========================== */

		iterator	begin()
		{
			return iterator(this->_tree.minimum(this->_tree.getRoot()), this->_tree.getRoot(), this->_tree.end());
		}

		const_iterator	begin() const
		{
			return const_iterator(this->_tree.minimum(this->_tree.getRoot()), this->_tree.getRoot(), this->_tree.end());
		}

		iterator	end()
		{
			return iterator(this->_tree.end(), this->_tree.getRoot(), this->_tree.end());
		}

		const_iterator	end() const
		{
			return const_iterator(this->_tree.end(), this->_tree.getRoot(), this->_tree.end());
		}

		reverse_iterator	rbegin()
		{
			return reverse_iterator(this->end());
		}

		const_reverse_iterator	rbegin() const
		{
			return const_reverse_iterator(this->end());
		}

		reverse_iterator	rend()
		{
			return reverse_iterator(iterator(this->_tree.minimum(this->_tree.getRoot()), this->_tree.getRoot(), this->_tree.end()));
		}

		const_reverse_iterator	rend() const
		{
			return const_reverse_iterator(iterator(this->_tree.minimum(this->_tree.getRoot()), this->_tree.getRoot(), this->_tree.end()));
		}

		/* ========================== Capacity ========================== */

		bool	empty() const
		{
			return !this->size() ;
		}

		size_type	size() const
		{
			return this->_tree.getSize();
		}

		size_type	max_size() const
		{
			return ((allocator_type().max_size() * sizeof(value_type)) / sizeof(ft::node<value_type>));
		}

		/* ======================= Element access ======================= */

		mapped_type &	operator[] (const key_type & k)
		{
			if (this->_tree.checkIfExist(k) == this->end())
				this->_tree.insert(ft::make_pair(k, mapped_type()));
			return (this->_tree.searchTreeHelper(k))->_value.second;
		}


		/* ========================= Modifiers ========================== */

		/* =========================== Insert =========================== */

		pair<iterator,bool>	insert(const value_type & val)
		{
			return this->_tree.insert(val);
		}

		iterator	insert(iterator position, const value_type & val)
		{
			(void) position;
			ft::pair<iterator, bool> p = insert(val);
			return p.first;
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			while(first != last)
				insert(*first++);
		}

		/* =========================== Erase ============================ */

		void	erase(iterator position)
		{
			this->_tree.deleteNode(position->first);
		}

		size_type	erase(const key_type & k)
		{
			return this->_tree.deleteNode(k);
		}

		void	erase(iterator first, iterator last)
		{
			if (first == this->begin() && last == this->end())
				this->clear();
			else
				while (first != last)
					this->erase(first++);
		}

		/* ============================ Swap ============================ */

		void	swap(map & x)
		{
			this->_tree.swap(x._tree);
			std::swap(_comp, x._comp);
			std::swap(_alloc, x._alloc);
			std::swap(_size, x._size);
		}

		/* =========================== Clear ============================ */

		void	clear()
		{
			while (!this->empty())
			{
				this->_tree.deleteNode(this->_tree.getKey(this->_tree.getRoot()));
			}
		}

		/* ========================= Observers ========================== */

		key_compare	key_comp(void) const
		{
			return key_compare();
		}

		value_compare	value_comp(void) const
		{
			return value_compare(key_comp());
		}

		/* ========================= Operations ========================= */

		iterator	find(const key_type & k)
		{
			return iterator(this->_tree.searchTreeHelper(k), this->_tree.getRoot(), this->_tree.end());
		}

		const_iterator	find(const key_type & k) const
		{
			return this->_tree.checkIfExist(k);
		}

		size_type	count(const key_type & k) const
		{
			if (find(k) != end())
				return 1;
			return 0;
		}

		iterator	lower_bound(const key_type & k)
		{
			return iterator(this->_tree.lower_bound(k), this->_tree.getRoot(), this->_tree.end());
		}

		const_iterator	lower_bound(const key_type & k) const
		{
			return const_iterator(this->_tree.lower_bound(k), this->_tree.getRoot(), this->_tree.end());
		}

		iterator	upper_bound(const key_type & k)
		{
			return iterator(this->_tree.upper_bound(k), this->_tree.getRoot(), this->_tree.end());
		}

		const_iterator	upper_bound(const key_type & k) const
		{
			return const_iterator(this->_tree.upper_bound(k), this->_tree.getRoot(), this->_tree.end());
		}

		pair<const_iterator,const_iterator>	equal_range(const key_type & k) const
		{
			return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
		}

		pair<iterator,iterator>	equal_range(const key_type & k)
		{
			return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
		}

		/* ========================= Allocator ========================== */

		allocator_type	get_allocator() const
		{
			return this->_alloc;
		}
	};

	template <class Key, class T, class Alloc>
	bool	operator==(const map<Key, T, Alloc> & lhs, const map<Key, T,Alloc> & rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Alloc>
	bool	operator!=(const map<Key, T, Alloc> & lhs, const map<Key, T, Alloc> & rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Alloc>
	bool	operator<(const map<Key, T, Alloc> & lhs, const map<Key, T,Alloc> & rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Alloc>
	bool	operator<=(const map<Key, T, Alloc> & lhs, const map<Key, T, Alloc> & rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}

	template <class Key, class T, class Alloc>
	bool	operator>(const map<Key, T, Alloc> & lhs, const map<Key, T, Alloc> & rhs)
	{
		return (!(lhs < rhs || lhs == rhs));
	}

	template <class Key, class T, class Alloc>
	bool	operator>=(const map<Key, T, Alloc> & lhs, const map<Key, T, Alloc> & rhs)
	{
		return (lhs > rhs || lhs == rhs);
	}
} // namespace ft

#endif
