#include <stdio.h>

int main(int argc, char * argv[]){
    int leftNeighbor;
    scanf("%d", &leftNeighbor);

    fprintf(stderr, "%d\n", leftNeighbor);

    int n;
    scanf("%d", &n);
    while(n != -1){
        if(n % leftNeighbor != 0){
            fprintf(stdout, "%d\n", n);
        }
        scanf("%d", &n);
    }
    printf("%d\n", -1);
}