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

private slots:
    void on_playButton_clicked();

    void on_forwardButton_clicked();

    void on_backwardButton_clicked();

    void on_openButton_clicked();

    void on_treeView_doubleClicked(const QModelIndex &index);

    void OpenFile(QString path);

    void on_volumeSlider_valueChanged(int value);

    void on_PositionSlider_sliderReleased();


private:
    Ui::MainWindow *ui;
    Player *_player;
    FileList *fileList;
};

#endif // MAINWINDOW_H
