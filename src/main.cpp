#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <iostream>
#include "Pig.h"
#include "Bird.h"
#include <list>


int main() {
    // --- 1. WINDOW SETUP ---
    sf::RenderWindow window(sf::VideoMode(800, 600), "Annoyed_Flocks");
    window.setFramerateLimit(60);

    //Box2D works in meters. SFML works in pixels.
    const float SCALE = 30.0f;

    //Can set a definition for PI.
    const float PI = 3.1415927;

    //Creates the mouse position variable
    float MousePosX;
    float MousePosY;
    

    //Sets the position for the bird to be reset
    const b2Vec2 SlingshotPos = b2Vec2(100.0f / SCALE , 500.0f / SCALE);

    //Have the bird reset back to this velocity
    const b2Vec2 ResetVel = b2Vec2(0, 0);



    //setup world.
    b2Vec2 b2_gravity(0.0f, 9.8f); // Earth-like gravity
    b2World world(b2_gravity);

    //Setup ground for the circle to move / bounce on.
    //Needs to have a body definition and a body. We use a raw pointer for the b2Body as Box2d does the management itself.
    //A body can be defined as having a position, velocity, and mass. 
    b2BodyDef b2_groundBodyDef;
    b2_groundBodyDef.position.Set(400.0f / SCALE, 590.0f / SCALE);
    b2Body* b2_groundBody = world.CreateBody(&b2_groundBodyDef);

    //Define a fixture shape that relates to the collision for the ground.
    b2PolygonShape b2_groundBox;
    b2_groundBox.SetAsBox(400.0f / SCALE, 10.0f / SCALE);
    b2_groundBody->CreateFixture(&b2_groundBox, 0.0f);

    //Set up the ground visualisation.
    sf::RectangleShape sf_groundVisual(sf::Vector2f(800.0f, 20.0f));
    sf_groundVisual.setOrigin(400.0f, 10.0f);
    sf_groundVisual.setFillColor(sf::Color(34, 139, 34)); // Forest Green

    //Setting up a wall for the ball to hit.
    b2BodyDef b2_wallDef;
    b2_wallDef.position.Set(750.0f / SCALE, 500.0f / SCALE);
    b2Body* b2_wallBody = world.CreateBody(&b2_wallDef);


    b2PolygonShape b2_wallBox;
    b2_wallBox.SetAsBox(10.0f / SCALE, 80.0f / SCALE);
    b2_wallBody->CreateFixture(&b2_wallBox, 0.0f);

    sf::RectangleShape sf_wallVisual(sf::Vector2f(20.0f, 160.0f));
    sf_wallVisual.setOrigin(10.0f, 80.0f);
    sf_wallVisual.setFillColor(sf::Color::Red);

    //Rather than having an immovable wall, we can use the dynamic body type to create one that can have velocity etc.
    b2BodyDef b2_plankDef;

    b2_plankDef.type = b2_dynamicBody;
    b2_plankDef.position.Set(550.0f / SCALE, 450.0f / SCALE);
    b2Body* b2_plankBody = world.CreateBody(&b2_plankDef);

    b2PolygonShape b2_plankBox;
    b2_plankBox.SetAsBox(10.0f / SCALE, 60.0f / SCALE);

    b2FixtureDef b2_plankFixture;
    b2_plankFixture.shape = &b2_plankBox;
    b2_plankFixture.density = 1.5f;   // Light wood
    b2_plankFixture.friction = 0.3f;
    b2_plankBody->CreateFixture(&b2_plankFixture);

    sf::RectangleShape sf_plankVisual(sf::Vector2f(20.0f, 120.0f));
    sf_plankVisual.setOrigin(10.0f, 60.0f);
    sf_plankVisual.setFillColor(sf::Color(139, 69, 19)); // Brown

   


    //Adding physics to the sprites
    b2Vec2 b2_pos; //The position of the object in the game world
    b2BodyDef b2_bodyDef; //The body definition for the object in the Box2D physics engine
    b2FixtureDef b2_fixtureDef; //The fixture definition for the object in the Box2D physics engine

    b2Body* b2_body; //the body for the object in the box2D physics engine

    b2CircleShape b2_dynamicCircle; //The shape of the object in the Box2D physics engine defined as a circle


    //Makes the pigs 
    std::list<std::unique_ptr<Pig>> PigVariant;

    PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/angry-birds-png-46187.png", b2Vec2(500.0f / SCALE, 450.0f / SCALE), world, 1.0f, 4.0f, 0.5f, 0.5f));
    PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/angry-birds-png-46187.png", b2Vec2(600.0f / SCALE, 450.0f / SCALE), world, 0.5f, 4.0f, 0.5f, 0.8f));


    std::list<std::unique_ptr<Bird>> BirdVariant;

    
   

    //Makes a Bird
    Bird Bird1("../assets/Ang_Birds/birds-png-3514.png", b2Vec2(100.0f / SCALE, 500.0f / SCALE),world, 1.0f, 4.0f, 0.5f, 1.0f);//defines the birds variables 


    // --- 7. MAIN LOOP ---
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::MouseMoved) 
            {
                MousePosX = (event.mouseMove.x);
                MousePosY = (event.mouseMove.y);
            }

            if (event.type == sf::Event::Closed)
                window.close();

            // INPUT HANDLING: Press Left Click to launch
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {


                    Bird1.setVelocity(ResetVel);
                    Bird1.setPosition(SlingshotPos,0);
                    
                    
                    Bird1.impulse(b2Vec2(MousePosX / 5, - MousePosY / 8), true); //Gets mouse position and sets the impulse to it divided by the specified scale

                    std::cout << "Firing!!!!" << std::endl;
                }
            }

            
        }

        // Update Physics
        world.Step(1.0f / 60.0f, 8, 3);

        //All of the visuals needs to be synced with the physics.



        //Static objects usually don't move, but we set the position once.
        sf_groundVisual.setPosition(b2_groundBody->GetPosition().x * SCALE, b2_groundBody->GetPosition().y * SCALE);
        sf_wallVisual.setPosition(b2_wallBody->GetPosition().x * SCALE, b2_wallBody->GetPosition().y * SCALE);

        // Dynamic wall.
        sf_plankVisual.setPosition(b2_plankBody->GetPosition().x * SCALE, b2_plankBody->GetPosition().y * SCALE);
        sf_plankVisual.setRotation(b2_plankBody->GetAngle() * (180.0f / PI));


        Bird1.UpdateSprite();


        //Render all of the content at each frame. Remember you need to clear the screen each iteration or artefacts remain.
        window.clear(sf::Color(135, 206, 235)); // Sky Blue

        window.draw(sf_groundVisual);
        window.draw(sf_wallVisual);
        window.draw(sf_plankVisual);
        Bird1.render(window);

        //Renders and updates the pig variants 
        for (std::unique_ptr<Pig>& p : PigVariant) 
        {
            p->UpdateSprite();
            p->render(window);
        }

        window.display();
    }

    return 0;
}