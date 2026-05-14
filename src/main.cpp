#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <iostream>
#include "Pig.h"
#include "Bird.h"
#include <list>
#include "Blocks.h"

#include "ContactListener.h"

#include <filesystem>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory>


int main() {
    // --- 1. WINDOW SETUP ---
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Annoyed_Flocks");
    window.setFramerateLimit(60);

    //Box2D works in meters. SFML works in pixels.
    const float SCALE = 30.0f;

    //Can set a definition for PI.
    const float PI = 3.1415927;

    //Creates the mouse position variable
    float MousePosX;
    float MousePosY;


    //setup world.
    b2Vec2 b2_gravity(0.0f, 9.8f); // Earth-like gravity
    b2World world(b2_gravity);

    ContactListener contactListener;
    world.SetContactListener(&contactListener);

    //Setup ground for the circle to move / bounce on.
    //Needs to have a body definition and a body. We use a raw pointer for the b2Body as Box2d does the management itself.
    //A body can be defined as having a position, velocity, and mass. 
    b2BodyDef b2_groundBodyDef;
    b2_groundBodyDef.position.Set(400.0f / SCALE, 590.0f / SCALE);
    b2Body* b2_groundBody = world.CreateBody(&b2_groundBodyDef);

    //Define a fixture shape that relates to the collision for the ground.
    b2PolygonShape b2_groundBox;
    b2_groundBox.SetAsBox(1000.0f / SCALE, 10.0f / SCALE);
    b2_groundBody->CreateFixture(&b2_groundBox, 0.0f);

    //Set up the ground visualisation.
    sf::RectangleShape sf_groundVisual(sf::Vector2f(1000.0f, 300.0f));
    sf_groundVisual.setOrigin(400.0f, 10.0f);
    sf_groundVisual.setFillColor(sf::Color(34, 139, 34)); // Forest Green

    //Setting up a wall for the ball to hit.
    b2BodyDef b2_wallDef;
    b2_wallDef.position.Set(995.0f / SCALE, 0.0f / SCALE);
    b2Body* b2_wallBody = world.CreateBody(&b2_wallDef);


    b2PolygonShape b2_wallBox;
    b2_wallBox.SetAsBox(10.0f / SCALE, 800.0f / SCALE);
    b2_wallBody->CreateFixture(&b2_wallBox, 0.0f);

    sf::RectangleShape sf_wallVisual(sf::Vector2f(20.0f, 750.0f));
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

    PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/angry-birds-png-46187.png", b2Vec2(500.0f / SCALE, 450.0f / SCALE), world, 1.0f, 4.0f, 0.5f, 1.0f,0.15f,0.15f,1,0.0f, "circle"));
    PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/PigKing.png", b2Vec2(600.0f / SCALE, 450.0f / SCALE), world, 0.5f, 4.0f, 0.5f, 1.6f,0.6f,0.6f,3,0.0f, "circle"));
    PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/PigSprite_5.png", b2Vec2(800.0f / SCALE, 450.0f / SCALE), world, 0.5f, 4.0f, 0.5f, 1.3f, 0.7f, 0.8f,2,0.0f, "circle"));

    std::list<std::unique_ptr<Bird>> BirdVariant;

    BirdVariant.push_back(std::make_unique<Bird>("../assets/Ang_Birds/birds-png-3514.png", b2Vec2(100.0f / SCALE, 500.0f / SCALE), world, 0.7f, 4.0f, 0.5f, 1.0f,0.08f,0.08f,100,0,"circle"));
    BirdVariant.push_back(std::make_unique<Bird>("../assets/Ang_Birds/angry-birds-png-46169.png", b2Vec2(20.0f / SCALE, 500.0f / SCALE), world, 2.0f, 4.0f, 0.5f, 0.5f, 0.04f, 0.03f,100,0.0f, "circle"));
    BirdVariant.push_back(std::make_unique<Bird>("../assets/Ang_Birds/angry-birds-png-46179.png", b2Vec2(20.0f / SCALE, 500.0f / SCALE), world, 0.7f, 4.0f, 0.5f, 1.0f, 0.06f, 0.06f,100,0.0f, "circle"));

    std::list<std::unique_ptr<Blocks>> BlockVariant;

    BlockVariant.push_back(std::make_unique<Blocks>("../assets/Ang_Birds/NicePng_angry-gamer-png_2299190.PNG", b2Vec2(700.0f / SCALE, 300.0f / SCALE), world, 1.f, 4.0f, 0.5f, 0.3f,1.2f, 1.2f, 2, 90.0f, "rectangle"));
    BlockVariant.push_back(std::make_unique<Blocks>("../assets/Ang_Birds/NicePng_angry-gamer-png_2299190.PNG", b2Vec2(700.0f / SCALE, 300.0f / SCALE), world, 1.f, 4.0f, 0.5f, 0.3f, 1.2f, 1.2f, 2, 0.0f, "rectangle"));


    sf::Vector2f slingshotOrigin(150.0f, 500.0f);
    float maxDragDistanceX = 75.0f;
    float maxDragDistanceY = 75.0f;
    float launchStrength = 10.0f;

    bool fired = false;
    bool birdInAir = false;
    bool isDragging = false;

    Bird* tempBird = BirdVariant.front().get();
    b2Body* tempBody = tempBird->getBody();
    tempBody->SetTransform(b2Vec2(150.0f / SCALE,500.0f / SCALE), 0);
    tempBody->SetType(b2_kinematicBody); //sets the loaded bird to a kinematic body that isnt affected by physics and thus remains in place
    int currentBird = 0;
    float waitingTime = 0.0f;
    float waitingTimeThreshhold = 5.0f;
    sf::Clock birdTimer;
   
 
    

    // --- 7. MAIN LOOP ---
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();



            // INPUT HANDLING: Press Left Click to launch
            if (event.type == sf::Event::MouseButtonPressed)  
            {
                if (event.key.code == sf::Mouse::Left) 
                {
                    if(currentBird < static_cast<int>(BirdVariant.size()) && !fired)
                    {
                        isDragging = true;//start dragging when left mouse is pressed
                    }
                    
                    //std::cout << "Firing!!!!" << std::endl;
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) 
            {
                if(event.key.code == sf::Mouse::Left)
                {
                    if (isDragging)
                    {
                        Bird* tempBird = BirdVariant.front().get();
                        b2Body* tempBody = tempBird->getBody();

                        sf::Vector2f birdPos(tempBody->GetPosition().x * SCALE, tempBody->GetPosition().y * SCALE);
                        sf::Vector2f slingshotVector = slingshotOrigin - birdPos; //calculates the vector of the birds position and the slingshot origin to find the force to preppel forwards with

                        tempBody->SetType(b2_dynamicBody);//allows for physics to affect the bird as it is fired 

                        tempBody->ApplyLinearImpulseToCenter(b2Vec2(slingshotVector.x * launchStrength / SCALE, slingshotVector.y * launchStrength / SCALE),true);//applies impulse firing the bird

                        
                        isDragging = false; //Bird has been fired and thus is no longer being dragged
                        //std::cout << isDragging <<std::endl;
                        fired = true;
                        birdTimer.restart(); //rests timer
                        
                    }

                }
            }

            

            
        }

        // Update Physics
        world.Step(1.0f / 60.0f, 8, 3);

        PigVariant.erase(std::remove_if(PigVariant.begin(), PigVariant.end(), [&](std::unique_ptr<Pig>& pig)
            {
                if (pig->destroyed)
                {
                    if (pig->getBody())
                    {
                        world.DestroyBody(pig->getBody());
                        pig->setBody(nullptr);
                    }
                    return true;
                }
                return false;
            }),
            PigVariant.end());


        

        //Dragging System Set-Up
        if (isDragging) 
        {
            Bird* tempBird = BirdVariant.front().get();
            b2Body* tempBody = tempBird->getBody();

            sf::Vector2i mousePos = sf::Mouse::getPosition(window); //Gets the current mouse position
            sf::Vector2f mouseWorldPos(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)); //Use static cast to convert to float
            sf::Vector2f dragVector = mouseWorldPos - slingshotOrigin; //Calculate the vector from slingshot to the mouse

            //Maxes the drag vector to the specified distnce of x and y
            dragVector.x = std::clamp(dragVector.x, -maxDragDistanceX, maxDragDistanceY);
            dragVector.y = std::clamp(dragVector.y, -maxDragDistanceY, maxDragDistanceX);

            sf::Vector2f finalPos = slingshotOrigin + dragVector; //Calculate final Position of bird based on dragVector and slingshotOrigin

            tempBody->SetTransform(b2Vec2(finalPos.x / SCALE, finalPos.y / SCALE), 0);
        }

        if (fired)
        {
            if (birdTimer.getElapsedTime().asSeconds() > waitingTimeThreshhold) 
            {
                fired = false;
                BirdVariant.erase(BirdVariant.begin()); //deletes the front bird
                tempBody->SetEnabled(false);
                
                 //reset the fired status to false, allows the next bird to be dragged and launched 

                if (0 < BirdVariant.size())
                {
                    
                    Bird* tempBird = BirdVariant.front().get(); //loads in the front bird which should have changed
                    b2Body* tempBody = tempBird->getBody();

                    tempBody->SetType(b2_kinematicBody);//sets the nect bird as a kinematic body
                    tempBody->SetTransform(b2Vec2(slingshotOrigin.x / SCALE, slingshotOrigin.y / SCALE), 0); //Sends the new bird into the slingshot position 

                    tempBody->SetLinearVelocity(b2Vec2(0, 0)); //Sets velocity to 0
                    tempBody->SetAngularVelocity(0); //Sets angular velocity to 0

                }
            }

            
        }



        //All of the visuals needs to be synced with the physics.

        //Static objects usually don't move, but we set the position once.
        sf_groundVisual.setPosition(b2_groundBody->GetPosition().x * SCALE, b2_groundBody->GetPosition().y * SCALE);
        sf_wallVisual.setPosition(b2_wallBody->GetPosition().x * SCALE, b2_wallBody->GetPosition().y * SCALE);


        // Dynamic wall.
        sf_plankVisual.setPosition(b2_plankBody->GetPosition().x * SCALE, b2_plankBody->GetPosition().y * SCALE);
        sf_plankVisual.setRotation(b2_plankBody->GetAngle() * (180.0f / PI));






        //Render all of the content at each frame. Remember you need to clear the screen each iteration or artefacts remain.
        window.clear(sf::Color(135, 206, 235)); // Sky Blue

        window.draw(sf_groundVisual);
        window.draw(sf_wallVisual);
        window.draw(sf_plankVisual);
        

        //Renders and updates the pig variants 
        for (std::unique_ptr<Pig>& p : PigVariant) 
        {
            p->UpdateSprite();
            p->render(window);
        }
        for (std::unique_ptr<Bird>& b : BirdVariant)
        {
            b->UpdateSprite();
            b->render(window);
        }
        for (std::unique_ptr<Blocks>& s : BlockVariant)
        {
            s->UpdateSprite();
            s->render(window);
        }

        window.display();
    }

    return 0;
}