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
    case master: return "������";
    case diamond: return "���̾�";
    case platinum: return "�÷�Ƽ��";
    case gold: return "���";
    case silver: return "�ǹ�";
    case bronze: return "�����";
    case normal: return "�Ϲ�ȸ��";
    default: return "�� �� ���� ���";
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
        printf("�̸�: %s, ���: %s, �ֹ���: %d��, ����Ʈ: %dP\n",
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
        printf("���� ã�� �� �����ϴ�.\n");
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    else {
        head = current->next; // ù ��° ��� ����
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("�� %s�� �����Ǿ����ϴ�.\n", name);
}

void update_node(char* name) {
    Customer* current = head;

    while (current != NULL && strcmp(current->customerName, name) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("���� ã�� �� �����ϴ�.\n");
        return;
    }

    int choice;
    printf("������ �׸��� �����ϼ���:\n");
    printf("1. �ֹ���\n");
    printf("2. ����Ʈ\n");
    printf("3. ���\n");
    printf("input: ");
    scanf_s("%d", &choice);

    switch (choice) {
    case 1:
        printf("���ο� �ֹ����� �Է��Ͻÿ�. : ");
        scanf_s("%d", &current->order_amount);
        printf("�ֹ��� ���� �Ϸ�.\n");
        break;
    case 2:
        printf("���ο� ����Ʈ�� �Է��Ͻÿ�. : ");
        scanf_s("%d", &current->point);
        printf("����Ʈ ���� �Ϸ�.\n");
        break;
    case 3:
        printf("���ο� ����� �Է��Ͻÿ�. (1: ������, 2: ���̾�, 3: �÷�Ƽ��, 4: ���, 5: �ǹ�, 6: �����, 7: �Ϲ�ȸ��): ");
        int rank_input;
        scanf_s("%d", &rank_input);
        if (rank_input >= 1 && rank_input <= 7) {
            current->rank = (Rank)rank_input;
            printf("��� ���� �Ϸ�.\n");
        }
        else {
            printf("�߸��� ����Դϴ�.\n");
        }
        break;
    default:
        printf("1~3����.\n");
    }
}

int main() {
    int choice, rank_input, point, order_amount;
    char name[30];
    while (1) {
        printf("\n1. ���� ������ '�߰�'�մϴ�. \n");
        printf("2. ���� ������ '����'�մϴ�. \n");
        printf("3. ���� ������ '���'�մϴ�. \n");
        printf("4. ���� ������ '����'�մϴ�. \n");
        printf("5. ���α׷��� �����մϴ�. \n\n");
        printf("input : ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("���� �̸��� �Է��Ͻÿ�. : ");
            scanf_s("%29s", name, (unsigned)_countof(name));
            printf("���� ����� �Է��Ͻÿ�. (1: ������, 2: ���̾�, 3: �÷�Ƽ��, 4: ���, 5: �ǹ�, 6: �����, 7: �Ϲ�ȸ��): ");
            scanf_s("%d", &rank_input);
            if (rank_input < 1 || rank_input > 7) {
                printf("�߸��� ����Դϴ�.\n");
                break;
            }
            printf("%s�� �ֹ����� �Է��Ͻÿ�. : ", name);
            scanf_s("%d", &order_amount);
            printf("%s�� ����Ʈ�� �Է��Ͻÿ�. : ", name);
            scanf_s("%d", &point);
            insert_node(name, (Rank)rank_input, order_amount, point);
            print_node();
            break;
        case 2:
            printf("������ �� �̸��� �Է��Ͻÿ�. : ");
            scanf_s("%29s", name, (unsigned)_countof(name));
            delete_node(name);
            print_node();
            break;
        case 3:
            print_node();
            break;
        case 4:
            printf("������ �� �̸��� �Է��Ͻÿ�. : ");
            scanf_s("%29s", name, (unsigned)_countof(name));
            update_node(name);
            break;
        case 5:
            return 0;
        default:
            printf("1~5����.\n");
        }
    }
    return 0;
}
