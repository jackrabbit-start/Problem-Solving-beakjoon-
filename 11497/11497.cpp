#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll T;
ll N;
vector<ll> v;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        v.clear();
        for(ll i = 0 ; i < N ; i++){
            ll input;
            cin >>input;
            v.push_back(input);
        }
        sort(v.rbegin(), v.rend());
        ll t =0;
        deque<ll> q;
        for(ll i = 0 ; i < N ; i++){
            if(i%2 == 0) q.push_back(v[i]);
            else q.push_front(v[i]);
        }
        for(ll i = 0 ; i < N ; i++){
            ll nxt = (i+1)%N;
            t = max(t, abs(q[nxt] - q[i]));
        }
        cout << t << "\n";
    }
    return 0;
}