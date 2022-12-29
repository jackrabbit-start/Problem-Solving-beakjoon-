#include <bits/stdc++.h>
using namespace std;
int a;
string s;
vector<int> number;
vector<int> operat;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> s;
    int ans = 0;
    int k = 0;
    string q;
    for(int i = 0 ; i < s.length(); i++){
        if(s[i] == '-'){
            q = s.substr(k,i-k);
            number.push_back(atoi(q.c_str()));
            operat.push_back(-1);
            k = i+1;
        }
        else if(s[i] == '+'){
            q = s.substr(k,i-k);
            number.push_back(atoi(q.c_str()));
            operat.push_back(1);
            k = i+1;
        }
    }
    q = s.substr(k,s.length()-k);
    number.push_back(atoi(q.c_str()));
    int checking = 0;
    int minus_n = 0;
    for(int i = 0 ; i < operat.size(); i++){
        if(checking == 1 && operat[i] == 1){
            minus_n += number[i];
        }
        else if(checking == 0 && operat[i] == 1){
            ans+= number[i];
        }
        else{
            if(checking == 1) ans -= number[i];
            else ans += number[i];
            ans -= minus_n;
            checking = 1;
            minus_n =0;
        }
        //cout << "(" << ans << " " << minus_n << " "<<  i << " " << checking<<"))";
    }
    if(checking == 1) ans -= number[number.size()-1];
    else ans += number[number.size()-1];
    ans -= minus_n;
    cout << ans;

    return 0;
}
