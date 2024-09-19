#include <stdio.h>

int acc(int num); // 팩토리얼 함수 선언, main 함수보다 앞에 선언해야 합니다.

int main3() {
    int number;
    printf("N! 팩토리얼 수를 입력 : ");
    scanf_s("%d", &number); // scanf 만 쓰면 작동하질 않네요...
    if (number < 0)
        printf("음수는 팩토리얼에 넣을 수 없습니다.\n");
    else 
        printf("%d! = %d\n", number, acc(number));
    return 0;
}

int acc(int num) {
    if (num == 0)  // 0! 일 경우 1입니다 
        return 1;
    else
        return num * acc(num - 1); // 재귀 함수 발동
}
