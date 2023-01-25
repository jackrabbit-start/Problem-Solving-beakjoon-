#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N;
ll arr[3005];
ll ans[3005];
vector<pair<ll , ll>> start;
vector<pair<ll , ll>> endpoll;
ll FIND(ll x){
    if(arr[x] == x) return x;
    return arr[x] = FIND(arr[x]);
}
void UNION(ll a, ll b){
    ll aa = FIND(a);
    ll bb = FIND(b);
    if(aa != bb){
        arr[bb] = aa;
    }
    return;
}
ll crossproduct(pair<ll ,ll> A, pair<ll ,ll> B , pair<ll, ll> C){
    ll tmp = (B.first - A.first) *(C.second - A.second) - (C.first - A.first) * (B.second - A.second);
    if(tmp > 0) return 1;
    else if (tmp < 0) return -1;
    else return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(ll i = 1 ; i <= N ; i++){
        arr[i] = i;
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        start.push_back({a,b});
        endpoll.push_back({c,d});
    }
    for(ll i = 1; i <= N ; i++){
        for(ll j = 1; j <= N ; j++){
            if(FIND(i) == FIND(j)) continue;
            else{
                pair<ll ,ll > A1 = {start[i-1].first ,start[i-1].second};
                pair<ll ,ll > A2 = {endpoll[i-1].first ,endpoll[i-1].second};
                pair<ll ,ll > B1 = {start[j-1].first ,start[j-1].second};
                pair<ll ,ll > B2 = {endpoll[j-1].first ,endpoll[j-1].second};
                ll result1 = crossproduct(A1, A2, B1);
                ll result2 = crossproduct(A1, A2, B2);
                ll result3 = crossproduct(B1, B2, A1);
                ll result4 = crossproduct(B1, B2, A2);
                if((result1 * result2 == 0) && (result3 * result4 == 0)){
                    if(A1 > A2) swap(A1, A2);
                    if(B1 > B2) swap(B1, B2);
                    if(B1 <= A2 && A1 <= B2) UNION(i,j);
                }
                else if((result1 * result2 <= 0) && (result3*result4 <= 0)){
                    UNION(i,j);
                }
            }
        }
    }
    ll answer = 0;
    for(ll i = 1; i <= N ; i++){
        FIND(i);
        ans[arr[i]]++;
    }
    ll numbers = 0;
    for(ll i = 1; i <= N ; i++){
        if(ans[i] > 0) numbers++;
        answer = max(answer , ans[i]);
    }
    cout << numbers << "\n" << answer;
    return 0;
}