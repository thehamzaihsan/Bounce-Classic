#pragma once

class Ball: public sf::CircleShape
{
public:
	Ball();
    void Update();
    sf::Vector2f* ballSpeed;

private:
    float EARTH_GRAVITY;
    float bouce_fac;
    float time;
    int i;
    int k;
    int j;
    int l;
    int z;
    int q;
    int w;
    float up;
    bool ground;
    bool top;
    int c;
    
    int max_speed;
    int anti_gravity;
};

Ball::Ball()
{
    ballSpeed = new sf::Vector2f(0, 0);
    EARTH_GRAVITY = 9.81 / 8;
    bouce_fac = 0.5;
    time = 0.0;
     i = 0;
     k = 0;
     j = 0;
     l = 0;
     z = 0;
     q = 0;
     w = 0;
     up = 0;
     ground = false;
     top = false;
     c = 0;
     max_speed = 30;
     anti_gravity = 20;
}






void Ball::Update()
{   
    if (ballSpeed->y > max_speed || ballSpeed->y < -max_speed) {

        ballSpeed->y = max_speed;

    }
    ballSpeed->x = ballSpeed->x + ballSpeed->x * (-0.010);

    if (ballSpeed->y < max_speed && ground != true) {

        ballSpeed->y += EARTH_GRAVITY;

    }
    if (i == 0)
        ballSpeed->x = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {


        if (this->getPosition().y > 20 && i - l > 30 && ground == true)
        {
            ground = false;
            ballSpeed->y = -anti_gravity;

            l = i;
        }


    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        if (this->getPosition().x <= 600 - this->getRadius() * 2 - 20 && i - q > 30)
        {
            ballSpeed->x = 10;
            q = i;
        }

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        if (this->getPosition().x >= 0 + 20 && i - w > 30)
        {
            ballSpeed->x = -10;
            w = i;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
       ballSpeed->x = 0;
       ballSpeed->y = 0;
       int i = 0;
       int k = 0;
       int j = 0;
       int l = 0;
       int z = 0;
       float up = 0;
       bool ground = false;
       bool top = false;
       int c = 0;
       this->setPosition(600 / 2 - this->getRadius(), 600 / 2 - this->getRadius());
       

    }
    if (up > 0) {
        ballSpeed->y = up;
        this->setPosition(this->getPosition().x, this->getPosition().y - ballSpeed->y);

    }

    else {
        if (ground != true)
            this->setPosition(this->getPosition().x, this->getPosition().y + ballSpeed->y);
        top = false;
    }


    if (ballSpeed->x < 1 && ballSpeed->x > -1)
    {
        ballSpeed->x = 0;
        c = 0;
    }
    this->setPosition(this->getPosition().x + ballSpeed->x + c, this->getPosition().y);


    up = up - EARTH_GRAVITY;

    if (this->getPosition().x >= 600 - this->getRadius() * 2 || this->getPosition().x <= 0) {


        ballSpeed->x = -ballSpeed->x;
        if (this->getPosition().x >= 600 - this->getRadius() * 2)
            this->setPosition(600 - this->getRadius() * 2, this->getPosition().y);
        if (this->getPosition().x <= 0)
            this->setPosition(0, this->getPosition().y);
        ballSpeed->x = ballSpeed->x + ballSpeed->x * (-0.10);
    }
    if (this->getPosition().y <= 0)
    {
        if (i - j != 1) {
            top = true;

            ballSpeed->y = up + ballSpeed->y;
            up = 0;
            //TOP BOUNCE FACTOR
            //ballSpeed->y = ballSpeed->y + ballSpeed->y * bouce_fac;
            int j = i;
            this->setPosition(this->getPosition().x, 0);
            //std::cout << "top !!" << std::endl;
        }
            
     

    }
    if (this->getPosition().y >= 600 - (this->getRadius() * 2)) {
        if (ground != true) {
            if (i - k - 1 != 0) {

                time = (ballSpeed->y * 2.83) / (EARTH_GRAVITY * 8);

                //std::cout << "Ball speed = " << ballSpeed->y * 2.83 << " ; time = " << time << std::endl;
                ballSpeed->y = -ballSpeed->y * bouce_fac;
                /*ballSpeed->x = ballSpeed->x + ballSpeed->x * (-0.10);*/
                ground = false;
                //std::cout << "Bounce Speed  " << ballSpeed->y << std::endl;
                k = i;

            }

                
          
        }
        if (ballSpeed->y > -3)
        {
            ground = true;
            this->setPosition(this->getPosition().x, 600 - this->getRadius() * 2);
            ballSpeed->y = 0;



        }
    }
    /*std::cout << i << "  ;ballSpeed Y =  "<< ballSpeed->y << "  ;  ballSpeed X =  " <<ballSpeed->x <<  std::endl;*/
    i++;
}



