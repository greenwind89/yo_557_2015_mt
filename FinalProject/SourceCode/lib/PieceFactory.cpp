#include "PieceFactory.h"

#include <algorithm>

ChessPiece* PieceFactory::get(string type) {
    if(type == "pawn") return new ChessPiece("../../data/pawn.obj");

    if(type == "knight") return new ChessPiece("../../data/knight.obj");

    if(type == "bishop") return new ChessPiece("../../data/bishop.obj");

    if(type == "queen") return new ChessPiece("../../data/queen.obj");

    if(type == "king") return new ChessPiece("../../data/king.obj");

    if(type == "rook") return new ChessPiece("../../data/rook.obj");

    if(type == "tile") return new ChessPiece("../../data/tile.obj");

    return new ChessPiece();

}
