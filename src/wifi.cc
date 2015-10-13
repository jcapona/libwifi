#include <wifi/wifi.h>
#include <string>
#include <iostream>

extern "C"
{
 #include <iwlib.h>
}

namespace ipr
{
    class wifi::impl
    {
    public:
        impl(const std::string &dev);
        ~impl();

        void connect(const std::string &network, const std::string &password);
        void disconnect();
        void list();
        bool isConnected() const;

    private:
        bool m_fd;
        std::string m_dev;
        void setParameters();
        void clear();
    };
}

// Implementation class
ipr::wifi::impl::impl(const std::string &dev)
    : m_dev(dev)
{

}

ipr::wifi::impl::~impl()
{
    disconnect();
}
void ipr::wifi::impl::connect(const std::string &network, const std::string &password)
{

}

void ipr::wifi::impl::disconnect()
{

}

/**
Lists available networks
*/
void ipr::wifi::impl::list()
{
 wireless_scan_head head;
 wireless_scan *result;
 iwrange range;
 int sock = iw_sockets_open(); // Socket to kernel

 if (iw_get_range_info(sock, (char*)m_dev.c_str(), &range) < 0) // Get data
 {
  std::cerr << "Error during iw_get_range_info. Aborting.\n";
  return ;
 }

 if (iw_scan(sock, (char*)m_dev.c_str(), range.we_version_compiled, &head) < 0) // Scan
 {
  std::cerr << "Error during iw_scan. Aborting.\n";
  return ;
 }

 result = head.result; 
 while (NULL != result) 
 {
  std::cout << result->b.essid <<"\n";
  result = result->next;
 }
}

bool ipr::wifi::impl::isConnected() const
{
 return m_fd != -1;
}


// Public API
ipr::wifi::wifi(const std::string &dev)
    : m_impl(new ipr::wifi::impl(dev))
{
}

ipr::wifi::~wifi()
{
}

void ipr::wifi::connect(const std::string &network, const std::string &password)
{
 m_impl->connect(network, password);
}

void ipr::wifi::disconnect()
{
 m_impl->disconnect();
}

void ipr::wifi::list()
{
 m_impl->list();
}

bool ipr::wifi::isConnected() const
{
 return m_impl->isConnected();
}
