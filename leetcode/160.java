/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode temp1 = headA;
        ListNode temp2 = headB;
        int cnt1 = 0;
        int cnt2 = 0;
        while(temp1 != null){
            temp1 = temp1.next;
            cnt1++;
        }
        while(temp2 != null){
            temp2 = temp2.next;
            cnt2++;
        }
        temp1 = headA;
        temp2 = headB;
        int cnt = Math.abs(cnt1-cnt2);
        if(cnt1>cnt2){
            while(cnt-- != 0){
                temp1 = temp1.next;
            }
        }
        else{
            while(cnt-- != 0){
                temp2 = temp2.next;
            }
        }
        while(temp1!=temp2){
            temp1 = temp1.next;
            temp2 = temp2.next;
        }
        return temp1;
    }
}