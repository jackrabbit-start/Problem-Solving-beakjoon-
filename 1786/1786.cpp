#include <bits/stdc++.h>
using namespace std;
int N;
string T;
string P;
int pi[1000005];
int ans;
vector<int> answer;
void getpi(string s){
    int sl = s.size();
    int j = 0;
    for(int i = 1 ; i < sl ; i++){
        while(j > 0 && s[i] != s[j]){
            j = pi[j];
        }
        if(s[i] == s[j]) j++;
        pi[i+1] = j;
    }
}

int KMPalgo(string a, string b){
    int al = a.size();
    int bl = b.size();
    int j = 0;
    for(int i = 0 ; i < al;i++){
        while(j > 0 &&a[i] != b[j]) j = pi[j];
        if(a[i] == b[j]) j++;
        if(j==bl){ans++; answer.push_back(i-bl+2);}
    }
    return ans;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    getline(cin, T);
    getline(cin,P);
    getpi(P);
    KMPalgo(T, P);
    cout << ans << "\n";
    for(int i = 0 ; i < ans; i++){
        cout << answer[i] << " ";
    }
    return 0;
}