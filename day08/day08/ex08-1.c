#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define Max_Len 100

int is_english_string(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) { // ������ ������� ����
            return 0;
        }
    }
    return 1;
}

void reverse_string(char* str) {
    char* start = str;               
    char* end = str + strlen(str) - 1; 

    while (start < end) {
        char temp = *start;          
        *start = *end; 
        *end = temp;              
        start++;                
        end--;                      
    }
}


int main() {
    char input[Max_Len];

    printf("���� ���ڿ��� �Է��ϼ���: ");
    scanf_s("%s", input, (unsigned)sizeof(input));

    while (!is_english_string(input)) {
        printf("���� ���ڸ� �Է��� �ּ���: ");
        scanf_s("%s", input, (unsigned)sizeof(input));
    }

    reverse_string(input);
    printf("������ ���ڿ�: %s\n", input);

    return 0;
}
