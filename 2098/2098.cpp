#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N;
ll arr[20][20];
ll DP[20][1<<18];

ll dfs(ll num, ll visited){ //num 현재위치 visited 방문한 곳
    if(visited == (1<<N)-1){
        if(arr[num][0] != 0) return arr[num][0];
    }
    if(DP[num][visited] != -1 ) return DP[num][visited];
    DP[num][visited] = INT_MAX;
    for(ll i = 0 ; i < N ; i++){
        if(arr[num][i] == 0) continue;
        if((visited&(1<<i)) != 0) continue;
        DP[num][visited] = min(DP[num][visited], dfs(i, visited|(1<<i)) + arr[num][i]);
    }
    return DP[num][visited];
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    memset(DP, -1 , sizeof(DP));
    for(ll i = 0 ; i < N ; i++){
        for(ll j = 0 ; j < N ; j++){
            cin >> arr[i][j];
        }
    }
    cout << dfs(0,1);
    return 0;
}