#include <stdio.h>

int main() {
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

    switch (choice) {
    case 1:
        result = num1 + num2;
        printf("���: %lf\n", result);
        break;
    case 2:
        result = num1 - num2;
        printf("���: %lf\n", result);
        break;
    case 3:
        result = num1 * num2;
        printf("���: %lf\n", result);
        break;
    case 4:
        if (num2 != 0) {
            result = num1 / num2;
            printf("���: %lf\n", result);
        }
        else {
            printf("����: 0���� ���� �� �����ϴ�.\n");
        }
        break;
    default:
        printf("�߸��� �����Դϴ�.\n");
        break;
    }
    return 0;
}
