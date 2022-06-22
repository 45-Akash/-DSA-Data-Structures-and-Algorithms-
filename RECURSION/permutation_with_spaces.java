import java.util.Scanner;
public class Main
{
    public static void solve(String ip, String op, int ind, int size)
    {
        if(ind == size)
        {
            System.out.println(op);
            return;
        }
        
        String op1 = op;
        String op2 = op;
        
        op1 += " ";
        op1 += ip.charAt(ind);
        op2 += ip.charAt(ind);
        
        
        solve(ip, op1, ind+1, size);
        solve(ip, op2, ind+1, size);
        return;
    }
	public static void main(String[] args)
	{
	    Scanner sc = new Scanner(System.in);
	    String input = sc.nextLine();
	    String output ="";
	    int size = input.length();
	   
	    output += input.charAt(0);
	    solve(input, output, 1, size);
  
	}
}