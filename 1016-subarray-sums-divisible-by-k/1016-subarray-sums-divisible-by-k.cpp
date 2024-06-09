class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
         vector<int> mp(k,0);
         mp[0]=1;
        int ans=0,sum=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=ans+mp[(sum%k+k)%k];
            mp[(sum%k+k)%k]++;
        }
        return ans;
    }
};