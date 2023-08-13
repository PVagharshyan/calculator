#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

double operand_1 = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //numbers
    connect(ui->button_0, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->button_1, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->button_2, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->button_3, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->button_4, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->button_5, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->button_6, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->button_7, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->button_8, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->button_9, SIGNAL(clicked()), this, SLOT(numbers()));
    //operations
    connect(ui->button_add, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->button_sub, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->button_mul, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->button_div, SIGNAL(clicked()), this, SLOT(operations()));

    ui->button_add->setCheckable(true);
    ui->button_sub->setCheckable(true);
    ui->button_mul->setCheckable(true);
    ui->button_div->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numbers() {
    QPushButton *button = (QPushButton*)sender();

    double all_numbers = 0;

    QString updated_label;
    all_numbers = (ui->label->text() + button->text()).toDouble();
    updated_label = QString::number(all_numbers, 'g', 15);
    ui->label->setText(updated_label);
}

void MainWindow::on_button_doc_clicked()
{
    if(!ui->label->text().contains('.')){
        ui->label->setText(ui->label->text() + '.');
    }
}

void MainWindow::on_button_p_clicked()
{
    double all_numbers = (ui->label->text()).toDouble();
    QString updated_label = QString::number(all_numbers * (-1), 'g', 15);
    ui->label->setText(updated_label);
}

void MainWindow::operations() {
    QPushButton *button = (QPushButton*)sender();

    operand_1 = (ui->label->text()).toDouble();
    ui->label->setText("0");
    button->setCheckable(true);
}

void MainWindow::on_button_equ_clicked()
{
    double label_number = 0;
    double operand_2 = 0;
    QString updated_label;

    operand_2 = ui->label->text().toDouble();

    if (ui->button_add->isChecked()) {
        label_number = operand_1 + operand_2;
        updated_label = QString::number(label_number, 'g', 15);

        ui->button_add->setChecked(false);
    }
    else if (ui->button_sub->isChecked()) {
        label_number = operand_1 - operand_2;
        updated_label = QString::number(label_number, 'g', 15);

        ui->button_sub->setChecked(false);
    }
    else if (ui->button_mul->isChecked()) {
        label_number = operand_1 * operand_2;
        updated_label = QString::number(label_number, 'g', 15);

        ui->button_mul->setChecked(false);
    }
    else {
        if (operand_2 == 0) {
            updated_label = QString::number(0, 'g', 15);
        }
        else {
            label_number = operand_1 / operand_2;
            updated_label = QString::number(label_number, 'g', 15);
        }
        ui->button_div->setChecked(false);
    }

    ui->label->setText(updated_label);
}


void MainWindow::on_button_clear_clicked()
{
    ui->label->setText("0");
}

