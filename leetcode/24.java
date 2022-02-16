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
    public ListNode swapPairs(ListNode head) {
        ListNode first = head;
        ListNode second = null;
        if(head!=null){
            second = head.next;
        }
        while(first!=null && second!=null){
            int temp = first.val;
            first.val = second.val;
            second.val = temp;
            first = second.next;
            if(first!=null){
                second = first.next;
            }
            else{
                second = null;
            }
        }
        return head;
    }
}