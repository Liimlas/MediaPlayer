#include "player.h"
#include "mainwindow.h"

/* Constructor of the player class
 * Sets some usefull connections between between sliders and according functions
 */
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

// Opens a music file and sets it to players current song
bool Player::OpenMusic(QString path)
{
    auto file = QUrl::fromLocalFile(path);

    if (file.isEmpty()) return false;

    _player->setMedia(file);

    if(_player->error() != QMediaPlayer::NoError) return false;
    return true;
}

// Gets the current position of song as milliseconds. Used for measuring the sliders position for example
qint64 Player::getCurrentPosition(){
    return _player->position();
}

// Playes the song
void Player::Play()
{
    _window->setSongDuration(0);
    _player->play();
}

// Pauses the song
void Player::Pause()
{
    _player->pause();
}

// Sets volume
void Player::SetVolume(float volume)
{
    _player->setVolume(volume);
}

// Sets the volume to be 50 at the beginning
void Player::Initialize()
{
    SetVolume(50);
}

// Returns the duration of the song as milliseconds
qint64 Player::Duration() const
{
    return _player->duration();
}
// Sets the songs position to match the sliders position when the slider is being moved
void Player::SetPosition(qint64 position)
{
    _player->setPosition(position);
}

// Switches the state of play button to be paused or play
int Player::TogglePlay() {
    if(_player->state() == 1) {
        Pause();
        return 1;
    } else {
        Play();
        return 0;
    }
}


