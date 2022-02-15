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
        ListNode answer = null;
        ListNode temp = null;
        ListNode front = head;
        boolean isDup = false;
        ListNode second;
        if(head!=null){
            second = head.next;
        }
        else{
            second = null;
        }
        while(front!=null && second!=null){
            if(front.val==second.val){
                second=second.next;
                isDup = true;
            }
            else{
                if(isDup==true){
                    front = second;
                    second = second.next;
                    isDup = false;
                }
                else{
                    if(temp==null){
                        ListNode t = new ListNode(front.val);
                        temp = t;
                        answer = temp;
                    }
                    else{
                        ListNode t = new ListNode(front.val);
                        temp.next = t;
                        temp = temp.next;
                    }
                    front = second;
                    second = second.next;
                }
            }
        }
        if(isDup==false && front!=null){
            ListNode t = new ListNode(front.val);
            if(temp==null){
                temp = t;
                answer = temp;
            }
            else{
                temp.next = t;
            }
        }
        return answer;
    }
}