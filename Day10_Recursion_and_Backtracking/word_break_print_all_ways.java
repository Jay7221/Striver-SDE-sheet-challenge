import java.util.* ;
import java.io.*; 
import java.util.ArrayList;

public class Solution {

	public static ArrayList<String> wordBreak(String s, ArrayList<String> dictionary) {
		ArrayList<String> ans = new ArrayList<String>();
		HashSet<String> tmp = new HashSet<>();
		StringBuilder sb = new StringBuilder();
		dfs(s, sb, dictionary, 0, tmp);
		for(String st : tmp){
			ans.add(st);
		}
		return ans;
	}
	static void dfs(String s, StringBuilder sb, ArrayList<String> dict, int index, HashSet<String> ans){
		for(String ss : dict){
			int k = ss.length();
			int n = s.length();
			if(index + k <= n){
				if(ss.equals(s.substring(index, index + k))){
					sb.append(ss + " ");
					if(index + k == n){
						ans.add(sb.toString());
					}else{
						dfs(s, sb, dict, index + k, ans);
					}
					sb.setLength(sb.length() - (k + 1));
				}
			}
		}
	}
}
