package dhbw_ma.models;

import java.util.ArrayList;
import java.util.List;

public class Student extends Person {
    private final int id;
    private final List<Lecture> lectures;
    private int semester;

    public Student(int id, String fullName) {
        super(fullName);

        this.id = id;
        this.lectures = new ArrayList<>();
        this.semester = 1;
    }

    public Person exmatriculate() {
        return new Person(getFullName());
    }

    public double getGrade() {
        double average = 0D;
        for (Lecture lecture : lectures) {
            average += lecture.getGradeByStudentId(id);
        }

        return average / lectures.size();
    }

    public boolean isSuccessful() {
        return getGrade() <= 4.0D;
    }

    public boolean isFinished() {
        return semester >= 6;
    }

    public int getId() {
        return id;
    }

    public List<Lecture> getLectures() {
        return lectures;
    }
}
