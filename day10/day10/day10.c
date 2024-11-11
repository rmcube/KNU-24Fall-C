#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[30];
    int score;
    struct Student* link;
} Student;

Student* head = NULL;

void insert_node(char* name, int score) {
    Student* TempValue = (Student*)malloc(sizeof(Student));
    strcpy_s(TempValue->name, sizeof(TempValue->name), name);
    TempValue->score = score;
    TempValue->link = NULL;
    if (head == NULL || head->score < score) {
        TempValue->link = head;
        head = TempValue;
    }
    else {
        Student* NewValue = head;
        while (NewValue->link != NULL && NewValue->link->score >= score) {
            NewValue = NewValue->link;
        }
        TempValue->link = NewValue->link;
        NewValue->link = TempValue;
    }
}
void print_node() {
    Student* NewValue = head;
    printf("------------------------------\n");
    while (NewValue != NULL) {
        printf("%s : %d\n", NewValue->name, NewValue->score);
        NewValue = NewValue->link;
    }
    printf("------------------------------\n");
}
void delete_node(char* name) {
    if (head == NULL) return;

    if (strcmp(head->name, name) == 0) {
        Student* temp = head;
        head = head->link;
        free(temp);
        return;
    }
    Student* NewValue = head;
    while (NewValue->link != NULL && strcmp(NewValue->link->name, name) != 0) {
        NewValue = NewValue->link;
    }
    if (NewValue->link != NULL) {
        Student* temp = NewValue->link;
        NewValue->link = NewValue->link->link;
        free(temp);
    }
}
int main() {
    int choice;
    char name[30];
    int score;
    while (1) {
        printf("1. 학생의 성적을 입력합니다. \n");
        printf("2. 학생 정보 제거합니다. \n");
        printf("3. 프로그램을 종효합니다. \n");
        printf("input : ");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            printf("학생 이름을 입력하시오. : ");
            scanf_s("%29s", name, (unsigned)_countof(name));
            printf("%s의 성적 : ", name);
            scanf_s("%d", &score);
            insert_node(name, score);
            print_node();
            break;
        case 2:
            printf("삭제할 학생 이름을 입력하시오. : ");
            scanf_s("%29s", name, (unsigned)_countof(name));
            delete_node(name);
            print_node();
            break;
        case 3:
            return 0;
        default:
            printf("1~3번만 가능합니다. \n");
        }
    }
    return 0;
}
