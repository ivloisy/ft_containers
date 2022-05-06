#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "includes/vector.hpp"
//	#include <map.hpp>
//	#include <stack.hpp>
//	#include <vector.hpp>
#endif

// #include <type_traits>/////////////////////

int main()
{
	ft::vector<int>	vec(5);
	// ft::vector<int>	vicky;

	// std::cout << "vicky.empty():\t" << vicky.empty() << std::endl << std::endl;
	// std::cout << "vec.empty():\t" << vec.empty() << std::endl << std::endl;
	//
	// for (int i = 0; i < 5; i++)
	// {
	// 	vec[i] = i + 1;
	// }
	//
	// ft::vector<int> test(vec);

	// vec[3] = 12;
	// for (int i = 0; i < 5; i++)
	// {
	// 	std::cout << "vec[" << i << "]:\t\t" << vec[i] << std::endl;
	// 	std::cout << "test[" << i << "]:\t" << test[i] << std::endl;
	// 	std::cout << std::endl;
	// }

	// ft::vector<int>::reverse_iterator it = vec.rbegin();
	// ft::vector<int> vickyveil(vec.begin(), --vec.end());
	// std::cout << "rbegin:\t\t" << it << std::endl;
	// std::cout << "begin:\t\t" << *vec.begin() << std::endl;
	// std::cout << "end - 1:\t" << *--vec.end() << std::endl;
	// std::cout << "end :\t" << *vec.end() << std::endl;
	std::cout << "begin:\t\t" << *vec.begin() << std::endl;
	std::cout << "rbegin:\t\t" << vec.rbegin() << std::endl; // Probleme pointeur reverse_iterator
	// std::cout << "size:\t\t" << vec.size() << std::endl;
	// std::cout << "max_size:\t" << vec.max_size() << std::endl;
	// std::cout << "capacity :" << vec.capacity() << std::endl;
	// std::cout << "empty :" << vec.empty() << std::endl;
	// std::cout << "at :" << vec.at(4) << std::endl;
	// std::cout << "back :" << vec.back() << std::endl;
	// std::cout << "front :" << vec.front() << std::endl;
	// arr[0] = 10;
	// std::vector<int> vec();
	// std::cout << *vec.begin() << std::endl;

//	std::cout << vector.begin() << std::endl;

	// arr[3] = 10;

	// std::cout << arr[3] << std::endl;
	//vec.get_allocator().deallocate(arr, 5);
	// std::cout << std::endl << "is_integral:" << std::endl;
	// std::cout << "char: " << std::is_integral<char>::value << std::endl;
	// std::cout << "int: " << std::is_integral<int>::value << std::endl;
	// std::cout << "float: " << std::is_integral<float>::value << std::endl;
	std::cout << std::endl << "is_integral:" << std::endl;
	std::cout << "char: " << ft::is_integral<char>::value << std::endl;
	std::cout << "int: " << ft::is_integral<int>::value << std::endl;
	std::cout << "float: " << ft::is_integral<float>::value << std::endl;
	return 0;
}
