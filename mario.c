#include <stdio.h>
#include <cs50.h>

int main(void){
    int n;
    do{
        printf("Height:\t");
        n=get_int();
    }while(n<0 || n>23);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            printf(" ");
        }
        for(int j=0; j<=i; j++){
            printf("#");
        }
        printf("  ");
        for(int j=0; j<=i; j++){
            printf("#");
        }
        printf("\n");
    }
}