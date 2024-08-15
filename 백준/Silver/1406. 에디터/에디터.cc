#include <iostream>
#include <list>
using namespace std;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    list<char> lst;
    char c;

    while((c=cin.get())!='\n'){
        lst.push_back(c);
    }

    list<char>::iterator cursor = lst.end(),tem;
    string str;
    int t;

    cin >> t;
    cin.ignore();
    while(t--){
        getline(cin,str);
        if(str.at(0)=='L'){
            if(cursor != lst.begin()) cursor--;
            continue;
        }
        if(str.at(0)=='D'){
            if(cursor != lst.end()) cursor++;
            continue;
        }
        if(str.at(0)=='B'){
            if(cursor == lst.begin()) continue;
            cursor = lst.erase(--cursor);
            continue;
        }
        if(str.at(0)=='P'){
            lst.insert(cursor,str[2]);
        }
    }
    for(char c : lst){
        cout << c;
    }
}