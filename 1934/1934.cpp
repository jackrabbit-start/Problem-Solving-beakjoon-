#include <bits/stdc++.h>
using namespace std;

int T;


int checking(int a, int b){
    if(b==0){
        return a;
    }
    else return checking(b, a%b);
}
int x, y;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    for(int i= 0 ; i < T; i++){
        cin >> x >> y;
        cout << (x*y)/checking(x,y) << "\n";
    }
    

    return 0;
}