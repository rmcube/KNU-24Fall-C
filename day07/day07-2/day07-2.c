#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int count = 1000000000;
    int inside_circle = 0;
    double x, y;

    srand(time(NULL));

    for (int i = 0; i < count; i++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1) {
            inside_circle++;
        }
        if (i % 10000000 == 0) {
            double temp_pi = 4.0 * inside_circle / (i + 1);
            int progress = (double)(i + 1) / count * 100;
            int gauge_length = 20;
            int filled_length = (progress * gauge_length) / 100;

            printf("%d%% 진행.. 원주율은 : %.6f ", progress, temp_pi);
            for (int j = 0; j < filled_length; j++) {
                printf("■"); 
            }
            for (int j = filled_length; j < gauge_length; j++) {
                printf("□");
            }
            printf("\n");
        }
    }
    double final_pi = 4.0 * inside_circle / count;
    printf("최종 원주율은 : %.6f\n", final_pi);

    return 0;
}
