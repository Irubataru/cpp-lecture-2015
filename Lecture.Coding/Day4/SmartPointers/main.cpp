/*
 * Created: 01-10-2015
 * Modified: Thu 01 Oct 2015 14:57:24 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include<utility>
#include<list>
#include<iostream>
#include "unique_ptr.hpp"
#include "employee.hpp"

int main(int, char**)
{
  std::list< UniquePtr<Employee> > all_employees;

  UniquePtr<FixedPayEmployee> employee_1 { new FixedPayEmployee {500} };
  UniquePtr<FixedPayEmployee> employee_2 { new FixedPayEmployee {850} };
  UniquePtr<HourlyPayEmployee> employee_3 { new HourlyPayEmployee {10} };
  employee_3->work(40);

  all_employees.push_back( std::move(employee_1) );
  all_employees.push_back( std::move(employee_2) );
  all_employees.push_back( std::move(employee_3) );

  double expenses = 0;

  for (auto it = all_employees.begin(); it != all_employees.end(); ++it) {
    expenses += (*it)->pay();
  }

  std::cout << "Total expenses: " << expenses << std::endl;


}
