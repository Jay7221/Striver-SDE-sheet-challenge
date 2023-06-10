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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null){
            return head;
        }
        int n = 0;
        ListNode tmp = head;
        while(tmp != null){
            ++n;
            tmp = tmp.next;
        }
        k %= n;
        k = n - k;
        ListNode head2 = head;
        for(int i = 0; i < k; ++i){
            head2 = (head2.next == null) ? head : head2.next;
        }
        ListNode cur = head2;
        while(cur.next != null){
            cur = cur.next;
        }
        cur.next = head;
        while(cur.next != head2){
            cur = cur.next;
        }
        cur.next = null;
        return head2;
    }
}
