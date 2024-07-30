#include <cstdio>
#include <queue>
using namespace std;
typedef struct node{
	int x;
	int y;
	int c;
}node;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n, m, arr[1000][1000], ans[1000][1000];
queue<node> que;

void bfs(){
	while(!que.empty()){
		node s = que.front();
		int x = s.x;
		int y = s.y;
		int c = s.c;
		ans[x][y] = c;
		que.pop();

		for(int i=0; i<4; i++){
			int x1 = x + dx[i];
			int y1 = y + dy[i];
			if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)continue;
			if(arr[x1][y1]==1){
				que.push((node){x1, y1, c+1});
				arr[x1][y1]=3;
				continue;
			}
			if(arr[x1][y1]==0){
				ans[x1][y1] = 0;
			}
		}
	}
}

int main(int argc, char const *argv[]){
	int tem;
	scanf("%d %d", &n, &m);
	
	for(int x=0; x<n; x++){
		for(int y=0; y<m; y++){
			scanf("%d", &tem);
			if(tem == 2){
				que.push((node){x,y,0});
				arr[x][y]=3;
			}
			arr[x][y] = tem;
			ans[x][y] = tem ? -1 : 0;
		}
	}
	bfs();

	for(int x=0; x<n; x++){
		for(int y=0; y<m; y++){
			printf("%d ",ans[x][y]);
		}
		printf("\n");
	}
}