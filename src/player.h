#ifndef PLAYER_H
#define PLAYER_H

#include <QMediaPlayer>

class Player
{
public:
    Player();

    bool OpenMusic(QString file);
    void Play();
    void Pause();
    void SetVolume(float volume);
private:
    QMediaPlayer *_player;
};

#endif // PLAYER_H
