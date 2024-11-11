#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    master = 1,
    diamond,
    platinum,
    gold,
    silver,
    bronze,
    normal
} Rank;

typedef struct Customer {
    char customerName[30];
    Rank rank;
    int order_amount;
    int point;
    struct Customer* prev;
    struct Customer* next;
} Customer;

Customer* head = NULL;

char* rank_to_string(Rank rank) {
    switch (rank) {
    case master: return "마스터";
    case diamond: return "다이아";
    case platinum: return "플래티넘";
    case gold: return "골드";
    case silver: return "실버";
    case bronze: return "브론즈";
    case normal: return "일반회원";
    default: return "알 수 없는 등급";
    }
}

int compare_customers(Rank rank1, int order1, int point1, Rank rank2, int order2, int point2) {
    if (rank1 != rank2) {
        return rank1 - rank2;  
    }
    else if (order1 != order2) {
        return order2 - order1;  
    }
    else {
        return point2 - point1; 
    }
}

void insert_node(char* name, Rank rank, int order_amount, int point) {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    strcpy_s(newCustomer->customerName, sizeof(newCustomer->customerName), name);
    newCustomer->rank = rank;
    newCustomer->order_amount = order_amount;
    newCustomer->point = point;
    newCustomer->prev = NULL;
    newCustomer->next = NULL;

    if (head == NULL) {
        head = newCustomer;
    }
    else {
        Customer* current = head;
        while (current->next != NULL && compare_customers(rank, order_amount, point, current->next->rank, current->next->order_amount, current->next->point) > 0) {
            current = current->next;
        }
        newCustomer->next = current->next;
        newCustomer->prev = current;
        if (current->next != NULL) {
            current->next->prev = newCustomer;
        }
        current->next = newCustomer;
    }
}

void print_node() {
    Customer* current = head;
    printf("----------------------------------------------------------\n");
    while (current != NULL) {
        printf("이름: %s, 등급: %s, 주문량: %d건, 포인트: %dP\n",
            current->customerName, rank_to_string(current->rank), current->order_amount, current->point);
        current = current->next;
    }
    printf("----------------------------------------------------------\n");
}

void delete_node(char* name) {
    Customer* current = head;

    while (current != NULL && strcmp(current->customerName, name) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("고객을 찾을 수 없습니다.\n");
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    else {
        head = current->next; // 첫 번째 노드 삭제
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("고객 %s가 삭제되었습니다.\n", name);
}

void update_node(char* name) {
    Customer* current = head;

    while (current != NULL && strcmp(current->customerName, name) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("고객을 찾을 수 없습니다.\n");
        return;
    }

    int choice;
    printf("수정할 항목을 선택하세요:\n");
    printf("1. 주문량\n");
    printf("2. 포인트\n");
    printf("3. 등급\n");
    printf("input: ");
    scanf_s("%d", &choice);

    switch (choice) {
    case 1:
        printf("새로운 주문량을 입력하시오. : ");
        scanf_s("%d", &current->order_amount);
        printf("주문량 수정 완료.\n");
        break;
    case 2:
        printf("새로운 포인트를 입력하시오. : ");
        scanf_s("%d", &current->point);
        printf("포인트 수정 완료.\n");
        break;
    case 3:
        printf("새로운 등급을 입력하시오. (1: 마스터, 2: 다이아, 3: 플래티넘, 4: 골드, 5: 실버, 6: 브론즈, 7: 일반회원): ");
        int rank_input;
        scanf_s("%d", &rank_input);
        if (rank_input >= 1 && rank_input <= 7) {
            current->rank = (Rank)rank_input;
            printf("등급 수정 완료.\n");
        }
        else {
            printf("잘못된 등급입니다.\n");
        }
        break;
    default:
        printf("1~3번만.\n");
    }
}

int main() {
    int choice, rank_input, point, order_amount;
    char name[30];
    while (1) {
        printf("\n1. 고객의 정보를 '추가'합니다. \n");
        printf("2. 고객의 정보를 '삭제'합니다. \n");
        printf("3. 고객의 정보를 '출력'합니다. \n");
        printf("4. 고객의 정보를 '수정'합니다. \n");
        printf("5. 프로그램을 종료합니다. \n\n");
        printf("input : ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("고객의 이름을 입력하시오. : ");
            scanf_s("%29s", name, (unsigned)_countof(name));
            printf("고객의 등급을 입력하시오. (1: 마스터, 2: 다이아, 3: 플래티넘, 4: 골드, 5: 실버, 6: 브론즈, 7: 일반회원): ");
            scanf_s("%d", &rank_input);
            if (rank_input < 1 || rank_input > 7) {
                printf("잘못된 등급입니다.\n");
                break;
            }
            printf("%s의 주문량을 입력하시오. : ", name);
            scanf_s("%d", &order_amount);
            printf("%s의 포인트를 입력하시오. : ", name);
            scanf_s("%d", &point);
            insert_node(name, (Rank)rank_input, order_amount, point);
            print_node();
            break;
        case 2:
            printf("삭제할 고객 이름을 입력하시오. : ");
            scanf_s("%29s", name, (unsigned)_countof(name));
            delete_node(name);
            print_node();
            break;
        case 3:
            print_node();
            break;
        case 4:
            printf("수정할 고객 이름을 입력하시오. : ");
            scanf_s("%29s", name, (unsigned)_countof(name));
            update_node(name);
            break;
        case 5:
            return 0;
        default:
            printf("1~5번만.\n");
        }
    }
    return 0;
}
