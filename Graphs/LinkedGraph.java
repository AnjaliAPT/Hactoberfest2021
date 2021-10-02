public class LinkedGraph {
    private int size;
    private List[] a; // adjacency list

    public LinkedGraph(String[] array) {
        size = array.length;
        a = new List[size];
        for (int i = 0; i < size; i++) {
            a[i] = new List(array[i]);
        }
    }

    private class List {
        private String vertex;
        Node edges;

        private class Node {
            private int to;
            Node next;

            public Node(int t, Node n) {
                to = t;
                next = n;
            }
        }

        public List(String v) {
            this.vertex = v;
        }

        public void add(int j) {
            edges = new Node(j, edges);
        }

        @Override
        public String toString() {
            String buf = vertex;
            if (edges != null) {
                buf += ":";
                for (Node p = edges; p != null; p = p.next)
                    buf += a[p.to].vertex;
            }
            return buf;
        }
    }

    public void add(String w, String v) {
        a[index(w)].add(index(v));
        a[index(v)].add(index(w));
    }

    private int index(String v) {
        for (int i = 0; i < size; i++) {
            if (a[i].vertex.equals(v))
                return i;
        }
        return -1;
    }

    @Override
    public String toString() {
        if (size == 0)
            return "{}";
        String buf = "{" + a[0];
        for (int i = 1; i < size; i++) {
            buf += "," + a[i];
        }

        return buf + "}";
    }
    public static void main(String[] args) {
        LinkedGraph graph = new LinkedGraph(new String[] { "A", "B", "C", "D", "E" });
        graph.add("A", "B");
        graph.add("B", "C");
        graph.add("D", "E");
        graph.add("E", "A");
        graph.add("B", "D");
        System.out.println(graph);
    }

}