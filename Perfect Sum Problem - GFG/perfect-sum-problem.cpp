// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    vector<vector<int>> dp;
    int mod=1e9+7;
	public:
	
	int helper(int arr[],int sum,int n)
	{
	    if(n==0)
	    {
	        if(sum==0)
	        return 1;
	        else
	        return 0;
	    }
	    if(dp[n][sum]!=-1)
	    return dp[n][sum];
	    
	    if(arr[n-1]>sum)
	    {
	        return dp[n][sum]=helper(arr,sum,n-1)%mod;
	    }
	    else
	    {
	        return dp[n][sum]=(helper(arr,sum,n-1)%mod+helper(arr,sum-arr[n-1],n-1)%mod)%mod;
	    }
	}
	
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        dp=vector<vector<int>>(n+1,vector<int>(sum+1,-1));
        return helper(arr,sum,n);
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends