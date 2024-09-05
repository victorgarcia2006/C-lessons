#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	char ch;
    char s[100];
    char s2[100];

    scanf("%c", &ch);
    scanf("%s", s);
    scanf("\n");
    scanf("%[^\n]%*c", s2);

    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s", s2);
    
      
    return 0;
}