#include <stdio.h>

#define MAX_FRAMES 10

int main() {
    int pages[MAX_FRAMES];  // array to store the pages in frames
    int page_count = 0;     // number of pages currently in frames
    int page_faults = 0;    // number of page faults
    int i, j, k;

    // initialize all pages to -1 to indicate an empty frame
    for (i = 0; i < MAX_FRAMES; i++) {
        pages[i] = -1;
    }

    // read the page sequence from input
    int n;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int sequence[n];
    printf("Enter page sequence: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    // perform FIFO page replacement
    for (i = 0; i < n; i++) {
        int page = sequence[i];
        int page_found = 0;

        // check if page is already in frames
        for (j = 0; j < page_count; j++) {
            if (pages[j] == page) {
                page_found = 1;
                break;
            }
        }

        // if page is not in frames, replace the oldest page with the new page
        if (!page_found) {
            if (page_count < MAX_FRAMES) {
                // add new page to an empty frame
                pages[page_count] = page;
                page_count++;
            } else {
                // replace the oldest page with the new page
                for (j = 0; j < MAX_FRAMES - 1; j++) {
                    pages[j] = pages[j+1];
                }
                pages[MAX_FRAMES - 1] = page;
            }
            page_faults++;
        }

        // print the current state of the frames after each page is processed
        printf("Page %d: ", page);
        for (j = 0; j < page_count; j++) {
            printf("%d ", pages[j]);
        }
        for (j = page_count; j < MAX_FRAMES; j++) {
            printf("- ");
        }
        printf("\n");
    }

    printf("Total number of page faults: %d\n", page_faults);

    return 0;
}
