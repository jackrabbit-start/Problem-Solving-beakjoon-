#include <bits/stdc++.h>
using namespace std;

int N;
vector<tuple<int, int, string>> v;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i= 0 ;i < N ; i++){
        int a;
        string s;
        cin >> a >> s;
        v.push_back(make_tuple(a,i,s));
    }
    sort(v.begin(),v.end());
    for(int i = 0 ;i < N ; i++){
        cout << get<0>(v[i]) << " " << get<2>(v[i]) << "\n";
    }

    return 0;
}