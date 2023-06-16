import java.io.*;
import java.util.*;
public class AggressiveCows{
    static boolean check(int x, int n, int c, int arr[]){
        int numCows = 1;
        int prev = arr[0];
        for(int i = 1; i < n; ++i){
            if(arr[i] >= x + prev){
                ++numCows;
                prev = arr[i];
            }
        }
        return (numCows >= c);
    }
    static int solve(int n, int c, int arr[]){
        Arrays.sort(arr);
        int lo = 0;
        int hi = 1000000000;
        while(lo < hi){
            int mid = (lo + hi + 1) / 2;
            if(check(mid, n, c, arr)){
                lo = mid;
            }else{
                hi = mid - 1;
            }
        }
        return lo;
    }
    public static void main(String args[]){
        int t;
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        for(int test = 0; test < t; ++test){
            int n = sc.nextInt();
            int c = sc.nextInt();
            int arr[] = new int[n];
            for(int i = 0; i < n; ++i){
                arr[i] = sc.nextInt();
            }
            System.out.println(solve(n, c, arr));
        }
    }
};
