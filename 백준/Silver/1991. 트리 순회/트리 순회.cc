#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> tree;

void preorder(int root){
    char c = root + 64;
    cout << c;
    for(int i=0;i<2;i++){
        if(tree[root][i]){
            preorder(tree[root][i]);
        }
    }
}

void inorder(int root){
    char c = root + 64;
    for(int i=0;i<2;i++){
        if(tree[root][i]){
            inorder(tree[root][i]);
        }
        if(!i){
            cout << c;
        }
    }
}

void postorder(int root){
    char c = root + 64;
    for(int i=0;i<2;i++){
        if(tree[root][i]){
            postorder(tree[root][i]);
        }
    }
    cout << c;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    tree.resize(n+1);

    char a,b,c;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        if(b > 64){
            tree[a-64].push_back(b-64);
        }else{
            tree[a-64].push_back(0);
        }
        if(c > 64){
            tree[a-64].push_back(c-64);
        }else{
            tree[a-64].push_back(0);
        }
    }
    preorder(1);
    cout<<"\n";
    inorder(1);
    cout<<"\n";
    postorder(1);
} 