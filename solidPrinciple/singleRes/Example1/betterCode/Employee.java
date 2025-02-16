public class Employee {
    private int id;
    private String name;
    private String address;
    public Employee(int id, String name,String address) {
        this.id = id;
        this.name = name;
        this.address = address;
    }
    public String getEmployeeName(){
         return name;
    }
    public void updateEmployeeData(){
        System.out.println("Employee data updated");
    }
    public  void setEmployeeName(String name){
        this.name = name;
    }
}
//not following the single responsibility principle

