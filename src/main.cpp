/* ****************************************************************
 * @author: Jephthah M. Orobia
 * @app name: AMAOEd Machine Problem 3
 * @app desc: To display payslips of employees
 * ****************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "_pause.h"
#include "employee.h"

using namespace std;

int main()
{
  Employee juan("Juan Dela Cruz");
  juan.newPayslip(12000, 2.5);
  juan.newPayslip(27500, 1.5);

  Employee maria("Maria Mercedez");
  maria.newPayslip(34000, 6.24);
  maria.newPayslip(34000, 1);

  for(const Payslip p: juan.getPayslips()){
    cout << endl << "========================================"
         << endl << "Employee Name\t: " << p.getName() << endl
         << "Basic Salary\t: " << p.getBasicSalarySTR() << endl
         << "Pay Grade\t: " <<  p.getPayGradeStr() << endl
         << "No. of OT Hours\t: " << p.getOvertimeHours() << endl
         << "OT Pay\t\t: " << p.getOvertimePaySTR() << endl
         << "Gross Pay\t: " << p.getGrossPaySTR() << endl
         << "Withholding Tax\t: " << p.getWithholdingTaxSTR() << endl
         << "Net Pay\t\t: " << p.getNetPaySTR()
         << endl << "========================================"
         << endl;
  }

  for(const Payslip p: maria.getPayslips()){
    cout << endl << "========================================"
         << endl << "Employee Name\t: " << p.getName() << endl
         << "Basic Salary\t: " << p.getBasicSalarySTR() << endl
         << "Pay Grade\t: " <<  p.getPayGradeStr() << endl
         << "No. of OT Hours\t: " << p.getOvertimeHours() << endl
         << "OT Pay\t\t: " << p.getOvertimePaySTR() << endl
         << "Gross Pay\t: " << p.getGrossPaySTR() << endl
         << "Withholding Tax\t: " << p.getWithholdingTaxSTR() << endl
         << "Net Pay\t\t: " << p.getNetPaySTR()
         << endl << "========================================"
         << endl;
  }




  cout << endl;
  _pause();
  return EXIT_SUCCESS;
}
