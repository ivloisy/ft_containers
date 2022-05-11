#include <iostream>
#include <string>
#include <deque>
//#include <vector>/////////////////
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

int main()
{
	ft::vector<int>	vec(4);
	// std::vector<int>	vic(5);
	ft::vector<int> allo(3);
	ft::vector<int>	vicky;

	std::cout << "vicky.empty():\t" << vicky.empty() << std::endl;
	std::cout << "vec.empty():\t" << vec.empty() << std::endl;
	std::cout << "vec.max_size():\t" << vec.max_size() << std::endl;
	std::cout << "vec.capacity():\t" << vec.capacity() << std::endl;
	std::cout << "vec.size():\t" << vec.size() << std::endl << std::endl;


	for (size_t i = 0; i < vec.size(); i++)
	{
		// vic[i] = i + 1;
		vec[i] = i + 1;
	}
	// std::cout << "vec.size():\t" << vec.size() << std::endl << std::endl;

	// ft::vector<int> test(vec);

	vec.push_back(27);
	vec.push_back(28);
	// vec.pop_back();
	vec[3] = 12;
	// vic[3] = 12;
	std::cout << "vec.capacity():\t" << vec.capacity() << std::endl;
	std::cout << "vec.size():\t" << vec.size() << std::endl << std::endl;

	vec.push_back(27);
	vec.push_back(28);
	vec.push_back(27);
	vec.push_back(28);
	std::cout << "vec.capacity():\t" << vec.capacity() << std::endl;
	std::cout << "vec.size():\t" << vec.size() << std::endl << std::endl;

	ft::vector<int>	vic(vec.begin() + 1, vec.end() - 2);
	for (size_t j = 0; j < vic.size(); j++)
		std::cout << *(vic.begin() + (int)j) << std::endl;
	std::cout << std::endl;

	std::cout << "vec.size():\t" << vec.size() << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << "vec[" << i << "]:\t\t" << vec[i] << std::endl;
		// std::cout << "test[" << i << "]:\t" << test[i] << std::endl;
		// std::cout << "vic[" << i << "]:\t\t" << vic[i] << std::endl;
		// std::cout << std::endl;
	}
	std::cout << std::endl;

	// ft::vector<int>::reverse_iterator it = vec.rbegin();
//	ft::vector<int> vickyveil(vec.begin(), --vec.end());
	// std::cout << "rbegin:\t\t" << it << std::endl;
	std::cout << "*vec.begin():\t" << *vec.begin() << std::endl;
	std::cout << "*--vec.end():\t" << *--vec.end() << std::endl;
	std::cout << "*vec.end():\t" << *vec.end() << std::endl;
	std::cout << "*vec.begin():\t" << *vec.begin() << std::endl;
	std::cout << "*vec.rbegin():\t" << *vec.rbegin() << std::endl; // Probleme pointeur reverse_iterator
	std::cout << "*vic.rbegin():\t" << *vic.rbegin() << std::endl; // Probleme pointeur reverse_iterator
	std::cout << "*vec.rend():\t" << *vec.rend() << std::endl;
	std::cout << "*vic.rend():\t" << *vic.rend() << std::endl; // Probleme pointeur reverse_iterator
	// std::cout << "rend :\t" << *vic.rend() << std::endl;
	// std::cout << "size:\t\t" << vec.size() << std::endl;
	// std::cout << "max_size:\t" << vec.max_size() << std::endl;
	std::cout << "vec.capacity():\t" << vec.capacity() << std::endl;
	// std::cout << "empty :" << vec.empty() << std::endl;
	// std::cout << "at :" << vec.at(4) << std::endl;
	// std::cout << "back :" << vec.back() << std::endl;
	// std::cout << "front :" << vec.front() << std::endl;
	// arr[0] = 10;
	// std::vector<int> vec();
	// std::cout << *vec.begin() << std::endl;

//	std::cout << vector.begin() << std::endl;

	// allo.resize(6, 4);
	// for (size_t i = 0; i < allo.size(); i++)
	// 	std::cout << "allo[" << i << "]:\t" << allo[i] << std::endl;

	// std::cout << std::endl;
	// allo.resize(4, 12);
	// for (size_t i = 0; i < allo.size(); i++)
	// 	std::cout << "allo[" << i << "]:\t" << allo[i] << std::endl;
	// std::cout << std::endl;

	// allo.resize(12, 3);
	// for (size_t i = 0; i < allo.size(); i++)
	// 	std::cout << "allo[" << i << "]:\t" << allo[i] << std::endl;

	// std::cout << std::endl;
	// allo.erase(allo.begin(), allo.begin() + 2);
	// for (size_t i = 0; i < allo.size(); i++)
	// 	std::cout << "allo[" << i << "]:\t" << allo[i] << std::endl;

	// for (size_t i = 0; i < allo.size(); i++)
	// {
	// //		vic[i] = i + 1;
	// 	allo[i] = i + 1;
	// }
	// std::cout << std::endl;
	// for (size_t i = 0; i < allo.size(); i++)
	// 	std::cout << "allo[" << i << "]:\t" << allo[i] << std::endl;

	// allo.insert(allo.begin() + 3, 387);
	// std::cout << std::endl;
	// for (size_t i = 0; i < allo.size(); i++)
	// 	std::cout << "allo[" << i << "]:\t" << allo[i] << std::endl;

	// // allo.insert(allo.begin() + 5, 4, 888);
	// // std::cout << std::endl;
	// // for (size_t i = 0; i < allo.size(); i++)
	// // 	std::cout << "allo[" << i << "]:\t" << allo[i] << std::endl;
	// // arr[3] = 10;

	// // std::cout << arr[3] << std::endl;
	// //vec.get_allocator().deallocate(arr, 5);
	// // std::cout << std::endl << "is_integral:" << std::endl;
	// // std::cout << "char: " << std::is_integral<char>::value << std::endl;
	// // std::cout << "int: " << std::is_integral<int>::value << std::endl;
	// // std::cout << "float: " << std::is_integral<float>::value << std::endl;
	// std::cout << std::endl << "is_integral:" << std::endl;
	// std::cout << "char: " << ft::is_integral<char>::value << std::endl;
	// std::cout << "int: " << ft::is_integral<int>::value << std::endl;
	// std::cout << "float: " << ft::is_integral<float>::value << std::endl;
	return 0;
}
