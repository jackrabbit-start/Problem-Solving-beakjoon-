#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000003
typedef long long int ll;
ll N;
ll K;
ll DP[1010][1010];
ll ans;
ll dfs(ll total, ll cnt){
    if(cnt*2 == total) return 2;
    if(cnt*2 > total) return 0;
    if(DP[total][cnt] != -1) return DP[total][cnt];
    DP[total][cnt] = (dfs(total-1, cnt) + dfs(total-2, cnt-1)) %MOD;
    return DP[total][cnt];
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> K;
    fill(&DP[0][0], &DP[1002][1002] , -1);
    for(ll i= 0 ; i <= N ; i++){
        DP[i][0] = 1;
        //DP[i][1] = i;
    }
    cout << dfs(N,K)%MOD;
    return 0;
}