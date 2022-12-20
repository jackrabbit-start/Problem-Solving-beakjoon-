#include <bits/stdc++.h>
using namespace std;

string s;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> s;
    sort(s.rbegin(),s.rend()); // 내림차순
    cout << s;
    return 0;
} // 3분 30초