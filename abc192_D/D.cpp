#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
string S;
ull M;

bool isOK(ull m){
    __int128 x = 1, s = 0;
    for(int i=S.size()-1; i>=0; i--){
        if(x > M) return false;
        s += x * (S[i] - '0');
        if(s > M) return false;
        x *= m;
    }
    return true;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> S;
    cin >> M;
    ull l, r, maxing;
    l = 0;
    r = M+1;
    for(int i = 0 ; i < S.size(); i++){
        l = max(l, (ull)(S[i]-'0'));
    }
    if (S.size() == 1) {
        if(l <= M) cout << 1;
        else cout << 0;
        return 0;
    }
    ull answer = 0;
    maxing = l;
    while(l <= r){
        ull mid = (l+r)/2;
        //cout << "(" << l << " " << r  << " "<< total << ")";
        if( isOK(mid) == false) r = mid-1;
        else {answer = max(answer, mid); l = mid+1;}
    }
    cout << (answer - maxing);


    return 0;
}