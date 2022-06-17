// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        sort(arr,arr+N);
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        if(sum%2)
            return 0;
        else 
            sum/=2;
        vector<vector<int>>dp(N+1,vector<int>(sum+1,0));
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j<arr[i-1])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else if(j==arr[i-1])
                {
                    dp[i][j]=j;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],arr[i-1]+dp[i-1][j-arr[i-1]]);
                    //include arr[i-1] ->arr[i-1]+dp[i-1][j-arr[i-1]]
                    //exclude arr[i-1] -> dp[i-1][j]
                }
            }
        }
        //cout<<sum<<endl;
        // for(int i=0;i<=N;i++)
        // {
        //     for(int j=0;j<=sum;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        if(dp[N][sum]==sum)
        return 1;
        else
        return 0;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends