class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<char> str;
        stack<int> num;
        str.push(s[0]);
        num.push(1);
        for(int i=1;i<s.size();i++){
            if(!str.empty() && s[i]==str.top()){
                num.top()++;
                if(num.top()==k){
                    num.pop();
                    str.pop();
                }
            }
            else{
                str.push(s[i]);
                num.push(1);
            }
        }
        string res;
        while(!str.empty()){
            for(int i=0;i<num.top();i++){
                res+=str.top();
            }
            str.pop();
            num.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};