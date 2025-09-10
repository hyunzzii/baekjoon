#include <cstdio>
using namespace std;

int N, arr[1001]={0,}, idx=1;
void lower_func(int n){
    int s=1, e=idx, mid;
    while(s < e){
        mid = (s+e)/2;
        if(arr[mid]<=n) e=mid; 
        else s=mid+1;
    }
    arr[e] = n;
}
int main(void){
    scanf("%d",&N);
    int tmp;
    for(int i=1;i<=N;i++){
        scanf("%d",&tmp);
        if(tmp < arr[idx]) arr[++idx] = tmp;
        else lower_func(tmp);
    }
    printf("%d",idx);
}