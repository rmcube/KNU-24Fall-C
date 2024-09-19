#include <stdio.h>
#include <stdlib.h>
int main() {
	srand(10);
	for (int i = 0; i < 10; i++) {
		printf("%d\n", rand());
	}
	return 0;
}