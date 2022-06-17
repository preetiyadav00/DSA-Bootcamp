// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
    int first;
    int second;
};



int maxChainLen(struct val p[],int n);
int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        val p[n];
        for(int i=0;i<n;i++)
        {
            cin>>p[i].first>>p[i].second;
        }
        
        cout<<maxChainLen(p,n)<<endl;
    }
    return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
    int first;
    int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
//Your code here
    vector<pair<int,int>>vp(n);
    for(int i=0;i<n;i++)
    {
        vp[i].first=p[i].first;
        vp[i].second=p[i].second;
    }
    sort(vp.begin(),vp.end());    //vvvvvimp (given order is not comp)
    vector<int>dp(n,0);
    int ans=1;
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        int num=-1;
        for(int j=0;j<i;j++)
        {
            if(vp[j].second < vp[i].first)
                num=max(num,dp[j]);
        }
        if(num==-1)
        dp[i]=1;
        else
        dp[i]=1+num;
        
        ans=max(ans,dp[i]);
    }
    return ans;
}