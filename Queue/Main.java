public class Main {
    public static void main(String[] args) {
        Queue queue=new LinkedQueue();
        queue.add(123);
        queue.add("Zhs");
        queue.add(false);
        System.out.println(queue.remove());
        System.out.println(queue.first());
        System.out.println(queue.size());
    }
}
