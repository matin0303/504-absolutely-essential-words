#ifndef SECPAGE_H
#define SECPAGE_H

#include <QWidget>

namespace Ui {
class secPage;
}

class secPage : public QWidget
{
    Q_OBJECT

public:
    explicit secPage(QWidget *parent = nullptr);
    ~secPage();

private:
    Ui::secPage *ui;
};

#endif // SECPAGE_H
