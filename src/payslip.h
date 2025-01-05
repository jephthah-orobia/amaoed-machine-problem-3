#include <iostream>
#include <sstream>
#include <iomanip>
#include <locale>

enum class PayGrade{ A, B };

struct comma_separated : std::numpunct<char> {
  virtual char do_thousands_spe() const {
    return ',';
  }
  virtual std::string do_grouping() const {
    return "\3";
  }
};

class Payslip {
private:
  std::string employee_name;
  double basic_salary;
  double overtime_hours;

  // default value: SSS + Pag-ibig + Philhealth
  double fixed_deduction = 500 + 200 + 100;

  // to be calculated each time `basic_salary` is set
  PayGrade pay_grade;
  double tax_rate;

  // to be calculated each time `basic_salary` or `overtime_hours` is set
  double overtime_pay;
  double gross_pay;
  double net_pay;
  double withholding_tax;

  void determinePayGradeAndTaxRate(){
    if((basic_salary < 15000)
      || (basic_salary >= 20000 && basic_salary < 25000)
      || (basic_salary >= 30000 && basic_salary < 35000)
      || (basic_salary >= 40000 && basic_salary < 45000)
      || (basic_salary >= 50000 && basic_salary < 55000))
      pay_grade = PayGrade::A;
    else
      pay_grade = PayGrade::B;

    if(basic_salary < 20000)
      tax_rate = 0.10;
    else if(basic_salary >= 20000 && basic_salary < 30000)
      tax_rate = 0.15;
    else if(basic_salary >= 30000 && basic_salary < 40000)
      tax_rate = 0.20;
    else if(basic_salary >= 40000 && basic_salary < 50000)
      tax_rate = 0.25;
    else
      tax_rate = 0.30;
  }


  void computePay(){
    overtime_pay = overtime_hours * 0.01 * basic_salary;
    gross_pay = basic_salary + overtime_pay;
    withholding_tax = gross_pay * tax_rate;
    net_pay = gross_pay - withholding_tax - fixed_deduction;
  }

  //format currency
  std::string formatCurrency(double value) const {
    std::ostringstream oss;
    oss.imbue(std::locale(oss.getloc(), new comma_separated));
    oss << std::fixed << std::setprecision(2) << value;
    return "Php " + oss.str();
  }

public:
  Payslip(std::string empName, double basic, double ot)
    : employee_name(empName) {
      if(basic >= 10000)
        basic_salary = basic;
      else
        std::cout << "\033[31mError: Invalid basic salary!\033[0m";
      if(ot >= 1)
        overtime_hours = ot;
      else
        std::cout << "\033[31mError: Invalid overtime hours!\033[0m";
      if(basic_salary && overtime_hours){
        determinePayGradeAndTaxRate();
        computePay();
      }
    }

  #pragma region Accessors
  // get the Name of the Employee
  std::string getName() const {return employee_name;}

  // get the Pay Grade
  PayGrade getPayGrade() const { return pay_grade;}

  // get the Pay Grade as String
  std::string getPayGradeStr() const {
    switch(pay_grade){
      case PayGrade::A:
        return "A";
        break;
      case PayGrade::B:
        return "B";
        break;
      default:
        return "Not Set";
        break;
    }
  }

  // get Basic Salary
  double getBasicSalary() const { return basic_salary; }

  // get Basic Salary formatted as currency
  std::string getBasicSalarySTR() const {
    return formatCurrency(basic_salary);
  }

  // get overtime hours
  double getOvertimeHours() const { return overtime_hours;}

  // get fixed deductions
  double getFixedDeduction() const { return fixed_deduction;}

  // get fixed deductions formatted as currency
  std::string getFixedDeductionSTR() const {
    return formatCurrency(fixed_deduction);
  }

  // get gross pay
  double getGrossPay() const { return gross_pay; }

  // get gross pay formatted as currency
  std::string getGrossPaySTR() const { return formatCurrency(gross_pay); }

  // get ot pay
  double getOvertimePay() const { return overtime_pay; }

  // get ot pay formatted as currency
  std::string getOvertimePaySTR() const {
    return formatCurrency(overtime_pay);
  }

  // get net pay
  double getNetPay() const { return net_pay;}

  // get net pay formatted as currency
  std::string getNetPaySTR() const { return formatCurrency(net_pay);}

  // get withholding tax
  double getWithholdingTax() const { return overtime_pay; }

  // get withholding tax formatted as currency
  std::string getWithholdingTaxSTR() const { return formatCurrency(overtime_pay); }
  #pragma endregion Accessors

  #pragma region Mutators
  // set employee's name
  void setName(std::string name){
    employee_name = name;
  }

  // set fixed_deduction
  void setFixedDeduction(double fixed_value){
    fixed_deduction = fixed_value;
    if(basic_salary && overtime_hours)
      computePay();
  }

  // set Basic Salary
  void setBasicSalary(double sal){
    if(sal >= 10000);
    basic_salary = sal;
    determinePayGradeAndTaxRate();
    if(overtime_hours)
      computePay();
  }

  // set Overtime Hours
  void setOvertimeHours(double ot){
    overtime_hours = ot;
    if(basic_salary)
      computePay();
  }

  #pragma endregion Mutators
};
