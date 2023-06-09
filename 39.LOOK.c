#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, head, i, j, totalMovement = 0;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the requests sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    int min = 0, max = 199; // Minimum and maximum cylinder values

    printf("\nSeek Sequence: %d ", head);
    totalMovement += abs(head - requests[0]);

    int direction = 1; // 1 for moving towards higher cylinders, -1 for moving towards lower cylinders

    // Sort the requests in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    if (head < requests[0])
        direction = 1;
    else
        direction = -1;

    // Scan in one direction
    if (direction == 1) {
        for (i = 0; i < n; i++) {
            if (requests[i] >= head) {
                printf("%d ", requests[i]);
                totalMovement += abs(requests[i] - head);
                head = requests[i];
            }
        }

        // Move to the last cylinder
        printf("%d ", max);
        totalMovement += abs(max - head);
        head = max;

        // Scan in the opposite direction
        for (i = n - 1; i >= 0; i--) {
            if (requests[i] < head) {
                printf("%d ", requests[i]);
                totalMovement += abs(requests[i] - head);
                head = requests[i];
            }
        }
    } else { // Scan in the opposite direction
        for (i = n - 1; i >= 0; i--) {
            if (requests[i] <= head) {
                printf("%d ", requests[i]);
                totalMovement += abs(requests[i] - head);
                head = requests[i];
            }
        }

        // Move to the first cylinder
        printf("%d ", min);
        totalMovement += abs(min - head);
        head = min;

        // Scan in the opposite direction
        for (i = 0; i < n; i++) {
            if (requests[i] > head) {
                printf("%d ", requests[i]);
                totalMovement += abs(requests[i] - head);
                head = requests[i];
            }
        }
    }

    printf("\nTotal Head Movement: %d\n", totalMovement);
    return 0;
}
