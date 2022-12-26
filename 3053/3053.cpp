#include <bits/stdc++.h>
using namespace std;
double R;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> R;
    double pi1 = acos(-1); // pi 값
    cout<<fixed; // 소수점 고정
    cout.precision(6); //cout  소수점 자릿수 조절
    cout << R*R*pi1 << "\n";
    cout.precision(6);
    cout << R*R*2 << "\n";
    
    

    return 0;
}