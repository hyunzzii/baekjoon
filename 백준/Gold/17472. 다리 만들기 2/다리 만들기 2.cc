#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct node{
    int a,b;
    long long value;
}node;
bool compare(node a, node b){
    return a.value < b.value;
}

int N,M,arr[10][10] = {0,};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<node> nrr;
int root[8] = {0,};

void dfs(int x, int y, int num){
    arr[x][y] = num;
    int tx,ty;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            tx = x + dx[i];
            ty = y + dy[i];
            if(tx>=0 && tx<N && ty>=0 && ty<M && arr[tx][ty] == 1){
                dfs(tx,ty,num);
            }
        }
    }
}
int find(int n){
    if(root[n] == n) return n;
    else return root[n] = find(root[n]);
}

int main(void){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=2;i<8;i++){
        root[i] = i;
    }
    int t=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j] == 1){
                dfs(i,j,++t);
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j] == 0) continue;
            for(int k=k+1;k<N;k++){
                if(arr[k][j] > 0){
                    if(k-i-1 >= 2) nrr.push_back({arr[i][j], arr[k][j], k-i-1});
                    break;
                }
            }
            for(int k=i-1;k>=0;k--){
                if(arr[k][j] > 0){
                    if(i-k-1 >= 2) nrr.push_back({arr[i][j], arr[k][j], i-k-1});
                    break;
                }
            }
            for(int k=j+1;k<M;k++){
                if(arr[i][k] > 0){
                    if(k-j-1 >= 2) nrr.push_back({arr[i][j], arr[i][k], k-j-1});
                    break;
                }
            }
            for(int k=j-1;k>=0;k--){
                if(arr[i][k] > 0){
                    if(j-k-1 >= 2)  nrr.push_back({arr[i][j], arr[i][k], j-k-1});
                    break;
                }
            }
        }
    }
    sort(nrr.begin(),nrr.end(),compare);
    int ta, tb, ans=0;
    for(int i=0;i<nrr.size();i++){
        ta = find(nrr[i].a);
        tb = find(nrr[i].b);
        if(ta < tb) root[tb] = ta;
        else if(ta > tb) root[ta] = tb;
        if(ta == tb) continue;
        ans += nrr[i].value;
    }
    for(int i=3;i<=t;i++){
        if(find(root[i]) != find(2)){
            printf("-1");
            return 0;
        }
    }
    printf("%d",ans);
}