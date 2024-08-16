#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main(void){
    int arr[10]={0,};
    char c;
    while(((c=getchar()))!='\n'){
        arr[c-48]++;
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<arr[i];j++){
            printf("%d",i);
        }
    }
}