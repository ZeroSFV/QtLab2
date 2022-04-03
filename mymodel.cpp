#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{
    Dog* std1 = new Dog("1", "Лайка", "3", "Такса", "Власова Нина Алексеевна", this);
    Dog* std2 = new Dog("2", "Макс", "5","Немецкая овчарка", "Баксова Мария Викторовна", this);
    Dog* std3 = new Dog("3", "Луна", "4", "Лабрадор-ретривер", "Акимова Вера Дмитриевна", this);
    AddDog(std1);
    AddDog(std2);
    AddDog(std3);
}

int MyModel::rowCount(const QModelIndex &) const
{
    return dogs.count();
}

int MyModel::columnCount(const QModelIndex &) const
{
    return 5;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        QString Value = "";
        Dog* std = dogs.at(index.row());
        if (index.column() == 0) { Value = std->ID(); }
        else if (index.column() == 1) { Value = std->Name(); }
        else if (index.column() == 2) { Value = std->Age(); }
        else if (index.column() == 3) { Value = std->Breed(); }
        else if (index.column() == 4) { Value = std->Owner(); }
        else { Value = ""; };
        return Value;
    }
    return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Имя");
            case 2:
                return QString("Возраст");
            case 3:
                return QString("Порода");
            case 4:
                return QString("ФИО владельца");
            }
        }
    }
    return QVariant();
}

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
   if (role == Qt::EditRole) {
        Dog* std = dogs.at(index.row());
        if (index.column() == 0) { std->setID(value.toString()); }
        else if (index.column() == 1) { std->setName(value.toString()); }
        else if (index.column() == 2) { std->setAge(value.toString()); }
        else if (index.column() == 3) { std->setBreed(value.toString()); }
        else if (index.column() == 4) { std->setOwner(value.toString()); }
   }
   return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex &/*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void MyModel::AddDog(Dog* dog)
{
    beginInsertRows(QModelIndex(), dogs.size(), dogs.size());
    dogs.append(dog);
    endInsertRows();    
}

void MyModel::DeleteDog(int row)
{
    beginRemoveRows(QModelIndex(), row, row);
    dogs.removeAt(row);
    endRemoveRows();
}

