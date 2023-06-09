#include <stdio.h>
typedef struct {
    int pid;
    int burst_time;
    int wait_time;
    int turnaround_time;
} Process;
void fcfs(Process processes[], int n, float* avg_wait_time, float* avg_turnaround_time) {
    int i;
    int total_wait_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;
    for (i = 0; i < n; i++) {
        Process process = processes[i];
        process.wait_time = current_time;
        current_time += process.burst_time;
        process.turnaround_time = current_time;
        total_wait_time += process.wait_time;
        total_turnaround_time += process.turnaround_time;
    }
    *avg_wait_time = (float) total_wait_time / n;
    *avg_turnaround_time = (float) total_turnaround_time / n;
}

int main() 
{
    Process processes[] = {{0, 2, 0, 0}, {1, 4, 0, 0}, {2, 8, 0, 0}};
    int n = sizeof(processes) / sizeof(Process);
    float avg_wait_time, avg_turnaround_time;
    fcfs(processes, n, &avg_wait_time, &avg_turnaround_time);
    printf("Average waiting time: %.2f\n", avg_wait_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
    
    return 0;
}
