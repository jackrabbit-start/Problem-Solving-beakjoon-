#include <bits/stdc++.h>
using namespace std;
string s;
int T;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> s;
        cout << s[0] << s[s.size()-1] << "\n";
    }
    return 0;
}