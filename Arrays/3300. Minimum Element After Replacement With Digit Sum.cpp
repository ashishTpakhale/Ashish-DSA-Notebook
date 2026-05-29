//first solution..
class Solution {
public:
    int fun(string s){
        int c=0;
        for(int i=0;i<s.size();i++)
            c+=s[i]-'0';
        return c;
    }
    int minElement(vector<int>& nums) {
        int mi=1e4;
        for(int i=0;i<nums.size();i++){
            nums[i]=fun(to_string(nums[i]));
            mi=min(mi,nums[i]);
        }
        return mi;
    }
    //TC - O(n.d)=O(n)
    //SC - O(d)
};


//second solution..
class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn=37;
        for(int i=0;i<nums.size();i++){
            int c=0;
            while(nums[i]){
                c+=nums[i]%10;
                nums[i]/=10;
            }
            mn=min(mn,c);
        }
        return mn;
    }
    //TC - O(n.d)= O(n)
    //SC - O(1)
};
