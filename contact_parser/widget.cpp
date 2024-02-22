#include "widget.h"
#include<QPushButton>
#include<QGridLayout>
#include<QTextEdit>
#include<QFileDialog>
#include<QFile>
#include<QTextStream>
#include<QTextCursor>
#include<QTextDocument>
#include<QMessageBox>
#include<QDebug>
#include<QTextCharFormat>
#include<QFont>

Widget::Widget(QWidget *parent)
    : QWidget(parent),loadButton(new QPushButton("Load")),
    processButton(new QPushButton("Process")),
    textEditor(new QTextEdit(this)),
    textDocument(new QTextDocument(this)),
    textCursor(new QTextCursor(textDocument))
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
{  //qDebug()<<"loading file...";
    QString fileName =
        QFileDialog::getOpenFileName(this,
                                    tr("Open File"),
                                    "/home",
                                    tr("Text files (*.txt)"));
    if(fileName.isEmpty()){
        QMessageBox msgBox;
        msgBox.setText("Failed to pick a file. Try again.");
        msgBox.exec();
    }

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox msgBox;
        msgBox.setText("Failed to open file.Try again.");
        msgBox.exec();

    }

    QTextStream cin(&file);
    QString info = cin.readAll();
    //qDebug()<<info;
    textDocument->setPlainText(info);

    textEditor->setDocument(textDocument);

}

void Widget::processFile()
{  //qDebug()<<"processing file...";

    QTextCursor cursor(textDocument);

    cursor.movePosition(QTextCursor::Start);
    while(!cursor.atEnd()){//qDebug() << "formating file...";
        cursor = textDocument->find(emailExpress,cursor);
        if(!cursor.isNull()){
            QTextCharFormat format;
            format.setFontWeight(QFont::Bold);
            cursor.mergeCharFormat(format);

        }else{
            break;
        }
    }

    cursor.movePosition(QTextCursor::Start);
    while(!cursor.atEnd()){//qDebug() << "formating file...";
        cursor = textDocument->find(phoneExpress,cursor);
        if(!cursor.isNull()){
            QTextCharFormat format;
            format.setFontWeight(QFont::Bold);
            cursor.mergeCharFormat(format);

        }else{
            break;
        }
    }
}


