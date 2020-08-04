class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;
        int curr=nums[0],mxend=nums[0],jump=0;
        for(int i=0;i<n-1;i++){
            mxend=max(mxend,i+nums[i]);
            if(curr==i){
                //must jump
                jump++;
                curr=mxend;
            }
        }
        jump++;
        return jump;
    }
};