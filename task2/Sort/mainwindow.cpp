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
    arrayPtr = nullptr;
    len = 0;
    ui->pushButton->setDisabled(true);
    ui->pushButton_2->setDisabled(true);

    tm.setInterval(500);
    connect(&tm, SIGNAL(timeout()), this, SLOT(update()));

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    if ((len > 0) && (arrayPtr))
    {
        QPainter painter(this);
        painter.setBrush(QColor::fromRgb(205, 235, 99));
        QRect rect(0, 0, width(), height()/2);
        painter.fillRect(rect, painter.brush());
        painter.drawRect(rect);
        painter.setBrush(QColor::fromRgb(99, 235, 128));

        for (int i = 0; i < len; i++)
        {
            if (i == 1)painter.setBrush(QColor::fromRgb(99, 189, 235));
            QRect rect(40*i, height()/2, 35, -arrayPtr[i]*10);
            painter.fillRect(rect, painter.brush());
            painter.drawRect(rect);
            painter.drawText(40*i+5, height()/2-10, QString::number(arrayPtr[i]));

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
            ui->pushButton->setDisabled(true);
            ui->pushButton_2->setDisabled(true);
            ui->pushButton_3->setDisabled(false);
        } else {
            bSort->step();
        }

    } else if (ui->comboBox->currentText()=="Insertions sort")
    {
        if ((iSort->sorted()) && (iSort != nullptr))
        {
            delete iSort;
            iSort = nullptr;
            tm.stop();
            ui->pushButton->setDisabled(true);
            ui->pushButton_2->setDisabled(true);
            ui->pushButton_3->setDisabled(false);
        } else {
            iSort->step();
        }
    } else if (ui->comboBox->currentText()=="Select sort")
    {
        if ((sSort->sorted()) && (sSort != nullptr))
        {
            delete sSort;
            sSort = nullptr;
            tm.stop();
            ui->pushButton->setDisabled(true);
            ui->pushButton_2->setDisabled(true);
            ui->pushButton_3->setDisabled(false);
        } else {
            sSort->step();
        }
    }
    repaint();
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (ui->comboBox->currentText()=="Bubble sort")
    {
        bSort = new BubbleSort<int>(arrayPtr, len);
    } else if (ui->comboBox->currentText()=="Insertions sort")
    {
        iSort = new InsertionSort<int>(arrayPtr, len);
    } else if (ui->comboBox->currentText()=="Select sort")
    {
        sSort = new SelectionSort<int>(arrayPtr, len);
    }
    tm.start();
    ui->pushButton->setDisabled(true);
    ui->pushButton_2->setDisabled(false);
    ui->pushButton_3->setDisabled(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    tm.stop();
    ui->pushButton->setDisabled(true);
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(false);
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
          arrayPtr[i] = num.toInt();
          i++;
     }
     ui->pushButton->setDisabled(false);
     ui->pushButton_2->setDisabled(false);
     ui->pushButton_3->setDisabled(true);
     repaint();
}



void MainWindow::on_horizontalSlider_actionTriggered(int action)
{
    tm.setInterval(ui->horizontalSlider->value()*100);
}

void MainWindow::on_pushButton_4_clicked()
{

//    srand(time(0));
//    for (long long i = 0; i < len; i++)
//    {
//        uint64_t rand_index_1 = static_cast<uint64_t>(rand()) % len;
//        uint64_t rand_index_2 = static_cast<uint64_t>(rand()) % len;
//        swaP(array[rand_index_1], array[rand_index_2]);
//    }
}
