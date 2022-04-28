/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:44:19 by ivloisy           #+#    #+#             */
/*   Updated: 2022/04/28 05:06:55 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <cstddef>

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
			// allocator_type getAlloc() {return this->_alloc;};
		
		private:
			allocator_type	_alloc;
			size_type	_capacity;
			pointer		_first;
			size_type	_size;

		public:
			vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _first(NULL), _size(0) {}
			
			vector(vector const & src) : _alloc(src._alloc), _capacity(src._capacity), _size(src._size)
			{
				_first = _alloc.allocate(_capacity);
				pointer current = _first;
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(current, src._first[i]);
					current++;
				}
				return ;
			}
			virtual ~vector()
			{
				std::cout << "bye" << std::endl;
				return ;
			}
			vector	& operator=(vector const & rhs)
			{
				(void)rhs;
				return *this;
			}
	};
	
	// vector::vector(/* args */)
	// {
	// 	return ;
	// }
	
	// vector::~vector()
	// {
	// 	return ;
	// }
	
} // namespace ft

#endif
