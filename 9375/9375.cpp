#include <bits/stdc++.h>
using namespace std;
int T;
int N;
map<string, int> v;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        string a, b;
        v.clear();
        for(int i = 0 ; i < N; i++){
            cin >> a >> b;
            if(auto iter = v.find(b) != v.end()){
                v[b]++;
            }
            else v.insert(make_pair(b,1));
        }
        int ans =1;
        for(auto iter = v.begin(); iter != v.end(); ++iter){
            int tmp = iter->second;
            tmp++;
            ans*=tmp;
        }
        cout << ans-1 <<"\n";
    }

    return 0;
}