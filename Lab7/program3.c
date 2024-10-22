#include <stdio.h>

int main() {
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int N, K;
        printf("Enter the number of people in the queue (N) and Vignesh's position (K): ");
        scanf("%d %d", &N, &K);
        int queue[N];
        for (int j = 0; j < N; j++) {
            queue[j] = j + 1;
        }
        int front = 0;
        while (front < N) {
            int group[3];
            for (int j = 0; j < 3; j++) {
                group[j] = queue[front];
                front = (front + 1);
            }
            if ((K >= group[0] && K <= group[2]) && (K + 1 >= group[0] && K + 1 <= group[2])) {
                printf("Yes\n");
                break;
            }
            if (front >= N) {
                printf("No\n");
                break;
            }
        }
    }
    return 0;
}