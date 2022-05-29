#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <iterator>
# include "algorithm.hpp"

namespace ft
{


	struct input_iterator_tag {};

	struct output_iterator_tag {};

	struct forward_iterator_tag : public input_iterator_tag {};

	struct bidirectional_iterator_tag : public forward_iterator_tag {};

	struct random_access_iterator_tag : public bidirectional_iterator_tag {};


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

	/* =========================== Distance ================================ */

	template <class T>
	typename ft::iterator_traits<T>::difference_type distance( T first, T last )
	{
		typename ft::iterator_traits<T>::difference_type r;
		for (r = 0; first != last; ++first)
			++r;
		return r;
	};

	/*
	**	random_access_iterator
	*/

	template<typename _Tp, typename node_base >
	class rb_tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, _Tp>
	{
		public :

			typedef _Tp															value_type;
			typedef typename rb_tree_iterator<_Tp, node_base>::reference		reference;
			typedef typename rb_tree_iterator<_Tp, node_base>::pointer			pointer;
			typedef typename rb_tree_iterator<_Tp, node_base>::difference_type	difference_type;

		protected:

			node_base *					current_node;

			node_base* null(void) const
			{
				node_base* _tmp = current_node;
				while ( _tmp->_right )
					_tmp = _tmp->_right;
				return _tmp;
			}

			node_base* root(void) const
			{
				node_base* _tmp = current_node;
				while ( _tmp->_parent )
					_tmp = _tmp->_parent;
				return _tmp;
			}


			node_base* successor(node_base* x) const
			{
				if (x->_right != null())
					return minimum(x->_right);
				node_base* y = x->_parent;
				while (y != null() && x == y->_right)
				{
					x = y;
					y = y->_parent;
				}
				return y;
			}

			node_base* predecessor(node_base* x) const
			{
				if (x->_left != null())
					return maximum(x->_left);
				node_base* y = x->_parent;
				while (y != null() && x == y->_left)
				{
					x = y;
					y = y->_parent;
				}

				return y;
			}

			node_base* minimum(node_base* node) const
			{
				while (node->_left != null())
					node = node->_left;
				return node;
			}

			node_base* maximum(node_base* node) const
			{
				while (node->_right != null())
					node = node->_right;
				return node;
			}

			node_base& test(node_base* node) const
			{
				// while (node->_right != null())
				// 	node = node->_right;
				return node;
			}

		public:

			rb_tree_iterator(): current_node() { }

			explicit rb_tree_iterator(node_base* x)	: current_node(x) { }

			rb_tree_iterator( const rb_tree_iterator &other ) : current_node(other.current_node) {};

			rb_tree_iterator &operator=( const rb_tree_iterator &other ) { current_node = other.current_node; return *this; };

			~rb_tree_iterator( void ) {};

			pointer base( void ) const { return &(current_node->_value); }

			reference operator*( void ) const { return *base(); }
			pointer operator->( void ) const { return &(operator*()); }

			rb_tree_iterator &operator++( void ) {
				if ( current_node == maximum(root())) {
					current_node = null();
					return *this;
				}
				if ( current_node == null() ) {
					current_node = null();
					return *this;
				}
				current_node = successor(current_node);
				return *this;
			}

			rb_tree_iterator operator++( int ) { rb_tree_iterator __tmp(*this); operator++(); return __tmp; }

			rb_tree_iterator &operator--( void ) {
				if ( !current_node ) {
					current_node = maximum(root());
					return *this;
				}
				if ( current_node == null() ) {
					current_node = maximum(root());
					return *this;
				}
				current_node = predecessor(current_node);
				return *this;
			}
			rb_tree_iterator operator--( int ) { rb_tree_iterator __tmp(*this); operator--(); return __tmp; }

			operator rb_tree_iterator<const _Tp, node_base>( void ) const
			{
				return rb_tree_iterator<const _Tp, node_base>(current_node);
			}

			bool
			operator==(const rb_tree_iterator& x) const
			{
				return current_node == x.current_node;
			}

			bool
			operator!=(const rb_tree_iterator& x) const
			{
				return current_node != x.current_node;
			}

	};

	template<class T>
	class random_access_iterator : public iterator <ft::random_access_iterator_tag, T>
	{
		public:
			typedef typename random_access_iterator<T>::iterator_category 	iterator_category;
			typedef typename random_access_iterator<T>::value_type			value_type;
			typedef typename random_access_iterator<T>::difference_type		difference_type;
			typedef typename random_access_iterator<T>::pointer				pointer;
			typedef typename random_access_iterator<T>::const_pointer			const_pointer;
			typedef typename random_access_iterator<T>::reference				reference;
			typedef typename random_access_iterator<T>::const_reference		const_reference;

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

