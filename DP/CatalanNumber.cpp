// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++




class Solution
{
    public:
    //Function to find the nth catalan number.
    
    cpp_int findCatalan(int n) 
    {
        vector<cpp_int>dp(n+1);
        dp[0]=1,dp[1]=1;

        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i]+=dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends


//Recursive memoization [tle]
// int Cat(int n,vector<int>& mem) {
//     if(n<=0)
//     {
//         mem[n]=1;
//         return 1;
//     }
//     int ans=0,term1=0,term2=0;
//     for(int i=0;i<n;i++)
//     {
//         if(mem[i]!=-1)
//             term1=mem[i];
//         else
//             term1=Cat(i,mem);
//         if(mem[n-1-i]!=-1)
//             term2=mem[n-1-i];
//         else
//             term2=Cat(n-1-i,mem);
//         ans+=term1*term2;
        
//     }
//     return ans;
// }
// vector<int>mem(n,-1);