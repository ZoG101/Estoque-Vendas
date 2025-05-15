#include "user.h"

User::User(const int& id, const QString& name, const char& access)
{
    this->id = new int(id);
    this->name = new QString(name);
    this->access = new char(access);
}

User::~User()
{
    delete id;
    delete name;
    delete access;
}

int User::getId() const
{
    return *this->id;
}

QString User::getName() const
{
    return *this->name;
}

char User::getAccess() const
{
    return *this->access;
}
