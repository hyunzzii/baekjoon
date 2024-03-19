#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int N;
    int sum = 0;
    scanf("%d",&N);
    
    for(int i=1;;i+=2){
        if((N/i) - (i/2) < 1)break;
        if(N % i == 0){
            sum++;
        }
    }
    for(int i=2;; i+=2){
        if((N/i) - (i/2 - 1) < 1)break;
        if(N % i == i / 2){
            sum++;
        }
    }
    
    printf("%d",sum);
}