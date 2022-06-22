import java.util.*;

public class Main
{
    private static int countSubsets(int arr[], int dp[][], int n, int sum)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else 
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    return dp[n][sum];
    }
    
	public static void main(String[] args)
	{
	    Scanner sc = new Scanner(System.in);
	    
	    System.out.print("Enter the size of array :- ");
	    int n = sc.nextInt();
	    
	    System.out.print("Enter the Difference between two sets :- ");
	    int diff = sc.nextInt();
	    
	    int[] arr = new int [n];
        int sumOfArray=0;
	    System.out.println("Enter the array Elements :- ");
	    for(int i=0; i<n; i++)
	    {
	        arr[i] = sc.nextInt();
	        sumOfArray += arr[i];
	    }
	    
	    int sum = (diff + sumOfArray)/2;        //key step
	    
	    int[][] dp = new int[n+1][sum+1];
	    //initialize the matrix
	    for(int i=0; i<=n; i++)
	    {
	        for(int j=0; j<=sum; j++)
	        {
	            if(i==0)     dp[i][j] = 0;
	            if(j==0)     dp[i][j] = 1;
	        }
	    }
	    
	    int ans = countSubsets(arr, dp, n, sum);
	    System.out.println("The number of subsets with difference "+diff+" is = "+ ans);
	}
}