// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int>dp(n);
       dp[0]=1;
       int ans=1;
       for(int i=1;i<n;i++)
       {
           int num=-1;
           for(int j=0;j<i;j++)
           {
               if(a[j]<a[i])
               {
                   num=max(num,dp[j]);
               }
           }
           if(num==-1)
           dp[i]=1;
           else
           dp[i]=num+1;
           
           ans=max(ans,dp[i]);
       }
       return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends