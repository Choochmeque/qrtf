#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qrtfreader.h"

#include <QFileDialog>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Open_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "", "/Volumes/Data/Development/QRtf/RtfTest", "*.rtf");

    if (filename.isEmpty()) {
        return;
    }

    QFile f(filename);
    f.open(QIODevice::ReadOnly);

    QRtfReader reader(f.readAll());

    ui->textBrowser->setHtml(reader.toHtml());
}
