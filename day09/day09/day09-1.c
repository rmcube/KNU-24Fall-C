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
    printf("ù ��° ���� (x, y, z)�� �Է��ϼ���: ");
    scanf_s("%f %f %f", &vec1.x, &vec1.y, &vec1.z);
    printf("�� ��° ���� (x, y, z)�� �Է��ϼ���: ");
    scanf_s("%f %f %f", &vec2.x, &vec2.y, &vec2.z);

    do {
        printf("\n�ɼ��� �����ϼ���:\n\n");
        printf("1. ������ �� (v1 + v2)\n");
        printf("2. ������ �� (v1 - v2)\n");
        printf("3. ������ ���� (v1 �� v2)\n");
        printf("4. ������ ���� (v1 �� v2)\n");
        printf("5. ����\n\n");
        printf("����: ");
        scanf_s("%d", &option);

        switch (option) {
        case 1: {
            Vector sum = vector_sum(vec1, vec2);
            printf("������ ��: (%.2f, %.2f, %.2f)\n", sum.x, sum.y, sum.z);
            break;
        }
        case 2: {
            Vector minus = vector_minus(vec1, vec2);
            printf("������ ��: (%.2f, %.2f, %.2f)\n", minus.x, minus.y, minus.z);
            break;
        }
        case 3: {
            float inside = vector_inside(vec1, vec2);
            printf("������ ����: %.2f\n", inside);
            break;
        }
        case 4: {
            Vector outside = vector_outside(vec1, vec2);
            printf("������ ����: (%.2f, %.2f, %.2f)\n", outside.x, outside.y, outside.z);
            break;
        }
        case 5:
            printf("���α׷��� �����մϴ�.\n");
            break;
        default:
            printf("��ȿ���� ���� �ɼ��Դϴ�. �ٽ� �����ϼ���.\n");
        }
    } while (option != 5);

    return 0;
}
