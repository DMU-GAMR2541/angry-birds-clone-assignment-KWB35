#include <gtest/gtest.h>
#include "Enemy.h"
#include "Slingshot.h"
#include "DynamicObject.h"
#include "StaticObject.h"
#include "Bird.h"
#include "Pig.h"
#include "Blocks.h"
#include "GameObject.h"
#include <box2d/box2d.h>
#include "ContactListener.h"

 

/// <summary>
///Taken from the GoogleTest primer. 
/// </summary>


// The fixture for testing class Foo.
class EnemyTest : public testing::Test {
public:
    std::unique_ptr<Enemy> enemy;


    std::list<std::unique_ptr<Pig>> PigVariant;
    std::list<std::unique_ptr<Bird>> BirdVariant;
    std::list<std::unique_ptr<Blocks>> BlockVariant;


    //setup world.
    b2Vec2 b2_gravity; // Earth-like gravity
    b2World world; 
    const float SCALE = 30.0f;

  
protected:
    // You can remove any or all of the following functions if their bodies would
    // be empty.

    EnemyTest() : b2_gravity(0.0f,9.8f), world(b2_gravity) {
        // You can do set-up work for each test here.

        b2Vec2 b2_gravity(0.0f, 9.8f); b2World world(b2_gravity);
                 
    }

    ~EnemyTest() override {
        // You can do clean-up work that doesn't throw exceptions here.
    } 

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
        enemy = std::make_unique<Enemy>(50); // All enemnies in this test suite start with 50 HP.

    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).

#

    }



};






//A single test, not a fixture. No setup is called.
TEST(Enemy, First_test) {
    Enemy e(100);
    EXPECT_GT(e.getHealth(), 100);
    /*SUCCEED() << "Test test passed";
    FAIL() << "Test didn't pass"; */
}

TEST_F(EnemyTest, LethalDamagePopsPig) {
    enemy->takeDamage(60);
    EXPECT_TRUE(enemy->checkIfPopped());
}

//my tests
TEST(Slingshot,Tension_check) {
    Slingshot s;
    EXPECT_EQ(s.getTension(), 0);
    /*SUCCEED() << "Test Passed";
    FAIL() << "Test Failed";*/
}


class ParamTest : public ::testing::TestWithParam<int> {
protected:
    ParamTest() = default;
    ~ParamTest() = default;

    void SetUp() override {
        //Code her will be called immediately after the constructer (right before each test
    }

    void TearDown() override {

        }
};

TEST_P(ParamTest, SimpleTest) {
    int i_test = GetParam();
    std::cout << "Param value::" << i_test << std::endl;
    EXPECT_GT(i_test, 1);
}

INSTANTIATE_TEST_SUITE_P(
    Simple,
    ParamTest, ::testing::Values(1, 2, 3, 4, 5)
);


TEST(EnemyTest1, XPos_Test) {
    Enemy e(0);
    std::cout << "X-Position: " << e.getX() << std::endl;
    EXPECT_EQ(e.getX(), 0);
}

TEST(EnemyTest1, YPos_Test) {
    Enemy e(0);
    std::cout << "Y-Position: " << e.getY() << std::endl;
    EXPECT_EQ(e.getY(), 0);
}

TEST(Slingshot, pullBack_Test) {
    Slingshot s;
    EXPECT_TRUE(s.pullBack(30));
    EXPECT_EQ(s.getTension(), 30);
}

//AnnoyedFlocks Testing

class BirdTest : public testing::Test
{
public:

    std::list<std::unique_ptr<Pig>> PigVariant;
    std::list<std::unique_ptr<Bird>> BirdVariant;

    
    //setup world.
    b2Vec2 b2_gravity; // Earth-like gravity
    b2World world;
    const float SCALE = 30.0f;

protected:
    BirdTest() : b2_gravity(0.0f, 9.8f), world(b2_gravity)
    {
        b2Vec2 b2_gravity(0.0f, 9.8f); b2World world(b2_gravity);


        BirdVariant.push_back(std::make_unique<Bird>("../assets/Ang_Birds/birds-png-3514.png", b2Vec2(100.0f / SCALE, 500.0f / SCALE), world, 0.7f, 4.0f, 0.5f, 1.0f, 0.08f, 0.08f, 100, 0, "circle"));
        BirdVariant.push_back(std::make_unique<Bird>("../assets/Ang_Birds/angry-birds-png-46169.png", b2Vec2(20.0f / SCALE, 500.0f / SCALE), world, 2.0f, 4.0f, 0.5f, 0.5f, 0.04f, 0.03f, 100, 0.0f, "circle"));
        BirdVariant.push_back(std::make_unique<Bird>("../assets/Ang_Birds/angry-birds-png-46179.png", b2Vec2(20.0f / SCALE, 500.0f / SCALE), world, 0.7f, 4.0f, 0.5f, 1.0f, 0.06f, 0.06f, 100, 0.0f, "circle"));

        PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/angry-birds-png-46187.png", b2Vec2(500.0f / SCALE, 450.0f / SCALE), world, 1.0f, 4.0f, 0.5f, 1.0f, 0.15f, 0.15f, 1, 0.0f, "circle"));
        PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/PigKing.png", b2Vec2(600.0f / SCALE, 450.0f / SCALE), world, 0.5f, 4.0f, 0.5f, 1.6f, 0.6f, 0.6f, 3, 0.0f, "circle"));
        PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/PigSprite_5.png", b2Vec2(800.0f / SCALE, 450.0f / SCALE), world, 0.5f, 4.0f, 0.5f, 1.3f, 0.7f, 0.8f, 2, 0.0f, "circle"));
        PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/PigSprite_5.png", b2Vec2(800.0f / SCALE, 450.0f / SCALE), world, 0.5f, 4.0f, 0.5f, 1.3f, 0.7f, 0.8f, 2, 0.0f, "circle"));

    }

