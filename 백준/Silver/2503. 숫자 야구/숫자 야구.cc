#include <iostream>
using namespace std;
#define MAX 504

bool check(int origin, int target, int s, int b){
    int ss=0, bb=0, x[3], y[3];
    for(int i=0,num=100;i<3;i++,num/=10){
        x[i] = origin/num;
        y[i] = target/num;
        origin %= num;
        target %= num;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(x[i] == y[j]){
                if(i==j)ss++;
                else bb++;
                break;
            }
        }
    }
    return ss==s && bb==b ? true : false;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, input, s, b, tmp[3];
    int arr[MAX], checked[MAX] = {0,}, sum=MAX;
    for(int i=1,idx=0;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(i==j) continue;
            for (int k=1;k<=9;k++){
                if(i==k || j==k) continue;
                arr[idx++] = i*100 + j*10 + k;
            }
        }
    }

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> input >> s >> b;
        for(int i=0;i<MAX;i++){
            if(!checked[i] && !check(arr[i],input,s,b)){
                checked[i] = 1;
                sum--;
            }
        }
    }
    cout << sum;
}