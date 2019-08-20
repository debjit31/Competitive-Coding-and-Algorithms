import java.util.*;
import java.io.*;
public class Anagrams
{
	private String s1;
	private String s2;
	public Anagrams(String s1, String s2)
	{
		this.s1 = s1;
		this.s2 = s2;
		
	}
	public void anagramCheck()
	{
		String str1 = s1.replace("\\s", "");
		String str2 = s2.replace("\\s", "");
		boolean status = true;
		if(str1.length()!= str2.length())
		{
			status = false;
		}
		else{
			
			char ArrayS1[] = s1.toLowerCase().toCharArray();
			char ArrayS2[] = s2.toLowerCase().toCharArray();
			
			Arrays.sort(ArrayS1);
			Arrays.sort(ArrayS2);
			
			status = Arrays.equals(ArrayS1,ArrayS2);
			if(status)
				System.out.println("Anagrams");
			else
				System.out.println("Not Anagrams");
		}
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the first String :- ");
		String s1 = sc.next();
		System.out.println("Enter the second String :- ");
		String s2 = sc.next();
		Anagrams ana = new Anagrams(s1,s2);
		ana.anagramCheck();
	}
}
