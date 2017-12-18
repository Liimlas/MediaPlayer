#include "player.h"

Player::Player()
{
    _player = new QMediaPlayer;
}

bool Player::OpenMusic(QString file)
{
    _player->setMedia(QUrl::fromLocalFile(file));
    return true;
}

void Player::Play() {
    _player->play();
}

void Player::Pause()
{
    _player->pause();
}


void Player::SetVolume(float volume)
{
    _player->setVolume(volume);
}
