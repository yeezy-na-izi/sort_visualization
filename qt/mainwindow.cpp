#include "mainwindow.h"
#include "ui_MainWindow.h"

MainWindow *g_main_window = nullptr;

MainWindow::MainWindow() : QMainWindow(nullptr), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    g_main_window = this;

    setupAdditionalUi();
    connectSignals();

    switchToSortingWindow();
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::switchToSortingWindow() {
    auto *sortingWindow = new SortingWindow(this);
    m_sortingWindow = sortingWindow;
    ui->mainContainer->addWidget(sortingWindow);
    sortingWindow->show();
}

void MainWindow::setupAdditionalUi() {
    ui->menuBar->setVisible(true);
    setWindowState(Qt::WindowFullScreen);
}

void MainWindow::connectSignals() {

}