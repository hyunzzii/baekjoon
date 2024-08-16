#include <iostream>
using namespace std;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,tem,sum=0,result=0;
    cin >> n;
    int arr[1001] = {0,};

    while(n--){
        cin >> tem;
        arr[tem]++;
    }
    for(int i=1;i<1001;i++){
        while(arr[i]--){
            result += sum + i;
            sum += i;
        }
    }
    cout << result;
}