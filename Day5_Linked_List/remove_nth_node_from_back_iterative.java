/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int sz = 0;
        ListNode tmp = head;
        while(tmp != null){
            tmp = tmp.next;
            ++sz;
        }
        if(n == sz){
            return head.next;
        }
        n = sz - n;
        tmp = head;
        for(int i = 0; i < n - 1; ++i){
            tmp = tmp.next;
        }
        tmp.next = tmp.next.next;
        return head;
    }
}
