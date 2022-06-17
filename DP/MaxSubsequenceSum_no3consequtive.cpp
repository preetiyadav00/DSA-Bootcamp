int maxSum(vector<int> &a, int n) 
{
    // Write your code here.
    vector<int>dp(n,0);
    if(n>=1)
        dp[0]=a[0];
    if(n>=2)
        dp[1]=a[0]+a[1];
    if(n>=3)
        dp[2]=max(a[0]+a[1],max(a[0]+a[2],a[2]+a[1]));

    for(int i=3;i<n;i++)
    {
        // we have 3 optns 
        // dp[i-1] -> exclude a[i]
        // dp[i-2]+a[i] -> exclude a[i-1]
        // dp[i-3]+a[i]+a[i-1] -> exclude a[i-2]

        dp[i]=max(dp[i-1],max(dp[i-2]+a[i],dp[i-3]+a[i]+a[i-1]));
    }
    return dp[n-1];
}



