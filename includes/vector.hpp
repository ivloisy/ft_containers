/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:44:19 by ivloisy           #+#    #+#             */
/*   Updated: 2022/05/19 04:04:03 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

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
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T									value_type;
			typedef Alloc								allocator_type;
			typedef typename allocator_type::reference	reference;
			// typedef T &								reference;
			typedef const T &							const_reference;
			typedef T *									pointer;
			typedef const T *							const_pointer;
			typedef ft::random_access_iterator<T>						iterator;
			typedef ft::random_access_iterator<const T>				const_iterator;
			typedef ft::ReverseIterator<iterator>				reverse_iterator;
			typedef ft::ReverseIterator<const_iterator>		const_reverse_iterator;
			typedef std::ptrdiff_t						difference_type;
			typedef size_t								size_type;

		private:
			allocator_type	_alloc;
			size_type		_capacity;
			pointer			_first;
			size_type		_size;

		public:
			/* =========================== Constructors/Destructors ========================= */

			/* ===== default constructor ====== */

			explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _first(NULL), _size(0)
			{
				return ;
			}

			/* ===== Fill constructor ====== */

			explicit vector (size_type n, const value_type& value = value_type(), const allocator_type & alloc = allocator_type()) : _alloc(alloc), _capacity(n), _first(NULL), _size(n)
			{
				this->_first = this->_alloc.allocate(this->_capacity);
				pointer current = this->_first;
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(current, value);
					current++;
				}
				return ;
			}

			/* ===== Range constructor ====== */

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL) : _alloc(alloc), _capacity(std::distance(first, last)), _first(NULL), _size(std::distance(first, last))
			{
				this->_first = this->_alloc.allocate(this->_size);
				pointer current = this->_first;
				for (size_t i = this->_size; i > 0; i--)
				{
					this->_alloc.construct(current, *first);
					current++;
					first++;
				}
				return ;
			}

			/* ===== Copy constructor ====== */

			vector(vector const & src) : _alloc(src._alloc), _capacity(src._capacity), _size(0)
			{
				this->_first = this->_alloc.allocate(this->_capacity);
				//this->assign(x.begin(), x.end());
				for (size_type i = 0; i < src._size; i++) {
					this->push_back(*(src._first + this->_size));
				}
				// std::cout << "============== plaf" << std::endl;
				// this->_capacity = src.size();
				// *this = src;
				// std::cout << "<<<<<<<<<<<<<<<plouf" << std::endl;
				return ;
			}

			/* ===== Destructor ====== */

			virtual ~vector()
			{
				this->clear();
				this->get_allocator().deallocate(this->_first, this->_capacity);
				return ;
			}

			/* =========== Operator =========== */

			vector &	operator=(vector const & rhs)
			{
				if ( this != &rhs)
					this->assign(rhs.begin(), rhs.end());
				return *this;
			}

			/* =========================== Iterators ======================================== */

			iterator	begin()
			{
				return iterator(this->_first);
			}

			const_iterator	begin() const
			{
				return const_iterator(this->_first);
			}

			iterator	end()
			{
				return iterator(this->_first + this->_size);
			}

			const_iterator	end() const
			{
				return const_iterator(this->_first + this->_size);
			}

			reverse_iterator	rbegin()
			{
				return reverse_iterator(this->_first + this->_size);
			}

			const_reverse_iterator	rbegin() const
			{
				return const_reverse_iterator(this->_first + this->_size);
			}

			reverse_iterator	rend()
			{
				return reverse_iterator(this->_first);
			}

			const_reverse_iterator	rend() const
			{
				return const_reverse_iterator(this->_first);
			}

			/* =========================== Capacity ========================================= */

			size_type	size() const
			{
				return this->_size;
			}

			size_type	max_size() const
			{
				return allocator_type().max_size();
			}

			void	resize (size_type n, value_type val = value_type())
			{
				if (n == 0)
				{
					this->clear();
				}
				else if (n < this->_size)
				{
					for (size_t i = 0; i < n + 1; i++)
						this->pop_back();
					this->_size = n;
				}
				else if (n > this->_size)
				{
					if (n <= this->_capacity)
					{
						for (size_t i = 0; i < n; i++)
							this->push_back(val);
					}
					else
					{
						if (this->_capacity * 2 < n)
							this->reserve(n);
						else
							this->reserve(this->_capacity * 2);
						// std::cout << this->_capacity << std::endl;
						for (size_t i = this->_size; i < n; i++)
							this->push_back(val);
					}
					this->_size = n;
				}
				return ;
			}

			size_type	capacity() const
			{
				return this->_capacity;
			}

			bool	empty() const
			{
				return this->_size == false;
			}

			void	reserve (size_type n)
			{
				if (n > this->max_size())
					throw(std::exception());
				if (n > this->_capacity)
				{
					pointer		tmp;
					size_t		tmps = this->_size;
					size_type	newCap = this->_capacity == 0 ? n : this->_capacity;
					while (n > newCap)
						newCap *= 2;
					if (newCap > this->max_size())
						throw(std::exception());
					tmp = this->_alloc.allocate(newCap);
					std::uninitialized_copy(this->begin(), this->end(), tmp);
					this->clear();
					this->_alloc.deallocate(this->_first, this->_capacity);
					this->_first = tmp;
					this->_capacity = newCap;
					this->_size = tmps;
				}
			}

			/* =========================== Element access =================================== */

			reference	operator[](size_type n)
			{
				return *(this->_first + n);
			}
			const_reference operator[] (size_type n) const
			{
				return (this->_first[n]);
			}

			reference	at(size_type n)
			{
				if (n >= this->_size)
					throw (std::out_of_range("ofr"));
				return *(this->_first + n);
			}

			const_reference	at(size_type n) const
			{
				if (n >= this->_size)
					throw (std::out_of_range("ofr"));
				return *(this->_first + n);
			}

			reference	front()
			{
				return (*(this->_first));
			}

			const_reference	front() const
			{
				return (*(this->_first));
			}

			reference	back()
			{
				return (*(this->_first + _size -1));
			}

			const_reference	back() const
			{
				return (*(this->_first + _size -1));
			}

			/* =========================== Modifiers ======================================== */

			/* ============ Insert ============ */

			iterator	insert (iterator position, const value_type & val)
			{
				///////////BEN
				// int ret = std::distance(this->begin(), position);
				// if (position != this->end())
				// {
				// 	if (this->_size + 1 > this->_capacity)
				// 		this->reserve(this->_capacity * 2);
				// 	this->_size++;
				// 	value_type insert = *position;
				// 	this->_alloc.destroy(&*position);
				// 	this->_alloc.construct(&*position, val);
				// 	position++;
				// 	value_type save = *position;
				// 	while (position != this->end())
				// 	{
				//
				// 		this->_alloc.destroy(&*position);
				// 		this->_alloc.construct(&*position, insert);
				// 		insert = save;
				// 		position++;
				// 		save = *position;
				// 	}
				// }
				// else
				// 	push_back(val);
				// return (this->begin() + ret);
				/////COCHON
				size_t n = &(*position) - this->_first;
				//std::cout << "position du ite: " << n<< std::endl;
				//std::cout << "          " << n << std::endl;

				if (this->_capacity >= this->_size + 1)
				{
					int i = 0;
					while (this->_size -i > n)
					{
						_alloc.construct(this->_first + this->_size - i, *(this->_first + this->_size -i-1));
						i++;
					}
					this->_alloc.construct(this->_first + this->_size - i , val);
					_size++;


				}
				else
				{
					int i = 0;
					if (_capacity == 0)
						reserve(1);
					else
						reserve(_size *2);
					while (_size -i > n)
					{
						_alloc.construct(_first + _size - i, *(_first + _size -i-1));
						i++;
					}
					if ((_first + _size - i))
						_alloc.destroy(_first + _size - i);
					_alloc.construct(_first + _size - i , val);
					_size++;

				}
				return (_first + n);
			}

			void	insert (iterator position, size_type n, const value_type & val)
			{
				ft::vector<T> tmp;
				size_type diff = std::distance(this->begin(), position);
				size_type i = 0;
				while (i < diff)
					tmp.push_back(this->_first[i++]);
				while (n--)
					tmp.push_back(val);
				while (i < this->size())
					tmp.push_back(this->_first[i++]);
				this->swap(tmp);
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL)
			{
					ft::vector<T> tmp;
					size_type diff = std::distance(this->begin(), position);
					size_type i = 0;
					while (i < diff)
						tmp.push_back(this->_first[i++]);
					while (first != last)
						tmp.push_back(*first++);
					while (i < this->size())
						tmp.push_back(this->_first[i++]);
					this->swap(tmp);
			}

			/* ============ Assign ============ */

			void assign (size_type n, const value_type& val)
			{
				this->clear();
				if (n > this->_capacity) /// a checker ==========================================/////
					this->_capacity = 0;
				this->insert(this->begin(), n, val);
				// this->resize(n, val);
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL)
			{
				this->clear();
				this->insert(this->begin(), first, last);
			}

			/* ============ Push & Pop ============ */

			void	push_back (const value_type& val)
			{
				if (this->_capacity < this->_size + 1)
					this->reserve(this->_size + 1);
				pointer current = this->_first;
				for (size_t n = 0; n < this->_size; n++)
					current++;
				this->_alloc.construct(current, val);
				this->_size++;
			}

			void	pop_back()
			{
				pointer current = this->_first;
				for (size_t n = 0; n < this->_size; n++)
					current++;
				this->_alloc.destroy(current - 1);
				this->_size--;
			}

			/* ============ Erase ============ */

			iterator	erase (iterator position)
			{
				int ret = std::distance(this->begin(), position);
				if (position == this->end())
					this->pop_back();
				while (position != this->end() - 1)
				{
					this->_alloc.destroy(&*position);
					this->_alloc.construct(&*position, *(position + 1));
					position++;
				}
				this->_alloc.destroy(&*position);
				this->_size--;
				return (iterator(this->begin() + ret));
			}

			iterator	erase (iterator first, iterator last)
			{
				int ret = std::distance(this->begin(), first);
				int distance = std::distance(first, last);
				iterator current = first;
				while (current != last)
				{
					this->_alloc.destroy(&*current);
					current++;
				}
				while (first != this->end() && last != this->end())
				{
					this->_alloc.construct(&*first, *last);
					this->_alloc.destroy(&*last);
					first++;
					last++;
				}
				this->_size -= distance;
				return (this->begin() + ret);
			}


			/* ============ Swap ============ */

			private:
				template <class ToSwap>
				void ft_swap(ToSwap &a, ToSwap &b)
				{
					ToSwap tmp = a;
					a = b;
					b = tmp;
				}

			public:

				void	swap (vector & x)
				{
					ft_swap(this->_first, x._first);
					ft_swap(this->_alloc, x._alloc);
					ft_swap(this->_size, x._size);
					ft_swap(this->_capacity, x._capacity);
				}

				/* ============ Clear ============ */

				void	clear()
				{
					for (size_t i = 0; i < this->_size; i++)
						_alloc.destroy(this->_first + i);
					this->_size = 0;
				}

				/* =========================== Allocator ======================================== */

				allocator_type	get_allocator() const
				{
					return this->_alloc;
				}

	};

	template <class T, class Alloc>
	bool	operator==(const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool	operator!=(const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool	operator<(const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool	operator<=(const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}

	template <class T, class Alloc>
	bool	operator>(const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs)
	{
		return (!(lhs < rhs || lhs == rhs));
	}

	template <class T, class Alloc>
	bool	operator>=(const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs)
	{
		return (lhs > rhs || lhs == rhs);
	}

	template <class T, class Alloc>
	void	swap(vector<T,Alloc> & x, vector<T,Alloc> & y)
	{
		x.swap(y);
	}
} // namespace ft

#endif
