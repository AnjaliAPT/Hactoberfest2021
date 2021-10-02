public class ArrayGraph {
    private String[] vertices;
    private int size;
    private boolean a[][];  //adjacency matrix

    public ArrayGraph(String[] array) {
        size = array.length;
        vertices = new String[size];
        a = new boolean[size][size];
        System.arraycopy(array, 0, vertices, 0, size);
    }

    public void add(String w, String v) {
        int i = index(w);
        int j = index(v);
        a[i][j] = a[j][i] = true;
    }

    private int index(String v) {
        for (int i = 0; i < size; i++) {
            if (v.equals(vertices[i]))
                return i;
        }
        return -1;
    }

    @Override
    public String toString() {
        if (size == 0)
            return "{}";
        String buf = "{" + vertex(0);
        for (int i = 1; i < size; i++) {
            buf += "," + vertex(i);
        }
        return buf + "}";
    }

    private String vertex(int i) {
        String buf = vertices[i] + ":";
        for (int j = 0; j < size; j++) {
            if (a[i][j])
                buf += vertices[j];
        }
        return buf;
    }

    public static void main(String[] args) {
        //LinkedGraph graph = new LinkedGraph(new String[] { "A", "B", "C", "D", "E" });
        ArrayGraph graph = new ArrayGraph(new String[] { "A", "B", "C", "D", "E" });
        graph.add("A", "B");
        graph.add("B", "C");
        graph.add("D", "E");
        graph.add("E", "A");
        graph.add("B", "D");
        System.out.println(graph);
    }

}
