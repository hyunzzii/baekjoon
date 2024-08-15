#include <cstdio>
using namespace std;

int main(void){
    int num=0,sum=0;
    char s,before;
    while((s=getchar())!='\n'){
        if(s=='('){
            num++;
            before=s;
            continue;
        }
        if(before=='('){
            sum += --num;
            before=s;
            continue;
        }
        before=s;
        num--;
        sum++;
    }
    printf("%d",sum);
}