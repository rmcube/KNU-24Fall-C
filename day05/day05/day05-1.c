#include <stdio.h>
#include <stdlib.h>

struct Student {
    int snum;
    int score;
    char name[100];
};

int main() {
    int N;
    printf("학생 수를 입력하세요: ");
    scanf_s("%d", &N); 

    struct Student* person = (struct Student*)malloc(N * sizeof(struct Student));
    for (int i = 0; i < N; i++) {
        printf("학생 %d의 학번: ", i + 1);
        scanf_s("%d", &person[i].snum);  
        printf("학생 %d의 이름: ", i + 1);
        scanf_s("%s", person[i].name, 100);  
        printf("학생 %d의 점수: ", i + 1);
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
    printf("최대 점수: %d\n", maxScore);
    printf("최소 점수: %d\n", minScore);
    printf("평균 점수: %.2f\n", averageScore);
    free(person);
    return 0;
}
