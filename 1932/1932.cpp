#include <bits/stdc++.h>
using namespace std;
int N;
int arr[505][505];
int DP[505][505];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 1 ; i <= N; i++){
        for(int j = 1; j <= i; j++){
            cin >> arr[i][j];
        }
    }
    DP[1][1] =  arr[1][1];
    for(int i = 2 ; i <= N; i++){
        for(int j = 1; j <= i; j++){
            DP[i][j] = arr[i][j] + max(DP[i-1][j],DP[i-1][j-1]);
        }
    }
    int ans = -1;
    for(int i = 1; i <= N ; i++){
        ans = max(ans, DP[N][i]);
    }
    cout << ans;

    

    return 0;
}