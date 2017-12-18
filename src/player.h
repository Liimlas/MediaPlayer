
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
    int GetVolume() const;
    int TogglePlay();
    void Initialize();

private:
    QMediaPlayer *_player;
    int volume = 50;
    MainWindow *_window;
};

#endif // PLAYER_H
