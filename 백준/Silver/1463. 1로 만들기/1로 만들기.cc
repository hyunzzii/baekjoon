#include <cstdio>
#include <climits>
using namespace std;

int N;
int arr[1000001] = {0,};

int min(int a, int b){
    return a < b ? a : b;
}
int main(void){
    scanf("%d",&N);
    int a,b,c;
    for(int i=2;i<=N;i++){
        a=b=INT_MAX;
        c=arr[i-1];
        if(i%2==0) a=arr[i/2];
        if(i%3==0) b=arr[i/3];
        arr[i] = min(a,min(b,c)) + 1;
    }
    printf("%d",arr[N]);
}