
#include <iostream>

#include "Array.h"

int main()
{

	Array<int> test{3, 5, 6, 8};

	std::cout << test << std::endl;

	test.add(5);
	test[0] = 11;

	std::cout << test << std::endl;

	test.setSize(2);

	std::cout << test;

	return 0;
}