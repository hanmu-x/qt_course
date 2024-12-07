#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    // 自定义信号函数
    void mySignal();


private slots:
    // 鼠标右键选择转到槽函数,会自动生成
    void on_no_ui_clicked();
    void on_btnCon_clickedMyself();
    void on_fortch_clicked();

    // 自定义槽函数
    void mySlog();


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
