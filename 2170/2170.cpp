#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int N;
vector<pair<ll, ll>> v;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        ll x, y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    ll answer = 0;
    sort(v.begin(), v.end());
    ll now = v[0].first;
    for(int i = 0 ; i < N ; i++){
        ll st = v[i].first;
        ll ed = v[i].second;
        if(now >= ed){
            continue;
        }
        else if(now >= st){
            answer += ed-now;
            now = ed;
        }
        else{
            answer += ed-st;
            now = ed;
        }
    }
    cout << answer;
    return 0;
}