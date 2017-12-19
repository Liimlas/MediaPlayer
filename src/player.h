
class MainWindow;

#ifndef PLAYER_H
#define PLAYER_H

#include <QMediaPlayer>


class Player
{
public:
    Player(MainWindow *window);

    bool OpenMusic(QString file);
    void Play();
    void Pause();
    void SetVolume(float volume);
    int TogglePlay();
    void Initialize();
    qint64 Duration() const;
    void SetPosition(qint64 position);
    qint64 getCurrentPosition();

private:
    QMediaPlayer *_player;
    MainWindow *_window;
};

#endif // PLAYER_H
