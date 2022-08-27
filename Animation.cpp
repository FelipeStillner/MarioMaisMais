#include "Animation.h"

Animation::Animation(sf::IntRect uvRect, std::string imageVect, float switchTime, bool faceRight)
{
    totalTime = 0;
    this->switchTime = switchTime;
    currentImage = 0;
    this->faceRight = 0;
    this->uvRect = uvRect;
    this->imageVect = imageVect;
    left = uvRect.left;

    if (faceRight)
    {
        uvRect.width *= -1;
        left -= uvRect.width;
    }
}
    
Animation::~Animation()
{

}

void Animation::change(sf::IntRect uvRect, std::string imageVect, bool faceRight, float switchTime = 0)
{
    if (switchTime != 0)
    {
        this->switchTime = switchTime;
    }
    
    this->imageVect = imageVect;
    this->faceRight = faceRight;
    this->uvRect = uvRect;
    currentImage = 0;
    left = uvRect.left;
}

void Animation::update(float deltaTime)
{
    std::cout<<deltaTime;
    totalTime += deltaTime;

    if (totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage++;
        if (imageVect[currentImage] == '\0')
        {
            currentImage = 0;
        }

        uvRect.left = ((imageVect[currentImage] - 48)* uvRect.width)+ left;
    }
}

