#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QRegExpValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Bubble sort");
    ui->comboBox->addItem("Quick sort");
    ui->comboBox->addItem("Insertions sort");
    ui->comboBox->addItem("Select sort");
    ui->comboBox->addItem("Merge sort");
    ui->comboBox->addItem("Shell sort");

   // bSort = new BubbleSort<int>(arrayPtr, 10);
//    iSort = new InsertionSort<int>(arrayPtr, 10);
//    sSort = new SelectionSort<int>(arrayPtr, 10);

    arrayPtr = nullptr;
    len = 0;

    tm.setInterval(100);
    connect(&tm, SIGNAL(timeout()), this, SLOT(update()));

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    if ((len > 0) && (arrayPtr))
    {
        qDebug()<<"Len:"<<len;
        QPainter painter(this);
        painter.setBrush(QColor::fromRgb(205, 235, 99));
        QRect rect(0, 0, width(), height()/2);
        painter.fillRect(rect, painter.brush());
        painter.drawRect(rect);
        painter.setBrush(QColor::fromRgb(99, 235, 128));

        for (int i = 0; i < len; i++)
        {
            if (i == 1)painter.setBrush(QColor::fromRgb(99, 189, 235));
            QRect rect(40*i, height()/2, 35, -arrayPtr[i]);
            painter.fillRect(rect, painter.brush());
            painter.drawRect(rect);
            painter.drawText(40*i+5, height()/2-10, QString::number((arrayPtr[i]- 40)/10));

        }
    }
}

void MainWindow::update(void)
{
    if (ui->comboBox->currentText()=="Bubble sort")
    {
        if ((bSort->sorted()) && (bSort != nullptr))
        {
            delete bSort;
            bSort = nullptr;
            tm.stop();
        } else {
            bSort->step();
        }

    } else if (ui->comboBox->currentText()=="Insertions sort")
    {
        iSort->step();
    } else if (ui->comboBox->currentText()=="Select sort")
    {
        sSort->step();
    }
    repaint();
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    bSort = new BubbleSort<int>(arrayPtr, len);
    tm.start();
}

void MainWindow::on_pushButton_2_clicked()
{
    tm.stop();
}

void MainWindow::on_pushButton_3_clicked()
{
    if (arrayPtr != nullptr) delete [] arrayPtr;
    len = 0;

    QString str = ui->textEdit->toPlainText().trimmed();
    if(str.isEmpty()) return;

    QStringList list = str.split(" ",QString::SkipEmptyParts);
    len = list.size();
    arrayPtr = new int [len];


    int i = 0;
     foreach(QString num, list)
     {
          arrayPtr[i] = 40+num.toInt()*10;
          i++;
     }

     repaint();
}


