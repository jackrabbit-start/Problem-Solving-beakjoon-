#include <bits/stdc++.h>
using namespace std;

int N;
int M;
vector<string> v;
unordered_map<string, int> pokemon;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        string s;
        cin >> s;
        pokemon.insert(make_pair(s,i));
        v.push_back(s);
    }
    for(int i = 0 ; i < M; i++){
        string s;
        cin >> s;
        int tmp = atoi(s.c_str());
        if(tmp == 0){
            auto iter = pokemon.find(s);
            cout << iter->second+1 << "\n";
        }
        else{
            cout << v[tmp-1] << "\n";
        }
    }
    

    return 0;
}