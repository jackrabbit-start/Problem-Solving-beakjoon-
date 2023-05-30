#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define modn 10007
ll N;
ll fac[110];

ll moding(ll n){
    ll a = 1;
    ll tmp = n;
    ll expo = modn-2;
    while(expo){
        if(expo&1){
            a = (a*tmp)%modn;
        }
        tmp = (tmp*tmp)%modn;
        expo/=2;
    }
    return a;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    if(N<4){cout << 0; return 0;}
    N-=4;
    fac[0] = 1;
    for(ll i = 1; i <= 100; i++){
        fac[i] = (fac[i-1] * i) %modn;
    }
    ll answer = 0;
    ll tmp = 4;
    ll cnt = 1;
    while(N>=0){
        if(cnt&1){
            answer += ((((moding(fac[N]) *moding(fac[52-tmp-N])%modn)*fac[52-tmp])%modn) * (((moding(fac[cnt]) *moding(fac[13-cnt])%modn)*fac[13])%modn))%modn;
        }
        else{
            answer -= ((((moding(fac[N]) *moding(fac[52-tmp-N])%modn)*fac[52-tmp])%modn) * (((moding(fac[cnt]) *moding(fac[13-cnt])%modn)*fac[13])%modn))%modn;
            answer = (answer+modn)%modn;
        }
        N-=4;
        cnt++;
        tmp+=4;
    }
    cout << answer%modn << "\n";
    return 0;
}