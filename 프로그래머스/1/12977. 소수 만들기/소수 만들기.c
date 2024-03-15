#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0;
    int min[100000] = {0,};
    int i,j,num = 0,tem=0;
    for(i=2;i<50000;i++){
        for(j=0;j<num;j++){
            if(i%min[j]==0)break;
        }
        if(j==num){
            min[num++]=i;
        }
    }
    for(i=0;i<num;i++){
        int mod[1000]={0,};
        for(j=0;j<nums_len;j++){
            if((nums[j]/min[i])<1) mod[nums[j]]=1;
        }
        for(int m=1;m<min[i];m++){
            if(mod[m]!=1)continue;
            for(int n=m+1;n+m<min[i];n++){
                if(mod[n]!=1)continue;
                tem = min[i]-m-n;
                if(tem<=n)break;
                if(mod[tem]==1){
                    printf("%d %d %d\n",m,n,tem);
                    answer+=1;
                }
            }
        }
    }
    return answer;
}