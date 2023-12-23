
#include <bits/stdc++.h>
using namespace std;
void f(vector<long long>&nums,vector<long long>&v,int r,int i,long long sum){
        if(i>r){
        v.push_back(sum);
            return;
        }
        f(nums,v,r,i+1,sum+nums[i]);
        f(nums,v,r,i+1,sum);
    }
    int minAbsDifference(vector<long long>& nums, long long goal) {
        int n=nums.size();
        vector<long long>v1,v2;
        f(nums,v1,n/2,0,0); //recursion 20-> 2^20 for storing all first half subsequence sums
        f(nums,v2,n-1,n/2+1,0); //recursion 20-> 2^20 for storing all second half subsequence sums
        sort(v2.begin(),v2.end());
        long long ans=LLONG_MAX;
        int a=v1.size(),b=v2.size();
        for(int i=0;i<a;i++){
            int ind=lower_bound(v2.begin(),v2.end(),goal-v1[i])-v2.begin();
            if(ind<b)
                ans=min(ans,abs(v1[i]+v2[ind]-goal));
            if(ind-1>=0)
                ans=min(ans,abs(v1[i]+v2[ind-1]-goal));
            if(ind+1<b)
                ans=min(ans,abs(v1[i]+v2[ind+1]-goal));
        }
        return ans;
        

    }
int main()
{
    int n;
    cin>>n;
    vector<long long int>v(n);
    for(auto &it:v)cin>>it;
    long long int goal;
    cin>>goal;
    cout<<minAbsDifference(v,goal)<<endl;

    return 0;
}
