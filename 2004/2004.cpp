#include <bits/stdc++.h>
using namespace std;
long long int n;
long long int m;
long long int n_2;
long long int m_2;
long long int n_5;
long long int m_5;
long long int k_2;
long long int k_5;
long long int ans[3][2];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n >> m;
    n_2 = n;
    n_5 = n;
    m_2 = m;
    m_5 = m;
    k_2 = n-m;
    k_5 = n-m;
    while(n_2>1){
        ans[0][0] += n_2/2;
        n_2/=2;
    }
    while(n_5>1){
        ans[0][1] += n_5/5;
        n_5/=5;
    }
    while(m_2>1){
        ans[1][0] += m_2/2;
        m_2/=2;
    }
    while(m_5>1){
        ans[1][1] += m_5/5;
        m_5/=5;
    }
    while(k_2>1){
        ans[2][0] += k_2/2;
        k_2/=2;
    }
    while(k_5>1){
        ans[2][1] += k_5/5;
        k_5/=5;
    }
    long long int ans1 = ans[0][0] - ans[1][0]- ans[2][0];
    long long int ans2 = ans[0][1] - ans[1][1]- ans[2][1];
    cout << min(ans1, ans2);
    
    return 0;
}