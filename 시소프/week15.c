#include <sys/file.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv)
{
    int i;
    int fd;
    int charsRead;
    char buffer[4096];

    //fd = open("srcfile",O_RDONLY);
    fd = open(argv[1],O_RDONLY);
    charsRead = read(fd,buffer,100);
    write(1,buffer,charsRead);
    close(fd);

    //fd = open("COPYFILE",O_CREAT|O_RDWR,0600);
    fd = open(argv[2],O_CREAT|O_RDWR,0600);
    write(fd,buffer,100);

    close(fd);

    return 0;
}
