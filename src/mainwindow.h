#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "player.h"
#include "filelist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void SetPlaying();
    void SetPaused();
    void SetButtons(bool state);

private slots:
    void on_playButton_clicked();

    void on_forwardButton_clicked();

    void on_backwardButton_clicked();

    void on_openButton_clicked();

    void on_treeView_doubleClicked(const QModelIndex &index);

    void OpenFile(QString path);

    void on_volumeSlider_valueChanged(int value);


private:
    Ui::MainWindow *ui;
    Player *_player;
    FileList *fileList;
};

#endif // MAINWINDOW_H
