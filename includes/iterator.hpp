#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <iterator>
# include "algorithm.hpp"

namespace ft
{

	//
	// struct input_iterator_tag {};
	//
	// struct output_iterator_tag {};
	//
	// struct forward_iterator_tag : public input_iterator_tag {};
	//
	// struct bidirectional_iterator_tag : public forward_iterator_tag {};
	//
	// struct random_access_iterator_tag : public bidirectional_iterator_tag {};


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


	template< class T, class Node >
	class rb_tree_iterator : public iterator <std::bidirectional_iterator_tag, T> {

		public:

			typedef T															value_type;
			typedef typename rb_tree_iterator<T, Node>::reference			reference;
			typedef typename rb_tree_iterator<T, Node>::pointer			pointer;
			typedef typename rb_tree_iterator<T, Node>::difference_type	difference_type;
			typedef Node *														ptr_node;
			typedef Node &														ref_node;

		protected:

			ptr_node	current;
			ptr_node	_root;
			ptr_node	_TNULL;


		public:

			rb_tree_iterator( void ) : current() {};
			explicit rb_tree_iterator( ptr_node x, ptr_node root, ptr_node null ) : current(x), _root(root), _TNULL(null) {};
			rb_tree_iterator( const rb_tree_iterator &other ) : current(other.current), _root(other._root), _TNULL(other._TNULL) {};
			rb_tree_iterator &operator=( const rb_tree_iterator &other )
			{
				current = other.current;
				_root = other._root;
				_TNULL = other._TNULL;
				return *this;
			};
			~rb_tree_iterator( void ) {};

			pointer base( void ) const { return &(current->_value); }

			reference operator*( void ) const { return *base(); }
			pointer operator->( void ) const { return &(operator*()); }

			rb_tree_iterator &operator++( void ) {
				if ( current == max(_root)) {
					current = _TNULL;
					return *this;
				}
				if ( current == _TNULL ) {
					current = _TNULL;
					return *this;
				}
				current = successor(current);
				return *this;
			}

			rb_tree_iterator operator++( int ) { rb_tree_iterator __tmp(this->current, this->_root, this->_TNULL); operator++(); return __tmp; }

			rb_tree_iterator &operator--( void ) {
				if ( !current ) {
					current = max(_root);
					return *this;
				}
				if ( current == _TNULL ) {
					current = max(_root);
					return *this;
				}
				current = predecessor(current);
				return *this;
			}
			rb_tree_iterator operator--( int ) { rb_tree_iterator __tmp(this->current, this->_root, this->_TNULL); operator--(); return __tmp; }

			operator rb_tree_iterator<const T, Node>( void ) const { return rb_tree_iterator<const T, Node>(current, _root, _TNULL); }

					bool
					operator==(const rb_tree_iterator& x) const
					{
						return current == x.current;
					}

					bool
					operator!=(const rb_tree_iterator& x) const
					{
						return current != x.current;
					}

		private:

			ptr_node 			min( ptr_node node ) {

				while ( node != _TNULL && node->_left != _TNULL )
					node = node->_left;
				return node;
			}

			ptr_node 			max( ptr_node node ) {

				while ( node != _TNULL && node->_right != _TNULL)
					node = node->_right;
				return (node);
			}

			ptr_node 			successor( ptr_node node ) {

				if ( node != _TNULL && node->_right != _TNULL )
					return min(node->_right);
				ptr_node tmp = node->_parent;
				while ( tmp && node == tmp->_right) {
					node = tmp;
					tmp = tmp->_parent;
				}
				return tmp;
			}

			ptr_node 			predecessor( ptr_node node ) {

				if ( node != _TNULL && node->_left != _TNULL )
					return (max(node->_left));
				ptr_node tmp = node->_parent;
				while ( tmp && node == tmp->_left )
				{
					node = tmp;
					tmp = tmp->_parent;
				}
				return tmp;
			}


	}; /* class bidirectional_iterator */

	template<class T>
	class random_access_iterator : public iterator <std::random_access_iterator_tag, T>
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

	template <typename T>
	    class ReverseIterator {

			private:
	            T _ptr;
	            typedef iterator_traits<T> _traits;

	        public:
	            typedef typename _traits::difference_type   difference_type;
	            typedef typename _traits::value_type        value_type;
	            typedef typename _traits::pointer           pointer;
	            typedef typename _traits::reference         reference;
	            typedef typename _traits::iterator_category iterator_category;
				typedef T iterator_type;

				T base(void) const { return (this->_ptr); }

	            //================= constructor / copy / destructor =================//
	            ReverseIterator(void): _ptr() {}
	            ReverseIterator(iterator_type ptr): _ptr(ptr) {}
	            template <typename U>
	                ReverseIterator(ReverseIterator<U> const &ref) : _ptr(ref.base()) {}
	            //template <typename U>
	            //    ReverseIterator(Iterator<U> const &ref) : _ptr(ref.base()) {}
	            ~ReverseIterator(void) {}

