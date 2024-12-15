#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#define OBSTACLE_COUNT_EASY 10
#define OBSTACLE_COUNT_NORMAL 15
#define OBSTACLE_COUNT_HARD 25
#define FRUIT_COUNT 3
#define MAX_TAIL_LENGTH 100

int i, j, height = 20, width = 40;
int gameover, score;
int x, y, fruitx, fruity, flag;
char fruits[FRUIT_COUNT] = { '*', '&', '$' };
int fruitScores[FRUIT_COUNT] = { 10, 20, 30 };
int fruitTailLength[FRUIT_COUNT] = { 1, 2, 3 };
char currentFruit;
int tailX[MAX_TAIL_LENGTH], tailY[MAX_TAIL_LENGTH];
int tailLength = 0;
int obstacles[OBSTACLE_COUNT_HARD][2]; // 최대 장애물 수

int obstacleCount; // 현재 장애물 수
int speed; // 이동 속도
int level; // 현재 난이도
int scoreMultiplier; // 점수 배율

int isObstacle(int xi, int yi) {
    for (int k = 0; k < obstacleCount; k++) {
        if (obstacles[k][0] == xi && obstacles[k][1] == yi)
            return 1;
    }
    return 0;
}

void generateObstacles() {
    int count = 0;
    while (count < obstacleCount) {
        int xi = rand() % (height - 2) + 1; // 장애물 Y 위치
        int yi = rand() % (width - 2) + 1; // 장애물 X 위치

        // 장애물이 겹치지 않도록 확인
        if (!isObstacle(xi, yi)) {
            obstacles[count][0] = xi;
            obstacles[count][1] = yi;
            count++;
        }
    }
}

void setup() {
    gameover = 0; // 게임 오버 상태 초기화
    flag = 0;
    printf("난이도 선택 (1: 쉬움, 2: 보통, 3: 어려움): "); // 난이도 선택 구문
    scanf_s("%d", &level); // 입력 받아오기
    switch (level) { // switch 문
    case 1: // 1을 선택할 경우 쉬움 단계
        obstacleCount = OBSTACLE_COUNT_EASY;
        speed = 200; // 느린 속도
        scoreMultiplier = 1; // 점수 배율
        break;
    case 2:// 2를 선택할 경우 보통 단계
        obstacleCount = OBSTACLE_COUNT_NORMAL;
        speed = 100; // 보통 속도
        scoreMultiplier = 2; // 점수 배율
        break;
    case 3:// 3을 선택할 경우 어려움 단계
        obstacleCount = OBSTACLE_COUNT_HARD;
        speed = 50; // 빠른 속도
        scoreMultiplier = 4; // 점수 배율
        break;
    default:
        printf("잘못된 난이도입니다! 기본값으로 보통으로 설정합니다.\n");
        obstacleCount = OBSTACLE_COUNT_NORMAL;
        speed = 100;
        scoreMultiplier = 2; // 점수 배율
        break;
    }

    do {
        x = rand() % (height - 2) + 1;
        y = rand() % (width - 2) + 1;
    } while (isObstacle(x, y));

    do {
        fruitx = rand() % (height - 2) + 1;
        fruity = rand() % (width - 2) + 1;
    } while (isObstacle(fruitx, fruity) || (fruitx == x && fruity == y));

    currentFruit = fruits[rand() % FRUIT_COUNT];

    score = 0;
    tailLength = 0;
    generateObstacles();
    Gaming();
}

void draw() {
    system("cls");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("#");
            }
            else if (i == x && j == y) {
                printf("O");
            }
            else if (i == fruitx && j == fruity) {
                printf("%c", currentFruit);
            }
            else if (isObstacle(i, j)) {
                printf("X");
            }
            else {
                int isTail = 0;
                for (int k = 0; k < tailLength; k++) {
                    if (i == tailX[k] && j == tailY[k]) {
                        printf("o");
                        isTail = 1;
                        break;
                    }
                }
                if (!isTail) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("점수: %d\n", score);
    printf("게임을 종료하려면 'X'를 누르세요\n");
}

void input() {
    if (_kbhit()) {
        switch (getch()) {
        case 'a': flag = 1; break; // 왼쪽
        case 's': flag = 2; break; // 아래
        case 'd': flag = 3; break; // 오른쪽
        case 'w': flag = 4; break; // 위
        case 'x': gameover = 1; break; // 종료
        }
    }
}

void logic() {
    Sleep(speed); // 난이도에 따라 속도 조절
    int prevX = x;
    int prevY = y;
    int prev2X, prev2Y;

    for (int k = 0; k < tailLength; k++) {
        prev2X = tailX[k];
        prev2Y = tailY[k];
        tailX[k] = prevX;
        tailY[k] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (flag) {
    case 1: y--; break; // 왼쪽
    case 2: x++; break; // 아래
    case 3: y++; break; // 오른쪽
    case 4: x--; break; // 위
    }

    if (x <= 0 || x >= height - 1 || y <= 0 || y >= width - 1 || isObstacle(x, y)) {
        gameover = 1;
    }

    for (int k = 0; k < tailLength; k++) {
        if (x == tailX[k] && y == tailY[k]) {
            gameover = 1;
            break;
        }
    }

    if (x == fruitx && y == fruity) {
        for (int k = 0; k < FRUIT_COUNT; k++) {
            if (currentFruit == fruits[k]) {
                score += fruitScores[k] * scoreMultiplier; // 점수 배율 적용
                tailLength += fruitTailLength[k];
                break;
            }
        }

        do {
            fruitx = rand() % (height - 2) + 1;
            fruity = rand() % (width - 2) + 1;
        } while (isObstacle(fruitx, fruity) || (fruitx == x && fruity == y));

        currentFruit = fruits[rand() % FRUIT_COUNT];
    }

    if (score >= 1000) {
        printf("\n너가 이겼어! 점수는 %d입니다.\n", score);
        gameover = 1;
    }
}

void restartGame() {
    char choice;
    printf("다시 플레이 하시겠습니까? (y/n): ");
    scanf_s(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        setup(); // 게임 재설정
    }
    else {
        gameover = 1; // 게임 종료
    }
}
int Gaming() {
    while (!gameover) {
        draw();
        input();
        logic();
    }
}
int main() {
    srand(time(NULL));
    setup();
    Gaming();
    restartGame(); // 게임 종료 후 재시작 여부 확인
    printf("게임을 플레이해 주셔서 감사합니다!\n");
    return 0;
}
