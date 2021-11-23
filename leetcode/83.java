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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode pre = null;
        ListNode start = null;
        while(head!=null){
            if(pre==null){
                ListNode temp = new ListNode(head.val);
                pre = temp;
                start = temp;
            }
            else{
                if(pre.val!=head.val){
                    ListNode temp = new ListNode(head.val);
                    pre.next = temp;
                    pre = temp;
                }
            }
            head = head.next;
        }
        return start;
    }
}