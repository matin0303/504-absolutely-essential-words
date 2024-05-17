#include "secondpage.h"
#include "ui_secondpage.h"
#include "mainwindow.h"
#include "db.h"
#include "time.h"
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
int qusetion_number = 0;
void secondPage::setExamPageLabels(const QString &lesson){
    qusetion_number++;
    ui->qs_num_lb->setText(" Question Number : " + QString::number( qusetion_number) + "/20" );
    int lesson_num = lesson.toInt();
    srand(time(0));
    int random_word = rand()%12;
    QString randQuestion = QString::fromStdString(db::words504[lesson_num-1][random_word][0]);
    QString Answer = QString::fromStdString(db::words504[lesson_num-1][random_word][1]);
    ui->qs_label->setText(randQuestion + Answer );
    //set random answer on radio buttons
    for(int i = 1 ; i <= 4 ; i++){
        QString randAnswer;
        QRadioButton *radios=findChild<QRadioButton*>("radio"+QString::number(i));
        randAnswer = QString::fromStdString(db::words504[rand()%42][random_word][1]);
        if (randAnswer == Answer){
            randAnswer = QString::fromStdString(db::words504[lesson_num][random_word][1]);
        }
        radios->setText(randAnswer);
    }
    //set currect answer on random Radio button
    srand(time(0));
    int randomRadioNum = rand()%4;
    QRadioButton *trueRadio=findChild<QRadioButton*>("radio"+QString::number(randomRadioNum+1));
    trueRadio->setText(Answer);
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
    setExamPageLabels("1");
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

