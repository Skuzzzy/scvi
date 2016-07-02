
#include <stdio.h>
#define putchar(c) putc((c),stdout)

void ucat(FILE *file)
{
    setbuf(stdout, NULL);
    char ch = getc(file);
    while(ch != EOF)
    {
	putc(ch, stdout);
	ch = getc(file);
    }
}

int main(int argc, char **argv)
{

    /*
    for(int i=0; i<argc; i++)
    {
	puts(argv[i]);
    }
    */

    // Scan argv
    int flag_group_count = 0;
    for(int i=1; i<argc; i++)
    {
	if(argv[i][0] == '-')
	{
            int argindex = 1;
	    while(argv[i][argindex] != '\0')
	    {
		//  Handle no cmd line flags at the moment
		//putchar(argv[i][argindex++]);
		//putchar('\n');
		argindex++;
	    }
	    flag_group_count++;
        }
        else 
	{
	    FILE *in = fopen(argv[i], "r");
	    if(!in)
	    {
		printf("ERROR: Could not find file \"%s\"\n", argv[i]);
		return 1;
	    }
	    else
	    {
		ucat(in);
	    }
        }
    }
//    printf("%d %d", argc, flag_group_count);
    if(argc-flag_group_count-1 == 0)
    {
	ucat(stdin);
    }
    
    
    return 0;
}
