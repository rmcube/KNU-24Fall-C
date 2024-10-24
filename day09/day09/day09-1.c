#include <stdio.h>

typedef struct {
    float x;
    float y;
    float z;
} Vector;  

Vector vector_sum(Vector a, Vector b) {
    Vector result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

Vector vector_minus(Vector a, Vector b) {
    Vector result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

float vector_inside(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector vector_outside(Vector a, Vector b) {
    Vector result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

int main() {
    Vector vec1, vec2;  
    int option;
    printf("첫 번째 벡터 (x, y, z)를 입력하세요: ");
    scanf_s("%f %f %f", &vec1.x, &vec1.y, &vec1.z);
    printf("두 번째 벡터 (x, y, z)를 입력하세요: ");
    scanf_s("%f %f %f", &vec2.x, &vec2.y, &vec2.z);

    do {
        printf("\n옵션을 선택하세요:\n\n");
        printf("1. 벡터의 합 (v1 + v2)\n");
        printf("2. 벡터의 차 (v1 - v2)\n");
        printf("3. 벡터의 내적 (v1 · v2)\n");
        printf("4. 벡터의 외적 (v1 × v2)\n");
        printf("5. 종료\n\n");
        printf("선택: ");
        scanf_s("%d", &option);

        switch (option) {
        case 1: {
            Vector sum = vector_sum(vec1, vec2);
            printf("벡터의 합: (%.2f, %.2f, %.2f)\n", sum.x, sum.y, sum.z);
            break;
        }
        case 2: {
            Vector minus = vector_minus(vec1, vec2);
            printf("벡터의 차: (%.2f, %.2f, %.2f)\n", minus.x, minus.y, minus.z);
            break;
        }
        case 3: {
            float inside = vector_inside(vec1, vec2);
            printf("벡터의 내적: %.2f\n", inside);
            break;
        }
        case 4: {
            Vector outside = vector_outside(vec1, vec2);
            printf("벡터의 외적: (%.2f, %.2f, %.2f)\n", outside.x, outside.y, outside.z);
            break;
        }
        case 5:
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("유효하지 않은 옵션입니다. 다시 선택하세요.\n");
        }
    } while (option != 5);

    return 0;
}
