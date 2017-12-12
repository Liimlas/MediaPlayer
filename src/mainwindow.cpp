#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QtWidgets/QPushButton>
#include <QFileDialog>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->playButton->setIcon(QIcon(("/u/38/liimatl3/unix/Desktop/play.png")));
    //QTreeView* asd = this->findChild<QTreeView*>("treeView");
    fileList = new FileList(ui->treeView);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete fileList;
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
    std::cout << file.toStdString() << std::endl;
    if (!_player.OpenMusic(file.toStdString())) {
        return; // error
    }

    ui->playingLabel->setText(file);
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    _player.SetVolume((float)position);
}

void MainWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
    QString filePath = fileList->getSongPath(index);
    if(!_player.OpenMusic(filePath.toStdString())){
        std::cout << "Could not open file" << filePath.toStdString() << std::endl;
    }
    ui->playingLabel->setText(filePath);
}
