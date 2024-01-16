#include<bits/stdc++.h>
class Solution {
public:
    string frequencySort(string s) {
    string ans;
    int n = s.length();
	priority_queue<pair<int,char>>pq;
	vector<int>hash(256,0);

	for(int i = 0;i < n;i++)hash[s[i]]++;

	for(int i =0;i<256;i++){
		if(hash[i]!= 0)
		pq.push(make_pair(hash[i],char(i)));
		
	}

	while(pq.size()>0){
		pair<int,char> p = pq.top();
		pq.pop();
		ans.insert(ans.end(),p.first,p.second);
	}
	
	return ans;
    }
};