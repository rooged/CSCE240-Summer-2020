/*  Copyright 240 Timothy Gedney
 *
 *  Expanded upon the provided methods in the .h file
 */

#include <inc/employee.h>
#include <string>
using std::string;

namespace exam3 {

Demographic::Demographic(const string& first_name, const string& last_name,
                         const string& date_of_birth) {
  first = first_name;
  last = last_name;
  birth = date_of_birth;
}

//  accessor
const string Demographic::first_name() const {
  return first;
}

const string Demographic::last_name() const {
  return last;
}

const string Demographic::date_of_birth() const {
  return birth;
}

Employee::Employee(const string& first_name, const string& last_name,
                   const string& date_of_birth, const string& employee_id) :
                   Demographic(first_name, last_name, date_of_birth) {
  id = employee_id;
}

Employee::~Employee() {
//  empty
}

const string Employee::employee_id() const {
  return id;
}

HourlyEmployee::HourlyEmployee(const string& first_name,
                               const string& last_name,
                               const string& date_of_birth,
                               const string& employee_id,
                               double hourly_rate) :
                               Employee(first_name, last_name,
                               date_of_birth, employee_id) {
  rate = hourly_rate;
}

//  accessor for houry_rate
double HourlyEmployee::pay_rate() const {
  return rate;
}

//  calculates payment based on employee's hourly_rate and hours_worked
double HourlyEmployee::CalculatePay(double hours_worked) const {
  return rate * hours_worked;
}

SalaryEmployee::SalaryEmployee(const string& first_name,
                               const string& last_name,
                               const string& date_of_birth,
                               const string& employee_id,
                               double salary) :
                               Employee(first_name, last_name,
                               date_of_birth, employee_id) {
  rateS = salary;
}

//  accessor for salary
double SalaryEmployee::pay_rate() const {
  return rateS;
}

/*  calculates payment based on worker's salary and percentage of the year
 *  for which payment is made e.g. a week payment is ~1.923% (1/52)
 */
double SalaryEmployee::CalculatePay(double annual_percentage) const {
  return rateS * (annual_percentage / 100);
}
}  //  namespace exam3