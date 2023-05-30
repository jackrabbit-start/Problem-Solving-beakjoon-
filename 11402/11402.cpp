#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll N, K, M;
ll cache[3000][3000];

ll binomal_cal(ll n,ll k){
    if(cache[n][k] != -1) return cache[n][k];
    if(k == 0 || k == n) return cache[n][k] = 1;
    return cache[n][k] = (binomal_cal(n-1,k-1) + binomal_cal(n-1,k))%M;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    memset(cache, -1, sizeof(cache));
    cin >> N >> K >> M;
    vector<ll> a;
    vector<ll> b;
    while(N){
        a.push_back(N%M);
        N/=M;
    }
    while(K){
        b.push_back(K%M);
        K/=M;
    }
    while(a.size() != b.size()){
        b.push_back(0);
    }
    ll answer = 1;
    for(ll i = 0; i < a.size(); i++){
        if(a[i] < b[i]) {answer =0; break;}
        answer *= binomal_cal(a[i], b[i]);
        answer %= M;
    }
    cout << answer << "\n";
    return 0;
    
}