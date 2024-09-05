#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n*2-1; i++){
        for(int j = 1; j <= n*2-1; j++){
            printf("%d ", n - abs(n - i) < n - abs(n - j) ? abs(n - i) + 1 : abs(n - j) + 1);
        }
        printf("\n");
    }


    return 0;
}