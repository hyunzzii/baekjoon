#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, M, N, x, y, tmp;
    cin >> T;
    while(T--){
        cin >> M >> N >> x >> y;
        if(x > y){
            swap(&x,&y);
            swap(&M,&N);
        }
        int ans=1, a=1, b=1;
        do{
            if(a==x && b==y){
                break;
            }else if(b-a == y-x){
                a++;b++;
                ans++;
            }else{
                b = (b+M)%N;
                ans += M;
            }
        }while(!(a==1 && b==1));
        if(a==x&&b==y){
            cout << ans << "\n";
        }else{
            cout << -1 <<"\n";
        }
    }
}