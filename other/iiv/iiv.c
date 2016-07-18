
#include <termios.h>
#include <stdio.h>

struct termios orig_termios;

int main()
{
    struct termios t;
    int fd = 0;
    tcgetattr(fd, &orig_termios);
    t = orig_termios;
    t.c_lflag |= ~ECHO;
    tcsetattr(fd, TCSANOW, &t);

    char ch = getchar();
    printf("%c", ch);
    ch = getchar();

    /*orig_termios.c_lflag |= ECHO;*/

    tcsetattr(fd,TCSANOW,&orig_termios);

    return 0;
}
