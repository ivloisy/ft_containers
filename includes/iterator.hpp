#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <iterator>
# include "algorithm.hpp"

namespace ft
{

	template<class Category,			// iterator::iterator_category
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

	// struct input_iterator_tag {};
	//
	// struct output_iterator_tag {};
	//
	// struct forward_iterator_tag : public input_iterator_tag {};
	//
	// struct bidirectional_iterator_tag : public forward_iterator_tag {};
	//
	// struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	/*
	**	random_access_iterator
	*/

	template<class T>
	class random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category 	iterator_category;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer				pointer;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::const_pointer			const_pointer;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference				reference;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::const_reference		const_reference;

		private :
			pointer _ptr;

		public :

			/* =========================== All categories ========================= */

			random_access_iterator(random_access_iterator const & src) : _ptr(src._ptr){}

			random_access_iterator(pointer value) : _ptr(value) {}

			random_access_iterator &	operator=(const random_access_iterator & rhs)
			{
				if (this != &rhs)
					_ptr = rhs._ptr;
				return *this;
			}

			~random_access_iterator() {}

			operator random_access_iterator<const T> () const
			{ return (random_access_iterator<const T>(this->_ptr)); }

			random_access_iterator &operator++()
			{
				++this->_ptr;
				return *this;
			}

			random_access_iterator	operator++(int)
			{
				random_access_iterator tmp = (*this);
				++(this)->_ptr;
				return tmp;
			}

			/* =========================== Input ======================================== */

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

			/* =========================== Output ======================================== */


			/* =========================== Forward ======================================== */

			random_access_iterator(): _ptr(NULL) {}

			/* =========================== Bidirectional ================================== */

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

			/* =========================== Random Access ================================ */

			random_access_iterator	operator+(difference_type value) const
			{
				return (this->_ptr + value);
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

			/* =========================== Friends Access ================================ */

			template<typename I, typename U>
			friend bool operator==(random_access_iterator<I> const &lhs, random_access_iterator<U> const &rhs);

			template<typename I, typename U>
			friend bool operator!=(random_access_iterator<I> const &lhs, random_access_iterator<U> const &rhs);

			template<typename I, typename U>
			friend bool operator<=(random_access_iterator<I> const &lhs, random_access_iterator<U> const &rhs);

			template<typename I, typename U>
			friend bool operator>=(random_access_iterator<I> const &lhs, random_access_iterator<U> const &rhs);

			template<typename I, typename U>
			friend bool operator<(random_access_iterator<I> const &lhs, random_access_iterator<U> const &rhs);

			template<typename I, typename U>
			friend bool operator>(random_access_iterator<I> const &lhs, random_access_iterator<U> const &rhs);

	};

