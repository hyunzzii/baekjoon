#include <cstdio>
using namespace std;

int main(void){
    int N, arr[1001] = {0,};
    int first[1001] = {0,}, second[1001] = {0,};

    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=N;i++){
        for(int j=i-1; j>0; j--){
            if(arr[j] < arr[i] && first[i] < first[j]){
                first[i] = first[j];
            }
        }
        first[i]++;
    }
    for(int i=N;i>0;i--){
        for(int j=i+1; j<=N; j++){
            if(arr[j] < arr[i] && second[i] < second[j]){
                second[i] = second[j];
            }
        }
        second[i]++;
    }

    int ans = 0;
    for(int i=1;i<=N;i++){
        if(first[i] + second[i] > ans){
            ans = first[i] + second[i];
        }
    }
    printf("%d",ans-1);
}