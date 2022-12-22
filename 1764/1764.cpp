#include <bits/stdc++.h>
using namespace std;

int N;
int M;
unordered_set<string> human;
set<string> ans;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;

    for(int i = 0 ; i < N ; i++){
        string s;
        cin >> s;
        human.insert(s);
    }
    for(int i = 0 ; i < M ; i++){
        string s;
        cin >> s;
        auto iter = human.find(s);
        if(iter != human.end()){
            ans.insert(s);
        }
    }
    cout << ans.size() << "\n";
    for(auto iter = ans.begin() ; iter != ans.end(); iter++){
        cout << *iter << "\n";
    }


    return 0;
}