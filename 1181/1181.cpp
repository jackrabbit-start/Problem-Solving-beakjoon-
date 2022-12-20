#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> v;
int N;

bool compare(string a, string b){
    if(a.length() < b.length()){
        return 1;
    }
    else if(a.length() == b.length()){
        return a<b;
    }
    else{
        return 0;
    }
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> s;
        auto iter = find(v.begin() , v.end() , s);
        if(iter == v.end()){v.push_back(s);}
    }
    sort(v.begin(),v.end(),compare);
    for(int i= 0 ; i < v.size(); i++){
        cout << v[i] << "\n";
    }
    return 0;
}