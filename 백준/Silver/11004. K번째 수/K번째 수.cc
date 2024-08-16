#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int k,n;
void swap(int num1,int num2){
    int tem = v[num1];
    v[num1] = v[num2];
    v[num2] = tem;
}

int quickSort(int start, int end){
    int pivot = (start+end)/2;
    swap(start,pivot);
    pivot = start++;

    while(start<end){
        if(v[start] < v[pivot]){
            start++;
        }
        else if(v[end] > v[pivot]){
            end--;
        }
        else{
            swap(start,end);
            start++;end--;
        }
    }
    if(v[pivot] > v[start]){
        swap(start,pivot);
        return start;
    }
    else{
        swap(--start,pivot);
        return start;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tem;
    cin >> n >> k;

    for(int i=0;i<n;i++){
        cin >> tem;
        v.emplace_back(tem);
    }
    int s=0, e=n-1,r=k--;
    do{
        r = quickSort(s,e);
        if(k<r){
            e = r-1;
        }
        else{
            s = r+1;
        }
    }while(r!=k && s!=e);
    cout << v[k];
} 