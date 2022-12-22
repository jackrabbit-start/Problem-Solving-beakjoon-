#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> a >> b >>c;
    while(a != 0 && b!=0 && c!=0){
        int ans = max(max(a,b),c);
        if((a*a + b*b + c*c) == (2*ans*ans)) cout << "right\n";
        else cout << "wrong\n";
        cin >> a >> b >>c;
    }
    

    return 0;
}