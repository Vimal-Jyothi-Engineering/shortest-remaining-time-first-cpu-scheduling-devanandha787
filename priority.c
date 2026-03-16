// srtf.c
// Shortest Remaining Time First (Preemptive SJF)

#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[20], at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;

        printf("Enter Arrival Time for P%d: ", pid[i]);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for P%d: ", pid[i]);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];   // remaining time
    }

    int completed = 0, time = 0;
    int min_rt, shortest = -1;

    while (completed < n) {

        min_rt = INT_MAX;
        shortest = -1;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        rt[shortest]--;
        time++;

        if (rt[shortest] == 0) {
            completed++;

            ct[shortest] = time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
        }
    }

    float total_wt = 0, total_tat = 0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);

    return 0;
}
