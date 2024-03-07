#include <stdio.h>
#include <stdlib.h>
#define MAX_BLOCKS 100 // Corrected to an integer value

typedef struct {
    int index_block[MAX_BLOCKS]; 
    int num_blocks; 
} File;

void initFile(File *file) {
    file->num_blocks = 0;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        file->index_block[i] = -1; 
    }
}

void addBlock(File *file, int block) {
    if (file->num_blocks < MAX_BLOCKS) {
        file->index_block[file->num_blocks++] = block;
    } else {
        printf("File is full. Cannot add block.\n");
    }
}

void readBlock(File *file, int blockIndex) { // Renamed variable for clarity
    if (blockIndex < file->num_blocks) {
        printf("Reading block %d:\n", blockIndex);
        printf("Block contents: %d\n", file->index_block[blockIndex]);
    } else {
        printf("Block %d does not exist.\n", blockIndex);
    }
}

int main() {
    File file;
    initFile(&file);
    addBlock(&file, 10);
    addBlock(&file, 20);
    addBlock(&file, 30);
    addBlock(&file, 40);
    readBlock(&file, 0); 
    readBlock(&file, 2); 
    readBlock(&file, 4); // This will print "Block 4 does not exist." because only 4 blocks (0-3) have been added
    return 0;
}

