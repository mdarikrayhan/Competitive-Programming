import java.util.*;
import java.lang.*;
import java.io.*;

public class Ideone
{
	static int n, m;
	static char[] st;
	
	
	public static boolean f(int x){
		
		int prev = 0;
		int k = m - 1;
		while (prev < n - 1) {

			int j = prev + x + 1;
			if (j >= n) {
				j = n - 1;
			}
			while (st[j] == '1' && j > prev) {
				j--;

			}
			if (prev == j) {
				return false;
			}
			prev = j;
			k--;
		}
		return k >= 0;
	}
	
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		st = sc.next().toCharArray();
		int l = -1;
		int r = n;
		while(r-  l > 1){
			int m  =r + l >> 1;
			if (!f(m)){
				l = m;
			}
			else{
				r = m;
			}
		}
		System.out.println(r);
	}
}