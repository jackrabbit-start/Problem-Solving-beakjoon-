#include <bits/stdc++.h>
using namespace std;
int N;
int arr[1005][3];
int DP[2000][3];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N ; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    int ans = 987654321;
    for(int i = 0; i <= 2 ; i++){
        for(int j = 0 ; j <= 2; j ++){
            if(i == j) DP[1][j] = arr[1][j];
            else DP[1][j] = 987654321;  
        }
        for(int j = 2 ; j <= N ; j++){
            DP[j][0] = min(DP[j-1][1] , DP[j-1][2]) + arr[j][0];
            DP[j][1] = min(DP[j-1][0] , DP[j-1][2]) + arr[j][1];
            DP[j][2] = min(DP[j-1][1] , DP[j-1][0]) + arr[j][2];
        }
        for(int j = 0 ; j <= 2; j ++){
            if(i != j) ans = min(DP[N][j] , ans);
        }
    }
    cout << ans;

    
    return 0;
}