    ~BirdTest() override {}

    void birdUpdate()
    {
        for (std::unique_ptr<Bird>& b : BirdVariant)
        {
            b->UpdateSprite();

        }

    };

};


class PigTest : public testing::Test
{
public:
    std::list<std::unique_ptr<Pig>> PigVariant;

    //setup world.
    b2Vec2 b2_gravity; // Earth-like gravity
    b2World world;
    const float SCALE = 30.0f;

protected:
    PigTest() : b2_gravity(0.0f, 9.8f), world(b2_gravity)
    {
        b2Vec2 b2_gravity(0.0f, 9.8f); b2World world(b2_gravity);

        PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/angry-birds-png-46187.png", b2Vec2(500.0f / SCALE, 450.0f / SCALE), world, 1.0f, 4.0f, 0.5f, 1.0f, 0.15f, 0.15f, 1, 0.0f, "circle"));
        PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/PigKing.png", b2Vec2(600.0f / SCALE, 450.0f / SCALE), world, 0.5f, 4.0f, 0.5f, 1.6f, 0.6f, 0.6f, 3, 0.0f, "circle"));
        PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/PigSprite_5.png", b2Vec2(800.0f / SCALE, 450.0f / SCALE), world, 0.5f, 4.0f, 0.5f, 1.3f, 0.7f, 0.8f, 2, 0.0f, "circle"));

    }

    ~PigTest() override {}

    void pigUpdate()
    {
        for (std::unique_ptr<Pig>& p : PigVariant)
        {
            p->UpdateSprite();

        }

    };

};

class BirdParamTest : public ::testing::TestWithParam<b2Vec2> {
public:
    
    std::list<std::unique_ptr<Bird>> BirdVariant;

    std::list<std::unique_ptr<Pig>> PigVariant;
    //setup world.
    b2Vec2 b2_gravity; // Earth-like gravity
    b2World world;
    const float SCALE = 30.0f;
protected:
    BirdParamTest() : b2_gravity(0.0f, 9.8f), world(b2_gravity)
    {
        BirdVariant.push_back(std::make_unique<Bird>("../assets/Ang_Birds/birds-png-3514.png", b2Vec2(100.0f / SCALE, 500.0f / SCALE), world, 0.7f, 4.0f, 0.5f, 1.0f, 0.08f, 0.08f, 100, 0, "circle"));
        BirdVariant.push_back(std::make_unique<Bird>("../assets/Ang_Birds/angry-birds-png-46169.png", b2Vec2(20.0f / SCALE, 500.0f / SCALE), world, 2.0f, 4.0f, 0.5f, 0.5f, 0.04f, 0.03f, 100, 0.0f, "circle"));
        BirdVariant.push_back(std::make_unique<Bird>("../assets/Ang_Birds/angry-birds-png-46179.png", b2Vec2(20.0f / SCALE, 500.0f / SCALE), world, 0.7f, 4.0f, 0.5f, 1.0f, 0.06f, 0.06f, 100, 0.0f, "circle"));

        PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/angry-birds-png-46187.png", b2Vec2(500.0f / SCALE, 450.0f / SCALE), world, 1.0f, 4.0f, 0.5f, 1.0f, 0.15f, 0.15f, 1, 0.0f, "circle"));
        PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/PigKing.png", b2Vec2(600.0f / SCALE, 450.0f / SCALE), world, 0.5f, 4.0f, 0.5f, 1.6f, 0.6f, 0.6f, 3, 0.0f, "circle"));
        PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/PigSprite_5.png", b2Vec2(800.0f / SCALE, 450.0f / SCALE), world, 0.5f, 4.0f, 0.5f, 1.3f, 0.7f, 0.8f, 2, 0.0f, "circle"));

     
    };
    ~BirdParamTest() = default;

