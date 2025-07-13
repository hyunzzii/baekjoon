#include <cstdio>
int main(void){
    int n,tmp, ans=0;
    scanf("%d",&n);
    bool notPrime[1001] = {false};
    notPrime[1] = true;
    for(int i=2;i<=1000;i++){
        for(int j=2;i*j<=1000;j++){
            notPrime[i*j]=true;
        }
    }
    while(n--){
        scanf("%d",&tmp);
        if(!notPrime[tmp]) ans++;
    }
    printf("%d",ans);
}