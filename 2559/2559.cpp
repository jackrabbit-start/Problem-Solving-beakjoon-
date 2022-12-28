#include <bits/stdc++.h>
using namespace std;

int N, K;
int DP[200005];
int arr[200005];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        DP[i] = arr[i];
    }
    for(int i = 1; i <= N; i++){
        DP[i] += DP[i-1];
    }
    int maxnum = -987654321;
    if(N == K){
        maxnum = DP[N];
    }
    else{
    for(int i = K ; i <= N; i++){
        maxnum = max(maxnum, DP[i]-DP[i-K]);
    }
    }
    cout << maxnum;

    return 0;
}