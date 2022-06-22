
import java.util.*;
public class Main
{
    void recrev(int n)
    {
        if(n==0) return;
        
        System.out.println(n+" ");
        recrev(n-1);
    }
	public static void main(String[] args)
	{
	    Scanner sc = new Scanner(System.in);
	    Main obj = new Main();
	    
	    System.out.println("Enter the Input :-");
	    int n=sc.nextInt();
	    
	    System.out.println("OUTPUT");
	    obj.recrev(n);
	}
}