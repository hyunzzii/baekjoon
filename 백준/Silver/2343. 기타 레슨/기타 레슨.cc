#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m,s=0,e=0,mid,result;
    int arr[100000] = {0,};
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        e+= arr[i];
        if(s < arr[i]){
            s = arr[i];
        }
    }
    result = e;
    while(s<=e){
        mid = (s+e)/2;
        int sum=0,num=1;
        for(int i=0;i<n;i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }
            else{
                num++;
                sum=arr[i];
            }
        }
        if(num<=m){
            e = mid-1;
            if(mid < result){
                result = mid;
            }
        }else{
            s = mid+1;
        }
    }
    cout << result;
} 