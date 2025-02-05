#include <cstdio>
using namespace std;

int main(void){
    long long k,n,arr[10000]={0,};
    scanf("%d %d",&k,&n);
    long long s=1,e=0;
    for(int i=0;i<k;i++){
        scanf("%d",&arr[i]);
        if(e < arr[i]){
            e= arr[i];
        }
    }
    while(s <= e){
        int sum=0;
        long long mid = (s+e)/2;
        for(int i=0;i<k;i++){
            sum += (arr[i]/mid);
        }
        if(sum < n){
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    printf("%d",e);
} 