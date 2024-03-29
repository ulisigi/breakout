#pragma once
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <tuple>
#include <algorithm>

#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include "game_object.h"
#include "game_level.h"
#include "power_up.h"

// Current state
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

typedef std::tuple<GLboolean, Direction, glm::vec2> Collision;

// Player paddle
const glm::vec2 PLAYER_SIZE(100, 20);
const GLfloat PLAYER_VELOCITY(500.0f);
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
const GLfloat BALL_RADIUS = 12.5F;

// State, functionality, data in single class for easy access
class Game
{
public:
    // Game state
    GameState           State;
    GLboolean           Keys[1024];
    GLboolean           KeysProcessed[1024];
    GLuint              Width, Height;
    std::vector<GameLevel> Levels;
    GLuint              Level;
    GLuint              Lives;

    // Constructor/Destructor
    Game(GLuint width, GLuint height);
    ~Game();

    // Initialize game state
    void Init();
    
    // Game loop
    void ProcessInput(GLfloat dt);
    void Update(GLfloat dt);
    void Render();
    void DoCollisions();
  
    void ResetLevel();
    void ResetPlayer();


};

#endif