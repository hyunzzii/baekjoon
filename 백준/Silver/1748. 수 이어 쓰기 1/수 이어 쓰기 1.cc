#include <cstdio>
int main(void){
    int n;
    scanf("%d",&n);
    int ans = 0;
    for(int i=1;i<=n;i*=10){
        ans += n - i + 1;
    }
    printf("%d",ans);
}