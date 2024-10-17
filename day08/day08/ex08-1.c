#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define Max_Len 100

int is_english_string(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) { // 공백을 허용하지 않음
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

    printf("영어 문자열을 입력하세요: ");
    scanf_s("%s", input, (unsigned)sizeof(input));

    while (!is_english_string(input)) {
        printf("영어 문자만 입력해 주세요: ");
        scanf_s("%s", input, (unsigned)sizeof(input));
    }

    reverse_string(input);
    printf("뒤집힌 문자열: %s\n", input);

    return 0;
}
