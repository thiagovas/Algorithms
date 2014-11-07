import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;


public class Main {

	public static void main(String[] args) {
		ArrayList<Stack<Integer> > als = new ArrayList<Stack<Integer> >();		
		Scanner sc = new Scanner(System.in);
		
		for(int i = 0; i < 3; i++)
			als.add(new Stack<Integer>());
		
		System.out.print("Number of piles: ");
		int piles = sc.nextInt();
		
		for(int i = piles-1; i >= 0; i--)
			als.get(0).push(i);
		
		Hanoi(als, piles, 0, 1, 2);
		printTab(als);
		sc.close();
	}
	
	public static void Hanoi(ArrayList<Stack<Integer> > als, int n, int origin, int temp, int dest)
	{
		if(n == 1)
			move(als, origin, dest);
		else
		{
			Hanoi(als, n-1, origin, dest, temp);
			move(als, origin, dest);
			Hanoi(als, n-1, temp, origin, dest);
		}
	}
	
	public static void move(ArrayList<Stack<Integer> > als, int origin, int dest)
	{
		System.out.println("Moving pile from " + (origin+1) + " to " + (dest+1));
		if(!als.get(origin).empty())
			als.get(dest).add(als.get(origin).pop());
	}
	
	public static void printTab(ArrayList<Stack<Integer> > als)
	{
		for(int i = 0; i < 3; i++)
		{
			System.out.print((i+1));
			while(!als.get(i).empty())
				System.out.print(" " + als.get(i).pop());
			System.out.println("");
		}
	}
}
