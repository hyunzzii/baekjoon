#include <cstdio>
#include <queue>
using namespace std;

int main(void){
    priority_queue<char> pq;
    char c;
    while(((c=getchar()))!='\n'){
        pq.push(c);
    }
    while(!pq.empty()){
        printf("%c",pq.top());
        pq.pop();
    }
}