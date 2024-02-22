#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QPushButton;
class QTextEdit;
class QTextDocument;
class QTextCursor;
#include<QRegularExpression>

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
    const QRegularExpression phoneExpress{"\\b(?:\\((\\d{3})\\)\\d{7}|\\((\\d{3})\\)\\d{3}-\\d{4}|(\\d{3}-\\d{3}-\\d{4})|(\\d{3}-\\d{7})|(\\d{10}))\\b"};
    const QRegularExpression emailExpress{"\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,}\\b"};
    QTextCursor *textCursor;

};
#endif // WIDGET_H
