
public class LinkedStack implements Stack {
    private Node top;
    private int size;

    private class Node {
        Object data;
        Node next;

        Node(Object d, Node n) {
            data = d;
            next = n;
        }
    }

    @Override
    public void push(Object o) {
        top = new Node(o, top);
        size++;
    }

    @Override
    public Object pop() {
        if (top == null)
            throw new IllegalStateException("Stack is empty!");
        Object obj = top.data;
        top = top.next;
        size--;
        return obj;
    }

    @Override
    public Object peek() {
        if (top == null)
            throw new IllegalStateException("Stack is empty!");
        return top.data;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public String toString() {
        if (top == null || size() == 0)
            return "[]";
        String buf = "[" + top.data;
        for (Node p = top.next; p != null; p = p.next)
            buf += "," + p.data;
        return buf + "]";
    }
}
