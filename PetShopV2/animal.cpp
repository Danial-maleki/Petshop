#include "animal.h"
QString Animal::filename = QDir::currentPath() + QDir::separator() + "log.txt";
bool Animal::logging = false;


static const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

Animal::Animal(const QString &name, int price)
    : m_name(name), m_price(price)
{
}

Animal::~Animal()
{
}

QString Animal::getName() const
{
    return m_name;
}

int Animal::getPrice() const
{
    return m_price;
}



void Animal::attach()
{
    Animal::logging = true;
    qInstallMessageHandler(Animal::handler);
}

void Animal::handler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if (Animal::logging) {
        QString txt;
        switch (type) {
        case QtInfoMsg:
            txt = QString("Info: %1").arg(msg);
            break;
        case QtDebugMsg:
            txt = QString("Debug: %1").arg(msg);
            break;
        case QtWarningMsg:
            txt = QString("Warning: %1").arg(msg);
            break;
        case QtCriticalMsg:
            txt = QString("Critical: %1").arg(msg);
            break;
        case QtFatalMsg:
            txt = QString("Fatal: %1").arg(msg);
            break;
        }


        QFile file(Animal::filename);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream ts(&file);
            ts << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ")<<txt<<context.file<<":"<<context.line;
            ts.flush();
            file.close();
        }


        (*QT_DEFAULT_MESSAGE_HANDLER)(type, context, msg);
    }
}
