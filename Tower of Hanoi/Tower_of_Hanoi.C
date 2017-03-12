/*
    SOLUTION TO TOWER OF HANOI PROBLEM
    AUTHOR: PROGYAN BHATTACHARYA
    GIT REPO: https://github.com/Progyan1997/Puzzle-Day/Tower_of_Hanoi
*/

#ifndef __stdio_h
#include <stdio.h>
#endif
#ifndef __stdlib_h
#include <stdlib.h>
#endif

void Tower_of_Hanoi(unsigned int N, char* SRC, char* DEST, char* VIA)
{
    if (N == 1){
        printf("Moved Disc#1 from %s to %s\n", SRC, DEST);
        return;
    }
    Tower_of_Hanoi(N - 1, SRC, VIA, DEST);
    printf("Moved Disc#%u from %s to %s\n", N, SRC, DEST);
    Tower_of_Hanoi(N - 1, VIA, DEST, SRC);
}

int main(int argc, char *argv[])
{
    if (argc != 5){
        fprintf(stderr, "Usage: %s N SOURCE DESTINATION VIA", argv[0]);
        return 1;
    }    
    unsigned int N = atoi(argv[1]);
    Tower_of_Hanoi(N, argv[2], argv[3], argv[4]);
    return 0;
}