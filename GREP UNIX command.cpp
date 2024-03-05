#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
int main(int argc, char *argv[])
{
    char *fname, *pat, buf[MAX];
    FILE *fp;
    int line, occ;
    fname = argv[1];
    pat = argv[2];
    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        perror("fopen");
        exit(1);
    }
    line = 0;
    occ = 0;
    while (fgets(buf, MAX, fp) != NULL)
    {
        line++;
        if (strstr(buf, pat) != NULL)
        {
            printf("%s %d %s", fname, line, buf);

            occ++;
        }
    }
    fclose(fp);
    if (ferror(fp))
    {
        perror("fclose");
        exit(1);
    }
    printf("\n Occurrence = %d\n", occ);
    return 0;
}