	/* =========================== iterator_traits ================================ */

	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;

	};

	template<typename T>
	struct iterator_traits<T*>
	{
		typedef std::random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef T*							pointer;
		typedef T&							reference;
	};

	template<typename T>
	struct iterator_traits<const T*>
	{
		typedef std::random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef T*							pointer;
		typedef T&							reference;
	};

	/* =========================== Reverse_traits ================================ */

	template<typename T>
	class ReverseIterator
	{
		public:
			typedef typename iterator_traits<T>::iterator_category 	iterator_category;
			typedef typename iterator_traits<T>::value_type			value_type;
			typedef typename iterator_traits<T>::difference_type		difference_type;
			typedef typename iterator_traits<T>::pointer				pointer;
			typedef typename iterator_traits<T>::reference			reference;
			T base(void) const { return (this->_ptr); }
		private :
			T _ptr;

		public :

			/* =========================== All categories ========================= */

			ReverseIterator() : _ptr(NULL) {}

			explicit ReverseIterator (T it): _ptr(it) {}

			template <class U>
			ReverseIterator(const ReverseIterator<U> & src) : _ptr(src.base()){}

			~ReverseIterator() {}

			ReverseIterator &operator++()
			{
				--this->_ptr;
				return *this;
			}

			ReverseIterator	operator++(int)
			{
				ReverseIterator tmp = (*this);
				--(this)->_ptr;
				return tmp;
			}

			bool	operator==(ReverseIterator const & rhs) const
			{
				return this->_ptr == rhs._ptr;
			}

			bool	operator!=(ReverseIterator const &rhs) const
			{
				return this->_ptr != rhs._ptr;
			}

			reference	operator*()
			{
				return *(this->_ptr);
			}

			// const_reference	operator*() const
			// {
			// 	return *(this->_ptr);
			// }

			T	operator->()
			{
				return (this->_ptr);
			}

			// const_pointer	operator->() const
			// {
			// 	return (this->_ptr);
			// }

			ReverseIterator &operator--()
			{
				++this->_ptr;
				return *this;
			}

			ReverseIterator	operator--(int)
			{
				ReverseIterator tmp(*this);
				++this->_ptr;
				return tmp;
			}

			ReverseIterator	operator+(int value) const
			{
				ReverseIterator tmp(*this);
				return tmp += value;
			}

			ReverseIterator	operator-(int value) const
			{
				ReverseIterator tmp(*this);
				return tmp -= value;
			}

			difference_type	operator-(ReverseIterator const & rhs) const
			{
				return this->_ptr - rhs._ptr;
			}

			bool	operator<(ReverseIterator const & rhs) const
			{
				return this->_ptr > rhs._ptr;
			}

			bool	operator>(ReverseIterator const & rhs) const
			{
				return this->_ptr < rhs._ptr;
			}

			bool	operator<=(ReverseIterator const & rhs) const
			{
				return this->_ptr >= rhs._ptr;
			}

			bool	operator>=(ReverseIterator const & rhs) const
			{
				return this->_ptr <= rhs._ptr;
			}

			ReverseIterator &	operator+=(int value)
			{
				this->_ptr -= value;
				return *this;
			}

			ReverseIterator &	operator-=(int value)
			{
				this->_ptr += value;
				return *this;
			}

			reference	operator[](int value)
			{
				return (*(this->_ptr + value));
			}

			template<typename I, typename U>
			friend bool operator==(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs);

			template<typename I, typename U>
			friend bool operator!=(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs);

			template<typename I, typename U>
			friend bool operator<=(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs);

			template<typename I, typename U>
			friend bool operator>=(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs);

			template<typename I, typename U>
			friend bool operator<(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs);

			template<typename I, typename U>
			friend bool operator>(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs);

	};


	template<typename I, typename U>
	bool operator==(random_access_iterator<I> const &lhs, random_access_iterator<U> const &rhs)
	{
		return (rhs._ptr == lhs._ptr);
	}

	template<typename I, typename U>
	bool operator!=(random_access_iterator<I> const &lhs, random_access_iterator<U> const &rhs)
	{
		return (lhs._ptr != rhs._ptr);
	}

	template<typename I, typename U>
	bool operator<=(random_access_iterator<I> const &lhs, random_access_iterator<U> const &rhs)
	{
		return (lhs._ptr <= rhs._ptr);
	}

	template<typename I, typename U>
	bool operator>=(random_access_iterator<I> const &lhs, random_access_iterator<U> const &rhs)
	{
		return (lhs._ptr >= rhs._ptr);
	}

	template<typename I, typename U>
	bool operator<(random_access_iterator<I> const &lhs, random_access_iterator<U> const &rhs)
	{
		return (lhs._ptr < rhs._ptr);
	}

	template<typename I, typename U>
	bool operator>(random_access_iterator<I> const &lhs, random_access_iterator<U> const &rhs)
	{
		return (lhs._ptr > rhs._ptr);
	}

	template<typename I, typename U>
	bool operator==(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}

	template<typename I, typename U>
	bool operator!=(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs)
	{
		return (lhs._ptr != rhs._ptr);
	}

	template<typename I, typename U>
	bool operator<=(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs)
	{
		return (lhs._ptr <= rhs._ptr);
	}

	template<typename I, typename U>
	bool operator>=(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs)
	{
		return (lhs._ptr >= rhs._ptr);
	}

	template<typename I, typename U>
	bool operator<(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs)
	{
		return (lhs._ptr < rhs._ptr);
	}

	template<typename I, typename U>
	bool operator>(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs)
	{
		return (lhs._ptr > rhs._ptr);
	}

	template<typename T>
	typename ft::random_access_iterator<T> operator+(typename ft::random_access_iterator<T>::difference_type lhs, typename ft::random_access_iterator<T>&	rhs) {
		return (&(*rhs)+lhs);
	}

	template<typename T>
	typename ft::random_access_iterator<T> operator-(typename ft::random_access_iterator<T>::difference_type lhs, typename ft::random_access_iterator<T>&	rhs) {
		return (&(*rhs)-lhs);
	}

	template<typename T>
	ReverseIterator<T> operator+(typename ReverseIterator<T>::difference_type lhs, ReverseIterator<T> const &rhs) {
		return (rhs+lhs);
	}

} // namespace ft

#endif
