#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void Make_Int_List(int(*array)[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            *(*(array + i) + j) = rand() % 20 + 1;
        }
    }
}

void Print_Int_List(int(*array)[SIZE]) {
    printf("배열 값:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d ", *(*(array + i) + j));
        }
        printf("\n");
    }
}

void Move_Pointer(void* array) {
    int(*arr)[SIZE] = (int(*)[SIZE])array;
    int x = 0;
    int y = 0;

    while (1) {
        printf("현재 위치: (%d, %d), 배열 값: %d\n", y, x, *(*(arr + y) + x));
        int move = *(*(arr + y) + x);
        int new_x = (x + move) % SIZE;
        int new_y = y + (x + move) / SIZE;
        if (new_y < 0 || new_y >= SIZE || new_x < 0 || new_x >= SIZE) {
            break;
        }

        x = new_x;
        y = new_y;
    }

    printf("더 이상 이동할 수 없습니다. 최종 위치: (%d, %d) 배열의 값: %d\n", y, x, *(*(arr + y) + x));
}

int main() {
    srand(time(NULL));
    int array[SIZE][SIZE];
    Make_Int_List(array);
    Print_Int_List(array);
    Move_Pointer(array);
    return 0;
}
