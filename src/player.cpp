#include "player.h"
#include <iostream>

#include "mainwindow.h"
Player::Player(MainWindow *window)
{
    _player = new QMediaPlayer;
    _window = window;

    QObject::connect(_player, &QMediaPlayer::stateChanged,
                     window, &MainWindow::setValue);
    QObject::connect(_player, &QMediaPlayer::positionChanged,
                     window, &MainWindow::positionSliderUpdate);
    QObject::connect(_player, &QMediaPlayer::stateChanged, window, &MainWindow::playNextSong);

    _player->setNotifyInterval(1);
}

bool Player::OpenMusic(QString path)
{
    auto file = QUrl::fromLocalFile(path);

    if (file.isEmpty()) return false;

    _player->setMedia(file);

    if(_player->error() != QMediaPlayer::NoError) return false;
    return true;
}

qint64 Player::getCurrentPosition(){
    return _player->position();
}

void Player::Play()
{
    _window->setSongDuration(0);
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

int Player::GetVolume() const {
    return _player->volume();
}

void Player::Initialize()
{
    SetVolume(50);
}

qint64 Player::Duration() const
{
    return _player->duration();
}

void Player::SetPosition(qint64 position)
{
    _player->setPosition(position);
}

int Player::TogglePlay() {
    if(_player->state() == 1) {
        Pause();
        return 1;
    } else {
        Play();
        return 0;
    }
}


