#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QPushButton>
#include <QFileDialog>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->playButton->setIcon(QIcon(("/u/38/liimatl3/unix/Desktop/play.png")));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playButton_clicked()
{
    std::cout << "Play music" << std::endl;
    if (_player.Playing()) {

    }
    _player.Play();
}


void MainWindow::on_forwardButton_clicked()
{

}

void MainWindow::on_backwardButton_clicked()
{

}

void MainWindow::on_openButton_clicked()
{
    auto file = QFileDialog::getOpenFileName(this, tr("Open Music"), "/home/", tr("Music Files (*.wav *.mp3)"));

    if (!_player.OpenMusic(file.toStdString())) {
        printf("Could not open filen\n");
        return; // error
    }

    ui->playingLabel->setText(file);
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    _player.SetVolume((float)position);
}
