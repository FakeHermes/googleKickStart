class Solution {
public:
    string decodeString(string s) {
        int num = 0;
    stack<int> numStack;
    stack<string> str;
    string res = "";
    string cur = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + s[i] - '0';
        }
        else if (s[i] == '[') {
            numStack.push(num);
            num = 0;
            str.push(cur);
            cur.clear();
        }
        else if (s[i] == ']') {
            num = numStack.top();
            numStack.pop();
            for (int j = 0; j < num; j++) {
                str.top()+=cur;
            }
            cur=str.top();
            str.pop();
            num = 0;
        }
        else {
            cur += s[i];
        }
    }
     return res+cur;   
    }
};