	            //============================ operator =============================//
	            friend bool operator==(const ReverseIterator &a, const ReverseIterator &b) { return a._ptr == b._ptr; };
	            friend bool operator!=(const ReverseIterator &a, const ReverseIterator &b) { return a._ptr != b._ptr; };
	            reference operator*(void) const {
					iterator_type tmp = this->_ptr;
					--tmp;
					return *tmp;
				}
	            pointer operator->(void) const {
					iterator_type tmp = this->_ptr;
					--tmp;
					return &*tmp;
				}
				//ReverseIterator operator=(const ReverseIterator& a){_ptr = a._ptr; return (*this);}
	            //ReverseIterator &operator=(ReverseIterator<T> const &ref) {
	            //    this->_ptr = ref.base();
	            //    return (*this);
	            //}
	            //ReverseIterator &operator=(pointer ptr) {
	            //    this->_ptr = ptr;
	            //    return (*this);
	            //}
	            ReverseIterator &operator++() {
	                --(this->_ptr);
	                return *this;
	            }
	            ReverseIterator operator++(int) {
	                ReverseIterator tmp = *this;
	                --(this->_ptr);
	                return tmp;
	            }
	            ReverseIterator &operator--() {
	                ++(this->_ptr);
	                return *this;
	            }
	            ReverseIterator operator--(int) {
	                ReverseIterator tmp = *this;
	                ++(this->_ptr);
	                return tmp;
	            }


	            ReverseIterator operator+(difference_type n) const {
	                return (ReverseIterator(this->_ptr - n));
	            }
	            ReverseIterator operator-(difference_type n) const {
	                return (ReverseIterator(this->_ptr + n));
	            }
	            difference_type operator+(ReverseIterator<T> const &ref) const {
	                return (this->_ptr + ref._ptr);
	            }
	            difference_type operator-(ReverseIterator<T> const &ref) const {
	                return (ref._ptr - this->_ptr);
	            }
				ReverseIterator operator+=(difference_type n) {
					this->_ptr -= n;
	                return *this;
	            }
				ReverseIterator operator-=(difference_type n) {
					this->_ptr += n;
	                return *this;
	            }

				bool operator<(ReverseIterator &ref) {
					return (this->_ptr > ref._ptr);
				}
				bool operator>(ReverseIterator &ref) {
					return (this->_ptr < ref._ptr);
				}
				bool operator<=(ReverseIterator &ref) {
					return (this->_ptr >= ref._ptr);
				}
				bool operator>=(ReverseIterator &ref) {
					return (this->_ptr <= ref._ptr);
				}
				reference operator[](difference_type n) const {
					return *(this->_ptr - n - 1);
				}
				// operator	ReverseIterator<T const>(void) const {
				// 	return (ReverseIterator<T const>(this->_ptr));
				// }
	    };;

		template <typename Iter1, typename Iter2>
		bool	operator==(
		ReverseIterator<Iter1> const &lhs,
		ReverseIterator<Iter2> const &rhs) {
			return (lhs.base() == rhs.base());
		}

		template <typename Iter1, typename Iter2>
		bool	operator<(
		ReverseIterator<Iter1> const &lhs,
		ReverseIterator<Iter2> const &rhs) {
			return (lhs.base() > rhs.base());
		}

		template <typename Iter1, typename Iter2>
		bool	operator!=(
		ReverseIterator<Iter1> const &lhs,
		ReverseIterator<Iter2> const &rhs) {
			return (lhs.base() != rhs.base());
		}

		template <typename Iter1, typename Iter2>
		bool	operator>(
		ReverseIterator<Iter1> const &lhs,
		ReverseIterator<Iter2> const &rhs) {
			return (lhs.base() < rhs.base());
		}

		template <typename Iter1, typename Iter2>
		bool	operator>=(
		ReverseIterator<Iter1> const &lhs,
		ReverseIterator<Iter2> const &rhs) {
			return (lhs.base() <= rhs.base());
		}

		template <typename Iter1, typename Iter2>
		bool	operator<=(
		ReverseIterator<Iter1> const &lhs,
		ReverseIterator<Iter2> const &rhs) {
			return (lhs.base() >= rhs.base());
		}

		template <typename Iterator>
		ReverseIterator<Iterator>	operator+(
		typename ReverseIterator<Iterator>::difference_type n,
		ReverseIterator<Iterator> const &iter) {
			return (iter + n);
		}

		template <typename Iterator>
		typename ReverseIterator<Iterator>::difference_type	operator+(
		ReverseIterator<Iterator> const &lhs,
		ReverseIterator<Iterator> const &rhs) {
			return (lhs.base() + rhs.base());
		}


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



} // namespace ft

#endif
