class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<string> c(n,string(26,'0'));
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<n;i++){
            for(int ch:strs[i])c[i][ch-'a']++;
            mp[c[i]].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
