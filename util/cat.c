#include <stdio.h>
#define putchar(c) putc((c),stdout)

int tab_flag = 0;

void ucat(FILE *file)
{
    setbuf(stdout, NULL);
    char ch = getc(file);
    while(ch != EOF)
    {
	if (tab_flag && ch == '\t')
	{
	    putc('^', stdout);
	    putc('I', stdout);
	}
	else
	{
	    putc(ch, stdout);
	}

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
		switch(argv[i][argindex])
		{
		case 't':
		case 'T':
		    tab_flag = 1;
		    break;
		}
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
