class Solution {
public:
    int getEnd(string &s){
        int j=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                j--;
                if(j<0){j=0;}
            }
            else{
                swap(s[i],s[j]);
                j++;
            }
        }
        return j;
    }
    bool backspaceCompare(string S, string T) {
        int js=getEnd(S),jt=getEnd(T);
        if(js==0 || jt==0){
            if(js==0 && jt==0){
                return true;
            }
            return false;
        }
        if(js==jt){
            return S.compare(0,js,T,0,jt)==0;
        }
        return false;
    }
};