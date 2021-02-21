#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::toDecimal(QVector<int> list) {
    QString rgb_color = "rgb(";
    rgb_color.append(QString::number(list[0]));
    for(int i = 1; i < 3; i++) {
        rgb_color.append(", ");
        rgb_color.append(QString::number(list[i]));
    }

    rgb_color.append(")");
    return rgb_color;
}

QString MainWindow::toHeximal(QVector<int> list) {
    QString hex_color = "#";
    for(int i = 0; i < 3; i++) {
        if(list[i] < 16) {
            hex_color.append("0");
            hex_color.append(QString::number(list[i], 16));
        }
        else if(list[i] > 16) {
            hex_color.append(QString::number(list[i], 16));
        }
    }

    //qDebug() << hex_color;

    return hex_color;
}

void MainWindow::on_red_slider_valueChanged(int value)
{
    ui->red_box->setValue(value);
    ui->current_color->setStyleSheet("border-radius:10px;background-color:rgb(" + QString::number(value)
                                     + "," + QString::number(ui->green_slider->value())
                                     + "," + QString::number(ui->blue_slider->value()) + ");");
    ui->rgb_pallet->setText(toDecimal(QVector<int>{value, ui->green_slider->value(), ui->blue_slider->value()}));
    ui->hex_pallet->setText(toHeximal(QVector<int>{value, ui->green_slider->value(), ui->blue_slider->value()}));
}

void MainWindow::on_green_slider_valueChanged(int value)
{
    ui->green_box->setValue(value);
    ui->current_color->setStyleSheet("border-radius:10px;background-color:rgb(" + QString::number(ui->red_slider->value())
                                     + "," + QString::number(value)
                                     + "," + QString::number(ui->blue_slider->value()) + ");");
    ui->rgb_pallet->setText(toDecimal(QVector<int>{ui->red_slider->value(), value, ui->blue_slider->value()}));
    ui->hex_pallet->setText(toHeximal(QVector<int>{ui->red_slider->value(), value, ui->blue_slider->value()}));
}

void MainWindow::on_blue_slider_valueChanged(int value)
{
    ui->blue_box->setValue(value);
    ui->current_color->setStyleSheet("border-radius:10px;background-color:rgb(" + QString::number(ui->red_slider->value())
                                     + "," + QString::number(ui->green_slider->value())
                                     + "," +QString::number(value)  + ");");
    ui->rgb_pallet->setText(toDecimal(QVector<int>{ui->red_slider->value(), ui->green_slider->value(), value}));
    ui->hex_pallet->setText(toHeximal(QVector<int>{ui->red_slider->value(), ui->green_slider->value(), value}));
}

void MainWindow::on_red_box_valueChanged(int arg1)
{
    ui->red_slider->setValue(arg1);
    on_red_slider_valueChanged(arg1);
}

void MainWindow::on_green_box_valueChanged(int arg1)
{
    ui->green_slider->setValue(arg1);
    on_green_slider_valueChanged(arg1);
}

void MainWindow::on_blue_box_valueChanged(int arg1)
{
    ui->blue_slider->setValue(arg1);
    on_blue_slider_valueChanged(arg1);
}
