#include "sortingwindow.h"
#include "ui_SortingWindow.h"
#include <iostream>


SortingWindow::SortingWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::SortingWindow) {
    ui->setupUi(this);

    setupAdditionalUi();
    connectSignals();
}

SortingWindow::~SortingWindow() {
    delete ui;
}


void SortingWindow::setupAdditionalUi() {
    QValidator *min_value_validator = new QIntValidator(-999, 999, this);
    QValidator *max_value_validator = new QIntValidator(-999, 999, this);
    QValidator *array_size_validator = new QIntValidator(1, 100, this);

    ui->min_value_input->setValidator(min_value_validator);
    ui->max_value_input->setValidator(max_value_validator);
    ui->length_input->setValidator(array_size_validator);

    ui->min_value_input->setText("0");
    ui->max_value_input->setText("100");
    ui->length_input->setText("10");
}

void SortingWindow::connectSignals() {
    connect(ui->generate, &QPushButton::clicked, this, &SortingWindow::generateRandomArray);
}

void SortingWindow::generateRandomArray() {
    int min_value = ui->min_value_input->text().toInt();
    int max_value = ui->max_value_input->text().toInt();
    int length = ui->length_input->text().toInt();

    m_array = random_gen(length, min_value, max_value);

    for (auto i: m_array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

}