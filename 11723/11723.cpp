#include <bits/stdc++.h>
using namespace std;
int M;
int num;
string input;
int input2;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> M;
    while(M--){
        cin >> input;
        if(input == "add"){
            cin >> input2;
            num = num|(1<<input2);
        }
        else if(input == "remove"){
            cin >> input2;
            num = num&~(1<<input2);
        }
        else if(input == "check"){
            cin >> input2;
            int result = num&(1<<input2);
            if(result == 0) cout << 0 << "\n";
            else cout << 1 << "\n"; 
        }
        else if(input == "toggle"){
            cin >> input2;
            num = num^(1<<input2);
        }
        else if(input == "all"){
            num = INT_MAX;
        }
        else if(input == "empty"){
            num = 0;
        }
    }
    return 0;
}