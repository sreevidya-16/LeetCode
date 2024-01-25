class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<int> prev(m+1,0) , cur(m+1,0);
        
        // for(int j = 0;j<=m;j++) dp[0][j] = 0;
        // for(int i = 0;i<=n;i++) dp[i][0] = 0;
        
        // base not req since i have already fille it with 0
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1])
                    cur[j] = 1 + prev[j-1];
                
                else
                    cur[j] = max(prev[j] , cur[j-1]);
            }
            prev = cur;
        }
        return prev[m];
    }
};