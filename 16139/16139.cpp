#include <bits/stdc++.h>
using namespace std;
string s;
int Q;
int DP[30][200005];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> s;
    for(int i = 0 ; i < s.length(); i++){
        DP[s[i]-'a'][i+1]++;
        for(int j = 0; j < 26; j++){
            DP[j][i+1] += DP[j][i];
        }
    }
    cin >> Q;
    char a;
    int starting, finishing;
    for(int i = 0 ; i < Q; i++){
        cin >> a >> starting >> finishing;
        cout << DP[a-'a'][finishing+1]-DP[a-'a'][starting] << "\n";
    }
    

    return 0;
}