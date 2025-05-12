package dhbw_ma;

public class clsMain {

    // C01 Math1
    // C02 Java_Programming
    // C03 Computer_Science
    //
    // S1234 Peter C01 C02
    // S0815 Paul C01 C03
    // S1015 Mary C02 C03
    public static void main(String[] args) {
        for (int i = 0; i <= 4; i += 2) {
            String courseId = args[i];
            String courseTitle = args[i + 1];

            clsCourse course = new clsCourse(courseId, courseTitle);
            System.out.println(course);
        }

        System.out.println("\n");

        for (int i = 6; i < args.length; i += 4) {
            String studentId = args[i];
            String studentName = args[i + 1];

            String firstCourse = args[i + 2];
            String secondCourse = args[i + 3];

            clsStudent student = new clsStudent(studentId, studentName);
            student.addCourse(firstCourse);
            student.addCourse(secondCourse);

            System.out.println(student);
        }
    }
}
