#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000
typedef long long int ll;
ll N;
ll K;
ll DP[5050][5050];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> K;
    for(int i = 0 ; i <= N ; i++){
        for(int j = 1 ; j <= K ; j++){
            if(i == 0) DP[i][j] = 1;
            else{
                DP[i][j] = (DP[i-1][j] + DP[i][j-1])%MOD;
            }
        }
    }
    cout << DP[N][K];
    return 0;
}