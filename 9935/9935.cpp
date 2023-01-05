#include <bits/stdc++.h>
using namespace std;

string s;
string bomb;
vector<char> v;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> s;
    cin >> bomb;
    int checking = 0;
    for(int i = 0 ; i < s.length(); i++){
        v.push_back(s[i]);
        if(bomb[bomb.length()-1] == s[i] && v.size() >= bomb.length()){
            checking = 0;
            for(int j = 0; j< bomb.length() ; j++){
                if(bomb[bomb.length()-j-1] != v[v.size()-1-j]){
                    checking = 1;
                }
            }
            if(checking == 0) {
                for(int j = 0 ; j < bomb.length(); j++){
                    v.pop_back();
                }
            }
        }
    }
    if(v.size() == 0) cout << "FRULA";
    else{
    for(int i = 0 ; i < v.size(); i++){
        cout << v[i];
    }
    }
    return 0;
}