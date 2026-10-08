#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node{
    double x,y;
};

int n;
vector<node> arr;

bool ok(double r){
    double l=-1e18,rr=1e18;
    for(int i=0;i<n;i++){
        double delta=2*arr[i].y*r-arr[i].y*arr[i].y;
        if(delta<0) return false;

        double d=sqrt(delta);
        l=max(l,arr[i].x-d);
        rr=min(rr,arr[i].x+d);
    }
    return l<=rr;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>n;
    arr.resize(n);

    bool pos=0,neg=0;
    for(auto &i:arr){
        cin>>i.x>>i.y;
        if(i.y>0) pos=1;
        if(i.y<0) neg=1;
    }

    if(pos&&neg){
        cout<<-1<<"\n";
        return 0;
    }

    for(auto &i:arr) i.y=abs(i.y);

    double l=0,r=1e15;
    for(auto &i:arr) l=max(l,i.y/2);

    for(int t=0;t<100;t++){
        double mid=l+(r-l)/2;
        if(ok(mid)) r=mid;
        else l=mid;
    }

    cout<<fixed<<setprecision(10)<<r<<"\n";
}