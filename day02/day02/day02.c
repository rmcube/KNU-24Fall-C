#include <stdio.h>

int main2() {
    int choice;
    double num1, num2, result;

    printf("���ϴ� ������ �����ϼ���:\n");
    printf("1. ���ϱ�\n");
    printf("2. ����\n");
    printf("3. ���ϱ�\n");
    printf("4. ������\n");
    scanf_s("%d", &choice);

    printf("ù ��° ���ڸ� �Է��ϼ���: ");
    scanf_s("%lf", &num1);
    printf("�� ��° ���ڸ� �Է��ϼ���: ");
    scanf_s("%lf", &num2);

    if (choice == 1) {
        result = num1 + num2;
        printf("���: %lf\n", result);
    }
    else if (choice == 2) {
        result = num1 - num2;
        printf("���: %lf\n", result);
    }
    else if (choice == 3) {
        result = num1 * num2;
        printf("���: %lf\n", result);
    }
    else if (choice == 4) {
        if (num2 != 0) {
            result = num1 / num2;
            printf("���: %lf\n", result);
        }
        else {
            printf("����: 0���� ���� �� �����ϴ�.\n");
        }
    }
    else {
        printf("�߸��� �����Դϴ�.\n");
    }

    return 0;
}
