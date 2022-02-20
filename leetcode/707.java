class Node{
    public int val;
    public Node next;

    Node(int val){
        this.val = val;
        this.next = null;
    }
}

class MyLinkedList {
    public Node head;
    int cnt;

    public MyLinkedList() {
        this.head = null;
        cnt = 0;
    }

    public int get(int index) {
        if(this.cnt<=index || this.cnt == 0){
            return -1;
        }
        int i = 0;
        Node cur = this.head;
        while(i<index){
            cur = cur.next;
            i++;
        }
        return cur.val;
    }

    public void addAtHead(int val) {
        Node new_node = new Node(val);
        if(this.head==null){
            this.head = new_node;
        }
        else{
            new_node.next = this.head;
            this.head = new_node;
        }
        this.cnt++;
    }

    public void addAtTail(int val) {
        Node cur = this.head;
        if(head==null){
            addAtHead(val);
            return;
        }
        else{
            while(cur.next!=null){
                cur = cur.next;
            }
            Node new_node = new Node(val);
            cur.next = new_node;
        }

        this.cnt++;
    }

    public void addAtIndex(int index, int val) {
        if(this.cnt<index){
            return;
        }
        if(index==0){
            this.addAtHead(val);
            return;
        }
        else{
            int i = 0;
            Node cur = this.head;
            while(i<index-1){
                cur = cur.next;
                i++;
            }
            Node new_node = new Node(val);
            Node temp = cur.next;
            cur.next = new_node;
            new_node.next = temp;
        }
        this.cnt++;
    }

    public void deleteAtIndex(int index) {
        if(this.cnt<=index || this.cnt == 0){
            return;
        }
        int i = 0;
        Node prev = null;
        Node cur = this.head;
        while(i<index){
            prev = cur;
            cur = cur.next;
            i++;
        }
        if(index==0){
            if(cnt==1){
                head = null;
            }
            else{
                head = cur.next;
            }
        }
        else{
            prev.next = cur.next;
        }
        this.cnt--;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
