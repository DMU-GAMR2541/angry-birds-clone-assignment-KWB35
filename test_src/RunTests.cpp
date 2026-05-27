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

        //BirdVariant.push_back(std::make_unique<Bird>("../assets/Ang_Birds/birds-png-3514.png", b2Vec2(100.0f / SCALE, 500.0f / SCALE), world, 0.7f, 4.0f, 0.5f, 1.0f, 0.08f, 0.08f, 100, 0, "circle"));
        //BirdVariant.push_back(std::make_unique<Bird>("../assets/Ang_Birds/angry-birds-png-46169.png", b2Vec2(20.0f / SCALE, 500.0f / SCALE), world, 2.0f, 4.0f, 0.5f, 0.5f, 0.04f, 0.03f, 100, 0.0f, "circle"));
        //BirdVariant.push_back(std::make_unique<Bird>("../assets/Ang_Birds/angry-birds-png-46179.png", b2Vec2(20.0f / SCALE, 500.0f / SCALE), world, 0.7f, 4.0f, 0.5f, 1.0f, 0.06f, 0.06f, 100, 0.0f, "circle"));

        //PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/angry-birds-png-46187.png", b2Vec2(500.0f / SCALE, 450.0f / SCALE), world, 1.0f, 4.0f, 0.5f, 1.0f, 0.15f, 0.15f, 1, 0.0f, "circle"));
        //PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/PigKing.png", b2Vec2(600.0f / SCALE, 450.0f / SCALE), world, 0.5f, 4.0f, 0.5f, 1.6f, 0.6f, 0.6f, 3, 0.0f, "circle"));
        //PigVariant.push_back(std::make_unique<Pig>("../assets/Ang_Birds/PigSprite_5.png", b2Vec2(800.0f / SCALE, 450.0f / SCALE), world, 0.5f, 4.0f, 0.5f, 1.3f, 0.7f, 0.8f, 2, 0.0f, "circle"));

                 
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


class BirdTest : public testing::Test
{
public:
    std::list<std::unique_ptr<Bird>> BirdVariant;
    //setup world.
    b2Vec2 b2_gravity; // Earth-like gravity
    b2World world;
    const float SCALE = 30.0f;

protected:
    BirdTest() : b2_gravity(0.0f, 9.8f), world(b2_gravity)
    {
        b2Vec2 b2_gravity(0.0f, 9.8f); b2World world(b2_gravity);
        
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

    }

    ~PigTest() override {}

    void birdUpdate()
    {
        for (std::unique_ptr<Pig>& p : PigVariant)
        {
            p->UpdateSprite();

        }

    };

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

//AnnoyedFlocks Testing


TEST_F(BirdTest, birdTextureLoading_Test) //Does the testure for the sprite load
{
    Bird& b = *BirdVariant.front(); //pulls the bird prome the front of the list
    const sf::Texture* texture = b.getSprite().getTexture(); //get the texture
    ASSERT_NE(texture, nullptr);
}

TEST_F(EnemyTest, pigTextureLoading_Test) //Does the testure for the sprite load
{
    Pig& p = *PigVariant.front(); //pulls the pig prome the front of the list
    const sf::Texture* texture = p.getSprite().getTexture(); //get the texture
    ASSERT_NE(texture, nullptr);
}

//End of Annoyed flocks testing

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




//end of my tests

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}