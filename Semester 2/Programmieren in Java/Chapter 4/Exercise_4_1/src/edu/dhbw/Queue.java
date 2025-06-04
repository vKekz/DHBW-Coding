package edu.dhbw;

public class Queue implements IQueue {
    private Object[] array;

    private int size = 0;
    private int capacity = 3;

    public Queue() {
        this.array = new Object[capacity];
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        for (Object o : array) {
            if (o == null) {
                continue;
            }

            s.append(o);
            s.append(", ");
        }

        return s.toString();
    }

    @Override
    public void add(Object value) {
        growIfNeeded();
        array[size++] = value;
    }

    @Override
    public Object remove() {
        size--;
        Object value = array[size];
        array[size] = null;

        return value;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    private void growIfNeeded() {
        if (size > capacity) {
            capacity *= 2;

            Object[] newArray = new Object[capacity];
            for (int i = 0; i < capacity; i++) {
                newArray[i] = array[i];
            }

            array = newArray;
        }
    }
}
