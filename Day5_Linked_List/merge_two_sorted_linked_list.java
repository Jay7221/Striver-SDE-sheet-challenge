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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode list = null;
        if((list1 == null) && (list2 == null)){
            return list;
        }
        if(list1 == null){
            list = list2;
            list2 = list2.next;
        }else if(list2 == null){
            list = list1;
            list1 = list1.next;
        }else if(list1.val < list2.val){
            list = list1;
            list1 = list1.next;
        }else{
            list = list2;
            list2 = list2.next;
        }
        ListNode head = list;
        while((list1 != null) || (list2 != null)){
            if(list1 == null){
                list.next = list2;
                list2 = list2.next;
            }else if(list2 == null){
                list.next = list1;
                list1 = list1.next;
            }else if(list1.val < list2.val){
                list.next = list1;
                list1 = list1.next;
            }else{
                list.next = list2;
                list2 = list2.next;
            }
            list = list.next;
        }
        return head;
    }
}
