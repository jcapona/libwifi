#ifndef IPR_WIFI_H
#define IPR_WIFI_H

#include <memory>

namespace ipr
{
    class wifi
    {
    public:
        wifi(const std::string &dev);
        ~wifi();

        void connect(const std::string &network, const std::string &password);
        void disconnect();
        void list();
        bool isConnected() const;

    private:
        class impl;
        std::unique_ptr<impl> m_impl;
    };
}
#endif
// IPR_WIFI_H
