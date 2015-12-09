#pragma once

// stl include
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// GLEW include
#include <GL/glew.h>

// GLM include files
#define GLM_FORCE_INLINE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "ChessPiece.h"
#include "Tile.h"
#include "HCI557Common.h"

using namespace std;

class ChessGame {

private:
    vector<ChessPiece*> _pieces;
    vector<Tile*> _tiles;
    GLAppearance* _apperance_default;
    GLAppearance* _apperance_white_tile;
    GLAppearance* _apperance_black_tile;
    int size_of_tile = 5;
public:
    ChessGame();

    ChessPiece* getChessPiecesAt(int idx);
    void build_chess_board();
    void build_chess_pieces();
    void setup_light_and_material();
    void draw();

};
