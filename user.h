#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User(const int& id, const QString& name, const char& access);
    ~User();
    int getId() const;
    QString getName() const;
    char getAccess() const;

private:
    const int *id;
    const QString *name;
    const char *access;
};

#endif // USER_H
