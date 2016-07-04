#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // MAINFORM_H
