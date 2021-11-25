class ListNode{
    int val;
    ListNode next;
    ListNode(){}
    ListNode(int val){
        this.val = val;
    }
    ListNode(int val, ListNode next){
        this.val = val;
        this.next = next;
    }
}

class MyQueue {
    
    ListNode head;
    ListNode tail;

    public MyQueue() {
        
    }
    
    public void push(int x) {
        ListNode temp = new ListNode(x);
        if(head==null){
            head = temp;
            tail = temp;
        }
        else{
            tail.next = temp;
            tail = temp;
        }
    }
    
    public int pop() {
        int temp = head.val;
        head = head.next;
        if(head==null){
            tail = null;
        }
        return temp;
    }
    
    public int peek() {
        return head.val;
    }
    
    public boolean empty() {
        if(head==null){
            return true;
        }
        else{
            return false;
        }
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */