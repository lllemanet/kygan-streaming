#pragma once

#include <QCoreApplication>
#include <QTcpServer>

#include "ClientsMediator.hpp"

namespace kygon::server {

class Application : public QCoreApplication {
    Q_OBJECT

public:
    Application(int argc, char* argv[]);

    /**
     * @brief Initialize the app. Should be called just after the constructor.
     *
     * @return whether init succeed.
     */
    bool init();

private:
    QTcpServer m_server;
    ClientsMediator m_clientsMediator;
};

}  // namespace kygon::server
