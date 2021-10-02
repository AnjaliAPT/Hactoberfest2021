public class LinkedQueue implements Queue {
    private Node head = new Node(null);
    private int size;

    private class Node {
        Object data;
        Node next;
        Node prev;

        Node(Object data) {
            this.data = data;
            next = prev = this;
        }

        Node(Object data, Node prev, Node next) {
            this.data = data;
            this.next = next;
            this.prev = prev;
        }
    }

    @Override
    public Object first() {
        if (size == 0)
            throw new IllegalStateException("Queue is Empty!");
        return head.next.data;
    }

    @Override
    public Object remove() {
        if (size == 0)
            throw new IllegalStateException("Queue is Empty!");
        Object obj = head.next.data;
        head.next = head.next.next;
        head.prev.next = head;
        --size;
        return obj;
    }

    @Override
    public void add(Object o) {
        head.prev = head.prev.next = new Node(o, head.prev, head);
        size++;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public String toString() {
        if (size() == 0)
            return "[]";
        Node p = head.next;
        String buf = "[" + p.data;
        while ((p=p.next)!=head) {
            buf+=","+p.data;
        }
        return buf + "]";
    }
}
