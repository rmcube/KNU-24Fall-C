#include <stdio.h>
#include <stdlib.h>

struct Student {
    int snum;
    int score;
    char name[100];
};

int main() {
    int N;
    printf("�л� ���� �Է��ϼ���: ");
    scanf_s("%d", &N); 

    struct Student* person = (struct Student*)malloc(N * sizeof(struct Student));
    for (int i = 0; i < N; i++) {
        printf("�л� %d�� �й�: ", i + 1);
        scanf_s("%d", &person[i].snum);  
        printf("�л� %d�� �̸�: ", i + 1);
        scanf_s("%s", person[i].name, 100);  
        printf("�л� %d�� ����: ", i + 1);
        scanf_s("%d", &person[i].score);  
    }

    int maxScore = person[0].score; 
    int minScore = person[0].score;  
    int sumScore = 0;

    for (int i = 0; i < N; i++) {
        if (person[i].score > maxScore) {
            maxScore = person[i].score;
        }
        if (person[i].score < minScore) {
            minScore = person[i].score;
        }
        sumScore += person[i].score;
    }
    double averageScore = (double)sumScore / N;
    printf("�ִ� ����: %d\n", maxScore);
    printf("�ּ� ����: %d\n", minScore);
    printf("��� ����: %.2f\n", averageScore);
    free(person);
    return 0;
}
