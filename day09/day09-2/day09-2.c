#include <stdio.h>

#define Max_Amount 5
#define Max_Name_Size 30

typedef struct {
    int id;
    char name[Max_Name_Size];
    int price;
} product;

void printProduct(product info) {
    printf("상품 ID: %d\n", info.id);
    printf("상품명: %s\n", info.name);
    printf("가격: %d원\n", info.price);
}

int main() {
    product item_list[Max_Amount] = { 0 }; 
    int count = 0;
    int arg = 0;

    do {
        printf("상품 정보를 입력해주세요. (id를 0입력 시 종료)\n");
        printf("상품 ID : ");
        scanf_s("%d", &arg);
        if (arg == 0) break;
        item_list[count].id = arg;

        printf("상품 이름 : ");
        scanf_s("%s", item_list[count].name, Max_Name_Size);
        printf("상품 가격 : ");
        scanf_s("%d", &item_list[count].price);
        printf("\n");
        count += 1;
    } while (count < Max_Amount);

    count = 0;
    printf("\n");
    while (count < Max_Amount && item_list[count].id != 0) {
        printProduct(item_list[count]);
        count += 1;
    }

    return 0;
}
