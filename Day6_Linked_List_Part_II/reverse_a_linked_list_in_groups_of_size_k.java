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
    public ListNode reverseKGroup(ListNode head, int k) {
        int cnt = 0;
        ListNode node = head;
        while((node != null) && (cnt < k)){
            ++cnt;
            node = node.next;
        }
        if(cnt < k){
            return head;
        }
        ListNode prevNode = null, curNode = head;
        for(int i = 0; i < k; ++i){
            ListNode nextNode = curNode.next;
            curNode.next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        head.next = reverseKGroup(curNode, k);
        return prevNode;
    }
}
