package dhbw_ma.models;

import java.util.Random;

public class Person {
    private final String fullName;

    public Person(String fullName) {
        this.fullName = fullName;
    }

    public Student enroll() {
        return new Student(new Random().nextInt(), fullName);
    }

    public String getFullName() {
        return fullName;
    }
}
