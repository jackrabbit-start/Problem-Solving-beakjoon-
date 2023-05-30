#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

typedef struct Point{
    ll x,y,z;
}Point;
ll N;
Point arr[100];
ll visited[100];
ll bm[100];

ll compare(Point &a, Point &b){
    if(a.x >= b.x && a.y >= b.y && a.z >= b.z) return 1;
    return 0;
}

ll dfs(ll now, ll no){
    for(ll i = 1; i <= N; i++){
        if(i == no) continue;
        if(i == now) continue;
        if(!compare(arr[now], arr[i])) continue;
        if(visited[i]) continue;
        visited[i] = 1;
        //cout << "(" << now << " " << i << ")";
        if((bm[i] == 0&&bm[i] != now && bm[now] != i) || dfs(bm[i])){
            bm[i] = now;
            return 1;
        }
    }
    return 0;
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(ll i = 1; i <= N ; i++){
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
    }
    ll ans = 0;
    sort(arr+1, arr+N+1, [](Point &a, Point &b){
        return a.x < b.x;
    });
    
    for(ll i =1 ; i <= N ; i++){
        if(bm[i] == 0){
            //cout << "<" << i << "> -";
            memset(visited, 0, sizeof(visited));
            if(dfs(i) , -1) ans++;
            memset(visited, 0, sizeof(visited));
            if(dfs(i), -1) ans++;
        }
    }
    ans = 0;
    for(ll i = 1; i <= N ; i++){
        if(bm[i] == 0) ans++;
    }
    cout << ans;

    return 0;
}