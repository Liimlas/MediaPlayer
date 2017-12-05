#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Audio.hpp>

class Player
{
public:
    Player();

    bool OpenMusic(std::string file);
    void Play();
    void Pause();
    void SetVolume(float volume);

    bool Playing();
    bool Paused();
private:
    sf::Music _music;
};

#endif // PLAYER_H
