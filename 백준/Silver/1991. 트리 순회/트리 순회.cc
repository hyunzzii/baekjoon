#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<vector<int>> tree;

void preorder(int root){
    printf("%c",root+64);
    for(int i=0;i<2;i++){
        if(tree[root][i]){
            preorder(tree[root][i]);
        }
    }
}

void inorder(int root){
    for(int i=0;i<2;i++){
        if(tree[root][i]){
            inorder(tree[root][i]);
        }
        if(!i){
            printf("%c",root+64);
        }
    }
}

void postorder(int root){
    for(int i=0;i<2;i++){
        if(tree[root][i]){
            postorder(tree[root][i]);
        }
    }
    printf("%c",root+64);
}

int main(void){
    scanf("%d",&n);
    tree.resize(n+1);

    char a,b,c;
    for(int i=0;i<n;i++){
        scanf(" %c %c %c",&a,&b,&c);
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
    printf("\n");
    inorder(1);
    printf("\n");
    postorder(1);
} 