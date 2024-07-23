class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long diff = abs(sum - goal);
        return (diff + limit - 1) / limit; // Equivalent to ceil(diff / limit)
    }
};