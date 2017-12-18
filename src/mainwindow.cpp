#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <QStandardPaths>
#include <string>
#include <QString>

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

void MainWindow::setValue(QMediaPlayer::State state)
{
    switch (state) {
        case QMediaPlayer::StoppedState:
            ui->playButton->setText("Play");
            break;
        case QMediaPlayer::PlayingState:
            ui->playButton->setText("Pause");
            break;
        case QMediaPlayer::PausedState:
            ui->playButton->setText("Play");
            break;
    }
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
    _player->Play();

}

void MainWindow::on_openButton_clicked()
{
    auto file = QFileDialog::getOpenFileName(this, tr("Open Music"), QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()), tr("Music Files (*.wav *.mp3)"));
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


void MainWindow::positionSliderUpdate(qint64 position)
{
    auto percent = (float)position / (float)_player->Duration() * 10000.f;
    setSongDuration(position);
    if (!ui->PositionSlider->isSliderDown()) {
        ui->PositionSlider->setValue((int)percent);
    }
}

void MainWindow::setSongDuration(qint64 position)
{
    int fullLength = _player->Duration() / 1000;
    int currentPosition = position / 1000;
    int wholeMinutes = fullLength / 60;

    if(wholeMinutes == 0) {
        std::string text = std::to_string(currentPosition) + "/" + std::to_string(fullLength);
        ui->durationLabel->setText(QString(text.c_str()));
    }
    else {
        ui->durationLabel->setText(QString(std::to_string(fullLength).c_str()));
    }
}

void MainWindow::on_PositionSlider_sliderReleased()
{
    _player->SetPosition(_player->Duration() / 10000 * ui->PositionSlider->value());
}
