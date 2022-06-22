import java.util.*;
public class Main
{
    public static int Bsearch(int []arr, int key, int s, int e)
    {
        if(s > e)                    return -1;
        
        int mid = s + (e-s) /2;
        if(arr[mid] == key)          
        {
            return mid;
        }
        else if(key < arr[mid])
        {
            return Bsearch(arr, key, s, mid-1);
        }
        
        return Bsearch(arr, key, mid+1, e);
        
    }
    
	public static void main(String[] args) 
	{
	    Scanner sc = new Scanner(System.in);
	    int n;
	    int key;
	    System.out.println("Enter the key value : ");
	    key = sc.nextInt();
		System.out.println("Enter the size of array");
		n = sc.nextInt();
		int []arr = new int[n];
		
		for(int i=0; i<n; i++)
		{
		    arr[i] = sc.nextInt();
		}
		
		int s = 0;
		int e = n-1;
	    int index = Bsearch(arr , key , s, e);
	    
	    System.out.println(key+" found at index "+index);
		
	}
}