#include <stdio.h>
#include <math.h>

double fx(double x) {
    return -log10(1.0 / x) + sin(x);
}

double gubunF(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (fx(a) + fx(b));
    for (int i = 1; i < n; i++) {
        sum += fx(a + i * h); 
    }
    return sum * h;
}

int main() {
    double start, end;
    int max;
    printf("적분할 시작 값을 입력하세요: ");
    scanf_s("%lf", &start);
    printf("적분할 끝 값을 입력하세요: ");
    scanf_s("%lf", &end);
    printf("최대 구간 수 (2^n) 입력하세요: ");
    scanf_s("%d", &max);
    max = pow(2, max);
    int count = 0;
    for (int n = 1; n < max; n *= 2) {
        count += 1;
        double result = gubunF(start, end, n);
        printf("[%d번] 구간 수: %d, 적분값: %.6f\n", count, n, result);
    }
    return 0;
}
