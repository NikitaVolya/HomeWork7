
#include <iostream>

#include "Array.h"

int main()
{

	Array<int> test(3);

	test[0] = 5;
	test[1] = -5;
	test[2] = 10;

	test.add(5);

	test.setSize(2);

	std::cout << test;

	return 0;
}