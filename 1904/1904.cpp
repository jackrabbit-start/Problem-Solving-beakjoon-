#include <bits/stdc++.h>
using namespace std;
int N;
int DP[1000004];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
    // 001 100 111 
    for(int i = 3; i <= N; i++){
        DP[i] = (DP[i-1] + DP[i-2])%15746;
    }
    cout << DP[N]%15746;

    return 0;
}