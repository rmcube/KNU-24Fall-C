#include <stdio.h>

int Prime_Tester(int prime); // �����Լ����� ���� �����ؾ���, �׷��� ������ ������.

int main() {
    printf("�Ҽ����� Ȯ���� ���� �Է��ϼ��� : ");
    int meta = 0;
    scanf_s("%d", &meta);  
    if (Prime_Tester(meta) == 1)
        printf("\n�ش� ���� �Ҽ��Դϴ�.");
    else
        printf("\n�ش� ���� �Ҽ��� �ƴմϴ�.");  
}

int Prime_Tester(int prime) {
    if (prime < 2) return 0;  // 2���� ������ 1�ۿ� ���� �װ� �Ҽ��Դϴ�.
    int temp = 2; 
    while (temp <= prime / 2) {
        if (prime % temp == 0)
            return 0;
        temp += 1;
    }
    return 1;
}
