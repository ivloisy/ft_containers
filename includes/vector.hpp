/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:44:19 by ivloisy           #+#    #+#             */
/*   Updated: 2022/04/29 05:18:41 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <cstddef>
# include <cmath>

# include "iterator.hpp"

namespace ft
{
	template< class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T							value_type;
			typedef Alloc						allocator_type;
			typedef T &							reference;
			typedef const T &					const_reference;
			typedef T *							pointer;
			typedef const T *					const_pointer;
			typedef random_access_iterator<T>	iterator;
			typedef random_access_iterator<const T>	const_iterator;
			// typedef T &			reverse_iterator;
			// typedef T &			const_reverse_iterator;
			// typedef T &			difference_type;
			typedef size_t						size_type;
			allocator_type getAlloc() {return this->_alloc;};
		
		private:
			allocator_type	_alloc;
			size_type	_capacity;
			pointer		_first;
			size_type	_size;

		public:
			explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _first(NULL), _size(0) {}
		
			explicit vector (size_type n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(n * 2), _first(NULL), _size(n)
			{
				this->_first = this->_alloc.allocate(n);
				pointer current = this->_first;
				for (size_type i = 0; i < _size; i++)
				{
					this->_alloc.construct(current, value);
					current++;
				}
			}
			
			vector(vector const & src) : _alloc(src._alloc), _capacity(src._capacity), _size(src._size)
			{
				*this = src;
				return ;
			}

			virtual ~vector()
			{
				std::cout << "bye" << std::endl;
				return ;
			}

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

			reference	operator[](size_type n) const
			{
				return *(this->_first + n);
			}

			iterator begin()
			{
				return (iterator(_first));
			}

			const_iterator begin() const {
				return (const_iterator(_first));
			}

			iterator end() {
				return (iterator(_first + _size));
			}

			const_iterator end() const {
				return (const_iterator(_first + _size));

			}

			size_type size()
			{
				return _size;
			}

			size_type max_size()
			{
				return (allocator_type().max_size());
			}

			size_type capacity()
			{
				return _capacity;
			}

			bool empty()
			{
				return (_size == 0);
			}

			reference	at(size_type n) {
			if (n >= size())
				throw (std::out_of_range("out of range in fonction at"));
			return (*(_first + n));

			}
			
			const_reference at(size_type n) const {
				if (n >= _size)
					throw (std::out_of_range("out of range in fonction at"));
				return (*(_first + n));
			
			}

			reference front() {
				return (*(_first));
			}

			const_reference front() const {
				return (*(_first));
			}

			reference	back() {
				return (*(_first + _size -1));
			}

			const_reference	back() const{
				return (*(_first + _size -1));
			}

			allocator_type get_allocator() const
			{
				return _alloc;
			}
				
	};



	
	
} // namespace ft

#endif
