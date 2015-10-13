#include <include/wifi.h>
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
        impl();
        ~impl();

        void connect(const std::string &network, const std::string &password);
        void disconnect();
        void list();
        bool isConnected() const;

    private:
        bool m_fd;
        void setParameters();
        void clear();
    };
}

// Implementation class
ipr::wifi::impl::impl()
{

}
void ipr::wifi::impl::connect(const std::string &network, const std::string &password)
{

}

void ipr::wifi::impl::disconnect()
{

}

void ipr::wifi::impl::list()
{

}

bool ipr::wifi::impl::isConnected() const
{
 return m_fd != -1;
}


// Public API
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
