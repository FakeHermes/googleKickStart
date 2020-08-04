class Solution {
public:
    static bool sortcol(const vector<int> &v1,const vector<int> &v2){
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),sortcol);
        int ans=0;
        int j=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=intervals[j][1]){
                j=i;
            }
            else{
                ans++;
            }
            
        }
        return ans;
    }
};