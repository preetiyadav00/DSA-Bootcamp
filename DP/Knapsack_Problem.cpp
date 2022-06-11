// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<pair<int,int>>vp;
       for(int i=0;i<n;i++)
       {
           vp.push_back({wt[i],val[i]});
       }
       //sort(vp.begin(),vp.end());
       int dp[n+1][W+1];
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=W;j++)
           {
               if(i==0 || j==0)
               {dp[i][j]=0;}
           }
       }
       int include=0,exclude=0;
       for(int i=1;i<=n;i++)    //items
       {
           for(int j=1;j<=W;j++)    //wt(1...wt)    //curr cpcity
           {
               if(vp[i-1].first>j)   //wt[i] > wt
               {dp[i][j]=dp[i-1][j];}   //same as upr col
               else
               {
                   exclude=dp[i-1][j];  //ex ith item
                   if(vp[i-1].first<=j) //if wt of curr bag i.e wt[i-1] <= cpcity
                   include=dp[i-1][j-(vp[i-1].first)] + vp[i-1].second; //profit of curr+remaining wt ka sol
                   else
                   include= vp[i-1].second;
                   dp[i][j]=max(exclude,include);
               }
           }
       }
       return dp[n][W];
    }
    
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends