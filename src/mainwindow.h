#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "player.h"
#include "filelist.h"
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void SetButtons(bool state);
    void setValue(QMediaPlayer::State state);

    void positionSliderUpdate(qint64 position);
    void setSongDuration(qint64 position);
    void loadSelectedSong(const QModelIndex &);
    void playNextSong();
    void updateSongData();

private slots:
    void on_playButton_clicked();

    void on_forwardButton_clicked();

    void on_backwardButton_clicked();

    void on_openButton_clicked();

    void on_treeView_doubleClicked(const QModelIndex &index);

    void OpenFile(QString path);

    void on_volumeSlider_valueChanged(int value);

    void on_PositionSlider_sliderReleased();

    void on_pushButton_clicked();

    void on_loopButton_toggled(bool checked);

    void on_searchLabel_textChanged();

private:
    Ui::MainWindow *ui;
    Player *_player;
    FileList *fileList;
    bool loopOn = false;
};

#endif // MAINWINDOW_H
