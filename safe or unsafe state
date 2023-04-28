# shaik-jigunu-OS
OPERATING SYSTEM-CSA0413
#include <stdio.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int finished[MAX_PROCESSES];

int num_processes, num_resources;

void input_data() {
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    printf("Enter the available resources: ");
    for(int i=0; i<num_resources; i++) {
        scanf("%d", &available[i]);
    }

    printf("Enter the maximum resource allocation for each process: ");
    for(int i=0; i<num_processes; i++) {
        for(int j=0; j<num_resources; j++) {
            scanf("%d", &maximum[i][j]);
            need[i][j] = maximum[i][j];
        }
        finished[i] = 0;
    }

    printf("Enter the current resource allocation for each process: ");
    for(int i=0; i<num_processes; i++) {
        for(int j=0; j<num_resources; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] -= allocation[i][j];
        }
    }
}

int can_finish(int process) {
    for(int i=0; i<num_resources; i++) {
        if(need[process][i] > available[i]) {
            return 0;
        }
    }
    return 1;
}

void release_resources(int process) {
    for(int i=0; i<num_resources; i++) {
        available[i] += allocation[process][i];
        allocation[process][i] = 0;
        need[process][i] = 0;
    }
}

void print_safe_sequence(int sequence[]) {
    printf("Safe sequence: ");
    for(int i=0; i<num_processes; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");
}

void find_safe_sequence() {
    int sequence[MAX_PROCESSES];
    int count = 0;

    while(count < num_processes) {
        int found = 0;
        for(int i=0; i<num_processes; i++) {
            if(!finished[i] && can_finish(i)) {
                finished[i] = 1;
                sequence[count++] = i;
                release_resources(i);
                found = 1;
            }
        }
        if(!found) {
            printf("System is not safe.\n");
            return;
        }
    }

    print_safe_sequence(sequence);
}

int main() {
    input_data();
    find_safe_sequence();
    return 0;
}
