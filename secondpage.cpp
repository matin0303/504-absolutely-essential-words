#include "secondpage.h"
#include "ui_secondpage.h"

secondPage::secondPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::secondPage)
{
    ui->setupUi(this);
}

secondPage::~secondPage()
{
    delete ui;
}
