#include "secondpage.h"
#include "ui_secondpage.h"
#include "mainwindow.h"
#include "db.h"
using namespace std;
secondPage::secondPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::secondPage)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page_2);

}

secondPage::~secondPage()
{
    delete ui;
}
void secondPage::setTitleText(const QString& str){

    QLabel *lesname = findChild<QLabel*>("label_2");
    lesname->setText("Lesson "+str);
    //QVBoxLayout *widgetLay = findChild<QVBoxLayout*>("verticalLayout_11");
    //QLabel* label1 = new QLabel(QString::fromStdString(db::words504[0][0][lesson_num]));
    //label1->setStyleSheet("color: rgb(170, 0, 0);");
    //widgetLay->addWidget(x);
    //ui->w2->setText("");

    int lesson_num = str.toInt();
    for(int i = 1 ; i<=12;i++){
        QString en_word = QString::fromStdString(db::words504[lesson_num-1][i-1][0]);
        QString tr_word = QString::fromStdString(db::words504[lesson_num-1][i-1][1]);
        QLabel *word = findChild<QLabel*>("w"+QString::number(i));
        word->setText(QString::number(i) +"-  "+ en_word + " : " + tr_word);
    }
}

void secondPage::on_back_btn_words_clicked()
{
    this->close();
    MainWindow *FirstPage = new MainWindow;
    FirstPage->show();
}

void secondPage::on_exam_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}
void secondPage::on_words_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}
void secondPage::on_back_btn_exam_clicked()
{
    this->close();
    MainWindow *FirstPage = new MainWindow;
    FirstPage->show();
}

