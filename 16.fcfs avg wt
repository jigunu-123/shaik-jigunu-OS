#include <stdio.h>

#define NUM_PROCESSES 3

int main() {
    int burst_times[NUM_PROCESSES] = {10, 15, 25};
    int waiting_times[NUM_PROCESSES] = {0};
    int turnaround_times[NUM_PROCESSES] = {0};
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // calculate waiting time for each process
    for (int i = 1; i < NUM_PROCESSES; i++) {
        waiting_times[i] = waiting_times[i-1] + burst_times[i-1];
        total_waiting_time += waiting_times[i];
    }

    // calculate turnaround time for each process
    for (int i = 0; i < NUM_PROCESSES; i++) {
        turnaround_times[i] = waiting_times[i] + burst_times[i];
        total_turnaround_time += turnaround_times[i];
    }

    // print out results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, burst_times[i], waiting_times[i], turnaround_times[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / NUM_PROCESSES);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / NUM_PROCESSES);

    return 0;
}
