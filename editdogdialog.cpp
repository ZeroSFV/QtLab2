#include "editdogdialog.h"
#include "Dog.h"

EditDogDialog::EditDogDialog(QWidget* pwgt): QDialog(pwgt)
{
    editID = new QLineEdit();
    editName = new QLineEdit();
    editAge = new QLineEdit();
    editBreed = new QLineEdit();
    editOwner = new QLineEdit();

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel("ID"), 1, 1);
    mainLayout->addWidget(editID, 1, 2);
    mainLayout->addWidget(new QLabel("Имя"), 2, 1);
    mainLayout->addWidget(editName, 2, 2);
    mainLayout->addWidget(new QLabel("Возраст"), 3, 1);
    mainLayout->addWidget(editAge, 3, 2);
    mainLayout->addWidget(new QLabel("Порода"), 4, 1);
    mainLayout->addWidget(editBreed, 4, 2);
    mainLayout->addWidget(new QLabel("ФИО владельца"), 5, 1);
    mainLayout->addWidget(editOwner, 5, 2);

    QPushButton* btnOk = new QPushButton("&ОК");

    mainLayout->addWidget(btnOk, 6, 1, 1, 2);

    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Данные о каталоге кинолога");

    //Располагаем диалог над основным окном
    int gx = 100;
    int gy = 100;
    if (pwgt != nullptr) {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();
    }
    this->setGeometry(gx+10, gy+10, 300, 150);
}

QString EditDogDialog::id() const
{
    return editID->text();
}
QString EditDogDialog::name() const
{
    return editName->text();
}
QString EditDogDialog::age() const
{
    return editAge->text();
}
QString EditDogDialog::breed() const
{
    return editBreed->text();
}
QString EditDogDialog::owner() const
{
    return editOwner->text();
}

void EditDogDialog::setUpDialog(QString id, QString name, QString age, QString breed, QString owner)
{
    editID->setText(id);
    editName->setText(name);
    editAge->setText(age);
    editBreed->setText(breed);
    editOwner->setText(owner);
}
