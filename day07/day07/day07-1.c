#include <stdio.h>

int main() {
    int arg = 0;
    while (arg < 1) {
        printf("�Ƕ�̵� ���� ���ּ���. (1�̻�): ");
        scanf_s("%d", &arg);
    }
    for (int loop = 0; loop < arg; loop++) {
        for (int loop3 = 0; loop3 < arg - loop - 1; loop3++) {
            printf(" "); // ���� ����
        }
        for (int loop2 = 0; loop2 < loop * 2 + 1; loop2++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
