#include "player.h"

Player::Player()
{
    _player = new QMediaPlayer;
}

bool Player::OpenMusic(QString path)
{
    auto file = QUrl::fromLocalFile(path);

    if (file.isEmpty()) return false;

    _player->setMedia(file);

    if(_player->error() != QMediaPlayer::NoError) return false;
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
