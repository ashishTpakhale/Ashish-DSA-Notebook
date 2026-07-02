//Solution 1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            int c=target-nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]==c)return {i,j};
            }
        }
        return {};
    }
};

//Solution 2
class Solution {
public:
    //optimizing using hash by trading space to improve TC ..reduce lookup of the remaining target near to O(1).. 'near to O(1)' coz if collision occurs then a lookup coud degenerate to O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int ,int>hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++){
            int c=target-nums[i];
            if(hash.find(c) != hash.end() && hash[c]!=i)return {i,hash[c]};
        }
        return {};
    }
};
