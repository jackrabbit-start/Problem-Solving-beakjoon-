#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define modn 1000000007
ll N;
ll metrix[2][2] = {{2,1},{1,0}};
ll calm[2][2] = {{1,0}, {0,1}};

ll calmetrix(ll a[][2], ll b[][2]){
    ll tmp[2][2] = {{0,0},{0,0}};
    tmp[0][0] = ((a[0][0] * b[0][0])%modn + (a[0][1]*b[1][0])%modn)%modn;
    tmp[0][1] = ((a[0][0] * b[0][1])%modn + (a[0][1]*b[1][1])%modn)%modn;
    tmp[1][0] = ((a[1][0] * b[0][0])%modn + (a[1][1]*b[1][0])%modn)%modn;
    tmp[1][1] = ((a[1][0] * b[0][1])%modn + (a[1][1]*b[1][1])%modn)%modn;
    a[0][0] = tmp[0][0];
    a[0][1] = tmp[0][1];
    a[1][0] = tmp[1][0];
    a[1][1] = tmp[1][1];
    return 0;
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    if(N==1) {cout << 3; return 0;}
    else if(N==2) {cout << 7; return 0;}
    N-=2;
    while(N){
        if(N%2 == 1){
            calmetrix(calm,metrix);
        }
        calmetrix(metrix, metrix);
        N/=2;
    }
    ll answer = ((calm[0][0] *7)%modn + (calm[0][1] * 3)%modn)%modn;
    cout <<answer << "\n";
    return 0;
}