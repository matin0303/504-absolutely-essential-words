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
    void setTitleText(const QString &str);


private slots:
    void on_back_btn_words_clicked();


    void on_exam_btn_clicked();

    void on_words_btn_clicked();


    void on_back_btn_exam_clicked();

private:
    Ui::secondPage *ui;
};

#endif // SECONDPAGE_H
