#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QPushButton;
class QTextEdit;
class QTextDocument;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void contactParserGui();
private slots:
    void loadFile();
    void processFile();
private:
    QPushButton *loadButton;
    QPushButton *processButton;
    QTextEdit *textEditor;
    QTextDocument *textDocument;
};
#endif // WIDGET_H
