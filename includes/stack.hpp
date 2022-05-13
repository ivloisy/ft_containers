#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{

	template <class T, class Container = ft::vector<T> > 
	class stack
	{
		public:
			typedef T			value_type;
			typedef Container  	container_type;
			typedef size_t		size_type;

		private:
			container_type	c;

		public:
			explicit	stack (const container_type & ctnr = container_type()) : c(ctnr) {}

			bool	empty() const { return this->c.empty(); }

			size_type	size() const { return this->c.size(); }

			value_type &	top() { return this->c.back(); }

			const value_type &	top() const { return this->c.back(); }

			void	push(const value_type & val) { this->c.push_back(val); }

			void	pop() { this->c.pop_back(); }

	};

} // namespace ft


#endif