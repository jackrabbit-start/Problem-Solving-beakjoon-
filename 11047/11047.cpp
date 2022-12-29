#include <bits/stdc++.h>
using namespace std;
int N , K;
vector<int> v;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> K;
    for(int i= 0 ; i < N ; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    int i = v.size()-1;
    int ans = 0;
    while(K > 0){
        if(v[i] <= K){
            ans += K/v[i];
            K = K%v[i];    
        }
        i--;
    }
    cout << ans;
    return 0;
}