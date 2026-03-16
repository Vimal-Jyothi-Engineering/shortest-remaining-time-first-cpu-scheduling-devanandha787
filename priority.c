#include <stdio.h>
#include <limits.h>

struct Process {
    char pid[10];
    int at;
    int bt;
    int rt;
    int ct;
    int wt;
    int tat;
};

int main() {

    int n;
    scanf("%d",&n);

    struct Process p[20];

    for(int i=0;i<n;i++){
        scanf("%s %d %d",p[i].pid,&p[i].at,&p[i].bt);
        p[i].rt = p[i].bt;
    }

    int completed = 0;
    int time = 0;

    while(completed < n){

        int min_rt = INT_MAX;
        int index = -1;

        for(int i=0;i<n;i++){
            if(p[i].at <= time && p[i].rt > 0 && p[i].rt < min_rt){
                min_rt = p[i].rt;
                index = i;
            }
        }

        if(index == -1){
            time++;
            continue;
        }

        p[index].rt--;
        time++;

        if(p[index].rt == 0){
            completed++;

            p[index].ct = time;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;

            if(p[index].wt < 0)
                p[index].wt = 0;
        }
    }

    float avg_wt = 0;
    float avg_tat = 0;

    printf("Waiting Time:\n");
    for(int i=0;i<n;i++){
        printf("%s %d\n",p[i].pid,p[i].wt);
        avg_wt += p[i].wt;
    }

    printf("Turnaround Time:\n");
    for(int i=0;i<n;i++){
        printf("%s %d\n",p[i].pid,p[i].tat);
        avg_tat += p[i].tat;
    }

    printf("Average Waiting Time: %.1f\n",avg_wt/n);
    printf("Average Turnaround Time: %.1f\n",avg_tat/n);

    return 0;
}
