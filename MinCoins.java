import java.util.*;
import java.lang.*;
public class MinCoins {
	public static int minCoin(int coin[],int n,int amt)
	{
		Arrays.sort(coin);
		int res=0,c;
		for(int i=n-1;i>=0;i--)
		{
			if(coin[i]<=amt)
			{
				c=(int)Math.floor(amt/coin[i]);
				res=res+c;
				amt=amt-c*coin[i];
				
			}
			
		}
		return res;
	}
	public static void main(String args[])
	{
		int coin[]= {5,10,2,1};
		int n=4;
		int amount=57;
		System.out.println(minCoin(coin,n,amount));
	}

}
