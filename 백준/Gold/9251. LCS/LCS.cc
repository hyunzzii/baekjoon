#include <iostream>
#include <string>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a;
    cin >> b;
    int arr[1002][1002] = {0,};
    for(int i=1;i<=a.length();i++){
        for(int j=1;j<=b.length();j++){
            if(a[i-1] == b[j-1]) arr[i][j] = arr[i-1][j-1] + 1;
            else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
    }
    cout << arr[a.length()][b.length()];
}