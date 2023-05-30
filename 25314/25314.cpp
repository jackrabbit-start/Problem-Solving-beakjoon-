#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    int ans = N/4;
    if(N%4 != 0) ans++;
    for(int i = 0 ; i < ans ; i++){
        cout << "long ";
    }
    cout << "int";
    return 0;
}