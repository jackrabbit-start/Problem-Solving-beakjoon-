#include <bits/stdc++.h>
using namespace std;
int T;
string s;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> s;
        int checking = 0;
        for(int i = 0 ; i < s.length()/2; i++){
            if(checking == 2)break; 
            if(s[i+checking] != s[s.length()-i-1]){
                checking++;
                i--;
                continue;
            }
        }
        int checking2 = 0;
        for(int i = s.length() ; i > s.length()/2; i--){
            if(checking2 == 2)break; 
            if(s[i-1-checking2] != s[s.length()-i]){
                checking2++;
                i++;
                continue;
            }
        }
        checking = min(checking, checking2);
        if(checking == 0) cout << "0\n";
        else if(checking == 1) cout << "1\n";
        else cout <<"2\n";
    }
    

    return 0;
}