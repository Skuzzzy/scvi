
#include <stdio.h>
#include <ctype.h>
#define putcn(ch) {putc(ch, stdout); putc('\n', stdout)}


int special_char(char ch)
{
    switch(ch)
    {
        case '[':
        case ']':
        case '{':
        case '}':    
        case '\'':    
        case '`':    
        case '~':    
        case '^':    
        case '@':
            return 1;
        default:
            return 0;
            break;
    }
}

void emit_tokens(char * code, int size)
{
    int index = 0;
    int comment_line = 0;
    while(index < size)
    {
        char ch = code[index++];
        if(comment_line)
        {
            if(ch == '\n')
            {
                comment_line = 0;
            }
            continue;
        }
        else if(special_char(ch))
        {
            putcn(ch);
        }
        else if(ch == ';')
        {
            comment_line = 1;
        }
        else if(isalnum(ch) || ch == '+' || ch == '-')
        {
            putc(ch, stdout);
        }
    }
}


int main()
{

}

