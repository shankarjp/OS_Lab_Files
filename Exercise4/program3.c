#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    pid_t p1, p2, p3, p4, p5;
    printf("p1: %d\n", getpid());
    p2 = fork();
    if(p2 == 0) {
        printf("p2: %d, parent: %d\n", getpid(), getppid());
    }
    else {
        p3 = fork();
        if(p3 == 0) {
            printf("p3: %d, parent: %d\n", getpid(), getppid());
            p4 = fork();
            if(p4 == 0) {
                printf("p4: %d, parent: %d\n", getpid(), getppid());
            }
            else {
                p5 = fork();
                if(p5 == 0) {
                    printf("p5: %d, parent: %d\n", getpid(), getppid());
                }
            }
        }
    };
    for(int i=0; i<3; i++) {
        wait(NULL);  
    };
}