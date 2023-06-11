
import java.util.* ;
import java.io.*; 
public class Solution
{
public static int findMinimumCoins(int amount)
    {
        int ans = 0;
        int coins[] = new int[]{1000, 500, 100, 50, 20, 10, 5, 2, 1};
        for(int c : coins){
            ans += amount / c;
            amount %= c;
        }
        return ans;
    }
}
