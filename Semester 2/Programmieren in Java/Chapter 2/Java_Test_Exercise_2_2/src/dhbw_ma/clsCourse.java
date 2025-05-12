package dhbw_ma;

public class clsCourse {
    private final String courseId;
    private final String title;

    public clsCourse(String courseId, String title) {
        this.courseId = courseId;
        this.title = title;
    }

    @Override
    public String toString() {
        return "Course (" + courseId + ", " + title + ")";
    }
}
