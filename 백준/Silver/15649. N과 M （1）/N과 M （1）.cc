#include <iostream>
using namespace std;
typedef long long ll;

int N, M;
char str[] = "                ";
int arr[9] = {0,};
void dfs(int num, int dept){
    if(dept == M){
        str[dept*2]='\0';
        cout << str <<"\n";
        return;
    }
    for(int i=1;i<=N;i++){
        if(!arr[i]){
            arr[i]=1;
            str[dept*2]=i+'0';
            str[dept*2+1]=' ';
            dfs(i,dept+1);
            arr[i]=0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        arr[i]=1;
        str[0]=i+'0';
        str[1]=' ';
        dfs(i,1);
        arr[i]=0;
    }
}