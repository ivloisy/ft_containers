/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:44:19 by ivloisy           #+#    #+#             */
/*   Updated: 2022/04/18 23:38:22 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

namespace ft
{
	template< class T, class Allocator = std::allocator<T> >
	class vector
	{
	private:
		/* data */
	public:
		vector(/* args */);
		~vector();
	};
	
	vector::vector(/* args */)
	{
		return ;
	}
	
	vector::~vector()
	{
		return ;
	}
	
} // namespace ft


#endif