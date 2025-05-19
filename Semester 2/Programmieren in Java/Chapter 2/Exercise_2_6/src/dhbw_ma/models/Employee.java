package dhbw_ma.models;

public class Employee extends Person implements Company {
    private final String companyName;

    public Employee(String fullName, String companyName) {
        super(fullName);

        this.companyName = companyName;
    }

    @Override
    public String getCompanyName() {
        return companyName;
    }
}
