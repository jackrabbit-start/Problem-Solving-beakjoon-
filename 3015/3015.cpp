#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N;
ll arr[500010];
deque<pair<ll, ll>> dq;
ll answer = 0;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(ll i = 1; i <= N ; i++){
        cin >> arr[i];
    }
    dq.push_back(make_pair(arr[1],1));
    ll ans = 0;
    for(ll i = 2; i <= N ; i++){
            ans = 0;
            while(!dq.empty() && arr[i] > dq.back().first){
                ans+= dq.back().second;
                dq.pop_back();
            }
            if(!dq.empty()&&arr[i] == dq.back().first){
                ans += dq.back().second;
                dq.back().second++;
                if(dq.size() != 1) ans++;
            }
            else{
                if(!dq.empty()) ans++;
                dq.push_back(make_pair(arr[i], 1));
            }
        answer += ans;
    }
    cout << answer;
    return 0;
}