import java.util.Arrays;

public class ArrayList {
    private int size;
    private Object array[];

    public ArrayList(int capacity) {
        array = new Object[capacity];
    }

    public ArrayList() {
        array = new Object[5];
    }

    public void add(Object o) {
        if (size == array.length)
            resizeArray();
        array[size++] = o;
    }

    private void resizeArray() {
        array = Arrays.copyOf(array, size * 2 + 1);
    }

    public boolean remove(Object o) {
        if (size == 0)
            return false;
        for (int i = 0; i < array.length; i++) {
            if (o.equals(array[i])) {
                array[i] = array[--size];
                array[size] = null;
                return true;
            }
        }
        return false;
    }

    @Override
    public String toString() {
        if (size == 0)
            return "[]";
        String buf = "[" + array[0];
        for (int i = 1; i < size; i++) {
            buf += "," + array[i];
        }
        return buf += "]";
    }

    public boolean contains(Object o) {
        if (size == 0)
            return false;
        for (int i = 0; i < array.length; i++) {
            if (o.equals(array[i])) {
                return true;
            }
        }
        return false;
    }

    public boolean clear() {
        if (size == 0)
            return true;
        array = new Object[5];
        size = 0;
        return true;
    }

    public Object elementAt(int index) {
        if (index < size && index >= 0) {
            return array[index];
        }
        throw new IndexOutOfBoundsException("Index should be in range of 0-" + (size - 1));
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int capacity() {
        return array.length;
    }
}
