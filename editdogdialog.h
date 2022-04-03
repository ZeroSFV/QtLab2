#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "Dog.h"

class EditDogDialog : public QDialog
{
    Q_OBJECT

private:
    QLineEdit* editID;
    QLineEdit* editName;
    QLineEdit* editAge;
    QLineEdit* editBreed;
    QLineEdit* editOwner;

public:
    EditDogDialog(QWidget* pwgt = nullptr);

    QString id() const;
    QString name() const;
    QString age() const;
    QString breed() const;
    QString owner() const;

    void setUpDialog(QString id, QString name, QString age, QString breed, QString owner);
};

#endif // INPUTDIALOG_H
