#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &c:a) cin>>c;
    multiset<int> st;
    for(int i=0;i<k;i++){
        st.insert(a[i]);
    }
    auto mid=st.begin();
    advance(mid,k/2-(k%2==0));
    cout<<*mid<<" ";
    for(int i=k;i<n;i++){
        st.insert(a[i]);
        if(a[i]<*mid) mid--;
        if(a[i-k]<=*mid) mid++;
        st.erase(st.lower_bound(a[i-k]));
        cout<<*mid<<" ";
    }
}
