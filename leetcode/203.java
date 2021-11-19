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
    public ListNode removeElements(ListNode head, int val) {
        ListNode temp = null;
        ListNode cur = null;
        while(head!=null){
            if(head.val==val){
                head = head.next;
            }
            else{
                if(temp==null){
                    temp = new ListNode();
                    temp.val = head.val;
                    cur = temp;
                }
                else{
                    ListNode t = new ListNode();
                    t.val = head.val;
                    cur.next = t;
                    cur = t;
                }
                head = head.next;
            }
        }
        return temp;
    }
}