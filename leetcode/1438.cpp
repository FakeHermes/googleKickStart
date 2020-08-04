class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        //two pointers
        map<int,int> m;
        int ans=1;
        int j=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            while(m.rbegin()->first-m.begin()->first>limit){
                m[nums[j]]--;
                if(m[nums[j]]==0){
                    m.erase(nums[j]);
                }
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;

    }
};