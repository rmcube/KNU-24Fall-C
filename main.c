#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#define OBSTACLE_COUNT_EASY 10 // 쉬움 모드 장애물 개수
#define OBSTACLE_COUNT_NORMAL 15 // 보통 모드 장애물 개수
#define OBSTACLE_COUNT_HARD 25 // 어려움 모드 장애물 개수
#define FRUIT_COUNT 3 // 과일 개수
#define MAX_TAIL_LENGTH 100 // 꼬리 최대 길이

int i, j, height = 20, width = 40; // 맵 크기 40(가로) * 20(세로)
int gameover, score; // 게임 기본 변수 [ 게임 오버 / 스코어 ]
int x, y, fruitx, fruity, flag;
char fruits[FRUIT_COUNT] = { '*', '&', '$' }; // * = 1배수, & = 2배수, $ = 3배수 즉 과일 별 점수가 다름
int fruitScores[FRUIT_COUNT] = { 10, 20, 30 }; // 과일 별 점수 차이를 주기 위함
int fruitTailLength[FRUIT_COUNT] = { 1, 2, 3 }; // 과일 별 꼬리 늘어나는 개수를 차이 두기 위함
char currentFruit; // 현재 꼬리에 대한 변수
int tailX[MAX_TAIL_LENGTH], tailY[MAX_TAIL_LENGTH]; // 꼬리 X축과 Y축에 대한 변수
int tailLength = 0; // 시작 꼬리 길이
int obstacles[OBSTACLE_COUNT_HARD][2]; // 최대 장애물 수

int obstacleCount; // 현재 장애물 수
int speed; // 이동 속도
int level; // 현재 난이도
int scoreMultiplier; // 점수 배율

int isObstacle(int xi, int yi) {  // 해당 위치가 장애물이라면 1을 리턴, 아니라면 0을 리턴
    for (int k = 0; k < obstacleCount; k++) {
        if (obstacles[k][0] == xi && obstacles[k][1] == yi)
            return 1;
    }
    return 0;
}

void generateObstacles() { // 게임 초기에 장애물을 배치하는 함수
    int count = 0;
    while (count < obstacleCount) { // 장애물 개수 와일문
        int xi = rand() % (height - 2) + 1; // 장애물 Y 위치 (랜덤값)
        int yi = rand() % (width - 2) + 1; // 장애물 X 위치 (랜덤값)
        if (!isObstacle(xi, yi)) { // 장애물이 겹치지 않도록 확인
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
        scoreMultiplier = 2; // 점수 배율 보통은 2배
        break;
    case 3:// 3을 선택할 경우 어려움 단계
        obstacleCount = OBSTACLE_COUNT_HARD;
        speed = 50; // 빠른 속도
        scoreMultiplier = 4; // 점수 배율 어려움은 4배
        break;
    default:
        printf("잘못된 난이도입니다! 기본값으로 보통으로 설정합니다.\n"); // 잘못 입력하면 보통으로 시작
        obstacleCount = OBSTACLE_COUNT_NORMAL;
        speed = 100;
        scoreMultiplier = 2; // 점수 배율
        break;
    }
    do {
        x = rand() % (height - 2) + 1;
        y = rand() % (width - 2) + 1;
    } while (isObstacle(x, y)); // 장애물이 아닌 곳에서 태어나기 위함
    do {
        fruitx = rand() % (height - 2) + 1;
        fruity = rand() % (width - 2) + 1;
    } while (isObstacle(fruitx, fruity) || (fruitx == x && fruity == y)); // 장애물이 아닌 곳에서 열매를 생성하기 위함
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
                printf("#"); // 맵 출력
            }
            else if (i == x && j == y) {
                printf("O"); // 본인 출력
            }
            else if (i == fruitx && j == fruity) {
                printf("%c", currentFruit); // 과일 출력
            }
            else if (isObstacle(i, j)) {
                printf("X"); // 장애물 출력 
            }
            else {
                int isTail = 0;
                for (int k = 0; k < tailLength; k++) {
                    if (i == tailX[k] && j == tailY[k]) {
                        printf("o"); // 꼬리 출력
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
    printf("점수: %d\n", score); // 점수 출력 
    printf("게임을 종료하려면 'X'를 누르세요\n"); // X를 누르면 게임이 종료되도록
}

void input() {
    if (_kbhit()) {
        switch (getch()) {
        case 'a': flag = 1; break; // 왼쪽 방향
        case 's': flag = 2; break; // 아래 방향
        case 'd': flag = 3; break; // 오른쪽 방향
        case 'w': flag = 4; break; // 위쪽 방향
        case 'x': gameover = 1; break; // 종료하기
        }
    }
}

void logic() {
    Sleep(speed); // 난이도에 따라 속도 조절
    int prevX = x; // 전 x위치 지정
    int prevY = y; // 전 y위치 지정
    int prev2X, prev2Y;

    for (int k = 0; k < tailLength; k++) { // 꼬리 이동하기 위함 x y에 따라서 유동적으로 변환시켜줘야함이 있음
        prev2X = tailX[k];
        prev2Y = tailY[k];
        tailX[k] = prevX;
        tailY[k] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (flag) {
    case 1: y--; break; // 왼쪽 방향
    case 2: x++; break; // 아래 방향
    case 3: y++; break; // 오른쪽 방향
    case 4: x--; break; // 위쪽 방향
    }

    if (x <= 0 || x >= height - 1 || y <= 0 || y >= width - 1 || isObstacle(x, y)) { // 장애물에 걸렸거나, 자기 몸에 부딪혔거나, 맵 밖으로 나갔거나 등
        gameover = 1;
    }

    for (int k = 0; k < tailLength; k++) {
        if (x == tailX[k] && y == tailY[k]) {
            gameover = 1;
            break;
        }
    }

    if (x == fruitx && y == fruity) { // 과일을 먹었을 경우
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

    if (score >= 1000) { // 1000점을 넘기면 게임을 끝나도록 함
        printf("\n너가 이겼어! 점수는 %d입니다.\n", score);
        gameover = 1;
    }
}

void restartGame() {
    char choice;
    printf("다시 플레이 하시겠습니까? (y/n): ");
    scanf_s(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        setup(); // 게임 재시작
    }
    else {
        gameover = 1; // 게임 종료
    }
}
int Gaming() { // 실제 게임 진행 메인 알고리즘
    while (!gameover) {
        draw();
        input();
        logic();
    }
    return 0;
}
int main() { // 메인 알고리즘
    srand(time(NULL));
    setup();
    Gaming();
    restartGame(); // 게임 종료 후 재시작 여부 확인
    printf("게임을 플레이해 주셔서 감사합니다!\n");
    return 0;
}
