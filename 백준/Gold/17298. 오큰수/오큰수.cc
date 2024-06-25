#include <iostream>

using namespace std;
typedef pair<int,int> node;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tem, top=0, result[1000001]={0,};
    
    cin >> n;
    node* stack = new node[n];

    for(int i=0;i<n;i++){
        cin >> tem;
        while(top && stack[top].first < tem){
            result[stack[top--].second] = tem;
        }
        stack[++top] = make_pair(tem,i);
    }
    for(int i=0;i<n;i++){
        cout << (result[i] ? result[i] : -1) << ' ';
    }
}