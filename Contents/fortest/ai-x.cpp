#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<double> arr;

double check(double val){
    double cur_ma=0,ma=0;
    double cur_mi=0,mi=0;

    for(int i=0;i<n;i++){
        double v=arr[i]-val;
        cur_ma=max(0.0,cur_ma+v);
        ma=max(ma,cur_ma);

        cur_mi=min(0.0,cur_mi+v);
        mi=min(mi,cur_mi);
    }

    return max(ma,-mi);
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    arr.resize(n);
    for(auto &i:arr) cin>>i;
    double l=-10000,r=10000;
    int t=100;
    while(t--){
        double ml=l+(r-l)/3;
        double mr=r-(r-l)/3;
        if(check(ml)<check(mr)) r=mr;
        else l=ml;
    }
    cout<<fixed<<setprecision(8)<<check(l)<<"\n";
}