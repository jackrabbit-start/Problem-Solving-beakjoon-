#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MODNN 100030001

ll N , L;
ll DP[400][400];
ll suming[400][400];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> L;
    DP[1][1] = 1;
    suming[1][1] = 1;
    for(ll i = 2; i <= L ; i ++){ // 높이
        for(ll j = 0 ; j <= N ;j++){ // 개수
            if(j < i){suming[i][j] = (suming[i-1][j] + DP[i][j])%MODNN; continue;}
            if(i < 10){
                ll tmp = (ll)pow((ll)2, i);
                if(j > tmp-1) {DP[i][j] = 0; (suming[i][j] = suming[i-1][j] + DP[i][j])%MODNN; continue;}
            }
            if(i==j){
                DP[i][j] = (DP[i-1][j-1] *2)%MODNN;
            } 
            else{
                for(ll k = 0 ; k < j ; k ++){
                    ll a = suming[i-1][k];
                    ll b = suming[i-1][j-1-k];
                    if(a == 0) a= 1;
                    if(b == 0) b= 1;
                    if(i-1 < 10){
                        ll tmp = (ll)pow((ll)2, i-1);
                        if(tmp <= k) a = 0;
                        if(tmp <= j-1-k) b = 0;
                    }         
                    DP[i][j] = (DP[i][j]+ (a * b)%MODNN)%MODNN;
                }
                DP[i][j] %= MODNN;
                DP[i][j] = (DP[i][j] - suming[i-1][j])%MODNN;
                if(DP[i][j] < 0) DP[i][j] += MODNN;
            }
            suming[i][j] = (suming[i-1][j] + DP[i][j])%MODNN;
        }
    }
    cout << DP[L][N] %MODNN;
    return 0;
}