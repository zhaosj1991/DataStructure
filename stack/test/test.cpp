#include "../stack.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	AStack<int> test_stack;

	test_stack.push(1);
	test_stack.push(11);
	test_stack.push(111);

	int a = 0;
	test_stack.pop(a);
	printf("%d\n", a);
	test_stack.pop(a);
	printf("%d\n", a);
	test_stack.pop(a);
	printf("%d\n", a);
	
	return 0;
}