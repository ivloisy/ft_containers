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
	#include "includes/map.hpp"
	#include "includes/rb_tree.hpp"
	#include "includes/utility.hpp"
	#include <map>
//	#include <stack.hpp>
//	#include <vector.hpp>
	// #include <tree>
#endif

int main()
{
	ft::map<char, int>	m1;
	// int x = 1;
<<<<<<< HEAD
	// ft::pair<int, int> lala(1, 3);
	// ft::pair<int, int> lolo(12, 4);
	// ft::pair<int, int> lulu(4, 2);
	// ft::pair<int, int> lili(5, 7);
	// ft::pair<int, int> lele(5, 7);
	//
	//
	//
	//
	// ft::rb_tree<int, ft::pair<int, int>, int, std::less<int> > test;
	//
	// ft::pair<ft::rb_tree<int, ft::pair<int, int>, int, std::less<int> >::rb_tree_iterator<ft::pair<int, int> >, bool> it;
	//
	//
	// std::cout << "ok" << std::endl;
	// it = test.insert(lala);
	//
	// std::cout << it.second << std::endl;
	//
	// it = test.insert(lolo);
	// std::cout << it.second << std::endl;
	// it = test.insert(lulu);
	// std::cout << it.second << std::endl;
	// it = test.insert(lili);
	// std::cout << it.second << std::endl;
	// it = test.insert(lele);
	// std::cout << it.second << std::endl;
	//
	// test.printTree();
=======
	ft::pair<int, int> lala(1, 3);
	ft::pair<int, int> lolo(12, 4);
	ft::pair<int, int> lulu(4, 2);
	ft::pair<int, int> lili(5, 7);
	// ft::pair<int, int> lele(5, 7);




	ft::rb_tree<int, ft::pair<int, int>, int, std::less<int> > test;

	ft::pair<ft::rb_tree<int, ft::pair<int, int>, int, std::less<int> >::rb_tree_iterator<ft::pair<int, int> >, bool> it;


	std::cout << "ok" << std::endl;
	it = test.insert(lala);

	std::cout << it.second << std::endl;

	it = test.insert(lolo);
	std::cout << it.second << std::endl;
	it = test.insert(lulu);
	std::cout << it.second << std::endl;
	it = test.insert(lili);
	std::cout << it.second << std::endl;
	// it = test.insert(lele);
	// std::cout << it.second << std::endl;
	test.deleteNode(4);
	test.deleteNode(1);
	test.deleteNode(12);
	test.deleteNode(5);

	test.printTree();
>>>>>>> 4f2de291788e904fdfa00c72157a3eda4c08bdc2

// 	ft::vector<int>			test(3, 3);
// //
// 	ft::vector<int>::reference tmp = test[1];
// 	std::cout << tmp << std::endl;
// 	std::cout << "self assignation test\n";
// 	ft::vector<ft::vector<int> >	self_assign;
// 	ft::vector<ft::vector<int> >	*ptr = &self_assign;
// 	ft::vector<ft::vector<int> >	*ptr2 = &self_assign;
//
// 	self_assign.assign(4, test);
// 	*ptr = *ptr2;
//
// 	std::cout << std::boolalpha << (*ptr == *ptr2) << '\n';
// 	//	self_assign = self_assign; //compiler doesn't like it!
//
//
//
// 	ft::vector<ft::vector<int> > JOHN;
// 	ft::vector<ft::vector<int> > BOB(5, test);
// 	std::cout << "BOB(5, test(test, 5)) : \n";
// 	for (size_t i = 0; i < BOB.size(); i++)
// 	{
// 		for (size_t j = 0; j < BOB[i].size(); j++)
// 			std::cout << BOB[i][j] << ' ';
// 		std::cout << '\n';
// 	}
// 	ft::vector<ft::vector<int> > MIKE(BOB);
// 	// std::cout << "fin" << std::endl;
//
// 	// CTORs
// 	std::cout << "\nCTORS\n";
// 	std::cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
// 	std::cout << "BOB is empty? " << BOB.empty() << '\n';
//
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	std::cout << "Size of MIKE " << MIKE.capacity() << std::endl;
//
// 	// RESIZE
// 	size_t	bob_resize = 2;
// 	std::cout << "\nRESIZE\n";
// 	BOB.resize(bob_resize);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= bob_resize)
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
// 	std::cout << "Size of MIKE " << MIKE.capacity() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";
//
// 	size_t	mike_resize = 9;
// 	bob_resize = 0;
//
// 	BOB.resize(bob_resize);
// 	std::cout << "BOB is empty now ? " << BOB.empty() << '\n';
// 	std::cout << "Size of MIKE " << MIKE.capacity() << std::endl;
// 	MIKE.resize(mike_resize, test);
// 	std::cout << "Size of MIKE " << MIKE.capacity() << std::endl;
// 	std::cout << "//////////////////////// capacity attendue 9 : " << MIKE.capacity() << std::endl;
// 	// return 1;
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= bob_resize)
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= mike_resize)
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 		{
// 			std::cout << MIKE[i][j] << ' ';
// 		}
// 	std::cout << std::endl;
// 	}
//
// 	// RESERVE
// 	std::cout << "\nRESERVE\n";
//
// 	size_t	john_reserve = 0;
// 	size_t	bob_reserve = 3;
// 	size_t	mike_reserve = 4;
//
// 	JOHN.reserve(john_reserve);
// 	BOB.reserve(bob_reserve);
// 	MIKE.reserve(mike_reserve);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= john_reserve)
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= bob_reserve)
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= mike_reserve)
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			std::cout << MIKE[i][j] << ' ';
// 	std::cout << std::endl;
// 	}
//
// 	//AT
// 	std::cout << "\nAT\n";
// 	try
// 	{
// 		std::cout << MIKE.at(2).front() << '\n';
// 		std::cout << MIKE.at(87).back() << '\n';
// 	}
// 	catch (std::out_of_range& oor)
// 	{
// 		(void)oor;
// 		std::cout << "OOR error caught\n";
// 	}
// 	// FRONT / BACK
// 	std::cout << "\nFRONT / BACK\n";
// 	std::cout << "front() of MIKE : " << MIKE.front().front() << '\n';
// 	std::cout << "back() of MIKE : " << MIKE.back().back() << '\n';
//
// 	//ASSIGN
// 	std::cout << "\nASSIGN\n";
// 	test.assign(3, 17);
// 	BOB.assign(3, test);
//
// 	//ASSIGN RANGE
// 	std::cout << "\nASSIGN RANGE\n";
// 	ft::vector<ft::vector<int> >	assign_range;
// 	std::cout << "init : " << assign_range.capacity() << ", " << assign_range.size() << std::endl;
// 	assign_range.assign(8, test);
// 	std::cout << "before : " << assign_range.capacity() << ", " << assign_range.size() << std::endl;
// 	std::cout << BOB.size() << std::endl;
// 	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);
// 	std::cout << "after : " << assign_range.capacity() << ", " << assign_range.size() << std::endl;
// 	// return 1;
// 	//EMPTY
// 	std::cout << "\nEMPTY\n";
// 	std::cout << "BOB is empty ? " << BOB.empty() << '\n';
// 	std::cout << "BOB at(1) : " << BOB.at(1).front() << '\n';
//
// 	//PUSH/POP_BACK
// 	std::cout << "\nPUSH/POP_BACK\n";
// 	test.assign(2, 42);
// 	BOB.push_back(test);
// 	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';
// 	BOB.pop_back();
// 	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';
//
// 	//INSERT
// 	std::cout << "\nINSERT\n";
// 	ft::vector<ft::vector<int> >	insert_in_me;
// 	for (int i = 0; i < 15; i++)
// 	{
// 		ft::vector<int>	j(2, i);
// 		insert_in_me.push_back(j);
// 	}
// 	for (size_t i = 0; i < insert_in_me.size(); i++)
// 	{
// 		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
// 			std::cout << insert_in_me.at(i).at(j) << ' ';
// 		std::cout << '\n';
// 	}
//
// 	ft::vector<ft::vector<int> >::iterator	tmp;
// 	test.assign(23, 19);
// 	tmp = insert_in_me.begin() + 4;
// 	insert_in_me.insert(tmp, 8, test);
// 	for (size_t i = 0; i < insert_in_me.size(); i++)
// 	{
// 		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
// 			std::cout << insert_in_me.at(i).at(j) << ' ';
// 		std::cout << '\n';
// 	}
//
// 	ft::vector<ft::vector<int> >::const_iterator const_it(insert_in_me.begin());
// 	std::cout << "Const it.front() : " << std::endl;
// 	std::cout << (*const_it).front() << '\n';
//
//
// 	//INSERT
// 	std::cout << "\nINSERT\n";
// 	ft::vector<ft::vector<int> >	std_insert_in_me;
// 	for (int i = 0; i < 15; i++)
// 		std_insert_in_me.push_back(test);
// 	for (size_t i = 0; i < std_insert_in_me.size(); i++)
// 		std::cout << std_insert_in_me.at(i).front() << ' ';
// 	std::cout << '\n';
//
// 	ft::vector<ft::vector<int> >::iterator	std_tmp;
// 	std_tmp = std_insert_in_me.begin() + 4;
// 	std_insert_in_me.insert(std_tmp, 8, test);
// 	for (size_t i = 0; i < std_insert_in_me.size(); i++)
// 		std::cout << std_insert_in_me.at(i).back() << ' ';
// 	std::cout << '\n';
//
//
// 	//INSERT RANGE
// 	std::cout << "\nINSERT RANGE\n";
// 	ft::vector<ft::vector<int> >	insert_bis;
// 	for (int i = 0; i < 7; i++)
// 	{
// 		ft::vector<int>	j(2, i * 3);
// 		insert_bis.push_back(j);
// 	}
// 	for (size_t i = 0; i < insert_bis.size(); i++)
// 		std::cout << insert_bis[i].back() << ' ';
// 	std::cout << '\n';
//
// 	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
// 	for (size_t i = 0; i < insert_bis.size(); i++)
// 		std::cout << insert_bis[i].back() << ' ';
// 	std::cout << '\n';
//
//
// 	//ERASE
// 	std::cout << "\nERASE\n";
// 	ft::vector<ft::vector<int> >	erase_in_me;
// 	for (int i = 0; i < 15; i++)
// 	{
// 		ft::vector<int>	j(1, i);
// 		erase_in_me.push_back(j);
// 	}
// 	for (size_t i = 0; i < erase_in_me.size(); i++)
// 		std::cout << erase_in_me.at(i).front() << ' ';
// 	std::cout << '\n';
//
// 	erase_in_me.erase(erase_in_me.begin() + 7);
// 	for (size_t i = 0; i < erase_in_me.size(); i++)
// 		std::cout << erase_in_me.at(i).front() << ' ';
// 	std::cout << '\n';
// 	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
// 	for (size_t i = 0; i < erase_in_me.size(); i++)
// 		std::cout << erase_in_me.at(i).front() << ' ';
// 	std::cout << '\n';
//
// 	//SWAP
// 	std::cout << "\nSWAP\n";
// 	john_reserve = 4;
// 	JOHN.reserve(john_reserve);
// 	BOB.swap(MIKE);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= BOB.size())
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			std::cout << MIKE[i][j] << ' ';
// 	std::cout << std::endl;
// 	}
//
// 	MIKE.swap(JOHN);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= BOB.size())
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			std::cout << MIKE[i][j] << ' ';
// 	std::cout << std::endl;
// 	}
//
// 	//CLEAR
// 	std::cout << "\nCLEAR\n";
// 	JOHN.clear();
// 	MIKE.clear();
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= BOB.size())
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			std::cout << MIKE[i][j] << ' ';
// 	std::cout << std::endl;
// 	}
//
// 	//NON MEMBER Functions
// 	std::cout << "\nNON MEMBER functions\n";
// 	swap(BOB, MIKE);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= BOB.size())
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			std::cout << MIKE[i][j] << ' ';
// 	std::cout << std::endl;
// 	}
//
// 	//RELATIONAL OPERATORS
// 	std::cout << "\nRELATIONAL OPERATORS\n";
// 	ft::vector<ft::vector<int> > MIKE_2(MIKE);
// 	std::cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
// 	std::cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';
//
// 	std::cout << "\nReal Vector\n";
// 	ft::vector<ft::vector<int> > real;
// 	real.assign(5, test);
// 	for (ft::vector<ft::vector<int> >::iterator it = real.begin(); it != real.end(); it++)
// 		std::cout << (*it).front() << " ";
// 	std::cout << '\n';
//
// 	std::cout << std::endl;
//
// 	// ft::vector<int>	vec(4);
// 	// ft::vector<int>	vla(vec);
// 	// // std::vector<int>	vic(5);
// 	// ft::vector<int> allo(3);
// 	// ft::vector<int>	vicky;
// 	//
// 	// std::cout << "vicky.empty():\t" << vicky.empty() << std::endl;
// 	// std::cout << "vec.empty():\t" << vec.empty() << std::endl;
// 	// std::cout << "vec.max_size():\t" << vec.max_size() << std::endl;
// 	// std::cout << "vec.capacity():\t" << vec.capacity() << std::endl;
// 	// std::cout << "vec.size():\t" << vec.size() << std::endl << std::endl;
// 	//
// 	//
// 	// for (size_t i = 0; i < vec.size(); i++)
// 	// {
// 	// 	// vic[i] = i + 1;
// 	// 	vec[i] = i + 1;
// 	// }
// 	// std::cout << "vec.size():\t" << vec.size() << std::endl << std::endl;
//
// 	// ft::vector<int> test(vec);
//
// 	// vec.push_back(27);
// 	// vec.push_back(28);
// 	// vec.pop_back();
// 	// vec[3] = 12;
// 	// // vic[3] = 12;
// 	// std::cout << "vec.capacity():\t" << vec.capacity() << std::endl;
// 	// std::cout << "vec.size():\t" << vec.size() << std::endl << std::endl;
// 	//
// 	// vec.push_back(27);
// 	// vec.push_back(28);
// 	// vec.push_back(27);
// 	// vec.push_back(28);
// 	// std::cout << "vec.capacity():\t" << vec.capacity() << std::endl;
// 	// std::cout << "vec.size():\t" << vec.size() << std::endl << std::endl;
//
// 	// class human
// 	// {
// 	// private:
// 	// 	/* data */
// 	// public:
// 	// 	human(/* args */){}
// 	// 	~human(){}
// 	// };
// 	//
// 	// human	A;
// 	// human	B;
//
// 	// ft::vector<int>	vic(vec.begin() + 1, vec.end() - 2);
// 	// // ft::vector<int>	vic(A, B);
// 	// for (size_t j = 0; j < vic.size(); j++)
// 	// 	std::cout << *(vic.begin() + (int)j) << std::endl;
// 	// std::cout << std::endl;
// 	//
// 	// std::cout << "vec.size():\t" << vec.size() << std::endl;
// 	// for (size_t i = 0; i < vec.size(); i++)
// 	// {
// 	// 	std::cout << "vec[" << i << "]:\t\t" << vec[i] << std::endl;
// 	// 	// std::cout << "test[" << i << "]:\t" << test[i] << std::endl;
// 	// 	// std::cout << "vic[" << i << "]:\t\t" << vic[i] << std::endl;
// 	// 	// std::cout << std::endl;
// 	// }
// 	// std::cout << std::endl;
//
// 	// ft::vector<int>::reverse_iterator it = vec.rbegin();
// //	ft::vector<int> vickyveil(vec.begin(), --vec.end());
// 	// std::cout << "rbegin:\t\t" << it << std::endl;
// 	// std::cout << "*vec.begin():\t" << *vec.begin() << std::endl;
// 	// std::cout << "*--vec.end():\t" << *--vec.end() << std::endl;
// 	// std::cout << "*vec.end():\t" << *vec.end() << std::endl;
// 	// std::cout << "*vec.begin():\t" << *vec.begin() << std::endl;
// 	// std::cout << "*vec.rbegin():\t" << *vec.rbegin() << std::endl; // Probleme pointeur reverse_iterator
// 	// std::cout << "*vic.rbegin():\t" << *vic.rbegin() << std::endl; // Probleme pointeur reverse_iterator
// 	// std::cout << "*vec.rend():\t" << *vec.rend() << std::endl;
// 	// std::cout << "*vic.rend():\t" << *vic.rend() << std::endl; // Probleme pointeur reverse_iterator
// 	// std::cout << "rend :\t" << *vic.rend() << std::endl;
// 	// std::cout << "size:\t\t" << vec.size() << std::endl;
// 	// std::cout << "max_size:\t" << vec.max_size() << std::endl;
// //	std::cout << "vec.capacity():\t" << vec.capacity() << std::endl;
// 	// std::cout << "empty :" << vec.empty() << std::endl;
// 	// std::cout << "at :" << vec.at(4) << std::endl;
// 	// std::cout << "back :" << vec.back() << std::endl;
// 	// std::cout << "front :" << vec.front() << std::endl;
// 	// arr[0] = 10;
// 	// std::vector<int> vec();
// 	// std::cout << *vec.begin() << std::endl;
// 	// std::cout << std::endl;
//
// // ================================== ASSIGN =======================================
// 	// ft::vector<int>	caca(4);
// 	// for (size_t i = 0; i < caca.size(); i++)
// 	// 	caca[i] = i + 1;
// 	// std::cout << "caca:" << std::endl;
// 	// for (size_t i = 0; i < caca.size(); i++)
// 	// 	std::cout << caca[i] << std::endl;
// 	//
// 	// std::cout << "caca.size():\t\t" << caca.size() << std::endl;
// 	// std::cout << "caca.capacity():\t" << caca.capacity() << std::endl;
// 	//
// 	// caca.push_back(5);
// 	// std::cout << std::endl << "after pushback:" << std::endl;
// 	// std::cout << "caca.size():\t\t" << caca.size() << std::endl;
// 	// std::cout << "caca.capacity():\t" << caca.capacity() << std::endl;
// 	//
// 	// // size_t prout = 3;
// 	// caca.assign(3, 42);
// 	// std::cout << std::endl << "after assign:" << std::endl;
// 	// std::cout << "caca.size():\t\t" << caca.size() << std::endl;
// 	// std::cout << "caca.capacity():\t" << caca.capacity() << std::endl;
// 	//
// 	// std::cout << std::endl << "caca:" << std::endl;
// 	// for (size_t i = 0; i < caca.size(); i++)
// 	// 	std::cout << caca[i] << std::endl;
// 	//
// 	//
// 	// int noufnouf[] = {5, 156, 123, 45689};
// 	// ft::vector<int> nana;
// 	// nana.assign(noufnouf, noufnouf + 3);
// 	// std::cout << std::endl << "nana:" << std::endl;
// 	// for (size_t i = 0; i < nana.size(); i++)
// 	// 	std::cout << nana[i] << std::endl;
// 	// int	test[5] = {42,6,57,11,32};
//
// 	// ft::vector<int>	pipi(4);
// 	// pipi.assign(test, test + 4);
// 	// // for (size_t i = 0; i < pipi.size(); i++)
// 	// // 	caca[i] = i + 1;
// 	// std::cout << "pipi:" << std::endl;
// 	// for (size_t i = 0; i < pipi.size(); i++)
// 	// 	std::cout << pipi[i] << std::endl;
//
// 	// std::cout << "caca.size():\t\t" << pipi.size() << std::endl;
// 	// std::cout << "caca.capacity():\t" << pipi.capacity() << std::endl;
//
// 	// caca.push_back(5);
// 	// std::cout << std::endl << "after pushback:" << std::endl;
// 	// std::cout << "caca.size():\t\t" << caca.size() << std::endl;
// 	// std::cout << "caca.capacity():\t" << caca.capacity() << std::endl;
//
// 	// caca.assign(3, 42);
// 	// std::cout << std::endl << "after assign:" << std::endl;
// 	// std::cout << "caca.size():\t\t" << caca.size() << std::endl;
// 	// std::cout << "caca.capacity():\t" << caca.capacity() << std::endl;
//
// 	// std::cout << std::endl << "caca:" << std::endl;
// 	// for (size_t i = 0; i < caca.size(); i++)
// 	// 	std::cout << caca[i] << std::endl;
// //	std::cout << vector.begin() << std::endl;
//
// 	// allo.resize(6, 4);
// 	// for (size_t i = 0; i < allo.size(); i++)
// 	// 	std::cout << "allo[" << i << "]:\t" << allo[i] << std::endl;
// 	//
// 	// std::cout << std::endl;
// 	// allo.resize(4, 12);
// 	// for (size_t i = 0; i < allo.size(); i++)
// 	// 	std::cout << "allo[" << i << "]:\t" << allo[i] << std::endl;
// 	// std::cout << std::endl;
// 	//
// 	// allo.resize(12, 3);
// 	// for (size_t i = 0; i < allo.size(); i++)
// 	// 	std::cout << "allo[" << i << "]:\t" << allo[i] << std::endl;
// 	//
// 	// std::cout << std::endl;
// 	// allo.erase(allo.begin(), allo.begin() + 2);
// 	// for (size_t i = 0; i < allo.size(); i++)
// 	// 	std::cout << "allo[" << i << "]:\t" << allo[i] << std::endl;
// 	//
// 	// for (size_t i = 0; i < allo.size(); i++)
// 	// {
// 	// //		vic[i] = i + 1;
// 	// 	allo[i] = i + 1;
// 	// }
// 	// std::cout << std::endl;
// 	// for (size_t i = 0; i < allo.size(); i++)
// 	// 	std::cout << "allo[" << i << "]:\t" << allo[i] << std::endl;
// 	//
// 	// allo.insert(allo.begin() + 3, 387);
// 	// std::cout << std::endl;
// 	// for (size_t i = 0; i < allo.size(); i++)
// 	// 	std::cout << "allo[" << i << "]:\t" << allo[i] << std::endl;
// 	//
// 	// allo.insert(allo.begin() + 5, 4, 888);
// 	// std::cout << std::endl;
// 	// for (size_t i = 0; i < allo.size(); i++)
// 	// 	std::cout << "allo[" << i << "]:\t" << allo[i] << std::endl;
// 	// arr[3] = 10;
//
// 	// // std::cout << arr[3] << std::endl;
// 	// //vec.get_allocator().deallocate(arr, 5);
// 	// // std::cout << std::endl << "is_integral:" << std::endl;
// 	// // std::cout << "char: " << std::is_integral<char>::value << std::endl;
// 	// // std::cout << "int: " << std::is_integral<int>::value << std::endl;
// 	// // std::cout << "float: " << std::is_integral<float>::value << std::endl;
// 	// std::cout << std::endl << "is_integral:" << std::endl;
// 	// std::cout << "char: " << ft::is_integral<char>::value << std::endl;
// 	// std::cout << "int: " << ft::is_integral<int>::value << std::endl;
// 	// std::cout << "float: " << ft::is_integral<float>::value << std::endl;
//
// 	//////////////// STACK ////////////////
// 	// ft::stack<int>	s1;
// 	// ft::stack<int>	s2;
// 	//
// 	// if (s1 == s2)
// 	// 	std::cout << "s1 == s2" << std::endl;
// 	// else
// 	// 	std::cout << "s1 != s2" << std::endl;
// 	//
// 	// if (s1 >= s2)
// 	// 	std::cout << "s1 >= s2" << std::endl;
// 	// else
// 	// 	std::cout << "s1 < s2" << std::endl;
// 	//
// 	// if (s1 <= s2)
// 	// 	std::cout << "s1 <= s2" << std::endl;
// 	// else
// 	// 	std::cout << "s1 > s2" << std::endl;
// 	//
// 	// if (s1 < s2)
// 	// 	std::cout << "s1 < s2" << std::endl;
// 	// else
// 	// 	std::cout << "s1 >= s2" << std::endl;
// 	//
// 	// if (s1 > s2)
// 	// 	std::cout << "s1 > s2" << std::endl;
// 	// else
// 	// 	std::cout << "s1 <= s2" << std::endl;
// 	//
// 	// std::cout << "\ns1.empty():\t" << s1.empty() << std::endl;
// 	// std::cout << "s1.size():\t" << s1.size() << std::endl;
// 	//
// 	// std::cout << "\n{ s1.push(42) }" << std::endl;
// 	// s1.push(42);
// 	// std::cout << "{ s1.push(3) }\n" << std::endl;
// 	// s1.push(3);
// 	//
// 	// std::cout << "s1.empty():\t" << s1.empty() << std::endl;
// 	// std::cout << "s1.size():\t" << s1.size() << std::endl << std::endl;
// 	//
// 	// for (size_t i = 0; i < 5; i++)
// 	// {
// 	// 	std::cout << "{ s1.push(" << i << ") }" << std::endl;
// 	// 	s1.push(i);
// 	// 	std::cout << "s1.top():\t" << s1.top() << std::endl;
// 	// }
// 	//
// 	// std::cout << "\ns1.empty():\t" << s1.empty() << std::endl;
// 	// std::cout << "s1.size():\t" << s1.size() << std::endl << std::endl;
// 	//
// 	// std::cout << "\n{ s1.pop() }" << std::endl;
// 	// s1.pop();
// 	// std::cout << "{ s1.pop() }\n" << std::endl;
// 	// s1.pop();
// 	//
// 	// std::cout << "s1.empty():\t" << s1.empty() << std::endl;
// 	// std::cout << "s1.size():\t" << s1.size() << std::endl;
// 	// std::cout << "s1.top():\t" << s1.top() << std::endl << std::endl;
// 	//
// 	//
// 	// if (s1 == s2)
// 	// 	std::cout << "s1 == s2" << std::endl;
// 	// else
// 	// 	std::cout << "s1 != s2" << std::endl;
// 	//
// 	// if (s1 >= s2)
// 	// 	std::cout << "s1 >= s2" << std::endl;
// 	// else
// 	// 	std::cout << "s1 < s2" << std::endl;
// 	//
// 	// if (s1 <= s2)
// 	// 	std::cout << "s1 <= s2" << std::endl;
// 	// else
// 	// 	std::cout << "s1 > s2" << std::endl;
// 	//
// 	// if (s1 < s2)
// 	// 	std::cout << "s1 < s2" << std::endl;
// 	// else
// 	// 	std::cout << "s1 >= s2" << std::endl;
// 	//
// 	// if (s1 > s2)
// 	// 	std::cout << "s1 > s2" << std::endl;
// 	// else
// 	// 	std::cout << "s1 <= s2" << std::endl;
// <<<<<<< HEAD
// 	//
// 	// return 0;
//
//
// =======
//
// 	////////PAIR
//
// 	ft::pair<char, int>	p1;
//
// 	std::cout << "p1.first =\t" << p1.first << std::endl;
// 	std::cout << "p1.second =\t" << p1.second << std::endl;
//
// 	p1.first = 'c';
// 	p1.second = 42;
//
// 	std::cout << "p1.first =\t" << p1.first << std::endl;
// 	std::cout << "p1.second =\t" << p1.second << std::endl;
//
// 	ft::pair<char, int>	p2(p1);
//
// 	std::cout << "p2.first =\t" << p2.first << std::endl;
// 	std::cout << "p2.second =\t" << p2.second << std::endl;
//
// 	p2.second = 21;
//
// 	ft::pair<char, int>	p3(p1.first, p2.second);
//
// 	std::cout << "p3.first =\t" << p3.first << std::endl;
// 	std::cout << "p3.second =\t" << p3.second << std::endl;
//
// 	p3.second = 2;
//
// 	std::cout << "p2.first =\t" << p2.first << std::endl;
// 	std::cout << "p2.second =\t" << p2.second << std::endl;
//
// 	std::cout << "p3.first =\t" << p3.first << std::endl;
// 	std::cout << "p3.second =\t" << p3.second << std::endl;
//
// 	std::cout << (p1 > p2) << std::endl;
// 	std::cout << (p1 < p2) << std::endl;
// 	std::cout << (p1 == p2) << std::endl;
//
// 	p3.first = 'u';
//
// 	ft::pair<char, int>	p4 = ft::make_pair(p3.first, p2.second);
//
// 	std::cout << "p4.first =\t" << p4.first << std::endl;
// 	std::cout << "p4.second =\t" << p4.second << std::endl;
// >>>>>>> af34554e0abb436dddcd952242ff18fd39ec1d34

