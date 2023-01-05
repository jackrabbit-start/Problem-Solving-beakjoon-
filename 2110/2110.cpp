#include <bits/stdc++.h>
using namespace std;
#define INT_MAXING 1000000001
typedef long long int ll;
ll N;
ll C;
vector<ll> v;
ll answer;

ll BS(ll left, ll right, ll n){
    if(left > right) return 0;
    ll mid = (left+right)/2;
    ll now = v[0];
    ll cnt = 1;
    ll lenght = 0;
    for(ll i = 0 ; i < v.size(); i++){
        if(v[i] - now >= mid){
            lenght = max(v[i]-now, lenght);
            cnt++;
            now = v[i];
        } 
    }
    if(cnt >= n){
        answer = max(mid, answer);
        BS(mid+1, right, n);
    }
    else{
        BS(left, mid-1, n);
    }
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> C;
    ll input;
    for(ll i = 0 ; i < N ; i++){
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    BS(0,INT_MAXING, C);
    cout << answer;

    return 0;
}