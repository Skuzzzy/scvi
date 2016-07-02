
#include <stdio.h>
#define BUF_SIZE 2048

static char buffer[BUF_SIZE];

int main()
{
    while(1)
    {
	fputs("scvi> " , stdout);
	fgets(buffer, BUF_SIZE, stdin);
	printf("i: %s", buffer);
    }
}
