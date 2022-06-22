import java.util.*;
public class Main
{
    public static void solve(int n, int s, int d, int h)
    {
        if(n == 1)
        {
            System.out.println("Moving Disc "+n+" from "+s+" to "+d);
            return;
        }
        
        solve(n-1, s, h, d);
        System.out.println("Moving Disc "+n+" from "+s+" to "+d);
        solve(n-1, h, d, s);
        
        return;
    }
    
	public static void main(String[] args)
	{
	    Scanner sc = new Scanner(System.in);
	    
	    System.out.print("Enter the number of Disc :-");
	    int n = sc.nextInt();
	    
	    int s = 1;
	    int h = 2;
	    int d = 3;
	    
	    solve(n, s, d, h);
	}
}