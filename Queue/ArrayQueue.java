import java.util.Arrays;

public class ArrayQueue implements Queue {
    private int size;
    private Object array[];

    @Override
    public Object first() {
        if (size == 0)
            throw new IllegalStateException("Stack is empty!");
        return array[0];
    }

    @Override
    public Object remove() {
        if (size == 0)
            throw new IllegalStateException("Stack is empty!");
        Object obj = array[0];
        System.arraycopy(array, 1, array, 0, --size);
        return obj;
    }

    @Override
    public void add(Object o) {
        if (size == array.length)
            resizeArray();
        array[size++]=o;
    }

    private void resizeArray() {
        array=Arrays.copyOf(array, size*2+1);
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    public int capacity(){
        return array.length;
    }

    public ArrayQueue() {
        this(5);
    }

    public ArrayQueue(int capacity) {
        array = new Object[capacity];
    }

    @Override
    public String toString() {
        if(size==0)
        return "[]";
        String buf="["+array[0];
        for (int i = 1; i < size; i++) {
            buf+=","+array[i];
        }
        return buf+"]";
    }

}
