#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <tag.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    _player = new Player(this);
    ui->setupUi(this);

    ui->volumeSlider->setValue(50);
    _player->Initialize();
    //Setup songList
    fileList = new FileList(ui->treeView);
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

void MainWindow::on_playButton_clicked()
{
    _player->TogglePlay();
}

//Move forward in fileList
void MainWindow::on_forwardButton_clicked()
{
    QModelIndex index = ui->treeView->indexBelow(ui->treeView->currentIndex());
    //Check if there is next index
    if(index.isValid())
    {
        ui->treeView->setCurrentIndex(index);
        loadSelectedSong(index);
    }
}
//Move backward in fileList
void MainWindow::on_backwardButton_clicked()
{
    QModelIndex index = ui->treeView->indexAbove(ui->treeView->currentIndex());
    //Check if there is index before
    if(index.isValid())
    {
        ui->treeView->setCurrentIndex(index);
        loadSelectedSong(index);
    }
}

void MainWindow::playNextSong()
{
    //Check if song has ended
    if(_player->Duration() != -1 && _player->Duration() <= _player->getCurrentPosition()){
        //Check if looping is on
        if(loopOn) {
            loadSelectedSong(ui->treeView->currentIndex());
        }
        else {
            on_forwardButton_clicked();
        }
    }
}
void MainWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
    loadSelectedSong(index);

}
void MainWindow::loadSelectedSong(const QModelIndex &index){
    //Get file path
    QString filePath = fileList->getSongPath(index);

    //Parse id3 tag from current song file
    TagLib::Tag *tag = fileList->getCurrentTag();
    auto text = tag->artist() +"\n"+ tag->title().toCString();

    //Update all the fields to use
    ui->playingLabel->setText(QString(text.toCString()));
    ui->AlbumInput->setText(tag->album().toCString());
    ui->TitleInput->setText(tag->title().toCString());
    ui->ArtistInput->setText(tag->artist().toCString());
    ui->CommentInput->setText(tag->comment().toCString());
    OpenFile(filePath);
    _player->Play();
}

void MainWindow::on_openButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 QDir::homePath(),
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    fileList->changeDirectory(dir);
}


void MainWindow::OpenFile(QString path)
{
    if (!_player->OpenMusic(path)) {
        return; // error
    }
    SetButtons(true);
    QFileInfo fi(path);
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


    std::string ternaryStr1 = (currentPosition % 60) < 10 ? ("0" + std::to_string(currentPosition % 60)) : std::to_string(currentPosition % 60);
    std::string ternaryStr2 = (fullLength % 60) < 10 ?("0" + std::to_string(fullLength % 60)) : std::to_string(fullLength % 60);
    std::string text = std::to_string(currentPosition / 60) + ":" + ternaryStr1 + "/" + std::to_string(fullLength / 60) + ":" + ternaryStr2;
    ui->durationLabel->setText(QString(text.c_str()));std::string search = "";
    QStringList NameList("asd");
}

void MainWindow::on_PositionSlider_sliderReleased()
{
    _player->SetPosition(_player->Duration() / 10000 * ui->PositionSlider->value());
}

void MainWindow::on_pushButton_clicked()
{
    TagLib::Tag *tag = fileList->getCurrentTag();
    tag->setAlbum(ui->AlbumInput->text().toStdString().c_str());
    tag->setArtist(ui->ArtistInput->text().toStdString().c_str());
    tag->setTitle(ui->TitleInput->text().toStdString().c_str());
    tag->setComment(ui->CommentInput->text().toStdString().c_str());

    auto text = tag->artist() +"\n"+ tag->title().toCString();
    ui->playingLabel->setText(QString(text.toCString()));
    fileList->saveMetadata();
}

void MainWindow::on_loopButton_toggled(bool checked)
{
    loopOn = checked;
}


void MainWindow::on_searchLabel_textChanged()
{
    QString search = ui->searchLabel->toPlainText();
    fileList->onSearch(search);
}
