#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{   

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

    FILE * destFile1 = fopen(argv[2], "w");
    if(!destFile1)
    {
        printf("Can't open %s for writing\n", argv[2]);
        exit(1);
    }

    FILE * destFile2 = fopen(argv[3], "w");
    if(!destFile2)
    {
        printf("Can't open %s for writing\n", argv[3]);
        exit(1);
    }


    char line[1000];
    {   
        // Read each line from the source file
        while (fgets(line, 1000, srcFile) != NULL)
        {  
            // Get the length of the line, excluding the newline character
           int length = strlen(line) - 1;

            // If the line is shorter than 20 characters, convert it to uppercase and write to destFile1
            if(length < 20)
            {
                for (int j = 0; line[j] != '\0'; ++j)
                {
                    line[j] = toupper(line[j]);
                }
                
                count1++;
                fprintf(destFile1, "%s", line);
            }

            // If the line is 20 characters or longer, convert it to lowercase and write to destFile2
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

    // Output the number of lines written to each destination file
    printf("%d lines written to short.txt\n", count1);
    printf("%d lines written to long.txt\n", count2);

    // Close the files
    fclose(srcFile);
    fclose(destFile1);
    fclose(destFile2);
}