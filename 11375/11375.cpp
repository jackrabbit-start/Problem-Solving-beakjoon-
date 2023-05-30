#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N, M;
vector<ll> edge[4000];
ll BMV[4000];
ll visited[4000];

ll dfs(ll now){
    for(ll nxt : edge[now]){
        if(visited[nxt]) continue;
        visited[nxt] = 1;
        if(BMV[nxt] == 0 || dfs(BMV[nxt])){
            BMV[nxt] = now;
            return 1;
        }
    }
    return 0;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++){
        ll hm;
        cin >> hm;
        for(ll j = 0 ; j < hm ; j++){
            ll input;
            cin >> input;
            edge[i].push_back(input);
        }
    }
    ll answer = 0;
    for(ll i = 1; i <= N ; i++){
        memset(visited,0,sizeof(visited));
        if(dfs(i)) answer++;
        memset(visited,0,sizeof(visited));
        if(dfs(i)) answer++;
    }
    cout << answer;

    
    return 0;
}