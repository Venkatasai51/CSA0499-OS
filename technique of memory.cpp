#include <stdio.h>
#define MAX_FRAMES 3
#define MAX_PAGES 10
int frames[MAX_FRAMES];
int pageQueue[MAX_FRAMES];
int rear = -1, front = -1;
int isInFrame(int page) {
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (frames[i] == page)
            return 1;
    }
    return 0;
}
void displayFrames() {
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (frames[i] == -1)
            printf(" - ");
        else
            printf(" %d ", frames[i]);
    }
    printf("\n");
}
void addPage(int page) {
    if (rear == MAX_FRAMES - 1) {
        printf("\nPage Fault: Page %d cannot be added to the frame\n", pageQueue[front]);
        front++;
        rear++;
        frames[rear] = page;
    } else {
        rear++;
        frames[rear] = page;
    }
}
void replacePage(int page) {
    printf("\nPage Fault: Page %d replaced by page %d\n", frames[front], page);
    front++;
    rear++;
    frames[rear] = page;
}
int main() {
    int pages[MAX_PAGES] = {1, 2, 3, 4, 5, 1, 2, 1, 2, 6};
    int page_faults = 0;
    for (int i = 0; i < MAX_FRAMES; i++)
        frames[i] = -1;
    printf("\nSimulation of FIFO Paging Technique:\n\n");
    for (int i = 0; i < MAX_PAGES; i++) {
        printf("Referencing Page %d: ", pages[i]);
        if (!isInFrame(pages[i])) {
            page_faults++;
            if (front == -1 && rear == -1) {
                front++;
                rear++;
                frames[rear] = pages[i];
                pageQueue[rear] = pages[i];
            } else {
                if (rear == MAX_FRAMES - 1)
                    replacePage(pages[i]);
                else
                    addPage(pages[i]);
            }
        } else {
            printf("No Page Fault\n");
        }
        displayFrames();
    }
    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}

