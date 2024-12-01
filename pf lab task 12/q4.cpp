#include <stdio.h>
#include <stdlib.h>

#define MAX 10001

int main() {
    int T;
    scanf("%d", &T);

    int *results = (int *)malloc(T * sizeof(int));

    for (int t = 0; t < T; t++) {
        int N;
        scanf("%d", &N);

        int *A = (int *)malloc(N * sizeof(int));
        int *freq = (int *)calloc(MAX, sizeof(int));

        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            freq[A[i]]++;
        }

        int maxFreq = 0;
        int result = 10001;

        for (int i = 1; i <= 10000; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                result = i;
            } else if (freq[i] == maxFreq && i < result) {
                result = i;
            }
        }

        results[t] = result;

        free(A);
        free(freq);
    }

    for (int t = 0; t < T; t++) {
        printf("%d\n", results[t]);
    }

    free(results);

    return 0;
}
