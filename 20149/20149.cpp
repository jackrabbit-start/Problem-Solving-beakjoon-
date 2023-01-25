#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double lld;
ll line1[10];
ll line2[10];

ll crosslines(ll a1, ll a2, ll b1, ll b2){
    if(a1*b2 - b1*a2 > 0) return 1;
    else if (a1*b2 - b1*a2 < 0) return -1;
    else return 0;
}
tuple<lld, lld, lld> crossproduct3(tuple<lld , lld , lld> A, tuple<lld, lld , lld> B){
    lld tmp1 = get<1>(A) * get<2>(B) - get<2>(A)*get<1>(B);
    lld tmp2 = get<2>(A) * get<0>(B) - get<0>(A)*get<2>(B);
    lld tmp3 = get<0>(A) * get<1>(B) - get<1>(A)*get<0>(B);
    tuple<lld, lld, lld> result = {tmp1, tmp2, tmp3};
    return result;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> line1[0] >> line1[1]>> line1[2]>> line1[3];
    cin >> line2[0] >> line2[1]>> line2[2]>> line2[3];
    ll tmp1 = crosslines(line1[2] - line1[0] , line1[3] - line1[1], line2[0]-line1[0] , line2[1]-line1[1]);
    ll tmp2 = crosslines(line1[2] - line1[0] , line1[3] - line1[1], line2[2]-line1[0] , line2[3]-line1[1]);
    ll tmp3 = crosslines(line2[2] - line2[0] , line2[3] - line2[1], line1[0]-line2[0] , line1[1]-line2[1]);
    ll tmp4 = crosslines(line2[2] - line2[0] , line2[3] - line2[1], line1[2]-line2[0] , line1[3]-line2[1]);
    pair<ll , ll> A1 = {line1[0], line1[1]};
    pair<ll , ll> A2 = {line1[2], line1[3]};
    pair<ll , ll> B1 = {line2[0], line2[1]};
    pair<ll , ll> B2 = {line2[2], line2[3]};
    if(tmp1 == 0 && tmp2 == 0 && tmp3 == 0 && tmp4 == 0){
        if(A1 < A2){
            if(B1 < B2){
                if(A2 == B1){
                    cout << 1 << "\n"<< A2.first<< " " << A2.second;return 0;
                }
                if(A1 == B2){
                    cout << 1 << "\n"<< A1.first<< " " << A1.second; return 0;
                }
                if(B2 >= A1  && B1 <= A2) cout << 1;
                else cout << 0;
            }
            else{
                if(A2 == B2){
                    cout << 1 << "\n"<< A2.first<< " " << A2.second;return 0;
                }
                if(A1 == B1){
                    cout << 1 << "\n"<< A1.first<< " " << A1.second; return 0;
                }
                if(B1 >= A1  && B2 <= A2) cout << 1;
                else cout << 0;
            }
        }
        else{
            if(B1 < B2){
                if(A1 == B1){
                    cout << 1 << "\n"<< A1.first<< " " << A1.second; return 0;
                }
                if(A2 == B2){
                    cout << 1 << "\n"<< A2.first<< " " << A2.second; return 0;
                }
                if(B2 >= A2  && B1 <= A1) cout << 1;
                else cout << 0;
            }
            else{
                if(A1 == B2){
                    cout << 1 << "\n"<< A1.first<< " " << A1.second; return 0;
                }
                if(A2 == B1){
                    cout << 1 << "\n"<< A2.first<< " " << A2.second; return 0;
                }
                if(B1 >= A2  && B2 <= A1) cout << 1; 
                else cout << 0;            
            }
        }
        return 0;
    }
    else if(tmp1*tmp2 <= 0 &&  tmp3*tmp4 <= 0) {
        cout << 1 << "\n";
        tuple<lld, lld ,lld> aa = {(lld)(line1[0]), (lld)line1[1], (lld)1};
        tuple<lld, lld ,lld> aa2 = {(lld)line1[2], (lld)line1[3], (lld)1};
        tuple<lld, lld ,lld> bb = {(lld)line2[0], (lld)line2[1], (lld)1};
        tuple<lld, lld ,lld> bb2 = {(lld)line2[2], (lld)line2[3], (lld)1};
        tuple<lld, lld ,lld> result1 = crossproduct3(aa, aa2);
        tuple<lld, lld ,lld> result2 = crossproduct3(bb, bb2);
        tuple<lld, lld ,lld> result3 = crossproduct3(result1, result2);
        cout << fixed;
        cout.precision(16);
        cout << get<0>(result3) / get<2>(result3) << " " << get<1>(result3) / get<2>(result3);
    }
    else cout << 0;
    return 0;
}
