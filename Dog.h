#ifndef CAFE_H
#define CAFE_H

#include "QString"
#include <QObject>

class Dog: public QObject
{
    Q_OBJECT

public:
    Dog(QString ID, QString Name, QString Age, QString Breed, QString Owner, QObject *parent = nullptr);
    virtual ~Dog();

    void setID(QString ID);
    void setName(QString Name);
    void setAge(QString Age);
    void setBreed(QString Breed);
    void setOwner(QString Owner);

    QString ID();
    QString Name();
    QString Age();
    QString Breed();
    QString Owner();

private:
    QString id;
    QString name;
    QString age;
    QString breed;
    QString owner;
};

#endif // CAFE_H
