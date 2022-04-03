#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"
#include "mymodel.h"
#include "QGridLayout"
#include "linedelegate.h"
#include "editdogdialog.h"
#include "dialogdelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Данные о каталоге кинолога");

    tableView = new QTableView();
    myModel = new MyModel(this);
    tableView->setModel(myModel);

    DialogDelegate* ddel = new DialogDelegate(nullptr, this);

    lineDelegate* ldel = new lineDelegate();
    tableView->setItemDelegateForColumn(0, ddel);
    tableView->setItemDelegateForColumn(1, ldel);
    tableView->setItemDelegateForColumn(2, ldel);
    tableView->setItemDelegateForColumn(3, ldel);
    tableView->setItemDelegateForColumn(4, ldel);
    tableView->viewport()->setAttribute(Qt::WA_Hover);

    QGridLayout* glay= new QGridLayout();
    glay->addWidget(tableView, 1, 1, 1, 2);

    QPushButton* pbtn1 = new QPushButton("Добавить собаку");
    QPushButton* pbtn2 = new QPushButton("Удалить собаку");

    glay->addWidget(pbtn1, 2, 1);
    glay->addWidget(pbtn2, 2, 2);

    QObject::connect(pbtn1, SIGNAL(clicked(bool)), this, SLOT(AddRow()));
    QObject::connect(pbtn2, SIGNAL(clicked(bool)), this, SLOT(DeleteRow()));

    QWidget* wdg=new QWidget();
    wdg->setLayout(glay);
    this->setCentralWidget(wdg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddRow()
{
    EditDogDialog* addDialog = new EditDogDialog(this);
    if (addDialog->exec() == QDialog::Accepted) {
        Dog* std = new Dog(addDialog->id(), addDialog->name(), addDialog->age(), addDialog->breed(), addDialog->owner(), this);
        myModel->AddDog(std);
    }

    addDialog->deleteLater();
}

void MainWindow::DeleteRow()
{
    QModelIndex selList = tableView->currentIndex();
    myModel->DeleteDog(selList.row());
}
