#include "GameScene.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    
    // FIXME
    // TODO - Remove this debug setting
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto backgroundSprite = Sprite::create("Background.png");
    backgroundSprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height /2 + origin.y));
    this->addChild(backgroundSprite);
    
    // Collision detection on screen edges
    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    
    auto edgeNode = Node::create();
    edgeNode->setPosition(visibleSize.width/2 + origin.x, visibleSize.height /2 + origin.y);
    
    edgeNode->setPhysicsBody(edgeBody);
    
    this->addChild(edgeNode);
    
    this->schedule(schedule_selector(GameScene::SpawnPipe), PIPE_SPAWN_FREQUENCY * visibleSize.width);
    
    return true;
}


void GameScene::SpawnPipe (float dt)
{
    pipe.SpawnPipe( 0 );
}
