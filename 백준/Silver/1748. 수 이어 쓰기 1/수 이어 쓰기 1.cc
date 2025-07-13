#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;
    int n = stoi(s), len = s.length();
    int ans = 0;
    for(int i=1;i<len;i++){
        ans += 9 * pow(10,i-1) * i;
        n -= 9 * pow(10,i-1);
    }
    ans += n*len;
    cout << ans;
}