#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1005];
int DP[1005];
int DP2[1005];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N ; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= N ; i++){
        DP[i] = 1;
        for(int j = 1; j < i ; j++){
            if(arr[j] < arr[i]){
                if(DP[i] < DP[j]+1){
                    DP[i] = DP[j]+1;
                }
            }
        }
    }
    for(int i = N; i >= 1 ; i--){
        DP2[i] = 1;
        for(int j = N; j > i ; j--){
            if(arr[j] < arr[i]){
                if(DP2[i] < DP2[j]+1){
                    DP2[i] = DP2[j]+1;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= N ; i++){
        //cout << DP[i] << DP2[i] << "\n";
        ans = max(ans, DP[i]+DP2[i]-1);
    }
    cout << ans;

    return 0;
}