#include <stdio.h>

int n;
void findPrime(int num, int m){
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return;
        }
    }
    int x[4]={1,3,7,9};
    
    if(m==n){
        printf("%d\n",num);
    }
    else{
        for(int i=0;i<4;i++){
            findPrime(num*10 + x[i], m+1);
        }
    }
} 

int main(void){
    scanf("%d",&n);

    findPrime(2,1);
    findPrime(3,1);
    findPrime(5,1);
    findPrime(7,1);
}