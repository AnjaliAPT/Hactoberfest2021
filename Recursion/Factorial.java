public class Factorial {
    public static long fact(int n) {
        if (n <= 1)
            return 1;
        return n * fact(n - 1);
    }

    public static void main(String[] args) throws Exception {
        for (int i = 0; i < 10; i++) {

            System.out.println(fact(i));
        }
    }
}
