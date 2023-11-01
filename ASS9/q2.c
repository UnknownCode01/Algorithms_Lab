#include <stdio.h>
#include <string.h>
#include <math.h>

int max(int a, int b)
{

    return (a > b) ? a : b;
}

void LCS(char x[], char y[])
{
    int m = strlen(x);
    int n = strlen(y);
    int z[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        z[i][0] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        z[0][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (x[i - 1] == y[j - 1])
                z[i][j] = z[i - 1][j - 1] + 1;
            else
                z[i][j] = max(z[i - 1][j], z[i][j - 1]);
        }
    }

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%d ", z[i][j]);
        }
        printf("\n");
    }

    printf("m=%d, n=%d, length=%d\n", m, n, z[m][n]);
}

int main()
{
    char s1[50];
    char s2[50];
    printf("Enter the string 1 : ");
    scanf("%s", s1);
    printf("Enter the string 2 : ");
    scanf("%s", s2);
    LCS(s1, s2);

    return 0;
}
