
#include "ChessGame.h"

#include <algorithm>

ChessGame::ChessGame() {
    ChessPiece* pawn = new Pawn();

    _pieces.push_back(pawn);

}


ChessPiece* ChessGame::getChessPiecesAt(int idx) {
    return _pieces[idx];
}
