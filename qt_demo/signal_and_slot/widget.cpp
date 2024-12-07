#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent) , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // ui中的按钮为信号,下面定义参函数

    //在构造函数中进行信号与槽的绑定
    //第二种方式：QObject::connect(sender, SIGNAL(signal()), receiver, SLOT(slot()));

    // ui->btnCon:按钮的别名, SIGNAL告知监听按钮的什么信号, this:谁来相应, SLOT槽函数干什么
    QObject::connect(ui->btnCon, SIGNAL(clicked()), this, SLOT(on_btnCon_clickedMyself()));

    //第三方式：lambda表达式：QObject::connect(sender, &Sender::signal, [=]() { /* lambda body */ });
    QObject::connect(ui->btnLambda, &QPushButton::clicked,[=](){
        std::cout << "btnLambdaClicked" << std::endl;
    });

    //第四种方式：QObject::connect(sender, &Sender::signal, receiver, &Receiver::slot);
    QObject::connect(ui->btnFortch,&QPushButton::clicked,this,&Widget::on_fortch_clicked);

    // 连接自定义的信号和槽函数
    QObject::connect(this,SIGNAL(mySignal()),this,SLOT(mySlog()));
    emit mySignal();

}

Widget::~Widget()
{
    delete ui;
}

//第一种方式：通过uiDesigner
//鼠标右键选择转到槽函数,会自动生成跳转到这里
void Widget::on_no_ui_clicked()
{
    std::cout<<"ui1"<<std::endl;
}

void Widget::on_btnCon_clickedMyself()
{
    std::cout<<"btnCon"<<std::endl;
}

void Widget::on_fortch_clicked()
{
    std::cout<<"fortch"<<std::endl;
}


void Widget::mySlog()
{
    std::cout<<"mySlog"<<std::endl;
}


