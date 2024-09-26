#include <stdio.h>
struct Student {
	int snum;
	char name[100];
	int score;
};

int main() {
	struct Student person;
	person.snum = 1111;
	strcpy_s(person.name, 100, "È«±æµ¿");
	person.score = 60;

	struct Student person2;
	person2.snum = 1111;
	strcpy_s(person2.name, 100, "°ûÃ¶¼ö");
	person2.score = 60;
	printf("%d %s %d\n", person.snum, person.name, person.score);
	return 0;

}