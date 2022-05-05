/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:44:19 by ivloisy           #+#    #+#             */
/*   Updated: 2022/05/03 16:09:55 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <cstddef>
# include <cmath>
// # include <iterator> ///////

# include "iterator.hpp"
# include "type_traits.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T								value_type;
			typedef Alloc							allocator_type;
			typedef T &								reference;
			typedef const T &						const_reference;
			typedef T *								pointer;
			typedef const T *						const_pointer;
			typedef random_access_iterator<T>		iterator;
			typedef random_access_iterator<const T>	const_iterator;
			// typedef T &			reverse_iterator;
			// typedef T &			const_reverse_iterator;
			// typedef T &			difference_type;
			typedef size_t							size_type;

		private:
			allocator_type	_alloc;
			size_type		_capacity;
			pointer			_first;
			size_type		_size;

		public:

			/*
			**	Default constructor
			*/

			explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _first(NULL), _size(0)
			{
				return ;
			}

			/*
			**	Fill constructor
			*/

			/////////////// reste le * 2 a change
			explicit vector (size_type n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(n * 2), _first(NULL), _size(n)
			{
				this->_first = this->_alloc.allocate(n);
				pointer current = this->_first;
				for (size_type i = 0; i < _size; i++)
				{
					this->_alloc.construct(current, value);
					current++;
				}
				return ;
			}

			/*
			**	Fill constructor
			*/

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _first(NULL), _size(0)
			{
				std::cout << "first:\t" << *first << std::endl;
				std::cout << "last:\t" << *last << std::endl;
				// (void)first;
				// (void)last;
				// ft::random_access_iterator<int> test1(first);
				// ft::random_access_iterator<int> test2(last);
				// std::cout << "distance " << std::distance(first, last) << std::endl;
				// this->_first = this->_alloc.allocate();
				// pointer current = this->_first;
				// InputIterator tmp = first;
				// while (tmp != last)
				// {
				// 	this->_alloc.construct(current, tmp->value);
				// 	tmp++;
				// 	current++;
				// }
				return ;
			}

			/*
			**	Copy constuctor
			*/

			vector(vector const & src) : _alloc(src._alloc), _capacity(src._capacity), _size(src._size)
			{
				*this = src;
				return ;
			}

			/*
			**	Destructor
			*/

			virtual ~vector()
			{
				this->clear();
				this->get_allocator().deallocate(this->_first, this->_capacity);
				return ;
			}

			/*
			**	Operator
			*/

			vector &	operator=(vector const & rhs)
			{
				if ( this != &rhs)
				{
					this->_first = this->_alloc.allocate(_capacity);
					pointer current = this->_first;
					for (size_type i = 0; i < _size; i++)
					{
						this->_alloc.construct(current, rhs._first[i]);
						current++;
					}
				}
				return *this;
			}

			/*
			**	Iterators
			*/

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

			//////////rbegin
			// reverse_iterator	rbegin()
			// {
				
			// }

			// const_reverse_iterator	rbegin() const
			// {
				
			// }

			//////////rend
			// reverse_iterator	rend()
			// {
				
			// }

			// const_reverse_iterator	rend() const
			// {
				
			// }

			/*
			**	Capacity
			*/

			size_type	size()
			{
				return this->_size;
			}

			size_type	max_size()
			{
				return allocator_type().max_size();
			}

			//////////resize
			// void	resize (size_type n, value_type val = value_type())
			// {
				
			// }

			size_type	capacity()
			{
				return this->_capacity;
			}

			bool	empty()
			{
				return this->_size == false;
			}

			//////////reserve
			// void	reserve (size_type n)
			// {
				
			// }

			/*
			**	Element access
			*/

			reference	operator[](size_type n) const
			{
				return *(this->_first + n);
			}

			// const_reference	operator[](size_type n) const
			// {
			// 	return *(this->_first + n);
			// }

			reference	at(size_type n)
			{
				if (n >= size())
				throw (std::out_of_range("out of range in fonction at"));
				return *(this->_first + n);
			}

			const_reference	at(size_type n) const
			{
				if (n >= this->_size)
				throw (std::out_of_range("out of range in fonction at"));
				return *(this->_first + n);
			}

			reference	front()
			{
				return *(this->_first);
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

			/*
			**	Modifiers
			*/

			// iterator insert (iterator position, const value_type & val)
			// {
				
			// }

			// void insert (iterator position, size_type n, const value_type & val)
			// {
				
			// }

			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last)
			// {
				
			// }

			// void	push_back (const value_type& val)
			// {
				
			// }

			// void	pop_back()
			// {
				
			// }

			// iterator	insert (iterator position, const value_type & val)
			// {
				
			// }

			// void	insert (iterator position, size_type n, const value_type & val)
			// {
				
			// }

			// template <class InputIterator>
		    // void	insert (iterator position, InputIterator first, InputIterator last)
			// {
				
			// }

			// iterator	erase (iterator position)
			// {
				
			// }

			// iterator	erase (iterator first, iterator last)
			// {
				
			// }

			// void	swap (vector & x)
			// {
				
			// }

			void	clear()
			{
				for (size_t i = 0; i < this->_size; i++)
					_alloc.destroy(this->_first + i);
				this->_size = 0;
			}

			/*
			**	Allocator
			*/

			allocator_type	get_allocator() const
			{
				return this->_alloc;
			}

	};





} // namespace ft

#endif
