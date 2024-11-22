#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{   
    int count = 0;
    int count1 = 0;
    int count2 = 0;

    // the user must input 3 files
    if (argc != 4)
    {
        printf("Must provide 3 files\n");
    }

    // sourcefile for reading and 2 destination files for writing
    FILE * srcFile = fopen(argv[1], "r");
    if(!srcFile)
    {
        printf("Can't open %s for reading\n", argv[1]);
        exit(1);
    }

    FILE * destFile1 = fopen(argv[1], "w");
    if(!destFile1)
    {
        printf("Can't open %s for writing\n", argv[2]);
        exit(1);
    }

    FILE * destFile2 = fopen(argv[1], "w");
    if(!destFile2)
    {
        printf("Can't open %s for writing\n", argv[3]);
        exit(1);
    }


    char line[1000];
    {
        while (fgets(line, 1000, srcFile) != NULL)
        {   
            for(int i = 0; line[i] != '\0'; ++i)
            {
                count++;
            }

            if(count < 20)
            {
                for (int j = 0; line[j] != '\0'; ++j)
                {
                    line[j] = toupper(line[j]);
                }
                
                count1++;
                fprintf(destFile1, "%s", line);
            }

            else
            {
                for (int j = 0; line[j] != '\0'; ++j)
                {
                    line[j] = tolower(line[j]);
                }

                count2++;
                fprintf(destFile2, "%s", line);
            }
            
        }
    }

    printf("%d lines written to short.txt\n", count1);
    printf("%d lines written to long.txt\n", count2);

    fclose(srcFile);
    fclose(destFile1);
    fclose(destFile2);
}