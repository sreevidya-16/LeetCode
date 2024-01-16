class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int a=strs.size();
        string x=strs[0],y=strs[a-1],ans="";
        for(int i=0;i<x.size();i++){
            if(x[i]==y[i]){
                ans+=x[i];
                }
                else break;
            
        }
        return ans;
        
    }
};