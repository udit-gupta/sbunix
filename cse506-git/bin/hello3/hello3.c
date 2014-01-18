#include <stdio.h>
#include <defs.h>
#include <stdlib.h>
int j;
int main(int argc, char* argv[], char* envp[]) {
    char buf[1024] = "We would like to express the deepest appreciation to our course instructor Professor Mike Ferdman, who has provided ceaseless help and guidance during the entire course of project. Also, we are thankful to the course mailing list and its active members for their continuous reference and assistance at every step of development of this project. In addition to that we would like to mention few of our class mates who extended a helping hand and stood by us during the critical moments. They include Rajesh Golani, Shashank Gupta, Prashant Pandey, Haseeb Niaz, Gautam Goswami, Sohil Gandhi, Akshay Joshi, Aniket Alshi, Sahil Parmar , Chidambaram Ramanathan, Tapti Palit, Kavita Agarwal, Srikanth Kandalam, and Abhinav Mishra. Last but not the least, we thank all who were directly or indirectly responsible for the completion of this course project.\n";
    printf("\nInside hello2 file\n");
    printf("\nbuf = %s\n", buf);

    file *fd = open("hdd/sbunix.txt");
    write(fd, buf, 100);
    printf("\nSize of %s\n", fd->filename);

    seek(fd, 50, SEEK_CUR);

    char* test = (char *)malloc(100*sizeof(char));
    read(fd, 50, test);
    printf(" \n offset  %d %s \n",fd->offset, test);

    uint64_t add = opendir("bin/");
    printf("\nOpendir Address=%x\n", add);
    printf("\nContents of Directory:\n");
    readdir(add);

    exit(1);
    return 0;
}
