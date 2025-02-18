#include <cstdio>
using namespace std;

int main(void){
    int n, arr[10000]={0,},max=0,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(arr[i] > max){
            max = arr[i];
        }
    }
    scanf("%d",&m);
    
    int s=1,e=m,mid,sum;
    while(s<=e){
        mid = (s+e)/2;
        sum=0;
        for(int i=0;i<n;i++){
            if(arr[i] > mid){
                sum+=mid;
            }else{
                sum+=arr[i];
            }
        }
        if(sum <= m){
            s = mid+1;
            if(mid >= max){
                e = max;
                break;
            }
        }else{
            e = mid-1;
        }
    }
    printf("%d",e);
} 