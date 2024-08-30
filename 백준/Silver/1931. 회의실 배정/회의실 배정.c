#include <stdio.h>
#define min(a,b) ((a)<(b))?(a):(b)

typedef struct node{
    float start;
    int end;
}node;

int* heap(node * nodeArr, int N);

int main(int argc, const char * argv[]) {
    int N;
    scanf("%d",&N);
    node *nodeArr = malloc(sizeof(node)*(N+1));
    int* mrr = malloc(sizeof(int)*N);
    
    int pnt,child,temp,m=0;
    
    for(int i=1;i<N+1;i++){
        scanf("%f %d",&nodeArr[i].start,&nodeArr[i].end);
        if((int)nodeArr[i].start==nodeArr[i].end) continue;
        nodeArr[i].start += 0.5;
    }
    int* srr = heap(nodeArr,N);

    for(int i=N;i>0;i--){
        temp = srr[i];
        srr[i] = srr[1];
        srr[1] = temp;
        pnt = 1;
        child = pnt*2;
        while(child <= i-1){
            child = nodeArr[srr[child]].start >= nodeArr[srr[min(child+1,i-1)]].start ? child : child+1;
            if(nodeArr[srr[child]].start < nodeArr[srr[pnt]].start) break;
            temp = srr[child];
            srr[child]=srr[pnt];
            srr[pnt]=temp;
            pnt = child;
            child = pnt*2;
        }
    }
    mrr[m]=0;
    mrr[++m] = nodeArr[srr[1]].end;
    for(int i=2;i<N+1;i++){
        if(mrr[m] <= (int)nodeArr[srr[i]].start){
            mrr[++m] = nodeArr[srr[i]].end;
            continue;
        }
        if(mrr[m-1] <= (int)nodeArr[srr[i]].start){
            mrr[m] = nodeArr[srr[i]].end < mrr[m] ? nodeArr[srr[i]].end : mrr[m];
        }
    }
    printf("%d",m);
}
int* heap(node* nodeArr, int N){
    int* srr = malloc(sizeof(int)*(N+1));
    int pnt,parent,temp;
    
    for(int i=1;i<N+1;i++){
        srr[i]=i;
        pnt=i;
        while(pnt>1){
            parent=pnt/2;
            if(nodeArr[srr[parent]].start > nodeArr[srr[pnt]].start) break;
            temp = srr[parent];
            srr[parent]=srr[pnt];
            srr[pnt]=temp;
            pnt = parent;
        }
    }
    return srr;
}