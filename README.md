# AMAOEd: ITE7101: Computer Programming
## Week 11 - Machine Problem 3

Write a C++ program with the following specifications:
1.	Create a class and name it **Payslip**.  This class should have the following attributes or properties: name, pay grade, basic salary, overtime hours, overtime pay, gross pay, net pay and withholding tax.  
2.	Define the accessors and mutators of the Payslip class based on its attributes or properties.  This class should also have the following methods: determinePayGradeAndTaxRate and computePay.
3.	Create another class and name it **Employee**.  This class will contain the main method.
4.	In the main method, instantiate an object of the Payslip class.  Input the employee name, basic salary, and number of overtime (OT) hours.  These values must be set to the object of the Payslip class.  Apply validations for input as follows:\
> a.	Basic salary should not be less than 10,000.\
> b.	Minimum overtime hours is 1 hour.
5.	Basic Salary Details:
  <table style="margin-left: 10rem; text-align: center;">
    <tr><th>Pay Grade A</th><th>Pay Grade B</th><th>Tax Rate</th></tr>
    <tr><td>10,000</td><td>	15,000</td><td>	10%</td></tr>
    <tr><td>20,000</td><td>25,000</td><td>15%</td></tr>
    <tr><td>30,000</td><td>35,000</td><td>20%</td></tr>
    <tr><td>40,000</td><td>45,000</td><td>25%</td></tr>
    <tr><td>50,000</td><td>55,000</td><td>30%</td></tr>
  </table>

6.	The computation is as follows:
Gross pay = basic salary + OT pay
OT pay = no. of OT hours * 1% of basic salary
Net pay = gross pay – withholding tax – fixed values
Withholding tax = gross pay * tax rate 
Note: Basic salary greater than or equal to 55,000 will have a pay grade of B and a tax rate of 30%.

7.	The following are fixed values:
>  SSS = 500.00\
>  Pag-ibig = 200.00\
>  Philhealth = 100.00

8.	Output should contain the following:

```
Employee Name   : 
Basic Salary    :
Pay Grade       :
No. of OT Hours :
OT Pay          : 
Gross Pay       : 
Withholding Tax : 
Net Pay         : 
```

>Note: Input of data and display of results should be defined on the main method. All monetary display should be formatted with comma separators, 2 decimal places, and “Php” (Ex: Php 32,546.95).
