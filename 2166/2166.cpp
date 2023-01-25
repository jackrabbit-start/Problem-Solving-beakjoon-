#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N;
vector<pair<ll, ll>> v;
ll x,y;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(ll i = 0 ; i < N ; i++){
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    v.push_back(make_pair(v[0].first,v[0].second));
    ll ans = 0;
    ll ans2 =0;
    for(ll i = 0 ; i < N ; i++){
        ans += v[i].first * v[i+1].second;
        ans2 += v[i].second* v[i+1].first;
    }
    double real_answer = abs(ans-ans2);
    real_answer/=2;
    cout << fixed;
    cout.precision(1);
    cout << real_answer;
    return 0;
}