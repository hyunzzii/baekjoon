#include <iostream>
#include <string>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c;
    string m, p;
    while(true){
        int n, c, dp[10001] = {0,}, price, money;
        cin >> n >> m;
        money = stoi(m.substr(0, m.find('.')) + m.substr(m.find('.')+1));
        if(n==0) break;
        for(int i=0;i<n;i++){
            cin >> c >> p;
            price = stoi(p.substr(0, p.find('.')) + p.substr(p.find('.')+1));
            for(int j=price;j<=money;j++){
                dp[j] = dp[j] > dp[j-price] + c ? dp[j] : dp[j-price] + c;
            }
        }
        cout << dp[money] << "\n";
    }
}