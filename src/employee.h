#include <vector>
#include "payslip.h"


class Employee{
private:
  std::string name;
  std::vector<Payslip> payslips = {};

public:
  Employee(std::string emp_name) : name(emp_name){}

  // get employee name;
  std::string getName() const { return name; }

  // get payslips
  std::vector<Payslip> getPayslips() const { return payslips;}

  // add a new Payslip
  Payslip newPayslip(double basic_pay, double ot_hours){
    payslips.push_back(Payslip(name, basic_pay, ot_hours));
  }
};
