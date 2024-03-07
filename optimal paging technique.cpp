#include <stdio.h>
#include <stdlib.h>
#define MAX_FRAMES 3
#define MAX_PAGES 10
#define INF 9999
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
int findOptimalReplacement(int *pages, int currentPage, int currentPageIndex, int *frames, int frameCount) {
    int optimalIndex = -1, farthestPageIndex = -1;
    for (int i = 0; i < frameCount; i++) {
        int j;
        for (j = currentPageIndex + 1; j < MAX_PAGES; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthestPageIndex) {
                    farthestPageIndex = j;
                    optimalIndex = i;
                }
                break;
            }
        }
        if (j == MAX_PAGES)
            return i; 
    }
    return optimalIndex;
}
int main() {
    int pages[MAX_PAGES] = {1, 2, 3, 4, 5, 1, 2, 1, 2, 6};
    int frames[MAX_FRAMES];
    int page_faults = 0;
    for (int i = 0; i < MAX_FRAMES; i++)
        frames[i] = -1;
    printf("\nSimulation of Optimal Paging Technique:\n\n");
    for (int i = 0; i < MAX_PAGES; i++) {
        printf("Referencing Page %d: ", pages[i]);
        if (!isInFrame(pages[i], frames, MAX_FRAMES)) {
            page_faults++;
            if (i < MAX_FRAMES) {
                frames[i] = pages[i];
            } else {
                int optimalIndex = findOptimalReplacement(pages, pages[i], i, frames, MAX_FRAMES);
                frames[optimalIndex] = pages[i];
            }
        } else {
            printf("No Page Fault\n");
        }
        displayFrames(frames, MAX_FRAMES);
    }
    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}

