#include <stdio.h>
#include <stdlib.h>
#define MAX_FRAMES 3
#define MAX_PAGES 10
int isInFrame(int page, int *frames, int frameCount) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page)
            return 1;
    }
    return 0;
}
void displayFrames(int *frames, int frameCount) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == -1)
            printf(" - ");
        else
            printf(" %d ", frames[i]);
    }
    printf("\n");
}
void replacePage(int page, int *frames, int *pageLastUsed, int frameCount) {
    int leastUsedIndex = 0;
    for (int i = 1; i < frameCount; i++) {
        if (pageLastUsed[i] < pageLastUsed[leastUsedIndex])
            leastUsedIndex = i;
    }
    printf("\nPage Fault: Page %d replaced by page %d\n", frames[leastUsedIndex], page);
    frames[leastUsedIndex] = page;
}
int main() {
    int pages[MAX_PAGES] = {1, 2, 3, 4, 5, 1, 2, 1, 2, 6};
    int frames[MAX_FRAMES];
    int pageLastUsed[MAX_FRAMES] = {0};
    int page_faults = 0;
    for (int i = 0; i < MAX_FRAMES; i++)
        frames[i] = -1;
    printf("\nSimulation of LRU Paging Technique:\n\n");
    for (int i = 0; i < MAX_PAGES; i++) {
        printf("Referencing Page %d: ", pages[i]);
        if (!isInFrame(pages[i], frames, MAX_FRAMES)) {
            page_faults++;
            if (i < MAX_FRAMES) {
                frames[i] = pages[i];
                pageLastUsed[i] = i + 1;
            } else {
                replacePage(pages[i], frames, pageLastUsed, MAX_FRAMES);
                for (int j = 0; j < MAX_FRAMES; j++) {
                    if (frames[j] == -1)
                        continue;
                    if (frames[j] != pages[i]) {
                        pageLastUsed[j]++;
                    } else {
                        pageLastUsed[j] = 1;
                    }
                }
            }
        } else {
            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == pages[i]) {
                    pageLastUsed[j] = 1;
                    break;
                }
            }
            printf("No Page Fault\n");
        }
        displayFrames(frames, MAX_FRAMES);
    }
    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}

