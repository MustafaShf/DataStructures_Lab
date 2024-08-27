#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int employeeId;
    string hireDate;

public:
    
    Employee(string empName, int empId, string empDate)
        : name(empName), employeeId(empId), hireDate(empDate) {}

    
    string getName() { return name; }
    int getEmployeeId() { return employeeId; }
    string getHireDate() { return hireDate; }

    
    void setName(string empName) { name = empName; }
    void setEmployeeId(int empId) { employeeId = empId; }
    void setHireDate(string empDate) { hireDate = empDate; }
};

class ProductionWorker : public Employee {
private:
    int shift;
    double hourlyPayRate;

public:
    // Parameterized constructor
    ProductionWorker(string empName, int empId, string empDate, int empShift, double empPayRate)
        : Employee(empName, empId, empDate), shift(empShift), hourlyPayRate(empPayRate) {}

    // Getter functions
    int getShift() { return shift; }
    double getHourlyPayRate() { return hourlyPayRate; }

    // Setter functions
    void setShift(int empShift) { shift = empShift; }
    void setHourlyPayRate(double empPayRate) { hourlyPayRate = empPayRate; }
};

class ShiftSupervisor : public Employee {
private:
    double annualSalary;
    double annualProductionBonus;

public:
    
    ShiftSupervisor(string empName, int empId, string empDate, double salary, double bonus)
        : Employee(empName, empId, empDate), annualSalary(salary), annualProductionBonus(bonus) {}

    
    double getAnnualSalary() { return annualSalary; }
    double getAnnualProductionBonus() { return annualProductionBonus; }

    
    void setAnnualSalary(double salary) { annualSalary = salary; }
    void setAnnualProductionBonus(double bonus) { annualProductionBonus = bonus; }
};

int main() {
    
    ProductionWorker worker("Tohseen", 10, "2024-08-26", 1, 15.50);
    cout << "Production Worker Details:" << endl;
    cout << "Name: " << worker.getName() << endl;
    cout << "Employee ID: " << worker.getEmployeeId() << endl;
    cout << "Hire Date: " << worker.getHireDate() << endl;
    cout << "Shift: " << (worker.getShift() == 1 ? "Day" : "Night") << endl;
    cout << "Hourly Pay Rate: " << worker.getHourlyPayRate() << endl;

    
    ShiftSupervisor supervisor("Ali", 20, "2023-01-15", 55000, 7000);
    cout << "\nShift Supervisor Details:" << endl;
    cout << "Name: " << supervisor.getName() << endl;
    cout << "Employee ID: " << supervisor.getEmployeeId() << endl;
    cout << "Hire Date: " << supervisor.getHireDate() << endl;
    cout << "Annual Salary: " << supervisor.getAnnualSalary() << endl;
    cout << "Annual Production Bonus: " << supervisor.getAnnualProductionBonus() << endl;

    return 0;
}
