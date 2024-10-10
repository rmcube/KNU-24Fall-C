#include <stdio.h>

int main() {
    int arg = 0;
    while (arg < 1) {
        printf("피라미드 층을 써주세요. (1이상): ");
        scanf_s("%d", &arg);
    }
    for (int loop = 0; loop < arg; loop++) {
        for (int loop3 = 0; loop3 < arg - loop - 1; loop3++) {
            printf(" "); // 왼쪽 여백
        }
        for (int loop2 = 0; loop2 < loop * 2 + 1; loop2++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
