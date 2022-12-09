#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string arr1;
string arr2;
int ans[200001] = {0,};

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> arr1;
    cin >> arr2;
    int size = max(arr1.length(), arr2.length());

    int up = 0;
    for(int i = arr1.length()-1, j = arr2.length()-1; (i >= 0 || j >= 0 ); i--, j--){
        int tmp;
        if(i < 0) tmp =(arr2[j]-'0');
        else if(j < 0) tmp = (arr1[i]- '0');
        else tmp = (arr1[i]- '0') + (arr2[j]-'0');
        tmp += up;
        ans[size] = (tmp%10);
        //printf("%d %d\n", ans[size], tmp);
        size--;
        if(tmp < 10) up = 0;
        else up = 1;
    }


    if(up == 1)printf("1");
    size = max(arr1.length(), arr2.length());
    for(int i = 1; i<=size; i++){
        printf("%d",ans[i]);
    }
    printf("\n");
   
    return 0;
}