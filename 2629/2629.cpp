#include <bits/stdc++.h>
using namespace std;

int DP[50][40005];
int arr[50];
int N;
int T;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    int input;
    for(int i = 1 ; i <= N ; i ++){
        cin >> arr[i];
    }
    for(int i = 1 ; i <= N ; i++){
        DP[i][arr[i]] = 1;
        for(int j = 1; j <= 40000; j++){
            DP[i][j] = DP[i][j] || DP[i-1][j];
            if(j-arr[i] > 0){
                DP[i][j] = DP[i][j] || DP[i-1][j-arr[i]];
            }
            if(j+arr[i] < 40001){
                DP[i][j] = DP[i][j] || DP[i-1][j+arr[i]];
            }
            if(arr[i]-j > 0){
                DP[i][j] = DP[i][j] || DP[i-1][arr[i]-j];
            }
        }
    }
    cin >> T;
    for(int i = 0 ; i < T; i++){
        cin >> input;
        if(DP[N][input] == 1) cout << "Y ";
        else cout <<"N ";
    }
    return 0;
}