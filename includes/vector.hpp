/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:44:19 by ivloisy           #+#    #+#             */
/*   Updated: 2022/04/26 02:47:18 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

# include "iterator.hpp"

namespace ft
{
	template< class T, class Alloc = std::allocator<T> >
	class vector
	{
		private:
			/* data */
		public:
			vector()
			{
				std::cout << "coucou" << std::endl;
				this->
				return ;
			}
			vector(vector const & src)
			{
				return ;
			}
			virtual ~vector()
			{
				std::cout << "bye" << std::endl;
				return ;
			}
			vector	& operator=(vector const & rhs)
			{
				return *this;
			}
			typedef T			value_type;
			typedef Alloc		allocator_type;
			typedef T &			reference;
			typedef const T &	const_reference;
			typedef T &			pointer;
			typedef const T &	const_pointer;
			typedef iterator<T>	iterator;
			// typedef T &			const_iterator;
			// typedef T &			reverse_iterator;
			// typedef T &			const_reverse_iterator;
			// typedef T &			difference_type;
			// typedef T &			size_type;
		
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
