#include <stdio.h>

#define MAX_PROCESSES 10

int main() {
    int n;                          // number of processes
    int burst_times[MAX_PROCESSES]; // array to store burst times
    int waiting_times[MAX_PROCESSES]; // array to store waiting times
    int turnaround_times[MAX_PROCESSES]; // array to store turnaround times
    int i, j, temp;

    // read the number of processes and their burst times
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the CPU burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &burst_times[i]);
    }

    // sort the burst times in ascending order using selection sort
    for (i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (burst_times[j] < burst_times[min_idx]) {
                min_idx = j;
            }
        }
        // swap burst times
        temp = burst_times[i];
        burst_times[i] = burst_times[min_idx];
        burst_times[min_idx] = temp;
    }

    // compute waiting times and turnaround times
    waiting_times[0] = 0;
    turnaround_times[0] = burst_times[0];
    for (i = 1; i < n; i++) {
        waiting_times[i] = waiting_times[i-1] + burst_times[i-1];
        turnaround_times[i] = turnaround_times[i-1] + burst_times[i];
    }

    // compute average waiting time and average turnaround time
    float avg_waiting_time = 0.0;
    float avg_turnaround_time = 0.0;
    for (i = 0; i < n; i++) {
        avg_waiting_time += waiting_times[i];
        avg_turnaround_time += turnaround_times[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // print the results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i+1, burst_times[i], waiting_times[i], turnaround_times[i]);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);

    return 0;
}
