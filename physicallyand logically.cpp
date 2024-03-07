#include <stdio.h>
#include <stdlib.h>
#define MAX_RECORDS 100
typedef struct {
    int records[MAX_RECORDS];
    int num_records;
} File;
void initFile(File *file) {
    file->num_records = 0;
}
void addRecord(File *file, int record) {
    if (file->num_records < MAX_RECORDS) {
        file->records[file->num_records++] = record;
    } else {
        printf("File is full. Cannot add record.\n");
    }
}
void readRecords(File *file, int record) {
    if (record <= file->num_records) {
        printf("Reading records up to record %d:\n", record);
        for (int i = 0; i < record; i++) {
            printf("%d ", file->records[i]);
        }
        printf("\n");
    } else {
        printf("Record %d does not exist.\n", record);
    }
}
int main() {
    File file;
    initFile(&file);
    addRecord(&file, 10);
    addRecord(&file, 20);
    addRecord(&file, 30);
    addRecord(&file, 40);
    readRecords(&file, 2); 
    readRecords(&file, 4); 
    readRecords(&file, 6); 
    return 0;
}

