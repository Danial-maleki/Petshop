#ifndef USER_H
#define USER_H

#include <QObject>
#include "usermanagement.h"
class User : public UserManagement
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr, const QString& u = "", const QString& p = "");
    void login() override;
signals:
};

#endif // USER_H
