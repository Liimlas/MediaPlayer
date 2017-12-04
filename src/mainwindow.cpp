#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <SFML/Audio.hpp>
#include <QtWidgets/QPushButton>
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

sf::Music music;
void MainWindow::on_playButton_clicked()
{
    std::cout << "Play music" << std::endl;
    if (!music.openFromFile("/u/38/liimatl3/unix/Desktop/dankshit.wav"))
        return; // error
    music.play();
}


void MainWindow::on_forwardButton_clicked()
{

}

void MainWindow::on_backwardButton_clicked()
{

}
