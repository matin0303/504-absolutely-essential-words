#include "secondpage.h"
#include "ui_secondpage.h"
#include "mainwindow.h"
#include "db.h"
#include "time.h"
#include <iostream>
#include <string>

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

QString lesson ;
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
    lesson = str;

}

static int question_number = 0;
static int score = 0;
QString trueAnswer ;
void secondPage::setExamPageLabels(const QString &lesson){
    question_number++;
    ui->qs_num_lb->setText(" Question Number : " + QString::number( question_number) + "/20" );
    int lesson_num = lesson.toInt();

    QString randQuestion;
    QString Answer;
    //select random word from db
    srand(time(0));
    int random_word = rand()%12;

    if (question_number <= 4 ){

        randQuestion = QString::fromStdString(db::words504[lesson_num-1][random_word][0]);
        Answer = QString::fromStdString(db::words504[lesson_num-1][random_word][1]);
        trueAnswer = Answer;
        ui->qs_label->setText("What is the Persian equivalent of ' " + randQuestion + " '?" );

        //set random answer on radio buttons
        for(int i = 1 ; i <= 4 ; i++){
            QString randAnswer;
            QRadioButton *radios=findChild<QRadioButton*>("radio"+QString::number(i));
            radios->setChecked(false);
            randAnswer = QString::fromStdString(db::words504[rand()%42][random_word][1]);
            if (randAnswer == Answer){
                if(lesson_num == 42){
                    randAnswer = QString::fromStdString(db::words504[lesson_num-2][random_word][1]);
                }else{
                    randAnswer = QString::fromStdString(db::words504[lesson_num][random_word][1]);
                }
            }
            radios->setText(randAnswer);
        }

        //set currect answer on random Radio button
        srand(time(0));
        int randomRadioNum = rand()%4;
        QRadioButton *trueRadio=findChild<QRadioButton*>("radio"+QString::number(randomRadioNum+1));
        trueRadio->setText(Answer);

    }else if(question_number <= 8){
        randQuestion = QString::fromStdString(db::words504[lesson_num-1][random_word][1]);
        Answer = QString::fromStdString(db::words504[lesson_num-1][random_word][0]);
        trueAnswer = Answer;
        ui->qs_label->setText("What is the English equivalent of ' " + randQuestion + " '?" );

        //set random answer on radio buttons
        for(int i = 1 ; i <= 4 ; i++){
            QString randAnswer;
            QRadioButton *radios=findChild<QRadioButton*>("radio"+QString::number(i));
            radios->setChecked(false);
            randAnswer = QString::fromStdString(db::words504[rand()%42][random_word][0]);
            if (randAnswer == Answer){
                if(lesson_num == 42){
                    randAnswer = QString::fromStdString(db::words504[lesson_num-2][random_word][1]);
                }else{
                    randAnswer = QString::fromStdString(db::words504[lesson_num][random_word][1]);
                }
            }
            radios->setText(randAnswer);
        }

        //set currect answer on random Radio button
        srand(time(0));
        int randomRadioNum = rand()%4;
        QRadioButton *trueRadio=findChild<QRadioButton*>("radio"+QString::number(randomRadioNum+1));
        trueRadio->setText(Answer);

    }else if(question_number <= 20 ){
        srand(time(0));
        int randomSentence = rand()%3+2;
        randQuestion = QString::fromStdString(db::words504[lesson_num-1][random_word][randomSentence]);
        Answer = QString::fromStdString(db::words504[lesson_num-1][random_word][0]);
        trueAnswer = Answer;

        //removing word from sentence and replace "..."
        int pos = randQuestion.indexOf(Answer);
        randQuestion.replace(pos , Answer.length() , " .... " ) ;
        ui->qs_label->setText( randQuestion );

        //set random answer on radio buttons
        for(int i = 1 ; i <= 4 ; i++){
            QString randAnswer;
            QRadioButton *radios=findChild<QRadioButton*>("radio"+QString::number(i));
            radios->setChecked(false);
            randAnswer = QString::fromStdString(db::words504[rand()%42][random_word][0]);
            if (randAnswer == Answer){
                if(lesson_num == 42){
                    randAnswer = QString::fromStdString(db::words504[lesson_num-2][random_word][1]);
                }else{
                    randAnswer = QString::fromStdString(db::words504[lesson_num][random_word][1]);
                }
            }
            radios->setText(randAnswer);
        }

        //set currect answer on random Radio button
        srand(time(0));
        int randomRadioNum = rand()%4;
        QRadioButton *trueRadio=findChild<QRadioButton*>("radio"+QString::number(randomRadioNum+1));
        trueRadio->setText(Answer);
    }else{
        ui->qs_label->setText("Great , your score "+ QString::number( score )+ " of 20");
        ui->qs_num_lb->setText("");
        ui->score_lb->setText("");
        ui->widget_15->setStyleSheet("border:none;");
        ui->widget_25->setStyleSheet("border:none;");
        for(int i = 1 ; i <= 4 ; i++){
            QRadioButton *radios=findChild<QRadioButton*>("radio"+QString::number(i));
            radios->hide();
        }
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
    question_number = 0;
    score = 0 ;

    //reset style after question_num > 20
    ui->score_lb->setText("Score : "+ QString::number(score));
    ui->widget_15->setStyleSheet("border:1px solid black;;");
    ui->widget_25->setStyleSheet("border-right:1px solid black;;");
    for(int i = 1 ; i <= 4 ; i++){
        QRadioButton *radios=findChild<QRadioButton*>("radio"+QString::number(i));
        radios->show();
    }

    setExamPageLabels(lesson);
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
void secondPage::on_radio1_clicked()
{
    QString selectedAnswer = ui->radio1->text();
    if(selectedAnswer == trueAnswer){
        score++;
        ui->score_lb->setText("Score : "+ QString::number(score));
    };
    setExamPageLabels(lesson);
}

void secondPage::on_radio2_clicked()
{
    QString selectedAnswer = ui->radio2->text();
    if(selectedAnswer == trueAnswer){
        score++;
        ui->score_lb->setText("Score : "+ QString::number(score));
    };
    setExamPageLabels(lesson);
}

void secondPage::on_radio3_clicked()
{
    QString selectedAnswer = ui->radio3->text();
    if(selectedAnswer == trueAnswer){
        score++;
        ui->score_lb->setText("Score : "+ QString::number(score));
    };
    setExamPageLabels(lesson);
}
void secondPage::on_radio4_clicked()
{
    QString selectedAnswer = ui->radio4->text();
    if(selectedAnswer == trueAnswer){
        score++;
        ui->score_lb->setText("Score : "+ QString::number(score));
    };
    setExamPageLabels(lesson);
}

