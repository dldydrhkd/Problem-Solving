/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode temp = head;
        while(true){
            if(temp==null){
                break;
            }
            if(temp.val==100001){
                return true;
            }
            else{
                temp.val=100001;
                temp = temp.next;
            }
        }
        return false;
    }
}