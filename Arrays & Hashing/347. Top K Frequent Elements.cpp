class Solution {
public:
    static bool comp(const pair<int,int>m1,const pair<int,int>m2){
        return m1.second >m2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<pair<int,int>>mp(m.begin(),m.end());
        vector<int>v;
        sort(mp.begin(),mp.end(),comp);
        for(auto it:mp){
            if(k<=0)break;
            v.push_back(it.first);
            k--;
        }
        return v;
    }
};
