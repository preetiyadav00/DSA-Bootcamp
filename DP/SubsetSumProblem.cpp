// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        dp[0][0]=1;
        //for all j->0 dp will be 1
        // beacause agr sum 0 hai to there is always 1 way to form the subset
        // i.e. {} empty subset
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j==0)
                {
                    dp[i][j]=1;
                    continue;
                }
                if(arr[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                    //isme j==arr[i-1] wala cover hojaega because jtj index 0 ho
                    //jaegai and dp[i][0]=1
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=sum;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][sum];
        
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends