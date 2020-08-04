//WA why? 
#include <bits/stdc++.h>

using namespace std;

int get_sum(int sum, vector<int>& b) {
    int ans = 0;
    while (sum > 0) {
        ans += b[sum];
        sum -= sum & (-sum);
    }
    return ans;
}
int solve(int index, int h_sum,int n,vector<int> &b,int pre) {
    int ans = pre;
    //update
    while (index <= n) {
        b[index]++;
        index += index & (-index); //lowbit(x)
    }
    //binary_search [pre,h_sum]
    int l = pre, r = h_sum;
    int mid = (l + r) / 2;
    int tmp = 0;
    while (l <= r) {
        tmp =h_sum - get_sum(mid-1, b);              //find # of paper_citation>mid
        if (tmp<mid) {
            r=mid-1;
        }
        else{
            l = mid+1;
            ans = mid > ans ? mid : ans;
        }
        mid = (l + r) / 2;
    }
    
    return ans;
}

int main() {
    int T;
    int iCase = 0;
    cin >> T;
    while (T--) {
        iCase++;
        int N;
        cin >> N;
        vector<int> a(N);
        int max_a = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            max_a = max_a > a[i] ? max_a : a[i];
        }
        /*
        while ((max_a << 1) != 0) {
            max_a += max_a & (-max_a);
        }*/
        vector<int> b(max_a + 1);
        for (int i = 0; i <= max_a; i++) {
            b[i] = 0;
        }
        int ans = 1,pre_ans=1;
        printf("Case #%d:", iCase);
        for (int i = 0; i < N; i++) {
            ans = solve(a[i], i+1, max_a, b, pre_ans);
            pre_ans = ans;
            printf(" %d",ans);
        }
        printf("\n");
    }
    return 0;
}
