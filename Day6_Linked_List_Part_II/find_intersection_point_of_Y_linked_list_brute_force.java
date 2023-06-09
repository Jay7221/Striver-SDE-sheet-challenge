/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode a = headA, b = headB;
        int la = 0, lb = 0;
        while(a != null){
            ++la;
            a = a.next;
        }
        while(b != null){
            ++lb;
            b = b.next;
        }
        a = headA;
        b = headB;
        while(la > lb){
            --la;
            a = a.next;
        }
        while(la < lb){
            --lb;
            b = b.next;
        }
        while(a != b){
            a = a.next;
            b = b.next;
        }
        return a;
    }
}
