#include <stdio.h>
#include<stdlib.h>
void decimalToBinary(FILE *inFile, FILE *outFile, int n)
{
    if (n > 0)
    {
        int num;
        if (fscanf(inFile, "%d", &num) != EOF)
        {
            fprintf(outFile, "%d : ", num);
            int binary[16] = {0};
            int i = 0;
            while (num > 0)
            {
                binary[i] = num % 2;
                num = num / 2;
                i++;
            }
            for (int j = 15; j >= 0; j--)
            {
                fprintf(outFile, "%d", binary[j]);
            }
            fprintf(outFile, "\n");
            decimalToBinary(inFile, outFile, n - 1);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage : %s ,<value1> <value2> <value3>\n", argv[0]);
        return 1;
    }
    FILE *inFile = fopen(argv[2], "r");
    FILE *outFile = fopen(argv[3], "w");
    int n = atoi(argv[1]);

    if (inFile == NULL || outFile == NULL)
    {
        printf("Error opening files.\n");
        return 1;
    }

    decimalToBinary(inFile, outFile, n);

    fclose(inFile);
    fclose(outFile);

    return 0;
}
