#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //虽然上面一行代码进行widget和ui的窗口关联，但是如果发生窗口大小变化的时候，里面的布局不会随之变化
    //通过下面这行代码进行显示说明，让窗口变化时，布局及其子控件随之调整
    this->setLayout(ui->verticalLayout);

}

Widget::~Widget()
{
    delete ui;
}

