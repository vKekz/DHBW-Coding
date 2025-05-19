package dhbw_ma.models;

public class DhbwStudent extends Student implements Company {
    private final String companyName;

    public DhbwStudent(int id, String fullName, String companyName) {
        super(id, fullName);

        this.companyName = companyName;
    }

    public void finishDegree() {
        employAtCompany();
    }

    private Employee employAtCompany() {
        return new Employee(getFullName(), companyName);
    }

    @Override
    public String getCompanyName() {
        return companyName;
    }
}
