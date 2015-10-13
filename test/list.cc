#include <wifi/wifi.h>
#include <iostream>


int main(int argc, char **argv)
{
 try
 {
  ipr::wifi con("wlan0");
  con.list();
 }
 catch(const std::exception &e)
 {
  std::cout << e.what() << " " << argv[1] << "\n";
  return -1;
 }

 return 0;
}

