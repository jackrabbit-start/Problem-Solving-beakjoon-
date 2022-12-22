#include <bits/stdc++.h>
using namespace std;

unordered_set<string> ans;
string s;
string tmp;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> s;
    for(int i = 0 ; i < s.length(); i++){
        for(int j = 0; j<=s.length()-i;j++){
            tmp = s.substr(i,j);
            ans.insert(tmp);
        }
    }
    cout << ans.size()-1;

    return 0;
}