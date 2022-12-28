#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100005];
int DP[100005][2];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 0 ; i< N ; i++){
        cin >> arr[i];
    }
    DP[0][0] = arr[0];
    DP[0][1] = arr[0];
    for(int i = 1; i < N ; i++){
        DP[i][0] = max(DP[i-1][0], DP[i-1][1]);
        DP[i][1] = max(DP[i-1][1] + arr[i] , arr[i]);
    }
    cout << max(DP[N-1][0], DP[N-1][1]);
    

    return 0;
}