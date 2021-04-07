
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    srand(time(NULL));
    int N, max;
    int **p = NULL;
    unsigned i, j;
    printf("Введите размер(N): ");
    scanf("%d", &N);

    p = (int**) malloc(N * sizeof(int*));
    for (i = 0; i < N; i++) {
        p[i] = (int*) malloc(N * sizeof(int));
    }

    for(i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            p[i][j] = 2 + rand() % 24;
            printf("p[%d][%d] = %d\t", i,j,p[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < N; i++){
        max = p[i][0];
        for (j = 0; j < N; j++){
            if (max < p[i][j]) max = p[i][j];
        }
        for (j = 0; j < N; j++){
            if (max == p[i][j]) p[i][j] = 1;
        }
    }

    printf("%\n");
    for(i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            printf("p[%d][%d] = %d\t", i,j,p[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < N; i++) {
        free(p[i]);
    }
    free(p);
  
  return 0;
}
