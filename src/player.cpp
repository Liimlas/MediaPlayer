#include "player.h"

Player::Player()
{

}

bool Player::OpenMusic(std::string file)
{
    if (!_music.openFromFile(file)) {
        return false; // error
    }
    return true;
}

void Player::Play() {
    _music.play();
}

void Player::Pause()
{
    _music.pause();
}

bool Player::Playing()
{
    return (_music.getStatus() == sf::SoundSource::Status::Playing);
}


bool Player::Paused()
{
    return (_music.getStatus() == sf::SoundSource::Status::Paused);
}


void Player::SetVolume(float volume)
{
    _music.setVolume(volume);
}
