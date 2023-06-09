#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROCESSES 100

int main() {
    int memory_size, n_blocks, n_processes;
    int block_sizes[MAX_BLOCKS], block_flags[MAX_BLOCKS];
    int process_sizes[MAX_PROCESSES], process_flags[MAX_PROCESSES];
    int i, j;

    // read the memory size and number of memory blocks
    printf("Enter the total memory size: ");
    scanf("%d", &memory_size);
    printf("Enter the number of memory blocks: ");
    scanf("%d", &n_blocks);

    // read the sizes of each memory block
    printf("Enter the size of each memory block:\n");
    for (i = 0; i < n_blocks; i++) {
        scanf("%d", &block_sizes[i]);
        block_flags[i] = 0; // initialize all blocks to be free
    }

    // read the number of processes and their sizes
    printf("Enter the number of processes: ");
    scanf("%d", &n_processes);
    printf("Enter the size of each process:\n");
    for (i = 0; i < n_processes; i++) {
        scanf("%d", &process_sizes[i]);
        process_flags[i] = 0; // initialize all processes to be not allocated
    }

    // allocate memory to processes using first-fit algorithm
    for (i = 0; i < n_processes; i++) {
        for (j = 0; j < n_blocks; j++) {
            if (process_flags[i] == 0 && block_flags[j] == 0 && process_sizes[i] <= block_sizes[j]) {
                // allocate the memory block to the process
                block_flags[j] = 1;
                process_flags[i] = 1;
                printf("Process %d allocated to memory block %d\n", i+1, j+1);
            }
        }
        if (process_flags[i] == 0) {
            printf("Process %d cannot be allocated to any memory block\n", i+1);
        }
    }

    return 0;
}
