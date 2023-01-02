#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long int N;
long long int K;
long long int arr[4000001];
long long int moding(long long int q){
    long long int tmp = 1;
    long long int expo = MOD-2;
    while(expo){
        if(expo & 1){
            tmp = (tmp*q) % MOD;
        }
        q = (q*q) %MOD;
        expo /= 2;
    }
    return tmp;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> K;
    arr[0] = 1;
    for(int i = 1 ; i <= N ; i++){
        arr[i] = (arr[i-1]*i) %MOD;
    }
    long long int answer = (((moding(arr[K])* moding(arr[N-K]))%MOD)*arr[N])%MOD; 
    cout << answer;
    return 0;
    
}