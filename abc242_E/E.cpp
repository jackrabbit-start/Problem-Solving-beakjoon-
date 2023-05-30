#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MODll 998244353
ll T, N;

ll moding(ll a, ll d){
    if(d == 0) return 1;
    ll tmp = 1;
    while(d){
        if(d&1){
            tmp = (tmp*a) % MODll;
        }
        a = (a*a)%MODll;
        d /= 2;
    }
    return tmp;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    while(T--){
        ll ans = 0;
        string s;
        cin >> N;
        cin >> s;
        string t = s;
        for(ll i = 0 ; i < N/2; i++){
            s[N-i-1] = s[i];
        }
        ll tmp = N/2;
        if(N%2) tmp++;
        for(ll i = 0 ; i < tmp; i++){
            ll num = s[i] - 'A';
            ans += (num*moding(26,tmp-i-1))%MODll;
            ans = ans % MODll;
        }
        if(s <= t) ans++;
        ans = ans % MODll;
        cout << ans << "\n";

    }
    return 0;
}