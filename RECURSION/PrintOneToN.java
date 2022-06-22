
import java.util.*;
public class Main
{
    void rec(int n)
    {
        if(n==0)
        {
            // System.out.println(1+" ");
            return;
        }
        
        rec(n-1);
        System.out.println(n+" ");
    }
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the input");
		
		int n = sc.nextInt();
		
		Main obj = new Main();
		obj.rec(n);
	}
}