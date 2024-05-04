#include "secpage.h"
#include "ui_secpage.h"

secPage::secPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::secPage)
{
    ui->setupUi(this);
}

secPage::~secPage()
{
    delete ui;
}
