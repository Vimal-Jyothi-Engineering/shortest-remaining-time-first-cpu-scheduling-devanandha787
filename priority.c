#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("\nEnter Arrival Time and Burst Time for Process %d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];   // remaining time = burst time initially
    }

    int completed = 0, time = 0, min = 9999, shortest = -1;
    int finish_time;

    while(completed != n) {

        min = 9999;
        shortest = -1;

        for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min) {
                min = rt[i];
                shortest = i;
            }
        }

        if(shortest == -1) {
            time++;
            continue;
        }

        rt[shortest]--;
        time++;

        if(rt[shortest] == 0) {
            completed++;
            finish_time = time;

            ct[shortest] = finish_time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
        }
    }

    float total_wt = 0, total_tat = 0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];

        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);

    return 0;
}
