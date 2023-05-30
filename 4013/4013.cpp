#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N, M;
ll S, P;

ll visited[500050];
ll sccID[500050];
vector<ll> graph[500050];
ll money[500050];

ll sccmoney[500050];
vector<ll> sccgraph[500050];
set<ll> sccrestaurant;
ll sccvisited[500050];

set<ll> restaurant;
ll vID;
deque<ll> st;
ll answer;
ll scccnt;

ll dfs(ll now){
    visited[now] = ++vID;
    st.push_front(now);
    ll result = vID;
    for(ll nxt : graph[now]){
        if(visited[nxt] == -1) result = min(result, dfs(nxt));
        else if (!sccID[nxt]) result = min(result, visited[nxt]);
    }
    if(result == visited[now]){
        scccnt++;
        ll total = 0;
        while(!st.empty()){
            ll tmp = st.front();
            st.pop_front();
            total += money[tmp];
            sccID[tmp] = scccnt;
            if(restaurant.count(tmp) >= 1) sccrestaurant.insert(scccnt);
            if(tmp == now) break;
        }
        sccmoney[scccnt] = total;
    }
    return result;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    memset(visited, -1 ,sizeof(visited));
    cin >> N >> M;
    for(ll i = 0 ; i < M ; i++){
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for(ll i = 1 ; i <= N ; i++){
        cin >> money[i];
    }
    cin >> S >> P;
    for(ll i = 0 ; i < P; i++){
        ll input;
        cin >> input;
        restaurant.emplace(input);
    }
    dfs(S);

    for(int i = 1; i <= N ; i++){
        for(int tmp : graph[i]){
            if(sccID[tmp] != sccID[i]){
                sccgraph[sccID[i]].push_back(sccID[tmp]);
            }
        }
    }
    S = sccID[S];
    queue<ll> q;
    q.push(S);
    sccvisited[S] = sccmoney[S];
    while(!q.empty()){
        ll now = q.front();
        q.pop();
        for(ll nxt : sccgraph[now]){
            if(sccvisited[nxt] < sccvisited[now]+sccmoney[nxt]){
                sccvisited[nxt] = sccvisited[now] + sccmoney[nxt];
                q.push(nxt);
            }
        }
    }
    ll answ = 0;
    for(auto iter = sccrestaurant.begin(); iter != sccrestaurant.end(); iter++){
        answ = max(answ, sccvisited[*iter]);
    }
    cout << answ;

    return 0;
}