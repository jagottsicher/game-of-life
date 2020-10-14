#include <stdio.h>

int main()
{
    for (int i = 32; i < 256;i++)
    {
        if (!(i==127))
            printf("%c", i);
    }
    printf("\n\u2500\u2501\n");
    return 0;
}