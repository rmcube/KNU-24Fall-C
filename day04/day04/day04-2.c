#include <stdio.h>

int main() {
	int a = 10;
	int b = 20;
	printf("%d, %d", a, b);
	swap(&a, &b);
	printf("%d, %d", a, b);
}

int swap(int* temp1, int* temp2) {
	int temp = *temp1;
	*temp1 = *temp2;
	*temp2 = temp;
}