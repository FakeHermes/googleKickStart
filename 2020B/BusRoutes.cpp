//这样的旅行是为了啥
//某些教训让我觉得cout<<比printf好

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll solve(vector<ll> h, int n,ll d) {
    for (int i = n-1; i >=0; i--) {

        if(d % h[i] != 0) {
            ll l = 0, r = d/h[i];
            while (l < r) {
                ll mid = (l + r) / 2;
                if (mid * h[i] < d) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            if (l * h[i] < d) {
                d = l * h[i];
            }
            else {
                d = (l - 1) * h[i];
            }
        }
        
        
    }
    return d;
}
int main() {
    int t;
    int icase = 0;
    cin >> t;
    while (t--) {
        icase++;
        int n;
        ll d;
        cin >> n>>d;
        vector<ll> x(n);
        
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
      
        ll res = solve(x,n,d);
        //printf("Case #%d: %lld\n", icase, res);
		cout << "Case #" << icase << ": "<<res;

    }
    

     return 0;
}



