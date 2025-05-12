package dhbw_ma;

import java.util.ArrayList;

public class clsStudent {
    private final String studentId;
    private final String name;
    private final ArrayList<String> courses;

    public clsStudent(String studentId, String name) {
        this.studentId = studentId;
        this.name = name;
        this.courses = new ArrayList<>();
    }

    public void addCourse(String course) {
        courses.add(course);
    }

    @Override
    public String toString() {
        return "Student (" + studentId + ", " + name + ") has courses: " + String.join(", ", courses);
    }
}
