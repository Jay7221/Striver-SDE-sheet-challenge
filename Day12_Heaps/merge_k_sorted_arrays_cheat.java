import java.util.* ;
import java.io.*; 
import java.util.ArrayList;

public class Solution 
{
	public static ArrayList<Integer> mergeKSortedArrays(ArrayList<ArrayList<Integer>> kArrays, int k)
	{
		ArrayList<Integer> arr = new ArrayList<Integer>();
		for(ArrayList a : kArrays){
			arr.addAll(a);
		}
		Collections.sort(arr);
		return arr;
	}
}

