#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N , M;
ll depth[100010];
vector<pair<ll ,ll>> graph[100010];
ll dp[100010][50];
ll dpweight[100010][50];
ll maxnum;

ll dfs(ll now, ll weight , ll parent){
    depth[now] = depth[parent]+1;
    dp[now][0] = parent;
    dpweight[now][0] = weight;
    for(ll i = 1; i <= maxnum ;i++){
        ll tmp = dp[now][i-1];
        dp[now][i] = dp[tmp][i-1];
        dpweight[now][i] = dpweight[now][i-1] + dpweight[tmp][i-1];
    }
    for(ll i = 0 ; i < graph[now].size(); i++){
        ll nxt = graph[now][i].first;
        ll nw = graph[now][i].second;
        if(depth[nxt] == -1){
            dfs(nxt, nw, now);
        }
    }
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    memset(depth, -1, sizeof(depth));
    for(ll i = 1; i < N ; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    maxnum = (ll)floor(log2(N));
    depth[0] = 0;
    dfs(1, 0 , 0);
    cin >> M;
    while(M--){
        ll a, b, k;
        ll ans = 0;
        ll input;
        ll commontop;
        cin >> input;
        cin >> a >> b;
        ll aa = a;
        ll bb = b;

        if(depth[a] != depth[b]){
            if(depth[a] > depth[b]) swap(a, b);
            for(ll i = maxnum; i>= 0 ; i--){
                if(depth[a] <= depth[dp[b][i]]){
                    ans += dpweight[b][i];
                    b = dp[b][i];
                }
            }
        }
        commontop = a;
        if(a != b){
            for(ll i = maxnum ; i >= 0 ; i--){
                if(dp[a][i] != dp[b][i]){
                    ans += dpweight[a][i];
                    ans += dpweight[b][i];
                    a = dp[a][i];
                    b = dp[b][i];
                }
                commontop = dp[a][i];
            }
        }
        if(b != commontop){
        ans += dpweight[a][0];
        ans += dpweight[b][0];
        }
        if(input == 1){
            
            cout << ans << "\n";
        }
        else{
            cin >> k;
            ll left = depth[aa] - depth[commontop];
            ll right = depth[bb] - depth[commontop];
            ll answer = 0;
            if(k == left+1){
                answer = commontop;
            }
            else if(k <= left){
                k--;
                answer = aa;
                for(ll i = maxnum; i>= 0 ; i--){
                    ll t = (ll)pow(2,i);
                    if(k >= t){
                        answer = dp[aa][i];
                        aa= dp[aa][i];
                        k -= t;
                    }
                }
            }
            else{
                k = left+right+1-k;
                answer = bb;
                for(ll i = maxnum; i>= 0 ; i--){
                    ll t = (ll)pow(2,i);
                    if(k >= t){
                        answer = dp[bb][i];
                        bb = dp[bb][i];
                        k -= t;
                    }
                }
            }
            cout << answer << "\n";
        }
    }


    return 0;
}