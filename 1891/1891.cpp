#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N;
vector<ll> arr;
ll R;
vector<ll> r;
vector<ll> u;
ll U;
ll a, b;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(ll i = 1; i <= N ; i++){
        char input;
        cin >> input;
        arr.push_back(input-'0');
    }
    cin >> R >> U;
    if(R<0) {R *= -1; a= 1;}
    if(U<0) {U *= -1; b = 1;}
    while(R){
        r.push_back(R%2);
        R/=2;
    }
    while(U){
        u.push_back(U%2);
        U/=2;
    }
    ll isok = 0;
    ll tmp = 0;
    ll tmp2 = 0;
    for(ll i = arr.size()-1 ;i >= 0; i--){
        if(a==0&&tmp){
            if(arr[i] == 4){
                arr[i] = 3;
            }
            else if(arr[i] == 3){
                arr[i] = 4;
                tmp--;
            }
            else if(arr[i] == 2){
                arr[i] = 1;
                tmp--;
            }
            else if(arr[i] == 1){
                arr[i] = 2;
            }
        }
        if(a==1&&tmp2){
            if(arr[i] == 4){
                arr[i] = 3;
                tmp2--;
            }
            else if(arr[i] == 3){
                arr[i] = 4;
            }
            else if(arr[i] == 2){
                arr[i] = 1;
            }
            else if(arr[i] == 1){
                arr[i] = 2;
                tmp2--;
            }
        }
        if(arr.size()-i-1 >= r.size()) continue;
        if(r[arr.size()-i-1] == 0) continue;
        if(arr[i] == 4){
            arr[i] = 3;
            tmp++;
        }
        else if(arr[i] == 3){
            arr[i] = 4;
            tmp2++;
        }
        else if(arr[i] == 2){
            arr[i] = 1;
            tmp2++;
        }
        else if(arr[i] == 1){
            arr[i] = 2;
            tmp++;
        }
    }

    if(a==1){
        if(tmp2 != 0) isok = 1;
    }
    else{
        if(tmp != 0) isok = 1;
    }
    
    
    tmp = 0;
    tmp2= 0;
    for(ll i = arr.size()-1 ;i >= 0; i--){
        if(b==0&&tmp){
            if(arr[i] == 4){
                arr[i] = 1;
                tmp--;
            }
            else if(arr[i] == 3){
                arr[i] = 2;
                tmp--;
            }
            else if(arr[i] == 2){
                arr[i] = 3;
            }
            else if(arr[i] == 1){
                arr[i] = 4;
            }
        }
        if(b==1&&tmp2){
            if(arr[i] == 4){
                arr[i] = 1;
            }
            else if(arr[i] == 3){
                arr[i] = 2;
            }
            else if(arr[i] == 2){
                arr[i] = 3;
                tmp2--;
            }
            else if(arr[i] == 1){
                arr[i] = 4;
                tmp2--;
            }
        }
        if(arr.size()-i-1 >= u.size()) continue;
        if(u[arr.size()-i-1] == 0) continue;
        if(arr[i] == 4){
            arr[i] = 1;
            tmp2++;
        }
        else if(arr[i] == 3){
            arr[i] = 2;
            tmp2++;
        }
        else if(arr[i] == 2){
            arr[i] = 3;
            tmp++;
        }
        else if(arr[i] == 1){
            arr[i] = 4;
            tmp++;
        }
    }
    
    if(b==1){
        if(tmp2 != 0) isok = 1;
    }
    else{
        if(tmp != 0) isok = 1;
    }

    if(isok || arr.size() < u.size() || arr.size() < r.size()) cout << "-1\n";
    else{
        for(ll i = 0 ; i < arr.size(); i++){
            cout << arr[i];
        }
        cout <<"\n";
    }
    return 0;
}