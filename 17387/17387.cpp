#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll line1[10];
ll line2[10];

ll crosslines(ll a1, ll a2, ll b1, ll b2){
    if(a1*b2 - b1*a2 > 0) return 1;
    else if (a1*b2 - b1*a2 < 0) return -1;
    else return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> line1[0] >> line1[1]>> line1[2]>> line1[3];
    cin >> line2[0] >> line2[1]>> line2[2]>> line2[3];
    ll tmp1 = crosslines(line1[2] - line1[0] , line1[3] - line1[1], line2[0]-line1[0] , line2[1]-line1[1]) * crosslines(line1[2] - line1[0] , line1[3] - line1[1], line2[2]-line1[0] , line2[3]-line1[1]);
    ll tmp2 = crosslines(line2[2] - line2[0] , line2[3] - line2[1], line1[0]-line2[0] , line1[1]-line2[1]) * crosslines(line2[2] - line2[0] , line2[3] - line2[1], line1[2]-line2[0] , line1[3]-line2[1]);
    pair<ll , ll> A1 = {line1[0], line1[1]};
    pair<ll , ll> A2 = {line1[2], line1[3]};
    pair<ll , ll> B1 = {line2[0], line2[1]};
    pair<ll , ll> B2 = {line2[2], line2[3]};
    if(tmp1 == 0 && tmp2 == 0){
        if(A1 < A2){
            if(B1 < B2){
                if(B2 >= A1  && B1 <= A2) cout << 1;
                else cout << 0;
            }
            else{
                if(B1 >= A1  && B2 <= A2) cout << 1;
                else cout << 0;
            }
        }
        else{
            if(B1 < B2){
                if(B2 >= A2  && B1 <= A1) cout << 1;
                else cout << 0;
            }
            else{
                if(B1 >= A2  && B2 <= A1) cout << 1; 
                else cout << 0;            
            }
        }
        return 0
        ;

    }
    else if(tmp1 <= 0 &&  tmp2 <= 0) cout << 1;
    else cout << 0;
    return 0;
}
