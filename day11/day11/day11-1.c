#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double judge, rp, rm;
    printf("ax^2 + bx + c������ ���� �Է��Ͻÿ�. (a�� 0�� �� �� ����) Ex) 1 2 1 ");
    scanf_s("%lf %lf %lf", &a, &b, &c);
    if (a == 0) {
        printf("a�� 0�� �� �� ����\n");
        return 1;
    }
    judge = b * b - 4 * a * c;
    if (judge > 0) {
        rp = (-b + sqrt(judge)) / (2 * a);
        rm = (-b - sqrt(judge)) / (2 * a);
        printf("�� ���� ��: %.2f, %.2f\n", rp, rm);
    }
    else if (judge == 0) {
        rp = -b / (2 * a);
        printf("�߱�: %.2f\n", rp);
    }
    else {
        printf("��� �Դϴ�.\n");
    }

    return 0;
}
