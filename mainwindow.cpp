#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //string Notation
    //connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(changeText()));

    //connect used Functor notation : Regular Slots
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::changeText);

    //Functor Notation : Lambdas
    /*connect(ui->pushButton,&QPushButton::clicked,[=](){
            ui->label->setText("LAMBDA HELLO");
    });
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeText()
{
    std::cout << "button is pressed" << std::endl;
    ui->label->setText("HELLO USER!");
}

