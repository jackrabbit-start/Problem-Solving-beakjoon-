#include <bits/stdc++.h>
using namespace std;


int ans;
int recursion(const char *s, int l, int r){
    ans++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}
int T;
char arr[10000];
int main(){  
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T; 
    for(int i = 0 ; i < T; i++){
        cin >> arr;
        ans = 0;
        cout << isPalindrome(arr) << " " << ans << "\n";
    }

    return 0;
}