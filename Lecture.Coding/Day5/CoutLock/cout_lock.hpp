/*
 * Created: 02-10-2015
 * Modified: Fri 02 Oct 2015 15:22:40 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#ifndef COUT_LOCK_HPP
#define COUT_LOCK_HPP

#include<fstream>
#include<iostream>
#include<string>
#include<stdexcept>

class CoutLock
{
public:
  CoutLock(std::string filename)
    : ofs {filename}
  {
    if (!ofs)
      throw std::runtime_error {"Cannot open buffer file"};

    buffer = std::cout.rdbuf();
    std::cout.rdbuf(ofs.rdbuf());
  }

  ~CoutLock()
  {
    std::cout.rdbuf(buffer);
    ofs.close();
  }
  

private:
  std::ofstream ofs;
  std::streambuf * buffer;

};


#endif /* COUT_LOCK_HPP */
