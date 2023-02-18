/*
 * Created: 01-10-2015
 * Modified: Thu 01 Oct 2015 14:53:55 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

class Employee
{
public:
  virtual double pay() const = 0;

  virtual ~Employee() {};
};

class FixedPayEmployee : public Employee
{
public:

  FixedPayEmployee(double fixed_pay)
    : fixed_pay {fixed_pay} {}

  virtual double pay() const override
  {
    return fixed_pay;
  }

private:
  double fixed_pay;
};

class HourlyPayEmployee : public Employee
{
public:

  HourlyPayEmployee(double hourly_rate)
    : hourly_rate {hourly_rate},
      hours_worked {0} {}

  void work(unsigned hours)
  {
    hours_worked += hours;
  }

  virtual double pay() const override
  {
    return hours_worked * hourly_rate;
  }

private:
  double hourly_rate;
  unsigned hours_worked;
};


#endif /* EMPLOYEE_HPP */
