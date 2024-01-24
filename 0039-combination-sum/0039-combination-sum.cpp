class Solution {
    
public:
    
    vector<int> ds;
    vector<vector<int>> ans;

    
    void f(int i, vector<int> nums, vector<int> ds, int target){
        
        if(i==nums.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        
        if(target>=nums[i]){
            ds.push_back(nums[i]);
            f(i, nums, ds, target-nums[i]);
            ds.pop_back();
        }
        
        f(i+1, nums, ds, target);
        
    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    
        sort(nums.begin(), nums.end());
        f(0, nums, ds, target);
        return ans;
    }
};