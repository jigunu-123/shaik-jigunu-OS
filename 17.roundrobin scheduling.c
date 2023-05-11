#include <stdio.h>

#define MAX_PROCESS 3
#define QUANTUM_TIME 4

struct process {
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    struct process processes[MAX_PROCESS] = {
        {24, 24, 0, 0},
        {3, 3, 0, 0},
        {3, 3, 0, 0}
    };

    int time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int completed_processes = 0;

    while (completed_processes < MAX_PROCESS) {
        for (int i = 0; i < MAX_PROCESS; i++) {
            if (processes[i].remaining_time <= 0) {
                continue;
            }

            int time_slice = processes[i].remaining_time < QUANTUM_TIME ? processes[i].remaining_time : QUANTUM_TIME;
            processes[i].remaining_time -= time_slice;
            time += time_slice;

            if (processes[i].remaining_time <= 0) {
                completed_processes++;
                processes[i].turnaround_time = time;
                processes[i].waiting_time = time - processes[i].burst_time;
                total_waiting_time += processes[i].waiting_time;
                total_turnaround_time += processes[i].turnaround_time;
            }
        }
    }

    float avg_waiting_time = (float) total_waiting_time / MAX_PROCESS;
    float avg_turnaround_time = (float) total_turnaround_time / MAX_PROCESS;

    printf("Average Waiting Time: %.2f ms\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f ms\n", avg_turnaround_time);

    return 0;
}
