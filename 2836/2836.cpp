#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N , M;
vector<pair<ll, ll>> v;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        ll a, b;
        cin >> a >> b;
        if(a > b) v.push_back({a,b});
    }
    ll answer = 0;
    sort(v.rbegin(), v.rend());
    ll pos = v[0].first;
    for(ll i = 0 ; i < v.size(); i++){
        //cout << "(" << v[i].first << " " << v[i].second << " " << pos << ")";
        if(v[i].first < pos){
            answer += v[i].first - v[i].second;
            pos = v[i].second;
        }
        else if(v[i].second > pos){
            continue;
        }
        else{
            answer += pos - v[i].second;
            pos = v[i].second;
        }
    }
    answer *= 2;
    cout << answer + M;
    return 0;
}