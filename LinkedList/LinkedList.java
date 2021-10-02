public class LinkedList {
    private Node list;
    private int size;

    private class Node {
        Object data;
        Node next;

        Node(Object d, Node n) {
            data = d;
            next = n;
        }
    }

    public void add(Object o) {
        if (list == null) {
            list = new Node(o, null);
            size++;
            return;
        }
        Node p = list;
        while (p.next != null) {
            p = p.next;
        }
        p.next = new Node(o, p.next);
        size++;
    }

    public boolean remove(Object o) {
        if (size == 0)
            return false;
        for (Node p = list; p.next != null; p = p.next) {
            if (p.next.data.equals(o)) {
                p.next = p.next.next;
                --size;
                return true;
            }
        }
        return false;
    }

    @Override
    public String toString() {
        if (size == 0)
            return "[]";
        Node p = list;
        String buf = "[" + p.data;
        while ((p = p.next) != null) {
            buf += "," + p.data;
        }
        return buf += "]";
    }

    public boolean contains(Object o) {
        if (size == 0)
            return false;
        for (Node p = list; p != null; p = p.next) {
            if (p.data.equals(o)) {
                return true;
            }
        }
        return false;
    }

    public boolean clear() {
        if (size == 0)
            return true;
        list = null;
        size = 0;
        return true;
    }

    public Object elementAt(int index) {
        if (index < size && index >= 0) {
            Object obj = "";
            int i = 0;
            for (Node p = list; p != null; p = p.next) {
                if (i++ == index)
                    return p.data;
            }
            return obj;
        }
        throw new IndexOutOfBoundsException("Index should be in range of 0-" + (size - 1));
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

}
