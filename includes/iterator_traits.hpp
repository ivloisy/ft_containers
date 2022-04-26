#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft
{

	struct input_iterator_tag {};

	struct output_iterator_tag {};

	struct forward_iterator_tag : public input_iterator_tag {};

	struct bidirectional_iterator_tag : public forward_iterator_tag {};

	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template<class Iterator>
	struct iterator_traits
	{
		public :
			typedef typename Iterator::iterator_category	iterator_category;
			typedef typename Iterator::value_type		value_type;	
			typedef typename Iterator::difference_type	difference_type;	
			typedef typename Iterator::pointer		pointer;	
			typedef typename Iterator::reference		reference;	

	};

	template<typename Tp>
	struct iterator_traits<Tp*> {

		public :
			typedef random_access_iterator_tag	iterator_category;	
			typedef Tp		value_type;	
			typedef std::ptrdiff_t		difference_type;	
			typedef Tp*		pointer;	
			typedef Tp&		reference;
	};

	template<typename Tp>
	struct iterator_traits<const Tp*> {
		public :
			typedef random_access_iterator_tag	iterator_category;	
			typedef Tp		value_type;	
			typedef std::ptrdiff_t		difference_type;	
			typedef const Tp*		pointer;	
			typedef const Tp&		reference;
	};

}
#endif