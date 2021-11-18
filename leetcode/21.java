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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = null;
        ListNode cur = null;
        while(l1!=null && l2!=null){
            if(head==null){
                head = new ListNode();
                if(l1.val<=l2.val){
                    head.val = l1.val;
                    cur = head;
                    l1 = l1.next;
                }
                else{
                    head.val = l2.val;
                    cur = head;
                    l2 = l2.next;
                }
            }
            else{
                ListNode temp = new ListNode();
                if(l1.val<=l2.val){
                    temp.val = l1.val;
                    l1 = l1.next;
                }
                else{
                    temp.val = l2.val;
                    l2 = l2.next;
                }
                cur.next = temp;
                cur = temp;
            }
        }
        while(l1!=null){
            if(head==null){
                head = new ListNode();
                head.val = l1.val;
                cur = head;
            }
            else{
                ListNode temp = new ListNode();
                temp.val = l1.val;
                cur.next = temp;
                cur = temp;
            }
            l1 = l1.next;
        }
        while(l2!=null){
            if(head==null){
                head = new ListNode();
                head.val = l2.val;
                cur = head;
            }
            else{
                ListNode temp = new ListNode();
                temp.val = l2.val;
                cur.next = temp;
                cur = temp;
            }
            l2 = l2.next;
        }
        return head;
    }
}