#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <QObject>

class UserManagement : public QObject
{
    Q_OBJECT
public:
    explicit UserManagement(QObject *parent = nullptr);

signals:
};

#endif // USERMANAGEMENT_H
