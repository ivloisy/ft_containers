#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>
// # include <iomanip>
// # include <sstream>
// # include <algorithm>

namespace ft
{
	template <typename T>
	struct	node
	{
		typedef node *	pointer;

		bool	_color;
		pointer	_parent;
		pointer	_left;
		pointer	_right;
		T		_value;

		node(void) : _color(0), _parent(NULL), _left(NULL), _right(NULL), _value(T()) {}
		node(const T & v) : _color(0), _parent(NULL), _left(NULL), _right(NULL), _value(v) {}
		node(const T & v, pointer parent) : _color(0), _parent(parent), _left(NULL), _right(NULL), _value(v) {}
		node(const node & src) : _color(src._color), _parent(src._parent), _left(src._left), _right(src._right), _value(src._value) {}
	};
}

#endif
