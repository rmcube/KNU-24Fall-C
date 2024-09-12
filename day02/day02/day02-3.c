#include <stdio.h>

int main() {
	int NumC = 0;
	while (1) {
		if (NumC > 100) break;
		if (NumC % 3 == 0 && NumC % 4 == 0 && NumC % 7 == 0){
			printf("%d ", NumC);
		}
		else {
			if (NumC % 3 == 0 && NumC % 4 == 0) printf("%d ", NumC);
			if (NumC % 7 == 0) printf("%d ", NumC);
		}

		NumC++;
	}
	return 0;
}