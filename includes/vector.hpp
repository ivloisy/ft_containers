/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:44:19 by ivloisy           #+#    #+#             */
/*   Updated: 2022/04/27 03:41:18 by ivloisy          ###   ########.fr       */
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
				return ;
			}
			vector(vector const & src)
			{
				(void)src;
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
			typedef T			value_type;
			typedef Alloc		allocator_type;
			typedef T &			reference;
			typedef const T &	const_reference;
			typedef T &			pointer;
			typedef const T &	const_pointer;
			typedef random_access_iterator<T>	iterator;
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
