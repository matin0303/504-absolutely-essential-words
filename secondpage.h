#ifndef SECONDPAGE_H
#define SECONDPAGE_H

#include <QDialog>

namespace Ui {
class secondPage;
}

class secondPage : public QDialog
{
    Q_OBJECT


public:
    explicit secondPage(QWidget *parent = nullptr);
    ~secondPage();

private:
    Ui::secondPage *ui;
};

#endif // SECONDPAGE_H
