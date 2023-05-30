#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N, K;
vector<pair<ll ,ll>> graph[100010];
ll depth[100010];
ll dp[100010][40][3]; // parent, 최대 , 최소
ll maxnum;

ll dfs(ll now, ll weight,ll parent){
    depth[now] = depth[parent]+1;
    dp[now][0][0] = parent;
    dp[now][0][1] = weight;
    dp[now][0][2] = weight;
    if(now == 1) dp[now][0][2] = 987654321;

    for(ll i = 1 ; i <= maxnum; i++){
        ll tmp = dp[now][i-1][0];
        dp[now][i][0] = dp[tmp][i-1][0];
        dp[now][i][1] = max(dp[now][i-1][1] , dp[tmp][i-1][1]);
        dp[now][i][2] = min(dp[now][i-1][2] , dp[tmp][i-1][2]);
    }

    for(ll i = 0 ; i < graph[now].size(); i++){
        ll nxt = graph[now][i].first;
        ll w = graph[now][i].second;
        if(depth[nxt] == -1){
            dfs(nxt ,w ,now);
        }
    }
    return 0;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    maxnum = (ll)floor(log2(N));
    memset(depth, -1, sizeof(depth));
    for(ll i = 1 ; i < N ; i++){
        ll u , v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    for(ll i = 0 ; i <= N ; i++){
        for(ll j = 0 ; j <= maxnum ;j++){
            dp[i][j][2] = 987654321;
        }
    }
    
    depth[0] = 0;
    dfs(1, 0, 0);
    cin >> K;
    ll a, b;
    for(ll i = 0 ; i < K ; i++){
        ll ans_max = 0;
        ll ans_min = 987654321;
        cin >> a >> b;
        if(depth[a] != depth[b]){
            if(depth[a] > depth[b]) swap(a,b);
            for(ll i = maxnum; i >= 0 ; i--){
                if(depth[a] <= depth[dp[b][i][0]]){
                    ans_max = max(ans_max, dp[b][i][1]);
                    ans_min = min(ans_min, dp[b][i][2]);
                    b = dp[b][i][0];
                }
            }
        }
        if(a != b){
            for(ll i = maxnum; i >= 0 ; i--){
                if(dp[a][i][0] != dp[b][i][0]){
                    ans_max = max(ans_max, dp[b][i][1]);
                    ans_min = min(ans_min, dp[b][i][2]);
                    ans_max = max(ans_max, dp[a][i][1]);
                    ans_min = min(ans_min, dp[a][i][2]);
                    a = dp[a][i][0];
                    b = dp[b][i][0];
                }
            }
            ans_max = max(ans_max, dp[b][0][1]);
            ans_min = min(ans_min, dp[b][0][2]);
            ans_max = max(ans_max, dp[a][0][1]);
            ans_min = min(ans_min, dp[a][0][2]);
        }
        cout << ans_min << " " << ans_max << "\n";
    }
    return 0;
}