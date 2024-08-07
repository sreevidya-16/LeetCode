class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ones=0;
       int twos=0;
       for(int n:nums){
        ones ^=n &(~twos);
        twos ^=n &(~ones);
       } 
       return ones;
    }
};