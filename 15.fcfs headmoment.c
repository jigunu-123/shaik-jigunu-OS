#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_TRACKS 9

int main() {
    int tracks[NUM_TRACKS] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int head_pos = 50; // starting head position
    int total_head_movement = 0;

    printf("FCFS Disk Scheduling Algorithm\n\n");
    printf("Initial Head Position: %d\n", head_pos);
    printf("Track Order: ");
    for (int i = 0; i < NUM_TRACKS; i++) {
        printf("%d ", tracks[i]);
        total_head_movement += abs(head_pos - tracks[i]);
        head_pos = tracks[i];
    }
    printf("\n\nTotal Head Movement: %d\n", total_head_movement);
    printf("Average Head Movement: %.2f\n", (float)total_head_movement / NUM_TRACKS);

    return 0;
}
