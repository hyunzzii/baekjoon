#include <iostream>
using namespace std;

int n,m;
int arr[100000] = {0,};

int explore(int mid){
    int sum=0,num=1;
    for(int i=0;i<n;i++){
        if(sum+arr[i]<=mid){
            sum+=arr[i];
        }
        else if(arr[i] > mid){
            return m+1;
        }
        else{
            num++;
            sum=arr[i];
        }
    }
    return num;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum=0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum+= arr[i];
    }
    int s=0, e=sum, mid, result=sum;
    while(s<=e){
        mid = (s+e)/2;
        int num = explore(mid);
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