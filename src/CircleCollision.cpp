#include "CircleCollision.h"

namespace cc {

    bool isCircColliding(sf::CircleShape &circ1, sf::CircleShape &circ2)
    {
        float dx = circ1.getPosition().x - circ2.getPosition().x;
        float dy = circ1.getPosition().y - circ2.getPosition().y;
        float distance = sqrt(dx*dx+dy*dy);

        if(distance < circ1.getRadius() + circ2.getRadius())
        {
            return true;
        }
        return false;
    }

}
