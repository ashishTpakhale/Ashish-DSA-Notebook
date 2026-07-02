class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prod=1;
        int n=nums.size();
        if(n<=1)return nums;
        vector<int>pref_prod(n); 
        vector<int>suff_prod(n);
      
        pref_prod[0]=nums[0];
        for(int i=1;i<n;i++){
            pref_prod[i]=pref_prod[i-1]*nums[i];
        }
        suff_prod[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff_prod[i]=suff_prod[i+1]*nums[i];
        } 
      
        nums[0]=suff_prod[1];
        nums[n-1]=pref_prod[n-2];
        for(int i=1;i<n-1;i++){
            nums[i]=pref_prod[i-1]*suff_prod[i+1];
        }
        return nums;
    }
};