	/* =========================== Reverse_traits ================================ */

	template<typename Iterator>
	class ReverseIterator
	{
		public:
			typedef typename iterator_traits<Iterator>::iterator_category 	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type					value_type;
			typedef typename iterator_traits<Iterator>::difference_type			difference_type;
			typedef typename iterator_traits<Iterator>::pointer							pointer;
			typedef typename iterator_traits<Iterator>::reference						reference;

		private :
			Iterator _it;

		public :

			ReverseIterator() : _it(NULL) {}

			explicit ReverseIterator (Iterator it): _it(it) {}

			template <class U>
			ReverseIterator(const ReverseIterator<U> & src) : _it(src.base()){}

			~ReverseIterator() {}

			Iterator base(void) const { return Iterator(this->_it); }

			reference	operator*()
			{
				Iterator it(this->_it);
				return *--it;
			}

			const reference	operator*() const
			{
				Iterator it(this->_it);
				return *--it;
			}

			ReverseIterator	operator+(difference_type value) const
			{
				// ReverseIterator tmp(*this);
				// return tmp += value;
				return ReverseIterator(this->_it - value);
			}

			difference_type	operator+(ReverseIterator const & rhs) const
			{
				return this->_it + rhs._it;
			}

			ReverseIterator & operator++()
			{
				--this->_it;
				return *this;
			}

			ReverseIterator	operator++(int)
			{
				ReverseIterator tmp = (*this);
				--this->_it;
				return tmp;
			}

			ReverseIterator &	operator+=(difference_type value)
			{
				this->_it -= value;
				return *this;
			}

			ReverseIterator	operator-(difference_type value) const
			{
				return ReverseIterator(this->_it + value);
			}

			difference_type	operator-(ReverseIterator const & rhs) const
			{
				return  rhs._it - this->_it;
			}

			ReverseIterator &operator--()
			{
				++this->_it;
				return *this;
			}

			ReverseIterator	operator--(int)
			{
				ReverseIterator tmp(*this);
				++this->_it;
				return tmp;
			}

			ReverseIterator &	operator-=(difference_type value)
			{
				this->_it += value;
				return *this;
			}

			Iterator	operator->()
			{
				return this->_it - 1;
			}

			reference	operator[](difference_type value)
			{
				return *(this->_it - value - 1);
			}
			//

			bool	operator==(ReverseIterator const & rhs) const
			{
				return this->_it == rhs._it;
			}
			//
			bool	operator!=(ReverseIterator const &rhs) const
			{
				return this->_it != rhs._it;
			}
			//
			// // const_reference	operator*() const
			// // {
			// // 	return *(this->_ptr);
			// // }
			// const Iterator	operator->() const
			// {
			// 	return this->_it;
			// }

			// // const_pointer	operator->() const
			// // {
			// // 	return (this->_ptr);
			// // }

			bool	operator<(ReverseIterator const & rhs) const
			{
				return this->_it > rhs._it;
			}

			bool	operator>(ReverseIterator const & rhs) const
			{
				return this->_it < rhs._it;
			}

			bool	operator<=(ReverseIterator const & rhs) const
			{
				return this->_it >= rhs._it;
			}

			bool	operator>=(ReverseIterator const & rhs) const
			{
				return this->_it <= rhs._it;
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

	template<typename T>
	typename ft::random_access_iterator<T> operator+(typename ft::random_access_iterator<T>::difference_type lhs, typename ft::random_access_iterator<T>&	rhs) {
		return (&(*rhs)+lhs);
	}

	template<typename T>
	typename ft::random_access_iterator<T> operator-(typename ft::random_access_iterator<T>::difference_type lhs, typename ft::random_access_iterator<T>&	rhs) {
		return (&(*rhs)-lhs);
	}


	template<typename I, typename U>
	bool operator==(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs)
	{
		return (lhs._it == rhs._it);
	}

	template<typename I, typename U>
	bool operator!=(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs)
	{
		return (lhs._it != rhs._it);
	}

	template<typename I, typename U>
	bool operator<=(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs)
	{
		return (lhs._it >= rhs._it);
	}

	template<typename I, typename U>
	bool operator>=(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs)
	{
		return (lhs._it <= rhs._it);
	}

	template<typename I, typename U>
	bool operator<(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs)
	{
		return (lhs._it > rhs._it);
	}

	template<typename I, typename U>
	bool operator>(ReverseIterator<I> const &lhs, ReverseIterator<U> const &rhs)
	{
		return (lhs._it < rhs._it);
	}

	template<typename T>
	ReverseIterator<T> operator+(typename ReverseIterator<T>::difference_type lhs, ReverseIterator<T> const &rhs) {
		return (rhs+lhs);
	}

} // namespace ft

#endif
