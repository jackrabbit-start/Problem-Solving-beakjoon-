#include <bits/stdc++.h>
using namespace std;

int a, b;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> a >> b;
    while(a != 0 && b != 0){
        if(b%a == 0){
            cout << "factor\n";
        }
        else if(a%b == 0){
            cout << "multiple\n";
        }
        else{
            cout << "neither\n";
        }
        cin >> a >> b;
    }

    return 0;
}