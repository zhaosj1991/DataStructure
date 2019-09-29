#include "rb_tree.h"
#include <stdio.h>

int main()
{
	RBTree<int, char> rb_tree(0, 'c');

	rb_tree.Insert(1, 's');
	rb_tree.Insert(132, 'h');

	printf("%c\n", rb_tree.Find(132));

	return 0;
}