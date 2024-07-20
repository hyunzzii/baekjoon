#include <stdio.h>
#include <queue>
using namespace std;

int main(void){
    int N;
    scanf("%d",&N);

    queue<int> que;
    for(int i=0;i<N;i++){
        que.push(i+1);
    }
    while(que.size()>1){
        que.pop();
        que.push(que.front());
        que.pop();
    }
    printf("%d",que.front());
}