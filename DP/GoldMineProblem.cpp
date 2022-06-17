// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        
        int num;
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int j=m-1;j>=0;j--)
        {
            for(int i=0;i<n;i++)
            {
                    if(j==m-1)
                        dp[i][j]=M[i][j];
                    else
                    {
                    int num1=0,num2=0,num3=0;

                    if(j<m-1)
                    num1=dp[i][j+1];
                    if(i<n-1 && j<m-1)
                    num2=dp[i+1][j+1];
                    if(i>0 && j<m-1)
                    num3=dp[i-1][j+1];
                    
                    dp[i][j]=max(num1,max(num2,num3));
                    

                    dp[i][j]+=M[i][j];
                    }
                
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans=0;
        for(int i=0;i<n;i++)
        ans=max(ans,dp[i][0]);
         return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends