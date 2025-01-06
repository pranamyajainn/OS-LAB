#include<stdio.h>

int main() {
    int pid[15], bt[15], wt[15], n;
    float twt = 0, tat = 0;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process IDs and burst times
    printf("Enter the process ID and burst time:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pid[i], &bt[i]);
    }

    // Calculate waiting time
    wt[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1]; // Waiting time is cumulative burst time
        twt += wt[i]; // Total waiting time
    }

    // Display the process table
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        int tat_i = wt[i] + bt[i]; // Turnaround time = Waiting time + Burst time
        tat += tat_i; // Total turnaround time
        printf("%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat_i);
    }

    // Calculate and display average waiting time and turnaround time
    printf("\nAverage Waiting Time = %.2f\n", twt / n);
    printf("Average Turnaround Time = %.2f\n", tat / n);

    return 0;
}
