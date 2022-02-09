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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode li = null;
        ListNode answer = li;
        int up = 0;
        while(l1!=null || l2!=null){
            int first = 0;
            int second = 0;
            if(l1!=null){
                first = l1.val;
            }
            if(l2!=null){
                second = l2.val;
            }
            ListNode temp = new ListNode((first+second+up)%10);
            up = (first+up+second)/10;
            if(li==null){
                li = temp;
                answer = li;
            }
            else{
                li.next = temp;
                li = li.next;
            }
            if(l1!=null){
                l1 = l1.next;
            }
            if(l2!=null){
                l2 = l2.next;
            }
        }
        if(up!=0){
            ListNode temp = new ListNode(up);
            li.next = temp;
        }
        return answer;
    }
}