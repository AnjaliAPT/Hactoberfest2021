public class Main {
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
