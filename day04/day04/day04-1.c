#include <stdio.h>

int main2() {
	char a = 'A';
	int num = 356;

	char* ptr1 = &a;
	int* ptr2 = &num;

	printf("%c\n", a);
	printf("%d\n", num);
	
	printf("%x\n", ptr1);
	printf("%x\n", ptr2);

	printf("%c\n", *ptr1);
	printf("%d\n", *ptr2);

	char *c1, *c2;
	printf("%d\n", sizeof(c1));
	printf("%d\n", sizeof(c2));

	num = 100;
	int* ptr = &num;
	printf("%d\n", ptr);
	printf("%d\n", *ptr);

	int num1 = 100, num2 = 100;
	int* pnum;
	pnum = &num1;
	(*pnum) += 30;

	pnum = &num2;
	(*pnum) -= 30;

	printf("%d\n", num1);
	printf("%d\n", num2);
	return 0;
}