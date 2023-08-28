#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QDialog>

namespace Ui {
class addfriend;
}

class addfriend : public QDialog
{
    Q_OBJECT

public:
    explicit addfriend(QWidget *parent = nullptr);
    ~addfriend();

private:
    Ui::addfriend *ui;
};

#endif // ADDFRIEND_H
