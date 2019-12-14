#include <sys/file.h>
#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv)
=======


int main(int argc, char *argv[])
>>>>>>> 64071e97cc4c91bf98f4bcd2b7242aebbc87ab50
{
    int i;
    int fd;
    int charsRead;
    char buffer[4096];

<<<<<<< HEAD
    //fd = open("srcfile",O_RDONLY);
    fd = open(argv[1],O_RDONLY);
    charsRead = read(fd,buffer,100);
    write(1,buffer,charsRead);
    close(fd);

    //fd = open("COPYFILE",O_CREAT|O_RDWR,0600);
=======
    
    fd = open(argv[1],O_RDONLY);
    charsRead = read(fd,buffer,100);
    write(1,buffer,charsRead);
    
   
    close(fd);


>>>>>>> 64071e97cc4c91bf98f4bcd2b7242aebbc87ab50
    fd = open(argv[2],O_CREAT|O_RDWR,0600);
    write(fd,buffer,100);

    close(fd);

    return 0;
}
