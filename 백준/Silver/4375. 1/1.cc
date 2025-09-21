#include <cstdio>

int main(void){
    int n, ans, mod;
    while(scanf("%d",&n) != EOF){
        ans=1, mod=1;
        while(mod < n){
            mod = mod * 10 + 1;
            ans++;
        }
        while((mod = mod % n) != 0){
            mod = mod * 10 + 1;
            ans++;
        };
        printf("%d\n",ans);
    }
}