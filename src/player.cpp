#include "player.h"
#include <iostream>

#include "mainwindow.h"
Player::Player(MainWindow *window)
{
    _player = new QMediaPlayer;
    _window = window;
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
    _window->SetPlaying();
}

void Player::Pause()
{
    _player->pause();
    _window->SetPaused();
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

int Player::TogglePlay() {
    std::cout << this->GetVolume() << std::endl;
    if(_player->state() == 1) {
        Pause();
        return 1;
    } else {
        Play();
        return 0;
    }
}


