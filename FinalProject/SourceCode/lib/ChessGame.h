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
#include "HCI557Common.h"

using namespace std;

class ChessGame {

private:
    vector<ChessPiece*> _pieces;
    vector<ChessPiece*> _tiles;

    GLDirectLightSource _default_light_source;
    GLMaterial _default_material;
    GLMaterial _white_tile_material;
    GLMaterial _black_tile_material;

    void setInitPicking(ChessPiece* obj);
    void setPreDrawPicking(ChessPiece* obj);
    ChessPiece *_selected_piece;

public:
    int size_of_tile = 5;

    ChessGame();

    ChessPiece* getChessPiecesAt(int idx);
    void build_chess_board();
    void build_chess_pieces();
    void setup_light_and_material();
    void draw();
    void preDrawPicking();
    void initPicking();
    void handleSelectedColor(float col[4]);
    void unhighlightAPiece(ChessPiece* p);
    void highlightAPiece(ChessPiece* p);

    ChessPiece* getObjectById(int id);

    GLAppearance* getDefaultAppearance();
    GLAppearance* getWhiteTileAppearance();
    GLAppearance* getBlackTileAppearance();



};
