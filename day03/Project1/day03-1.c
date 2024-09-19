#include <stdio.h>

int Prime_Tester(int prime); // 메인함수보다 먼저 선언해야함, 그래서 저렇게 선언함.

int main() {
    printf("소수인지 확인할 수를 입력하세요 : ");
    int meta = 0;
    scanf_s("%d", &meta);  
    if (Prime_Tester(meta) == 1)
        printf("\n해당 수는 소수입니다.");
    else
        printf("\n해당 수는 소수가 아닙니다.");  
}

int Prime_Tester(int prime) {
    if (prime < 2) return 0;  // 2보다 작으면 1밖에 없고 그건 소수입니다.
    int temp = 2; 
    while (temp <= prime / 2) {
        if (prime % temp == 0)
            return 0;
        temp += 1;
    }
    return 1;
}
