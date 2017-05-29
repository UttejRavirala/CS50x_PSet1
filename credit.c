#include <stdio.h>
#include <cs50.h>
#include <math.h>

void checkCredit(long long credit, int type){
    long long n=credit/10;
    int prosum=0;
    while(n>0){
        int product=(n%10)*2;
        while(product>0){
            prosum+=product%10;
            product=product/10;
        }
        n=n/100;
    }
    n=credit;
    while(n>0){
        prosum+=n%10;
        n=n/100;
    }
    if(prosum%10==0){
        switch(type){
            case 1: printf("AMEX\n");
            break;
            case 2: printf("MASTERCARD\n");
            break;
            case 3: printf("VISA\n");
            break;
            default: printf("INVALID\n");
        }
    }
}

int main(void){
    printf("Credit:\t");
    long long credit=get_long_long(), n;
    n=credit;
    int length=0;
    while(n>0){
        n=n/10;
        length++;
    }
    
    if(!(length==13 || length==15 || length ==16)) printf("INVALID\n");
    
    if(length==15){
        long long first = credit/(pow(10,13));
        if(!(first==34 || first==37)) printf("INVALID\n");
        checkCredit(credit, 1);
    }
    
    if(length==16){
        long long firstMaster = credit/(pow(10,14));
        long long firstVisa = credit/(pow(10,15));
        if(!(firstMaster==51 || firstMaster==52 || firstMaster==53 || firstMaster==54 || firstMaster==55 || firstVisa==4)) printf("INVALID\n");
        if(firstMaster==51 || firstMaster==52 || firstMaster==53 || firstMaster==54 || firstMaster==55)
            checkCredit(credit, 2);
        if(firstVisa == 4){
            checkCredit(credit, 3);
        }
    }

    if(length==13){
        long long firstVisa = credit/(pow(10,12));
        if(!(firstVisa==4)) printf("INVALID\n");
        checkCredit(credit, 3);
    }
    
}