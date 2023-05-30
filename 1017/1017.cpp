#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N;
ll arr[100];
ll prime[3000];
ll bm[100];
ll visited[100];

ll dfs(ll now, ll no){
    for(ll i = 2 ; i <= N ; i++ ){
        if(i == no || i == now) continue;
        if(prime[arr[i] + arr[now]] == 1) continue;
        if(bm[now] == i) continue;
        if(visited[i]) continue;
        visited[i] = 1;
        visited[now] = 1;
        if(bm[now] == 0 && bm[i] == 0){
            bm[now] = i;
            bm[i] = now;
            return 1;
        }
        else if(bm[now] != 0 && bm[i] != 0){
            ll tmp[100];
            for(ll i = 1; i <= N ; i++) tmp[i] = bm[i];
            bm[bm[now]] = 0;
            bm[bm[i]] = 0;
            if(dfs(bm[now],no) && dfs(bm[i],no)){
                bm[now] = i;
                bm[i] = now;
                return 1;
            }
            else{
                for(ll i = 1; i <= N ; i++) bm[i] = tmp[i];
            }

        }
        else if(bm[i] != 0){
            ll tmp[100];
            for(ll i = 1; i <= N ; i++) tmp[i] = bm[i];
            bm[bm[i]] = 0;
            if(dfs(bm[i],no)){
                bm[now] = i;
                bm[i] = now;
                return 1;
            }
            else{
                for(ll i = 1; i <= N ; i++) bm[i] = tmp[i];
            }
            
        }
        else{
            ll tmp[100];
            for(ll i = 1; i <= N ; i++) tmp[i] = bm[i];
            bm[bm[now]] = 0;
            if(dfs(bm[now],no)){
                bm[now] = i;
                bm[i] = now;
                return 1;
            }
            else{
                for(ll i = 1; i <= N ; i++) bm[i] = tmp[i];
            }
        }
    }
    
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N ; i++){
        cin >> arr[i];
    }
    for(ll i = 2; i <= 2500; i++){
        if(prime[i] == 1) continue;
        for(ll j = 2*i;j<=2500; j+=i){
            prime[j] = 1;
        }
    }
    vector<ll> answer;
    for(ll i = 2; i <= N ; i++){
        if(prime[arr[1] + arr[i]] == 0){
            memset(bm, 0, sizeof(bm));
            bm[1] = i;
            bm[i] = 1;
            ll cnt = 0;
            for(ll j = 2; j <= N ;j++){
                memset(visited, 0, sizeof(visited));
                visited[1] = 1;
                visited[i] = 1;
                if(bm[j]==0) {
                    dfs(j,i);
                }
            }
            ll isok = 1;
            for(ll k= 1; k <= N ; k++){
                if(bm[k] == 0) isok = 0;
            }
            if(isok==1) answer.push_back(arr[i]);
        }
    }
    if(answer.size() == 0) cout << -1;
    else{
        sort(answer.begin(), answer.end());
    for(ll i = 0 ; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    }

    return 0;
}