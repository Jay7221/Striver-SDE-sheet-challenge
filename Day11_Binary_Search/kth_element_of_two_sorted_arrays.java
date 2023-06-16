//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main(String[] args) throws IOException
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0)
        {
            StringTokenizer stt = new StringTokenizer(br.readLine());
            
            int n = Integer.parseInt(stt.nextToken());
            int m = Integer.parseInt(stt.nextToken());
            int k = Integer.parseInt(stt.nextToken());
            int a[] = new int[(int)(n)];
            int b[] = new int[(int)(m)];
            
            
            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(inputLine[i]);
            }
            String inputLine1[] = br.readLine().trim().split(" ");
            for (int i = 0; i < m; i++) {
                b[i] = Integer.parseInt(inputLine1[i]);
            }
            
            
            Solution obj = new Solution();
            System.out.println(obj.kthElement( a, b, n, m, k));
            
        }
	}
}

// } Driver Code Ends


//User function Template for Java


class Solution {
    int get(int x, int arr[]){
        if(arr.length == 0){
            return 0;
        }
        if(arr[0] > x){
            return 0;
        }
        // we wish to find largest i, such that arr[i] <= x
        int l = 0, r = arr.length - 1;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(arr[mid] > x){
                r = mid - 1;
            }else{
                l = mid;
            }
        }
        return (l + 1);
    }
    public long kthElement( int arr1[], int arr2[], int n, int m, int k) {
        // kth element => k - 1 elements before it
        // find the smallest element that has k - 1 elements less than it in arr1 and arr2
        int l = 0;
        int r = Integer.MAX_VALUE;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(get(mid, arr1) + get(mid, arr2) >= k){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
}
