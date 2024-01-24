#include "UiApplication.hpp"

#include "common/Utils.hpp"

namespace kygon::client {

namespace {
// TODO: temp
QByteArray username{"username1"};
}  // namespace

UiApplication::UiApplication(int argc, char* argv[]) : QGuiApplication{argc, argv} {}

bool UiApplication::init() {
    if (arguments().size() < 3) {
        qKDebug() << "Invalid arguments\n"
                  << "Usage: " << arguments().at(0) << " <server-address> <server-port>";
        return false;
    }

    QHostAddress address{arguments().at(1)};
    auto port = arguments().at(2).toUInt();
    if (!m_session.init(address, port, username)) {
        qKDebug() << "Can't init " << address.toString() << ":" << port;
        return false;
    }

    // TODO: recover
    connect(&m_session, &Session::closed, []() {
        qKCritical() << "Session closed, exitting app";
        QCoreApplication::exit(-1);
    });

    return true;
}

}  // namespace kygon::client