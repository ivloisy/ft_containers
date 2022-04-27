#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>

# include "iterator_traits.hpp"

namespace ft
{

	template <class Category,		// iterator::iterator_category
		class T,					// iterator::value_type
		class Distance = ptrdiff_t,	// iterator::difference_type
		class Pointer = T*,			// iterator::pointer
		class Reference = T&>		// iterator::reference
	struct	iterator
	{
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};

	template <class T>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{

	};
} // namespace ft

#endif
