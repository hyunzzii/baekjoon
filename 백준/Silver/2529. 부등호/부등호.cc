#include <iostream>
using namespace std;

int k, arr[10]={0,}, brr[10]={0,}, flag=0;
char sign[10] = "         ";
char str[10]="         ";

void func_max(int idx, int before){
    str[idx]=before+'0';
    if(idx == k){
        str[k+1] = '\0';
        cout <<str<< "\n";
        flag=1;
    }
    for(int i=9; i>=0 && !flag; i--){
        if(!arr[i]){
            if(sign[idx] == '>' && before > i){
                arr[i] = 1;
                func_max(idx+1, i);
                arr[i] = 0;
            }else if(sign[idx] == '<' && before < i){
                arr[i] = 1;
                func_max(idx+1, i);
                arr[i] = 0;
            }
        }
    }
}

void func_min(int idx, int before){
    str[idx]=before+'0';
    if(idx == k){
        str[k+1] = '\0';
        cout <<str<< "\n";
        flag=1;
    }
    for(int i=0; i<=9 && !flag; i++){
        if(!brr[i]){
            if(sign[idx] == '>' && before > i){
                brr[i] = 1;
                func_min(idx+1, i);
                brr[i] = 0;
            }else if(sign[idx] == '<' && before < i){
                brr[i] = 1;
                func_min(idx+1, i);
                brr[i] = 0;
            }
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    for(int i=0;i<k;i++){
        cin >> sign[i];
    }
    for(int i=9; i>=0 && !flag; i--){
        arr[i] = 1;
        func_max(0,i);
        arr[i] = 0;
    }
    flag=0;
    for(int i=0; i<=9 && !flag; i++){
        brr[i] = 1;
        func_min(0,i);
        brr[i] = 0;
    }
}