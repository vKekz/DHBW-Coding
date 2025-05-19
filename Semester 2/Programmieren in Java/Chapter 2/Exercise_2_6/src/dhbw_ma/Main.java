package dhbw_ma;

import dhbw_ma.models.DhbwStudent;
import dhbw_ma.models.Person;
import dhbw_ma.models.Student;

public class Main {
    public static void main(String[] args) {
        // Case 1
        Person person = new Person("Vigan Veliu");
        Student enrolledPerson = person.enroll();
        System.out.println(enrolledPerson.getId());

        // Case 2
        Student student = new Student(0, "Vigan Veliu");
        if (!student.isSuccessful()) {
            student.exmatriculate();
        }

        // Case 3
        DhbwStudent dhbwStudent = new DhbwStudent(1, "Vigan Veliu", "Litexa");
        if (dhbwStudent.isFinished()) {
            dhbwStudent.finishDegree();
        }
    }
}
