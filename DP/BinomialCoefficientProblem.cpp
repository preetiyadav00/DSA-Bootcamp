// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    //  int ncr(int n,int r, vector<vector<int>>& mem)
    // {
    //      int mod=1e9 + 7;
    //     if(r<0 || n<0)
    //         {
    //             mem[n][r]=0;
    //             return 0;
    //         }
    //     if(r==0 || r==n) 
    //     {
    //         mem[n][r]=1;
    //         return 1;
            
    //     } //only 1 way to select
    //     if(n<r)
    //     {
    //         return 0;
            
    //     } //not possible
        
    //     if(mem[n][r]!=-1)    //if value is already not computed
    //     {
    //         return mem[n][r]%mod;    //ssp tree has alredy computed this value
    //     }
    //     else
    //         mem[n][r] =  ((ncr(n-1,r-1,mem))%mod +  (ncr(n-1,r,mem))%mod)%mod;    //nCr= n-1Cr-1 + n-1Cr
        
    //     return mem[n][r]%mod;
    // }
    int NCR(int n,int r,vector<vector<int>>&dp)
    {
        int mod=1e9 + 7;
        for(int i=0;i<=n;i++) //**n will start from 0 
        {
            dp[i][0]=1; //r->0 i.e. do not select any ele(only 1 way)
        }
        int include=0,exclude=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=r;j++)
            {
                include=dp[i-1][j-1]%mod;   //n-1Cr-1
                exclude=dp[i-1][j]%mod;     //n-1Cr
                dp[i][j]=(include+exclude)%mod;
            }
        }
        return dp[n][r];
    }
    
    int nCr(int n, int r){
        // code here
        //nCr= n-1Cr-1 + n-1Cr
        //n-1Cr-1 -> include curr item (subprblm -> select r-1 from remain n-1)
        //n-1Cr -> exclude curr item (subprblm-> select r from remain n-1 )
         //vector<vector<int>> mem(n+1,vector<int>(r+1,-1));  //memoization
         
         vector<vector<int>>dp(n+1,vector<int>(r+1,0));  //dp
        
         return NCR(n,r,dp);   
        //return ncr(n,r,mem);
            
    }
    //o(n*r)
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends