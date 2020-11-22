#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Bubble sort");
    ui->comboBox->addItem("Quick sort");
    ui->comboBox->addItem("Insertions sort");
    ui->comboBox->addItem("Merge sort");
    ui->comboBox->addItem("Shell sort");


    for (int i = 0; i < 10; i++)
            higthValue[i] = 40+i*10;

    bSort = new BubbleSort<int>(higthValue, 10);

    tm.setInterval(100);
    connect(&tm, SIGNAL(timeout()), this, SLOT(update()));

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setBrush(QColor::fromRgb(205, 235, 99));
    QRect rect(0, 0, width(), height()/2);
    painter.fillRect(rect, painter.brush());
    painter.drawRect(rect);
    painter.setBrush(QColor::fromRgb(99, 235, 128));

    for (int i = 0; i < 10; i++)
    {
        if (i == 1)painter.setBrush(QColor::fromRgb(99, 189, 235));
        QRect rect(40*i, height()/2, 35, -higthValue[i]);
        painter.fillRect(rect, painter.brush());
        painter.drawRect(rect);
        painter.drawText(40*i+5, height()/2-10, QString::number((higthValue[i]- 40)/10));

    }
}

void MainWindow::update(void)
{
    bSort->step();
    repaint();
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    tm.start();
}

void MainWindow::on_pushButton_2_clicked()
{
    tm.stop();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString str = ui->textEdit->toPlainText().trimmed();
    if(str.isEmpty()) return;

    QStringList list = str.split(" ",QString::SkipEmptyParts);
    int i = 0;
     foreach(QString num, list)
     {
          higthValue[i] = 40+num.toInt()*10;
          i++;
     }
     repaint();


}
