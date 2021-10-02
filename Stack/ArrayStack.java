import java.util.Arrays;

public class ArrayStack implements Stack {
    private int size = 0;
    private Object array[];

    ArrayStack(int capacity) {
        array = new Object[capacity];
    }

    ArrayStack() {
        this(5);
    }

    @Override
    public void push(Object o) {
        if (size == array.length)
            resizeArray();
        array[size++] = o;
    }

    @Override
    public Object pop() {
        Object obj = array[--size];
        array[size] = null;
        return obj;
    }

    @Override
    public Object peek() {
        return array[size - 1];
    }

    @Override
    public int size() {
        return size;
    }

    public void resizeArray() {
        array = Arrays.copyOf(array, array.length * 2 + 1);
    }

    @Override
    public String toString() {
        if (array == null || size == 0)
            return "[]";
        String buf = "[" + array[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            buf += "," + array[i];
        }
        return buf + "]";
    }

    public int capacity() {
        return array.length;
    }

}