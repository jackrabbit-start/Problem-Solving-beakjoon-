#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N;
ll K;
ll answer;
ll BS(ll left, ll right , ll n){
    //cout << "(" << left << " " << right << ")";
    
    if(left > right){
        answer = left;
        return 0;
    }
    ll mid = (left+right)/2;
    ll total = 0;
    for(int i = 1 ; i <= N ; i++){
        total += min(mid/i, N);
    }
    //cout << total << "*";
    if(left == right && total < K){
        answer = mid+1;
        return 0;
    }
    if(left == right && total >= K){
        answer = mid;
        return 0;
    }
    if(total >= K){
        answer = min(mid, answer);
        BS(left, mid-1, n);
    }
    else{
        BS(mid+1, right, n);
    }
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> K;
    BS(1, 10000000000 , K);
    cout << answer;

    return 0;
}