#include "Dog.h"

Dog::Dog(QString ID, QString Name, QString Age, QString Breed, QString Owner, QObject *parent): QObject(parent)
{
    id = ID;
    name = Name;
    age = Age;
    breed = Breed;
    owner = Owner;
}

void Dog::setID(QString ID)
{
    id = ID;
}
void Dog::setName(QString Name)
{
    name = Name;
}
void Dog::setAge(QString Age)
{
    age = Age;
}
void Dog::setBreed(QString Breed)
{
    breed = Breed;
}
void Dog::setOwner(QString Owner)
{
    owner = Owner;
}
QString Dog::ID()
{
    return id;
}
QString Dog::Name()
{
    return name;
}
QString Dog::Age()
{
    return age;
}
QString Dog::Breed()
{
    return breed;
}
QString Dog::Owner()
{
    return owner;
}

 Dog::~Dog()
{
}
