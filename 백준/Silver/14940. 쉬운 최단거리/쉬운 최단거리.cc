#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> node;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n, m, arr[1000][1000], ans[1000][1000];
queue<node> que;

int main(int argc, char const *argv[]){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> n >> m;
	
	for(int x=0; x<n; x++){
		for(int y=0; y<m; y++){
			cin >> arr[x][y];
			ans[x][y] = arr[x][y] ? -1 : 0;
			if(arr[x][y] == 2){
				que.push(make_pair(x,y));
				ans[x][y]=0;
				arr[x][y]=3;
			}
		}
	}
	
	while(!que.empty()){
		node s = que.front();
		int x = s.first;
		int y = s.second;
		que.pop();

		for(int i=0; i<4; i++){
			int x1 = x + dx[i];
			int y1 = y + dy[i];

			if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)continue;
			if(arr[x1][y1]==1){
				que.push(make_pair(x1,y1));
				ans[x1][y1]=ans[x][y] + 1;
				arr[x1][y1]=3;
				continue;
			}
		}
	}

	for(int x=0; x<n; x++){
		for(int y=0; y<m; y++){
			cout << ans[x][y] << ' ';
		}
		cout << '\n';
	}
}