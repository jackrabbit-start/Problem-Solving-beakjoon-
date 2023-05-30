#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll R, C;
char arr[1000][1000];
ll dp1[1000][1000];
ll dp2[1000][1000];
ll dp3[1000][1000];
ll dp4[1000][1000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> R >> C;
    for(ll i = 1; i <= R; i++){
        for(ll j = 1 ; j <= C; j++){
            cin >> arr[i][j];
        }
    }
    for(ll i = 1; i <= R; i++){
        for(ll j = 1 ; j <= C; j++){
            if(arr[i][j] == '1'){
                dp1[i][j] = dp1[i-1][j+1] +1; // 밑좌
                dp2[i][j] = dp2[i-1][j-1] + 1;  // 밑우
            }
        }
    }
    for(ll i = R; i >= 1; i--){
        for(ll j = C ; j >= 1; j--){
            if(arr[i][j] == '1'){
                dp3[i][j] = dp3[i+1][j+1] +1; // 상좌
                dp4[i][j] = dp4[i+1][j-1] + 1;  // 상우
            }
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= R; i++){
        for(ll j = 1 ; j <= C; j++){
            ll tmp = min(dp1[i][j], dp3[i][j]);
            for(ll k = tmp; k >= ans; k--){
                if(j+k*2 <= C){
                    if(min(dp2[i][j+k*2], dp4[i][j+k*2]) >= k+1){
                        ans = max(ans, k+1);
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}