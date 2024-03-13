#include <iostream>

int main(void){
    int N;
    int arr[2001] = {0,};

    std::cin >> N;
    while(N--){
        int tem;
        std::cin >> tem;
        arr[1000 + tem] = 1;
    }

    int num = 0;
    for(int i = 0; i < 2001; i++){
        if(arr[i] == 1){
            std::cout << i-1000 << std::endl;
            num++;
            if(num == N) return 0;
        }
    }
}