#ifndef SECONDPAGE_H
#define SECONDPAGE_H
#include <iostream>
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
    class Handel_secondPage;
    void setTitleText(const QString &str);
    void setExamPageLabels(const QString &lesson);


private slots:
    void on_back_btn_words_clicked();


    void on_exam_btn_clicked();

    void on_words_btn_clicked();


    void on_back_btn_exam_clicked();

    void on_radio1_clicked();

    void on_radio2_clicked();

    void on_radio3_clicked();

    void on_radio4_clicked();

private:
    Ui::secondPage *ui;
};

#endif // SECONDPAGE_H
