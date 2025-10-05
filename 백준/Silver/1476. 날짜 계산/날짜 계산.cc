#include <cstdio>
int main(void){
    int e,s,m;
    scanf("%d %d %d",&e,&s,&m);
    int year = s;
    e = e % 15;
    m = m % 19;
    while(true){
        if(year % 15 == e && year % 19 == m) break;
        year += 28;
    }
    printf("%d",year);
}