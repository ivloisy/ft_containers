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

int main()
{
	ft::vector<int>	vec;
	ft::vector<int>	vicky;
	int* arr = vec.get_allocator().allocate(5);
	std::cout << "empty :" << vicky.empty() << std::endl;
	for (int i = 0; i < 5; i++)
	{
		arr[i] = i;
	}
	// ft::vector<int> test(vec);
	arr[3] = 12;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "vec " << arr[i] << std::endl;
		// std::cout << "test " << test[i] << std::endl;
		std::cout << std::endl;
	}
	// std::cout << "begin : " << vec.begin() << std::endl;
	// std::cout << "end : " << *vec.end() << std::endl;
	// std::cout << "size :" << vec.size() << std::endl;
	// std::cout << "max_size :" << vec.max_size() << std::endl;
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
	vec.get_allocator().deallocate(arr, 5);
	return 0;
}