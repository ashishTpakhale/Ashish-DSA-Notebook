class Solution {
public:
    struct chef_job{
        int start;
        int finish;
        int profit;
        
    };
    long long calculateMaxProfit(vector<int>& jobStartTimes,
                                 vector<int>& jobEndTimes,
                                 vector<int>& jobProfits)
    {
        vector<chef_job> job;
        for(int i=0;i<jobStartTimes.size();i++){
            job.push_back({jobStartTimes[i],jobEndTimes[i],jobProfits[i]});
        }
        sort(job.begin(),job.end(), [](const chef_job &x,chef_job &y){
            return x.start <y.start;
        });
        
        vector<int>v(job.size());
        vector<long long>dp1( jobProfits.size()+1,0);
        for(int i=0;i<jobProfits.size();i++){
            v[i]=job[i].start;
        }
        for(int i=job.size()-1;i>=0;i--){
            int c=std::lower_bound(v.begin(),v.end(),job[i].finish)-v.begin();
            long long x=job[i].profit+dp1[c];
            long long y=dp1[i+1];
            dp1[i]=max(x,y);
        }
        long long ans;
        ans =dp1[0];
        return ans;
        // write your code here 
        
    }
};
