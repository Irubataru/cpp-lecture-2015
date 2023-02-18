/*
 * Created: 30-09-2015
 * Modified: Wed 30 Sep 2015 08:14:24 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#ifndef INTEGRATE_HPP
#define INTEGRATE_HPP

double integrate(double,double,unsigned,double(*)(double));
double integrate_w_args(double,double,unsigned,double(*)(double,double[]),double[]);


#endif /* INTEGRATE_HPP */
