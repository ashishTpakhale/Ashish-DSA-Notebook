class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int c=0,f=INT_MIN;
        int mx=0;
        for(auto &it:m){
            if(f!=INT_MIN && it.first==f+1){
                f=it.first;
                c++;
            }
            else {
                c=1;
            }
            mx=max(mx,c);
            f=it.first;
        }
        return mx;
    }
};
