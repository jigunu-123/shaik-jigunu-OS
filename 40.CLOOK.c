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

    // Find the index of the head position in the sorted requests array
    int headIndex = 0;
    for (i = 0; i < n; i++) {
        if (requests[i] >= head) {
            headIndex = i;
            break;
        }
    }

    // Scan in one direction
    for (i = headIndex; i < n; i++) {
        printf("%d ", requests[i]);
        totalMovement += abs(requests[i] - head);
        head = requests[i];
    }

    // Move to the first cylinder
    printf("%d ", min);
    totalMovement += abs(min - head);
    head = min;

    // Scan in the same direction from the beginning of the sorted requests array
    for (i = 0; i < headIndex; i++) {
        printf("%d ", requests[i]);
        totalMovement += abs(requests[i] - head);
        head = requests[i];
    }

    printf("\nTotal Head Movement: %d\n", totalMovement);
    return 0;
}
