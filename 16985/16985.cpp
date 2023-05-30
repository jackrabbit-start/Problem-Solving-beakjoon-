#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> v;
ll arr[6][4][6][6]; // 몇번째 판, 몇번 돌림, x ,y 
ll answer = INT_MAX;
ll wheel[10];
ll visited[10][10][10];

ll dx[6] = {1, -1, 0, 0, 0, 0};
ll dy[6] = {0, 0, 1, -1, 0, 0};
ll dh[6] = {0, 0, 0, 0, 1, -1};


ll bfs(ll h, ll x, ll y){
    queue<tuple<ll, ll, ll>> q;
    q.push({h,x,y});
    while(!q.empty()){
        auto[nh,nx,ny] = q.front();
        if(nh == 5 && nx == 4 && ny == 4) return 0;
        q.pop();
        for(ll i = 0 ; i < 6; i++){
            ll nxt_x = nx + dx[i];
            ll nxt_y = ny + dy[i];
            ll nxt_h = nh + dh[i];
            if(nxt_x < 5 && nxt_x >= 0 && nxt_y < 5 && nxt_y>= 0 && nxt_h <= 5 && nxt_h>0 && visited[nxt_h][nxt_x][nxt_y] > visited[nh][nx][ny]+1 && arr[v[nxt_h-1]][wheel[v[nxt_h-1]]][nxt_x][nxt_y] == 1){
                visited[nxt_h][nxt_x][nxt_y] = visited[nh][nx][ny]+1;
                if(visited[nxt_h][nxt_x][nxt_y]> answer) return 0;
                q.push({nxt_h, nxt_x, nxt_y});
            }

        }
    }
    return 0;
}


ll solve(int cnt){
    if(cnt == 6){
        if(arr[v[0]][wheel[v[0]]][0][0] == 1){
            fill(&visited[0][0][0] , &visited[6][6][6], INT_MAX);
            visited[1][0][0] = 0;
            bfs(1,0,0);
            answer = min(answer , visited[5][4][4]);
        }
        return 0;
    }
    for(ll i = 0 ; i < 4; i++){
        wheel[cnt] = i;
        solve(cnt+1);
    }
    return 0;
}



int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for(ll i = 1; i <= 5 ; i++){
        v.push_back(i);
        for(ll j = 0; j < 5; j++){
            for(ll k = 0; k < 5; k++){
                cin >> arr[i][0][j][k];
            }
        }
    }
    for(ll i = 1; i <= 5; i++){
        for(ll j = 0; j < 5; j++){
            for(ll k= 0; k < 5; k++){
                arr[i][2][4-j][4-k] = arr[i][0][j][k]; // 2번돌림
                arr[i][1][k][4-j] = arr[i][0][j][k]; // 1번돌림
                arr[i][3][4-k][j] = arr[i][0][j][k]; // 3번돌림
            }
        }
    }
    do {
        solve(1);
    }
    while (next_permutation(v.begin(), v.end()));
    if(answer == INT_MAX) cout << -1 << "\n";
    else cout << answer << "\n";
    return 0;
}