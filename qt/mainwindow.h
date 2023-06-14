#pragma once

#include <QMainWindow>
#include "sortingwindow.h"


namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow();

    ~MainWindow() override;

    void switchToSortingWindow();

private:
    Ui::MainWindow *ui;

    SortingWindow *m_sortingWindow;

    void setupAdditionalUi();

    void connectSignals();

};

extern MainWindow *g_main_window;