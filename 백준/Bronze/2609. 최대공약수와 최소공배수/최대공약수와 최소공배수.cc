#include <cstdio>
int main(void){
    int a,b;
    scanf("%d %d",&a,&b);

    int min = a < b ? a : b, ans = 1;
    for(;min>1;min--){
        if(a%min==0 && b%min==0){
            a = a/min;
            b = b/min;
            ans *= min;
        }
    }
    printf("%d\n%d",ans,ans*a*b);
}