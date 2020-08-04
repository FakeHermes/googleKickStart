//392的后续挑战
//heap-buffer-overflow?

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ns=s.length(),nt=t.length();
        vector<vector<int>> a;
        vector<int> v={-1};
        for(int i=0;i<26;i++){
            a.push_back(v);
        }
        for(int i=0;i<nt;i++){
            a[t[i]-'a'].push_back(i);
        }
        int pre=-1;
        for(int i=0;i<ns;i++){
            int j=1,m=a[s[i]-'a'].size();
            while(a[s[i]-'a'][j]<=pre){
                j++;
                if(j==m) return false;
            }
            pre=a[s[i]-'a'][j];
        }
        return true;
    }
};