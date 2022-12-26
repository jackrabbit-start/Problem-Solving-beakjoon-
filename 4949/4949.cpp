#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> small;
vector<int> big;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    while(1){
        s.clear();
        int ans = 1;
        getline(cin,s);
        if(s[0] == '.'){
            break;
        }
        small.clear();
        big.clear();
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] == '('){
                small.push_back(i);
            }
            else if(s[i] == '['){
                big.push_back(i);
            }
            else if(s[i] == ')'){
                if(small.size() == 0) {ans = 0; break;}
                int tmp = small.back();
                small.pop_back();
                if(big.size()!=0 && big.back() > tmp) ans = 0;
            }
            else if(s[i] == ']'){
                if(big.size() == 0) {ans = 0; break;}
                int tmp = big.back();
                big.pop_back();
                if(small.size()!=0&&small.back() > tmp) ans = 0;
            }
        }
        if(big.size() == 0 && small.size() == 0 && ans == 1){
            cout <<"yes\n";
        }
        else cout << "no\n";

    }

    return 0;
}