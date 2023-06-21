import java.util.* ;
import java.io.*; 

public class Solution {

    // minHeap function which take size of Queries and Queries as Input.
// Returns an array out outputs depending on the quer

    static int arr[];
    static int len = 0;
    static void add(int x){
        ++len;
        int ind = len;
        arr[ind] = x;
        while(ind > 1){
            int par = ind / 2;
            if(arr[par] > arr[ind]){
                int tmp = arr[par];
                arr[par] = arr[ind];
                arr[ind] = tmp;
            }
            ind /= 2;
        }
        
        // System.out.println("add " + x);
        // for(int i = 1; i <= len; ++i){
        //     System.out.print(arr[i] + " ");
        // }
        // System.out.println();
    }
    static int pop(){
        int ans = arr[1];
        int ind = 1;
        arr[ind] = arr[len];
        --len;
        while((2 * ind) <= len){
            int l = 2 * ind;
            int r = 2 * ind + 1;
            if((r <= len) && (arr[r] < arr[l])){
                l = r;
            }
            if(arr[ind] < arr[l]){
                break;
            }
            int tmp = arr[ind];
            arr[ind] = arr[l];
            arr[l] = tmp;
            ind = l;
        }
        // System.out.println("pop " + ans);
        // for(int i = 1; i <= len; ++i){
        //     System.out.print(arr[i] + " ");
        // }
        // System.out.println();
        return ans;
    }
    static int[] minHeap(int n, int[][] q) {
        arr = new int[n + 1];
        len = 0;
        int m = 0;
        for(int i = 0; i < n; ++i){
            if(q[i][0] == 1){
                ++m;
            }
        }
        int j = 0;
        int sol[] = new int[m];
        for(int i = 0; i < n; ++i){
            if(q[i][0] == 0){
                add(q[i][1]);
            }else{
                sol[j] = pop();
                ++j;
            }
        }
        return sol;
    }
}
