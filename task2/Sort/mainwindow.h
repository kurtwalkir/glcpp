#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QTime>
#include "sorting.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *event);
    QTimer tm;

private:
    Ui::MainWindow *ui;
    BubbleSort<int> *bSort;
    int higthValue[10];

private slots:
    void update(void);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

};
#endif // MAINWINDOW_H
