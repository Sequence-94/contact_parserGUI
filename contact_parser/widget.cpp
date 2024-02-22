#include "widget.h"
#include<QPushButton>
#include<QGridLayout>
#include<QTextEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent),loadButton(new QPushButton("Load")),
    processButton(new QPushButton("Process")),
    textEditor(new QTextEdit(this))
{
    contactParserGui();
    setFixedSize(800,500);
    setWindowTitle("Search");
}

Widget::~Widget() {}

void Widget::contactParserGui()
{
    QGridLayout* layout(new QGridLayout(this));
    layout->addWidget(loadButton,0,0);
    layout->addWidget(processButton,0,1);
    layout->addWidget(textEditor,1,0,6,4);
    setLayout(layout);


    connect(loadButton,&QPushButton::clicked,this,&Widget::loadFile);
    connect(processButton,&QPushButton::clicked,this,&Widget::processFile);
}

void Widget::loadFile()
{

}

void Widget::processFile()
{

}


