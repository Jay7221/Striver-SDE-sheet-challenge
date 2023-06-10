/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null){
            return head;
        }
        Node newHead = new Node(head.val);
        Node cur = head.next, newCur = newHead;
        while(cur != null){
            newCur.next = new Node(cur.val);
            cur = cur.next;
            newCur = newCur.next;
        }
        newCur = newHead;
        int n = 0;
        while(newCur != null){
            ++n;
            newCur = newCur.next;
        }
        cur = head;
        newCur = newHead;
        while(cur != null){
            Node tmp = cur.random;
            int i = 0;
            while(tmp != null){
                ++i;
                tmp = tmp.next;
            }
            i = n - i;
            tmp = newHead;
            while(i-- > 0){
                tmp = tmp.next;
            }
            newCur.random = tmp;
            cur = cur.next;
            newCur = newCur.next;
        }
        return newHead;
    }
}
