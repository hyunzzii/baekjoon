#include <cstdio>
using namespace std;

int main(void){
    unsigned a,b,c;
    scanf("%u %u %u",&a,&b,&c);
    
    unsigned m = a % c;
    unsigned long r=1, r1;
    while(b>1){
        unsigned i = 1;
        r1 = m;
        while(i*2 < b){
            i = i*2;
            r1 = (r1*r1)%c;
        }
        b -= i;
        r = (r1*r)%c;
    }
    if(b == 1){
        r = (r*a)%c;
    }
    printf("%lu",r);
} 