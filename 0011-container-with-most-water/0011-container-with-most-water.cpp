class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0;
        int n = height.size();
        int l = 0;
        int r = n-1; 
        while(l<r){
            int curr = min(height[l], height[r]) * (r-l);
            maxi = max(curr, maxi);
        if(height[l] < height[r]) l++;
        else r--;
        }
         
        return maxi;
    }
    
};