    void SetUp() override {
        //Code her will be called immediately after the constructer (right before each test

    }

    void TearDown() override {

    }
};

INSTANTIATE_TEST_SUITE_P(
    Simple,
    BirdParamTest, ::testing::Values( b2Vec2(20.0,10.0), b2Vec2(40.0,10.0), b2Vec2(60.0,10.0), b2Vec2(90.0,10.0))
);




TEST_F(BirdTest, birdTextureLoading_Test) //Does the testure for the sprite load
{
    Bird& b = *BirdVariant.front(); //pulls the bird prome the front of the list
    EXPECT_TRUE(b.textureLoaded);
    
}

TEST_F(PigTest, pigTextureLoading_Test) //Does the testure for the sprite load
{
    Pig& p = *PigVariant.front(); //pulls the pig prome the front of the list
    EXPECT_TRUE(p.textureLoaded);

}

TEST_P(BirdParamTest, birdMovement_Test) //test the correctness of bird movement across a spread of values
{
    b2Vec2 ptImpulse = GetParam();
    b2Vec2 prevPos;

    Bird* bird = BirdVariant.front().get();
    b2Body* body = bird->getBody();

    b2Vec2 startPos = body->GetPosition();

    body->ApplyLinearImpulseToCenter(b2Vec2(ptImpulse), true);

    for (int i = 0; i < 60; ++i)
    {
        world.Step(1.0f / 60.0f ,8,3);
    }

    b2Vec2 endPos = body->GetPosition();

    b2Vec2 disTravelled = (endPos - startPos);
    
    EXPECT_GT(disTravelled.x,prevPos.x);
    EXPECT_GT(disTravelled.x,ptImpulse.x * 0.1f);

    prevPos = endPos;
}

TEST_F(BirdTest, BirdtoPigDistance_Test) //Test distance from bird to the pigs 
{
    BirdVariant.push_back(std::make_unique<Bird>("../assets/Ang_Birds/birds-png-3514.png", b2Vec2(100.0f / SCALE, 500.0f / SCALE), world, 0.7f, 4.0f, 0.5f, 1.0f, 0.08f, 0.08f, 100, 0, "circle"));
   
    PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/angry-birds-png-46187.png", b2Vec2(100.0f / SCALE, 500.0f / SCALE), world, 1.0f, 4.0f, 0.5f, 1.0f, 0.15f, 0.15f, 1, 0.0f, "circle"));
    PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/PigKing.png", b2Vec2(600.0f / SCALE, 450.0f / SCALE), world, 0.5f, 4.0f, 0.5f, 1.6f, 0.6f, 0.6f, 3, 0.0f, "circle"));
    PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/PigSprite_5.png", b2Vec2(800.0f / SCALE, 450.0f / SCALE), world, 0.5f, 4.0f, 0.5f, 1.3f, 0.7f, 0.8f, 2, 0.0f, "circle"));
    PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/PigSprite_5.png", b2Vec2(800.0f / SCALE, 450.0f / SCALE), world, 0.5f, 4.0f, 0.5f, 1.3f, 0.7f, 0.8f, 2, 0.0f, "circle"));

    for (auto& b : BirdVariant)
    {
        b2Body* bBody = b.get()->getBody();

        for (auto& p : PigVariant)
        {
            b2Body* pBody = p.get()->getBody();

            EXPECT_EQ(bBody->GetPosition(), pBody->GetPosition()); 
        }
    }
    
}

TEST(Pig, pigTakeDamage_Test)
{
    Pig p;
    p.maxHealth = 1;
    p.TakeDamage(1);
    EXPECT_TRUE(p.destroyed);
}

//Texture Loading test
TEST(TextureTest, TextureLoading_Test)
{
    sf::Texture texture;

    bool loaded = texture.loadFromFile("../assets/Ang_Birds/Angry_Birds.png");
    ASSERT_TRUE(loaded); //if fails fatal
}

TEST(PhysicsTest, physicsGravity_Test)
{
    b2Vec2 b2_gravity = b2Vec2(0, -9.8);
    b2World world(b2_gravity);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 10.0f);
    b2Body* body = world.CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(0.5f, 0.5f);

    b2FixtureDef fixDef;

    fixDef.shape = &shape;
    fixDef.density = 1.0f;
    body->CreateFixture(&fixDef);

    float initY = body->GetPosition().y;
    float initVelY = body->GetLinearVelocity().y;

    for (int i = 0; i < 60; ++i)
    {
        world.Step(1.0f / 60.0f, 8, 3);
    }

    float finalY = body->GetPosition().y;
    float finalVelY = body->GetLinearVelocity().y;

    EXPECT_LT(finalVelY,initVelY );
    EXPECT_LT(finalY,initY);
}


//End of Annoyed flocks testing

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}