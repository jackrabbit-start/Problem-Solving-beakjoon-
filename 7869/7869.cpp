#include <bits/stdc++.h>
using namespace std;
typedef long double lld;
# define MY_PI 3.14159265358979323846

pair<lld , lld> one;
pair<lld , lld> two;
lld r1, r2;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> one.first >> one.second >> r1 >> two.first >> two.second >> r2;
    lld distance = abs(pow(one.first - two.first,2)) + abs(pow(one.second - two.second,2));
    lld dis = sqrt(distance);
    //cout << distance << " " << r1 << " " << r2 << "\n";
    if(dis >= r1 + r2){
        cout<<fixed;
        cout.precision(3);
        cout << 0.000;
    }
    else if(abs(r1 - r2) >= dis){
        cout<<fixed;
        cout.precision(3);
        cout << pow(min(r1,r2),2)*MY_PI;
    }
    else if(pow(max(r1, r2),2) - pow(min(r1,r2),2) > distance){
        if(r1 > r2){
            swap(r1,r2);
        }
        lld cosine1 = pow(r1,2) + distance - pow(r2,2);
        cosine1 /= r1 * 2.0 * sqrt(distance);
        lld cosine2 = pow(r2,2) + distance - pow(r1,2);
        cosine2 /= r2 * 2.0 * sqrt(distance);
        lld angle1 = acos(cosine1);
        lld angle2 = acos(cosine2);
        angle1 *= 2;
        angle2 *= 2;
        lld plane1 = (pow(r1,2) / 2.0) * angle1 + (pow(r1,2) * sin(2.00000000*MY_PI-angle1))/2; 
        lld plane2 = ((pow(r2,2) / 2.0) * angle2) - ((pow(r2,2) * sin(angle2))/2); 
        cout<<fixed;
        cout.precision(3);
        cout << plane1 + plane2;
    }
    else{
        lld cosine1 = pow(r1,2) + distance - pow(r2,2);
        cosine1 /= r1 * 2.0 * dis;
        lld cosine2 = pow(r2,2) + distance - pow(r1,2);
        cosine2 /= r2 * 2.0 * dis;
        lld angle1 = acos(cosine1);
        lld angle2 = acos(cosine2);
        angle1 *= 2;
        angle2 *= 2;
        lld plane1 = (pow(r1,2) / 2.0) * angle1 - (pow(r1,2) * sin(angle1))/2; 
        lld plane2 = (pow(r2,2) / 2.0) * angle2 - (pow(r2,2) * sin(angle2))/2; 
        cout<<fixed;
        cout.precision(3);
        cout << plane1 + plane2;
    }
    

    return 0;
}