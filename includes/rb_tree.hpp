#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <iostream>

# include "iterator.hpp"
# include "type_traits.hpp"

namespace ft
{
	enum tree_color { _S_red = false, _S_black = true };

	struct rb_tree
	{
		struct node_base
		{
			typedef node_base*			ptr_base;
			typedef const node_base*	const_ptr_base;

			tree_color	_color;
			ptr_base	_parents;
			ptr_base	_left;
			ptr_base	_right;
		};

		template <typename value>
		struct node : public node_base
		{
			typedef node<value>*	link;
			value					_value;
		}
	};
} // namespace ft

#endif
