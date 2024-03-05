#include <stdio.h>
void implementFirstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocation[processes];
    for(int i = 0; i < processes; i++){
        allocation[i] = -1;
    }
    for (int i=0; i < processes; i++)
    {
        for(int j = 0; j < blocks; j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
int main()
{
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int blocks = sizeof(blockSize)/sizeof(blockSize[0]);
    int processes = sizeof(processSize)/sizeof(processSize[0]);
    implementFirstFit(blockSize, blocks, processSize, processes);
    return 0 ;
}

