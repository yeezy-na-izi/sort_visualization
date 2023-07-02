#include "sortingwindow.h"
#include "ui_SortingWindow.h"
#include <iostream>
#include "../utils/sortings.h"
#include <chrono>
#include <thread>


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
    QValidator *array_size_validator = new QIntValidator(1, 31, this);

    ui->min_value_input->setValidator(min_value_validator);
    ui->max_value_input->setValidator(max_value_validator);
    ui->length_input->setValidator(array_size_validator);

    ui->min_value_input->setText("0");
    ui->max_value_input->setText("100");
    ui->length_input->setText("10");
}

void SortingWindow::connectSignals() {
    connect(ui->generate, &QPushButton::clicked, this, &SortingWindow::generateRandomArray);
    connect(ui->sort, &QPushButton::clicked, this, &SortingWindow::sortArray);
}

void SortingWindow::refresh_array() {
    ui->array->clear();
    ui->array->setRowCount(1);
    ui->array->setColumnCount(static_cast<int>(m_array.size()));

    for (int i = 0; i < m_array.size(); i++) {
        ui->array->setItem(0, i, new QTableWidgetItem(QString::number(m_array[i])));
    }
}

void SortingWindow::refresh_array(std::pair<int, int> indexes, bool is_swap) {
    ui->array->clear();
    ui->array->setRowCount(1);
    ui->array->setColumnCount(static_cast<int>(m_array.size()));
    auto color = is_swap ? Qt::red : Qt::green;
    if (is_swap) {
        std::swap(m_array[indexes.first], m_array[indexes.second]);
    }

    for (int i = 0; i < m_array.size(); i++) {
        auto item = new QTableWidgetItem(QString::number(m_array[i]));
        if (i == indexes.first || i == indexes.second) {
            item->setBackground(QBrush(color));
        }
        ui->array->setItem(0, i, item);
    }
}

void SortingWindow::generateRandomArray() {
    ui->array->clear();
    m_array.clear();
    int min_value = ui->min_value_input->text().toInt();
    int max_value = ui->max_value_input->text().toInt();
    int length = ui->length_input->text().toInt();

    if (length > 31) {
        return;
    }
    m_array = random_gen(length, min_value, max_value);

    refresh_array();
}


void SortingWindow::sortArray() {
    std::string sort_type = ui->sort_selection->currentText().toStdString();

    if (m_array.empty()) {
        return;
    }

    Sorting *sort;
    if (sort_type == "Bubble sort") {
        sort = new BubbleSort(m_array);
    } else if (sort_type == "Selection sort") {
        sort = new SelectionSort(m_array);
    } else if (sort_type == "Quick sort") {
        sort = new QuickSort(m_array);
    } else {
        return;
    }

    refresh_array();
    while (!sort->isFinished()) {
        auto indexes_and_bool = sort->nextStep();
        auto indexes = indexes_and_bool.first;
        bool is_swapped = indexes_and_bool.second;
        refresh_array(indexes, is_swapped);
        QApplication::processEvents();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}