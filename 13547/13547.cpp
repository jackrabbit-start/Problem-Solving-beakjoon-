#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N;
ll k;
ll arr[100010];
ll checking[1000010];
ll nums[1000010];
ll howm[1000010];
ll Q;
vector<tuple<ll, ll , ll>> Qeury;
ll answer[100010];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> Q;
    for(ll i = 1; i <= N ; i++){
        cin >> arr[i];
    }
    k =sqrt(N);
    for(ll i = 1; i <= Q ; i++){
        ll a, b;
        cin >> a >> b;
        Qeury.push_back({a,b, i});
    }
    sort(Qeury.begin(), Qeury.end(), [](tuple<ll,ll,ll> &a, tuple<ll, ll, ll>&b) {
        if(get<0>(a)/k == get<0>(b)/k) return get<1>(a) < get<1>(b);
        return get<0>(a)/k < get<0>(b)/k;
    });
    priority_queue<pair<ll, ll>> pq;
    ll res = 0;
    ll l = 0;
    ll r = 0;
    for(ll i = 0; i < Q; i++){
        while(l < get<0>(Qeury[i])){
            checking[arr[l]]--;
            res += ((checking[arr[l]]*checking[arr[l]]) - ((checking[arr[l]]+1)*(checking[arr[l]]+1))) * arr[l];
            l++;
        }
        while(l > get<0>(Qeury[i])){
            l--;
            checking[arr[l]]++;
            res += ((checking[arr[l]]*checking[arr[l]]) - ((checking[arr[l]]-1)*(checking[arr[l]]-1))) * arr[l];
        }
        while(r < get<1>(Qeury[i])){
            r++;
            checking[arr[r]]++;
            res += ((checking[arr[r]]*checking[arr[r]]) - ((checking[arr[r]]-1)*(checking[arr[r]]-1))) * arr[r];
        }
        while(r > get<1>(Qeury[i])){
            checking[arr[r]]--;
            res += ((checking[arr[r]]*checking[arr[r]]) - ((checking[arr[r]]+1)*(checking[arr[r]]+1))) * arr[r];
            r--;
        }
        answer[get<2>(Qeury[i])] = res;
    }
    for(ll i = 1; i <= Q; i++){
        cout << answer[i] << "\n";
    }

    return 0;
}