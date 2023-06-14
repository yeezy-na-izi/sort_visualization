#pragma once

#include <QWidget>
#include <vector>
#include "../utils/random_generator.h"

namespace Ui { class SortingWindow; }


class SortingWindow : public QWidget {
Q_OBJECT

public:
    explicit SortingWindow(QWidget *parent = nullptr);

    ~SortingWindow() override;

    void setupAdditionalUi();

    void connectSignals();

private slots:

    void generateRandomArray();

private:
    Ui::SortingWindow *ui;

    std::vector<int> m_array;
};

