#include <stdio.h>

#define MAX 100

int main() {
    int n;
    char pid[MAX][10];
    int at[MAX], bt[MAX], rt[MAX];
    int ct[MAX], tat[MAX], wt[MAX];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", pid[i], &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    int completed = 0, time = 0;

    while (completed < n) {
        int min_index = -1;
        int min_rt = 100000;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                min_index = i;
            }
        }

        if (min_index == -1) {
            time++;
            continue;
        }

        rt[min_index]--;
        time++;

        if (rt[min_index] == 0) {
            completed++;
            ct[min_index] = time;
            tat[min_index] = ct[min_index] - at[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];
        }
    }

    float total_wt = 0, total_tat = 0;

    printf("Waiting Time:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", pid[i], wt[i]);
        total_wt += wt[i];
    }

    printf("Turnaround Time:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", pid[i], tat[i]);
        total_tat += tat[i];
    }

    printf("Average Waiting Time: %.1f\n", total_wt / n);
    printf("Average Turnaround Time: %.1f\n", total_tat / n);

    return 0;
}
