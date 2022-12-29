#include <bits/stdc++.h>
using namespace std;
long long int N, M;
long long int arr[1000001];
long long int answer[1005];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;
    long long int a;
    for(long long int i = 0 ; i < N ; i++){
        cin >> a;
        arr[i] = a%M;
    }
    answer[arr[0]]++;
    for(long long int i = 1 ; i < N ; i++){
        arr[i] = (arr[i] + arr[i-1])%M;
        answer[arr[i]]++;
    }
    long long int ans = 0;
    for(long long int i = 0 ; i < M ; i++){
        if(i == 0){
            ans += answer[i];
        }
        if(answer[i] > 0) ans += (answer[i] * (answer[i]-1))/2;
    }
    cout << ans;

    

    return 0;
}