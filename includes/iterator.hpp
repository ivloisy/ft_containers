#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>

# include "iterator_traits.hpp"

namespace ft
{

	template <class Category,			// iterator::iterator_category
		class T,						// iterator::value_type
		class Distance = std::ptrdiff_t,// iterator::difference_type
		class Pointer = T*,				// iterator::pointer
		class Reference = T&>			// iterator::reference
	struct	iterator
	{
		typedef Category		iterator_category;
		typedef T				value_type;
		typedef Distance		difference_type;
		typedef Pointer			pointer;
		typedef const Pointer	const_pointer;
		typedef Reference		reference;
		typedef const Reference	const_reference;
	};

	template <class T>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category 	iterator_category;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer				pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::const_pointer			const_pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference				reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::const_reference		const_reference;

		private :
			pointer _ptr;

		public :

			/*
			**	All categories
			*/

 			random_access_iterator(const random_access_iterator & src) : _ptr(src._ptr){}
			
			random_access_iterator(pointer value) : _ptr(value) {}

	//		random_access_iterator(const_pointer value) : _ptr(value) {}

			random_access_iterator &	operator=(const random_access_iterator & rhs)
			{
				if (this != &rhs)
					_ptr = rhs._ptr;
				return *this;
			}

			~random_access_iterator() {}

			random_access_iterator &	operator++()
			{
				++this->_ptr;
				return *this;
			}

			random_access_iterator	operator++(int)
			{
				random_access_iterator tmp(*this);
				++this->_ptr;
				return tmp;
			}

			/*
			**	Input
			*/

			//	const vs non const ??? ////////////
			bool	operator==(random_access_iterator const & rhs) const
			{
				return this->_ptr == rhs._ptr;
			}

			bool	operator!=(random_access_iterator const &rhs) const
			{
				return this->_ptr != rhs._ptr;
			}

			reference	operator*()
			{
				return (*this->_ptr);
			}

			const_reference	operator*() const
			{
				return (*this->_ptr);
			}

			pointer	operator->()
			{
				return (this->_ptr);
			}

			const_pointer	operator->() const
			{
				return (this->_ptr);
			}

			/*
			**	Output
			*/

			///////////////
			///////////////

			/*
			**	Forward
			*/

			random_access_iterator(): _ptr(NULL) {}

			///////////////

			/*
			**	Bidirectional
			*/

			random_access_iterator &	operator--()
			{
				--this->_ptr;
				return *this;
			}

			random_access_iterator	operator--(int)
			{
				random_access_iterator tmp(*this);
				--this->_ptr;
				return tmp;
			}

			///////////////

			/*
			**	Random access
			*/

			random_access_iterator	operator+(int value) const
			{
				random_access_iterator tmp(*this);
				return tmp += value;
			}

			random_access_iterator	operator-(int value) const
			{
				random_access_iterator tmp(*this);
				return tmp -= value;
			}

			difference_type	operator-(random_access_iterator const & rhs) const
			{
				return this->_ptr - rhs._ptr;
			}

			bool	operator<(random_access_iterator const & rhs) const
			{
				return this->_ptr < rhs._ptr;
			}

			bool	operator>(random_access_iterator const & rhs) const
			{
				return this->_ptr > rhs._ptr;
			}

			bool	operator<=(random_access_iterator const & rhs) const
			{
				return this->_ptr <= rhs._ptr;
			}

			bool	operator>=(random_access_iterator const & rhs) const
			{
				return this->_ptr >= rhs._ptr;
			}

			random_access_iterator &	operator+=(int value)
			{
				this->_ptr += value;
				return *this;
			}

			random_access_iterator &	operator-=(int value)
			{
				this->_ptr -= value;
				return *this;
			}

			reference	operator[](int value)
			{
				return (*(this->_ptr + value));
			}

			const_reference	operator[](int value) const
			{
				return (*(this->_ptr + value));
			}

	};
} // namespace ft

#endif
