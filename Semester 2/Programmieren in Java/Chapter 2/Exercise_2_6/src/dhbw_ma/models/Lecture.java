package dhbw_ma.models;

import java.util.HashMap;

public class Lecture {
    private final HashMap<Integer, Double> grades;

    public Lecture() {
        grades = new HashMap<>();
    }

    public double getGradeByStudentId(int studentId) {
        return grades.get(studentId);
    }
}
