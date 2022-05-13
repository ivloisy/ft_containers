#include <iostream>
#include <string>
#include <deque>
//#include <vector>/////////////////
#if 0 //CREATE A REAL STL EXAMPLE (1=STD 0=FT)
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "includes/vector.hpp"
	#include "includes/stack.hpp"
//	#include <map.hpp>
//	#include <stack.hpp>
//	#include <vector.hpp>
#endif

template <typename T>
void	printVec(ft::vector<T> v, std::string s)
{
	std::cout << "*** " << s << " ***" << std::endl;
	if (v.empty())
	{
		std::cout << s << ".begin():\tnone" << std::endl;
		std::cout << s << ".end():\tnone" << std::endl;
		std::cout << s << ".rbegin():\tnone" << std::endl;
		std::cout << s << ".rend():\tnone" << std::endl;
	}
	else
	{
		std::cout << s << ".begin():\t" << *v.begin() << std::endl;
		std::cout << s << ".end():\t" << *--v.end() << std::endl;
		std::cout << s << ".begin():\t" << *v.rbegin() << std::endl;
		std::cout << s << ".rend():\t" << *v.rend() << std::endl;
	}
	std::cout << s << ".size():\t" << v.size() << std::endl;
	std::cout << s << ".max_size():\t" << v.max_size() << std::endl;
	std::cout << s << ".capacity():\t" << v.capacity() << std::endl;
	std::cout << s << ".empty():\t" << v.empty() << std::endl;
	// std::cout << s << ".end():\t" << *v.end() << std::endl;
	// std::cout << s << ".rbegin():\t" << *v.rbegin() << std::endl;

	std::cout << std::endl;
	for (size_t i = 0; i < v.size(); i++)
		std::cout << s << "[" << i << "] =\t" << v[i] << std::endl;
	std::cout << "**********" << std::endl;
	std::cout << std::endl;
}

int main()
{
	/////////////// VECTOR ///////////////
	ft::vector<int>	v1;

	printVec(v1, "v1");

	std::cout << "{ v1.resize(4) }" << std::endl;
	v1.resize(4);
	std::cout << std::endl;
	printVec(v1, "v1");

	std::cout << "{ v1.reserve(2) }" << std::endl;
	v1.reserve(2);
	std::cout << std::endl;
	printVec(v1, "v1");

	std::cout << "{ v1.reserve(9) }" << std::endl;
	v1.reserve(9);
	std::cout << std::endl;
	printVec(v1, "v1");


	// std::cout << "v1.begin():\t" << v1.begin() << std::endl;

	/////////////// STACK ///////////////
	// ft::stack<int>	s1;
	// ft::stack<int>	s2;

	// if (s1 == s2)
	// 	std::cout << "s1 == s2" << std::endl;
	// else
	// 	std::cout << "s1 != s2" << std::endl;

	// if (s1 >= s2)
	// 	std::cout << "s1 >= s2" << std::endl;
	// else
	// 	std::cout << "s1 < s2" << std::endl;

	// if (s1 <= s2)
	// 	std::cout << "s1 <= s2" << std::endl;
	// else
	// 	std::cout << "s1 > s2" << std::endl;

	// if (s1 < s2)
	// 	std::cout << "s1 < s2" << std::endl;
	// else
	// 	std::cout << "s1 >= s2" << std::endl;

	// if (s1 > s2)
	// 	std::cout << "s1 > s2" << std::endl;
	// else
	// 	std::cout << "s1 <= s2" << std::endl;

	// std::cout << "\ns1.empty():\t" << s1.empty() << std::endl;
	// std::cout << "s1.size():\t" << s1.size() << std::endl;

	// std::cout << "\n{ s1.push(42) }" << std::endl;
	// s1.push(42);
	// std::cout << "{ s1.push(3) }\n" << std::endl;
	// s1.push(3);

	// std::cout << "s1.empty():\t" << s1.empty() << std::endl;
	// std::cout << "s1.size():\t" << s1.size() << std::endl << std::endl;

	// for (size_t i = 0; i < 5; i++)
	// {
	// 	std::cout << "{ s1.push(" << i << ") }" << std::endl;
	// 	s1.push(i);
	// 	std::cout << "s1.top():\t" << s1.top() << std::endl;
	// }

	// std::cout << "\ns1.empty():\t" << s1.empty() << std::endl;
	// std::cout << "s1.size():\t" << s1.size() << std::endl << std::endl;

	// std::cout << "\n{ s1.pop() }" << std::endl;
	// s1.pop();
	// std::cout << "{ s1.pop() }\n" << std::endl;
	// s1.pop();

	// std::cout << "s1.empty():\t" << s1.empty() << std::endl;
	// std::cout << "s1.size():\t" << s1.size() << std::endl;
	// std::cout << "s1.top():\t" << s1.top() << std::endl << std::endl;


	// if (s1 == s2)
	// 	std::cout << "s1 == s2" << std::endl;
	// else
	// 	std::cout << "s1 != s2" << std::endl;

	// if (s1 >= s2)
	// 	std::cout << "s1 >= s2" << std::endl;
	// else
	// 	std::cout << "s1 < s2" << std::endl;

	// if (s1 <= s2)
	// 	std::cout << "s1 <= s2" << std::endl;
	// else
	// 	std::cout << "s1 > s2" << std::endl;

	// if (s1 < s2)
	// 	std::cout << "s1 < s2" << std::endl;
	// else
	// 	std::cout << "s1 >= s2" << std::endl;

	// if (s1 > s2)
	// 	std::cout << "s1 > s2" << std::endl;
	// else
	// 	std::cout << "s1 <= s2" << std::endl;

	return 0;
}
