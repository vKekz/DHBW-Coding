package edu.dhbw;

public class QueueTest
{
    public void start() {
        queueCanAddItem();
        queueRemovesItemThatGotFirstIn();
        queueKnowsItsEmpty();
    }

    private void queueCanAddItem() {
        Queue queue = new Queue();
        queue.add(3);
        queue.add(2);

        IQueue refQueue = queue;
        System.out.println(refQueue.remove());

        System.out.println(queue);
        System.out.println("IsEmpty: " + queue.isEmpty());
    }

    private void queueRemovesItemThatGotFirstIn() {
        Queue queue = new Queue();
        queue.add(3);
        queue.add(2);

        System.out.println(queue.remove());
    }

    private void queueKnowsItsEmpty() {
        Queue queue = new Queue();
        queue.add(1);
        queue.remove();

        System.out.println("IsEmpty: " + queue.isEmpty());
    }
}