// 	ft::vector<int>			test(3, 3);
//
// 	std::cout << "self assignation test\n";
// 	ft::vector<ft::vector<int> >	self_assign;
// 	ft::vector<ft::vector<int> >	*ptr = &self_assign;
// 	ft::vector<ft::vector<int> >	*ptr2 = &self_assign;
//
// 	self_assign.assign(4, test);
// 	*ptr = *ptr2;
//
// 	std::cout << std::boolalpha << (*ptr == *ptr2) << '\n';
// //	self_assign = self_assign; //compiler doesn't like it!
//
//
//
// 	ft::vector<ft::vector<int> > JOHN;
// 	ft::vector<ft::vector<int> > BOB(5, test);
// 	std::cout << "BOB(5, test(test, 5)) : \n";
// 	for (size_t i = 0; i < BOB.size(); i++)
// 	{
// 		for (size_t j = 0; j < BOB[i].size(); j++)
// 			std::cout << BOB[i][j] << ' ';
// 		std::cout << '\n';
// 	}
// 	ft::vector<ft::vector<int> > MIKE(BOB);
//
// 	// CTORs
// 	std::cout << "\nCTORS\n";
// 	std::cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
// 	std::cout << "BOB is empty? " << BOB.empty() << '\n';
//
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//
// 	// RESIZE
// 	size_t	bob_resize = 2;
// 	std::cout << "\nRESIZE\n";
// 	BOB.resize(bob_resize);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= bob_resize)
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";
//
// 	size_t	mike_resize = 9;
// 	bob_resize = 0;
//
// 	BOB.resize(bob_resize);
// 	std::cout << "BOB is empty now ? " << BOB.empty() << '\n';
// 	MIKE.resize(mike_resize, test);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= bob_resize)
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= mike_resize)
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 		{
// 			std::cout << MIKE[i][j] << ' ';
// 		}
// 	std::cout << std::endl;
// 	}
// 	// RESERVE
// 	std::cout << "\nRESERVE\n";
//
// 	size_t	john_reserve = 0;
// 	size_t	bob_reserve = 3;
// 	size_t	mike_reserve = 4;
//
// 	JOHN.reserve(john_reserve);
// 	BOB.reserve(bob_reserve);
// 	MIKE.reserve(mike_reserve);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= john_reserve)
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= bob_reserve)
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= mike_reserve)
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			std::cout << MIKE[i][j] << ' ';
// 	std::cout << std::endl;
// 	}
//
// 	//AT
// 	std::cout << "\nAT\n";
// 	try
// 	{
// 		std::cout << MIKE.at(2).front() << '\n';
// 		std::cout << MIKE.at(87).back() << '\n';
// 	}
// 	catch (std::out_of_range& oor)
// 	{
// 		(void)oor;
// 		std::cout << "OOR error caught\n";
// 	}
//
// 	// FRONT / BACK
// 	std::cout << "\nFRONT / BACK\n";
// 	std::cout << "front() of MIKE : " << MIKE.front().front() << '\n';
// 	std::cout << "back() of MIKE : " << MIKE.back().back() << '\n';
//
// 	//ASSIGN
// 	std::cout << "\nASSIGN\n";
// 	test.assign(3, 17);
// 	BOB.assign(3, test);
//
// 	//ASSIGN RANGE
// 	std::cout << "\nASSIGN RANGE\n";
// 	ft::vector<ft::vector<int> >	assign_range;
// 	assign_range.assign(8, test);
// 	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);
//
// 	//EMPTY
// 	std::cout << "\nEMPTY\n";
// 	std::cout << "BOB is empty ? " << BOB.empty() << '\n';
// 	std::cout << "BOB at(1) : " << BOB.at(1).front() << '\n';
//
// 	//PUSH/POP_BACK
// 	std::cout << "\nPUSH/POP_BACK\n";
// 	test.assign(2, 42);
// 	BOB.push_back(test);
// 	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';
// 	BOB.pop_back();
// 	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';
//
// 	//INSERT
// 	std::cout << "\nINSERT\n";
// 	ft::vector<ft::vector<int> >	insert_in_me;
// 	for (int i = 0; i < 15; i++)
// 	{
// 		ft::vector<int>	j(2, i);
// 		insert_in_me.push_back(j);
// 	}
// 	for (size_t i = 0; i < insert_in_me.size(); i++)
// 	{
// 		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
// 			std::cout << insert_in_me.at(i).at(j) << ' ';
// 		std::cout << '\n';
// 	}
//
// 	ft::vector<ft::vector<int> >::iterator	tmp;
// 	test.assign(23, 19);
// 	tmp = insert_in_me.begin() + 4;
// 	insert_in_me.insert(tmp, 8, test);
// 	for (size_t i = 0; i < insert_in_me.size(); i++)
// 	{
// 		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
// 			std::cout << insert_in_me.at(i).at(j) << ' ';
// 		std::cout << '\n';
// 	}
//
// 	ft::vector<ft::vector<int> >::const_iterator const_it(insert_in_me.begin());
// 	std::cout << "Const it.front() : " << std::endl;
// 	std::cout << (*const_it).front() << '\n';
//
//
// 	//INSERT
// 	std::cout << "\nINSERT\n";
// 	ft::vector<ft::vector<int> >	std_insert_in_me;
// 	for (int i = 0; i < 15; i++)
// 		std_insert_in_me.push_back(test);
// 	for (size_t i = 0; i < std_insert_in_me.size(); i++)
// 		std::cout << std_insert_in_me.at(i).front() << ' ';
// 	std::cout << '\n';
//
// 	ft::vector<ft::vector<int> >::iterator	std_tmp;
// 	std_tmp = std_insert_in_me.begin() + 4;
// 	std_insert_in_me.insert(std_tmp, 8, test);
// 	for (size_t i = 0; i < std_insert_in_me.size(); i++)
// 		std::cout << std_insert_in_me.at(i).back() << ' ';
// 	std::cout << '\n';
//
//
// 	//INSERT RANGE
// 	std::cout << "\nINSERT RANGE\n";
// 	ft::vector<ft::vector<int> >	insert_bis;
// 	for (int i = 0; i < 7; i++)
// 	{
// 		ft::vector<int>	j(2, i * 3);
// 		insert_bis.push_back(j);
// 	}
// 	for (size_t i = 0; i < insert_bis.size(); i++)
// 		std::cout << insert_bis[i].back() << ' ';
// 	std::cout << '\n';
//
// 	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
// 	for (size_t i = 0; i < insert_bis.size(); i++)
// 		std::cout << insert_bis[i].back() << ' ';
// 	std::cout << '\n';
//
//
// 	//ERASE
// 	std::cout << "\nERASE\n";
// 	ft::vector<ft::vector<int> >	erase_in_me;
// 	for (int i = 0; i < 15; i++)
// 	{
// 		ft::vector<int>	j(1, i);
// 		erase_in_me.push_back(j);
// 	}
// 	for (size_t i = 0; i < erase_in_me.size(); i++)
// 		std::cout << erase_in_me.at(i).front() << ' ';
// 	std::cout << '\n';
//
// 	erase_in_me.erase(erase_in_me.begin() + 7);
// 	for (size_t i = 0; i < erase_in_me.size(); i++)
// 		std::cout << erase_in_me.at(i).front() << ' ';
// 	std::cout << '\n';
// 	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
// 	for (size_t i = 0; i < erase_in_me.size(); i++)
// 		std::cout << erase_in_me.at(i).front() << ' ';
// 	std::cout << '\n';
//
// 	//SWAP
// 	std::cout << "\nSWAP\n";
// 	john_reserve = 4;
// 	JOHN.reserve(john_reserve);
// 	BOB.swap(MIKE);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= BOB.size())
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			std::cout << MIKE[i][j] << ' ';
// 	std::cout << std::endl;
// 	}
//
// 	MIKE.swap(JOHN);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= BOB.size())
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			std::cout << MIKE[i][j] << ' ';
// 	std::cout << std::endl;
// 	}
//
// 	//CLEAR
// 	std::cout << "\nCLEAR\n";
// 	JOHN.clear();
// 	MIKE.clear();
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= BOB.size())
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			std::cout << MIKE[i][j] << ' ';
// 	std::cout << std::endl;
// 	}
//
// 	//NON MEMBER Functions
// 	std::cout << "\nNON MEMBER functions\n";
// 	swap(BOB, MIKE);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= BOB.size())
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			std::cout << MIKE[i][j] << ' ';
// 	std::cout << std::endl;
// 	}
//
// 	//RELATIONAL OPERATORS
// 	std::cout << "\nRELATIONAL OPERATORS\n";
// 	ft::vector<ft::vector<int> > MIKE_2(MIKE);
// 	std::cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
// 	std::cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';
//
// 	std::cout << "\nReal Vector\n";
// 	ft::vector<ft::vector<int> > real;
// 	real.assign(5, test);
// 	for (ft::vector<ft::vector<int> >::iterator it = real.begin(); it != real.end(); it++)
// 		std::cout << (*it).front() << " ";
// 	std::cout << '\n';
//
// 	std::cout << std::endl;
	return (0);
}
