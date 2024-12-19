#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#define OBSTACLE_COUNT_EASY 10 // ���� ��� ��ֹ� ����
#define OBSTACLE_COUNT_NORMAL 15 // ���� ��� ��ֹ� ����
#define OBSTACLE_COUNT_HARD 25 // ����� ��� ��ֹ� ����
#define FRUIT_COUNT 3 // ���� ����
#define MAX_TAIL_LENGTH 100 // ���� �ִ� ����

int i, j, height = 20, width = 40; // �� ũ�� 40(����) * 20(����)
int gameover, score; // ���� �⺻ ���� [ ���� ���� / ���ھ� ]
int x, y, fruitx, fruity, flag;
char fruits[FRUIT_COUNT] = { '*', '&', '$' }; // * = 1���, & = 2���, $ = 3��� �� ���� �� ������ �ٸ�
int fruitScores[FRUIT_COUNT] = { 10, 20, 30 }; // ���� �� ���� ���̸� �ֱ� ����
int fruitTailLength[FRUIT_COUNT] = { 1, 2, 3 }; // ���� �� ���� �þ�� ������ ���� �α� ����
char currentFruit; // ���� ������ ���� ����
int tailX[MAX_TAIL_LENGTH], tailY[MAX_TAIL_LENGTH]; // ���� X��� Y�࿡ ���� ����
int tailLength = 0; // ���� ���� ����
int obstacles[OBSTACLE_COUNT_HARD][2]; // �ִ� ��ֹ� ��

int obstacleCount; // ���� ��ֹ� ��
int speed; // �̵� �ӵ�
int level; // ���� ���̵�
int scoreMultiplier; // ���� ����

int isObstacle(int xi, int yi) {  // �ش� ��ġ�� ��ֹ��̶�� 1�� ����, �ƴ϶�� 0�� ����
    for (int k = 0; k < obstacleCount; k++) {
        if (obstacles[k][0] == xi && obstacles[k][1] == yi)
            return 1;
    }
    return 0;
}

void generateObstacles() { // ���� �ʱ⿡ ��ֹ��� ��ġ�ϴ� �Լ�
    int count = 0;
    while (count < obstacleCount) { // ��ֹ� ���� ���Ϲ�
        int xi = rand() % (height - 2) + 1; // ��ֹ� Y ��ġ (������)
        int yi = rand() % (width - 2) + 1; // ��ֹ� X ��ġ (������)
        if (!isObstacle(xi, yi)) { // ��ֹ��� ��ġ�� �ʵ��� Ȯ��
            obstacles[count][0] = xi;
            obstacles[count][1] = yi;
            count++;
        }
    }
}

