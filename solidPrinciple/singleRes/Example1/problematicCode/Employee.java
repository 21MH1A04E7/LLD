public class Employee {
    private int id;
    private String name;
    private String address;
    public Employee(int id, String name,String address) {
        this.id = id;
        this.name = name;
        this.address = address;
    }
    public void printPerformanceReport() {
        System.out.println("Employee Name: " + name);
    }
    public double computeSalary(){
        return 1000.0;
    }
    public void updateEmployeeData(){
        System.out.println("Employee data updated");
    }
    public  void fetchEmployeesData(){
        System.out.println("Fetching employees data");
    }
}
//not following the single responsibility principle

