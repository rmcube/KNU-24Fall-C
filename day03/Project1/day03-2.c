#include <stdio.h>

int acc(int num); // ���丮�� �Լ� ����, main �Լ����� �տ� �����ؾ� �մϴ�.

int main3() {
    int number;
    printf("N! ���丮�� ���� �Է� : ");
    scanf_s("%d", &number); // scanf �� ���� �۵����� �ʳ׿�...
    if (number < 0)
        printf("������ ���丮�� ���� �� �����ϴ�.\n");
    else 
        printf("%d! = %d\n", number, acc(number));
    return 0;
}

int acc(int num) {
    if (num == 0)  // 0! �� ��� 1�Դϴ� 
        return 1;
    else
        return num * acc(num - 1); // ��� �Լ� �ߵ�
}
