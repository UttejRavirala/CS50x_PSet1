#include <stdio.h>
#include <cs50.h>

int main(void){
    printf("Enter no. of minutes:\t");
    int min=get_int();
    printf("Minutes: %d\nBottles: %d\n", min, min*12);
}