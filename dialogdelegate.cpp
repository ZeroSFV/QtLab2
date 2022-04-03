#include "dialogdelegate.h"
#include "QtWidgets"
#include "editdogdialog.h"

DialogDelegate::DialogDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent)
{
    dparentWidget = parentWidget;
}

bool DialogDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                 const QStyleOptionViewItem &, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick) {
        EditDogDialog* editDialog = new EditDogDialog(dparentWidget);

        QString id = model->data(model->index(index.row(), 0, index)).toString();
        QString name = model->data(model->index(index.row(), 1, index)).toString();
        QString age = model->data(model->index(index.row(), 2, index)).toString();
        QString breed = model->data(model->index(index.row(), 3, index)).toString();
        QString owner = model->data(model->index(index.row(), 4, index)).toString();

        editDialog->setUpDialog(id, name, age, breed, owner);

        if (editDialog->exec() == QDialog::Accepted) {
            model->setData(model->index(index.row(), 0, index), editDialog->id());
            model->setData(model->index(index.row(), 1, index), editDialog->name());
            model->setData(model->index(index.row(), 2 , index), editDialog->age());
            model->setData(model->index(index.row(), 3, index), editDialog->breed());
            model->setData(model->index(index.row(), 4, index), editDialog->owner());

            editDialog->deleteLater();
        }
    }
    return false;
}

QWidget *DialogDelegate::createEditor(QWidget* /* parent */,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    return nullptr;
}
