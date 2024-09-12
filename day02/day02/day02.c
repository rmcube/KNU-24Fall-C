#include <stdio.h>

int main() {
    int choice;
    double num1, num2, result;

    printf("원하는 연산을 선택하세요:\n");
    printf("1. 더하기\n");
    printf("2. 빼기\n");
    printf("3. 곱하기\n");
    printf("4. 나누기\n");
    scanf_s("%d", &choice);

    printf("첫 번째 숫자를 입력하세요: ");
    scanf_s("%lf", &num1);
    printf("두 번째 숫자를 입력하세요: ");
    scanf_s("%lf", &num2);

    switch (choice) {
    case 1:
        result = num1 + num2;
        printf("결과: %lf\n", result);
        break;
    case 2:
        result = num1 - num2;
        printf("결과: %lf\n", result);
        break;
    case 3:
        result = num1 * num2;
        printf("결과: %lf\n", result);
        break;
    case 4:
        if (num2 != 0) {
            result = num1 / num2;
            printf("결과: %lf\n", result);
        }
        else {
            printf("오류: 0으로 나눌 수 없습니다.\n");
        }
        break;
    default:
        printf("잘못된 선택입니다.\n");
        break;
    }
    return 0;
}