void setup() {
    gameover = 0; // ���� ���� ���� �ʱ�ȭ
    flag = 0;
    printf("���̵� ���� (1: ����, 2: ����, 3: �����): "); // ���̵� ���� ����
    scanf_s("%d", &level); // �Է� �޾ƿ���
    switch (level) { // switch ��
    case 1: // 1�� ������ ��� ���� �ܰ�
        obstacleCount = OBSTACLE_COUNT_EASY;
        speed = 200; // ���� �ӵ�
        scoreMultiplier = 1; // ���� ����
        break;
    case 2:// 2�� ������ ��� ���� �ܰ�
        obstacleCount = OBSTACLE_COUNT_NORMAL;
        speed = 100; // ���� �ӵ�
        scoreMultiplier = 2; // ���� ���� ������ 2��
        break;
    case 3:// 3�� ������ ��� ����� �ܰ�
        obstacleCount = OBSTACLE_COUNT_HARD;
        speed = 50; // ���� �ӵ�
        scoreMultiplier = 4; // ���� ���� ������� 4��
        break;
    default:
        printf("�߸��� ���̵��Դϴ�! �⺻������ �������� �����մϴ�.\n"); // �߸� �Է��ϸ� �������� ����
        obstacleCount = OBSTACLE_COUNT_NORMAL;
        speed = 100;
        scoreMultiplier = 2; // ���� ����
        break;
    }
    do {
        x = rand() % (height - 2) + 1;
        y = rand() % (width - 2) + 1;
    } while (isObstacle(x, y)); // ��ֹ��� �ƴ� ������ �¾�� ����
    do {
        fruitx = rand() % (height - 2) + 1;
        fruity = rand() % (width - 2) + 1;
    } while (isObstacle(fruitx, fruity) || (fruitx == x && fruity == y)); // ��ֹ��� �ƴ� ������ ���Ÿ� �����ϱ� ����
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
                printf("#"); // �� ���
            }
            else if (i == x && j == y) {
                printf("O"); // ���� ���
            }
            else if (i == fruitx && j == fruity) {
                printf("%c", currentFruit); // ���� ���
            }
            else if (isObstacle(i, j)) {
                printf("X"); // ��ֹ� ��� 
            }
            else {
                int isTail = 0;
                for (int k = 0; k < tailLength; k++) {
                    if (i == tailX[k] && j == tailY[k]) {
                        printf("o"); // ���� ���
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
    printf("����: %d\n", score); // ���� ��� 
    printf("������ �����Ϸ��� 'X'�� ��������\n"); // X�� ������ ������ ����ǵ���
}

void input() {
    if (_kbhit()) {
        switch (getch()) {
        case 'a': flag = 1; break; // ���� ����
        case 's': flag = 2; break; // �Ʒ� ����
        case 'd': flag = 3; break; // ������ ����
        case 'w': flag = 4; break; // ���� ����
        case 'x': gameover = 1; break; // �����ϱ�
        }
    }
}

void logic() {
    Sleep(speed); // ���̵��� ���� �ӵ� ����
    int prevX = x; // �� x��ġ ����
    int prevY = y; // �� y��ġ ����
    int prev2X, prev2Y;

    for (int k = 0; k < tailLength; k++) { // ���� �̵��ϱ� ���� x y�� ���� ���������� ��ȯ����������� ����
        prev2X = tailX[k];
        prev2Y = tailY[k];
        tailX[k] = prevX;
        tailY[k] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (flag) {
    case 1: y--; break; // ���� ����
    case 2: x++; break; // �Ʒ� ����
    case 3: y++; break; // ������ ����
    case 4: x--; break; // ���� ����
    }

    if (x <= 0 || x >= height - 1 || y <= 0 || y >= width - 1 || isObstacle(x, y)) { // ��ֹ��� �ɷȰų�, �ڱ� ���� �ε����ų�, �� ������ �����ų� ��
        gameover = 1;
    }

    for (int k = 0; k < tailLength; k++) {
        if (x == tailX[k] && y == tailY[k]) {
            gameover = 1;
            break;
        }
    }

    if (x == fruitx && y == fruity) { // ������ �Ծ��� ���
        for (int k = 0; k < FRUIT_COUNT; k++) {
            if (currentFruit == fruits[k]) {
                score += fruitScores[k] * scoreMultiplier; // ���� ���� ����
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

    if (score >= 1000) { // 1000���� �ѱ�� ������ �������� ��
        printf("\n�ʰ� �̰��! ������ %d�Դϴ�.\n", score);
        gameover = 1;
    }
}

void restartGame() {
    char choice;
    printf("�ٽ� �÷��� �Ͻðڽ��ϱ�? (y/n): ");
    scanf_s(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        setup(); // ���� �����
    }
    else {
        gameover = 1; // ���� ����
    }
}
int Gaming() { // ���� ���� ���� ���� �˰���
    while (!gameover) {
        draw();
        input();
        logic();
    }
    return 0;
}
int main() { // ���� �˰���
    srand(time(NULL));
    setup();
    Gaming();
    restartGame(); // ���� ���� �� ����� ���� Ȯ��
    printf("������ �÷����� �ּż� �����մϴ�!\n");
    return 0;
}
