#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double judge, rp, rm;
    printf("ax^2 + bx + c순으로 값을 입력하시오. (a는 0이 될 수 없음) Ex) 1 2 1 ");
    scanf_s("%lf %lf %lf", &a, &b, &c);
    if (a == 0) {
        printf("a는 0이 될 수 없음\n");
        return 1;
    }
    judge = b * b - 4 * a * c;
    if (judge > 0) {
        rp = (-b + sqrt(judge)) / (2 * a);
        rm = (-b - sqrt(judge)) / (2 * a);
        printf("두 개의 근: %.2f, %.2f\n", rp, rm);
    }
    else if (judge == 0) {
        rp = -b / (2 * a);
        printf("중근: %.2f\n", rp);
    }
    else {
        printf("허근 입니다.\n");
    }

    return 0;
}
