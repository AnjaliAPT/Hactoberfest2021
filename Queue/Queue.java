public interface Queue{
    Object first();
    Object remove();
    void add(Object o);
    int size();
    boolean isEmpty();
}