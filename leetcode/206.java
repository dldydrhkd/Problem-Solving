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
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode cur = null;
        while(head!=null){
            if(cur==null){
                ListNode temp = new ListNode();
                temp.val = head.val;
                cur = temp;
            }
            else{
                prev = cur;
                ListNode temp = new ListNode();
                temp.val = head.val;
                temp.next = prev;
                cur = temp;
            }
            head = head.next;
        }
        return cur;
    }
}