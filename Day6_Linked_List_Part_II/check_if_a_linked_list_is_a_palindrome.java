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
    public boolean isPalindrome(ListNode head) {
        ListNode slow = head, fast = head;
        while((fast != null) && (fast.next != null)){
            fast = fast.next.next;
            slow = slow.next;
        }
        ListNode prev = null;
        ListNode mid = slow;
        while(slow != null){
            ListNode nextNode = slow.next;
            slow.next = prev;
            prev = slow;
            slow = nextNode;
        }
        ListNode head2 = prev;
        ListNode c1 = head, c2 = head2;
        while(c1 != mid){
            if(c1.val != c2.val){
                break;
            }
            c1 = c1.next;
            c2 = c2.next;
        }
        return ((c1 == mid) && ((c2 == null) || (c2.next == null)));
    }
}
