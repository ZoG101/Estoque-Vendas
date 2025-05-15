#include "log_in_dao.h"

Log_in_DAO::Log_in_DAO()
{
    this->con = ConnectionFactory::getInstance();
    this->user = nullptr;
}

Log_in_DAO::~Log_in_DAO()
{}

int Log_in_DAO::valid(const QString& user, const QString& password)
{
    if (!this->con->openDB()) return -1;

    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT id, username, senha, nome, acesso FROM tb_colaborador WHERE username = :user and senha = :senha");
    query->bindValue(":user", user);
    query->bindValue(":senha", password);

    if (query->exec()) {

        if (query->first()) {

            if ((query->value(1).toString().compare(user) == 0) and
                (query->value(2).toString().compare(password) == 0)) {
                int id = query->value(0).toInt();

                this->con->closeDB();
                this->user = new User(query->value(0).toInt(), query->value(3).toString(), query->value(4).toString().toStdString().at(0));

                delete query;
                return id;
            } else {
                this->con->closeDB();

                delete query;
                return -2;
            }
        } else {
            this->con->closeDB();

            delete query;
            return -2;
        }
    } else {
        this->con->closeDB();

        delete query;
        return -3;
    }

    this->con->closeDB();

    delete query;
}

User* Log_in_DAO::getUser()
{
    return this->user;
}
