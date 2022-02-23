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
    public ListNode reverseKGroup(ListNode head, int k) {
        int cnt = 0;
        ListNode temp = head;
        while(temp!=null){
            temp = temp.next;
            cnt++;
        }
        if(cnt<k){
            return head;
        }
        else{
            ListNode first = null;
            ListNode last = null;
            ListNode cur = head;
            while(cnt>=k){
                ListNode first_temp = new ListNode(cur.val);
                ListNode last_temp = first_temp;
                cur = cur.next;
                for(int i=1; i<k; i++){
                    ListNode new_node = new ListNode(cur.val);
                    new_node.next = first_temp;
                    first_temp = new_node;
                    cur = cur.next;
                }
                if(first==null){
                    first = first_temp;
                    last = last_temp;
                }
                else{
                    last.next = first_temp;
                    last = last_temp;
                }
                cnt-=k;
            }
            while(cur!=null){
                ListNode new_node = new ListNode(cur.val);
                last.next = new_node;
                last = new_node;
                cur = cur.next;
            }
            return first;
        }
    }
}
