#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QtWidgets/QPushButton>
#include <QFileDialog>
#include <iostream>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    _player = new Player(this);
    ui->setupUi(this);
    fileList = new FileList(ui->treeView);
    ui->volumeSlider->setValue(50);
    ui->playingLabel->setText("");
    _player->Initialize();

    SetButtons(false);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete fileList;
}


void MainWindow::SetButtons(bool state) {
    ui->backwardButton->setEnabled(state);
    ui->forwardButton->setEnabled(state);
    ui->playButton->setEnabled(state);
}

// Todo
void MainWindow::on_playButton_clicked()
{
    _player->TogglePlay();
}


void MainWindow::on_forwardButton_clicked()
{

}

void MainWindow::on_backwardButton_clicked()
{

}


void MainWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
    auto filePath = fileList->getSongPath(index);
    OpenFile(filePath);

}

void MainWindow::on_openButton_clicked()
{
    auto file = QFileDialog::getOpenFileName(this, tr("Open Music"), QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()), tr("Music Files (*.wav *.mp3)"));
    std::cout << file.toStdString() << std::endl;
    OpenFile(file);
}


void MainWindow::OpenFile(QString path)
{
    if (!_player->OpenMusic(path)) {
        return; // error
    }


    SetButtons(true);
    QFileInfo fi(path);
    ui->playingLabel->setText(fi.fileName());
}

void MainWindow::on_volumeSlider_valueChanged(int position)
{
    _player->SetVolume((float)position);
}

void MainWindow::SetPlaying() {
    ui->playButton->setText("Pause");
}

void MainWindow::SetPaused() {
    ui->playButton->setText("Play");
}
