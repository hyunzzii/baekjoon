#include <cstdio>
using namespace std;

int n;
int tree[27][2] = {0,};

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

    char a,b,c;
    for(int i=0;i<n;i++){
        scanf(" %c %c %c",&a,&b,&c);
        if(b > 64){
            tree[a-64][0] = b-64;
        }
        if(c > 64){
            tree[a-64][1] = c-64;
        }
    }
    preorder(1);
    printf("\n");
    inorder(1);
    printf("\n");
    postorder(1);
} 