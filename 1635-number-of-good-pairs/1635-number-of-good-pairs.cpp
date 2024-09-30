class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto i = nums.begin(); i != nums.end(); ++i) {
            m[*i]++;
        }
        
        int ans = 0;
        for(auto i = m.begin(); i != m.end(); ++i) {
            ans += i->second * (i->second - 1) / 2;
        }
        return ans;
    }
};