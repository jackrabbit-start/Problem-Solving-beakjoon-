#include <bits/stdc++.h>
using namespace std;

int L;
string s;
int pi[1000005];
void getpi(string a){
    int al = a.size();
    int j=0;
    for(int i = 1; i < a.size(); i++){
        while(j > 0 && a[i] != a[j]) j = pi[j-1];
        if(a[i] == a[j]) j++;
        pi[i] = j;
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> L;
    cin >> s;
    getpi(s);
    int ans = 0;
    cout << L-pi[L-1];
    return 0;
}