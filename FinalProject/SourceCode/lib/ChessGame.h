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
#include "Pawn.h"

using namespace std;

class ChessGame {

private:
    vector<ChessPiece*> _pieces;
public:
    ChessGame();

    ChessPiece* getChessPiecesAt(int idx);

};
