#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once

class Animation
{
public:
  Animation(sf::IntRect uvRect, std::string imageVect, float switchTime, bool faceRight);
  ~Animation();
  void update(float deltaTime);
  void change(sf::IntRect uvRect, std::string imageVect, bool faceRight, float switchTime);

private:

public: 
  sf::IntRect uvRect;
    
private:
  int currentImage;
  float totalTime;
  float switchTime;
  bool faceRight;
  std::string imageVect;
  int left;
};
