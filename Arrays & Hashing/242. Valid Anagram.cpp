//Solution 1
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};

//Solution 2
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        vector<int>c(26,0);
        if(t.size()!=n)return false;
        for(int i=0;i<n;i++){
            c[s[i]-'a']++;
            c[t[i]-'a']--;
        }
        for(int x:c){
            if(x){
                return false;
            }
        }
        return true;
    }

};
