
#include "ChessGame.h"
#include "PieceFactory.h"

#include <algorithm>

ChessGame::ChessGame() {
    setup_light_and_material();
    build_chess_board();
    build_chess_pieces();
}


ChessPiece* ChessGame::getChessPiecesAt(int idx) {
    return _pieces[idx];
}

void ChessGame::build_chess_board() {

    // list board along x then goes up to z
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {

            Tile* t = new Tile(2.5 + j*size_of_tile, 2.5 + i*size_of_tile, 0, size_of_tile, size_of_tile);

            if((i + j) % 2 == 0 ) {
                t->setApperance(*_apperance_white_tile);
            } else {
                t->setApperance(*_apperance_black_tile);
            }

            t->init();

            glm::mat4 tranform = glm::rotate(glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));;
            t->setMatrix(tranform);

            _tiles.push_back(t);

        }

    }
}

void ChessGame::build_chess_pieces() {
    // generate pawns
    for (size_t i = 0; i < 8; i++) {
        ChessPiece* pawn1 = PieceFactory::get("pawn");

        pawn1->setApperance(*_apperance_default);
        pawn1->init();

        // pawn is at second line
        glm::mat4 tranform = glm::translate(glm::vec3(size_of_tile/2 + i*size_of_tile, 0.0f, size_of_tile + size_of_tile/2)) * glm::scale(glm::vec3(5.0, 5.0f, 5.0f));
        pawn1->setMatrix(tranform);

        _pieces.push_back(pawn1);

        ChessPiece* pawn2 = PieceFactory::get("pawn");

        pawn2->setApperance(*_apperance_default);
        pawn2->init();

        // pawn is at second line
        glm::mat4 tranform2 = glm::translate(glm::vec3(size_of_tile/2 + i*size_of_tile, 0.0f, size_of_tile*6 + size_of_tile/2)) * glm::scale(glm::vec3(5.0, 5.0f, 5.0f));
        pawn2->setMatrix(tranform2);

        _pieces.push_back(pawn2);
    }

    // generate others
    string type;
    for (size_t i = 0; i < 8; i++) {
        if(i == 0 || i == 7) type = "rook";
        else if(i == 1 || i == 6) type = "knight";
        else if(i == 2 || i == 5) type = "bishop";
        else if(i == 3) type = "king";
        else type = "queen";

        ChessPiece* p1 = PieceFactory::get(type);

        p1->setApperance(*_apperance_default);
        p1->init();

        // pawn is at second line
        glm::mat4 tranform = glm::translate(glm::vec3(size_of_tile/2 + i*size_of_tile, 0.0f, size_of_tile/2)) * glm::scale(glm::vec3(5.0, 5.0f, 5.0f));
        p1->setMatrix(tranform);

        _pieces.push_back(p1);

        ChessPiece* p2 = PieceFactory::get(type);

        p2->setApperance(*_apperance_default);
        p2->init();

        // pawn is at second line
        glm::mat4 tranform2 = glm::translate(glm::vec3(size_of_tile/2 + i*size_of_tile, 0.0f, size_of_tile*7 + size_of_tile/2)) * glm::scale(glm::vec3(5.0, 5.0f, 5.0f));
        p2->setMatrix(tranform2);

        _pieces.push_back(p2);
    }
}

void ChessGame::setup_light_and_material() {
    // create an apperance object.
    GLAppearance* apperance_0 = new GLAppearance("../../data/shaders/multi_vertex_lights.vs", "../../data/shaders/multi_vertex_lights.fs");

    GLDirectLightSource  light_source;
    light_source._lightPos = glm::vec4(20.0,20.0,0.0, 0.0);
    light_source._ambient_intensity = 0.2;
    light_source._specular_intensity = 5.5;
    light_source._diffuse_intensity = 2.0;
    light_source._attenuation_coeff = 0.0;

    // add the light to this apperance object
    apperance_0->addLightSource(light_source);

    // Create a material object
    GLMaterial material_0;
    material_0._diffuse_material = glm::vec3(1.0, 0.0, 0.2);
    material_0._ambient_material = glm::vec3(1.0, 0.0, 0.2);
    material_0._specular_material = glm::vec3(1.0, 1.0, 1.0);
    material_0._shininess = 12.0;
    material_0._transparency = 1.0;

    // Add the material to the apperance object
    apperance_0->setMaterial(material_0);
    apperance_0->finalize();


    // If you want to change appearance parameters after you init the object, call the update function
    apperance_0->updateLightSources();
    _apperance_default = apperance_0;

    // -------------------------- white tile =---------------------

    GLAppearance* apperance_white_tile = new GLAppearance("../../data/shaders/multi_vertex_lights.vs", "../../data/shaders/multi_vertex_lights.fs");

    GLMaterial material_white_tile;
    material_white_tile._diffuse_material = glm::vec3(1.0, 1.0, 1.2);
    material_white_tile._ambient_material = glm::vec3(1.0, 1.0, 1.2);
    material_white_tile._specular_material = glm::vec3(1.0, 1.0, 1.0);
    material_white_tile._shininess = 12.0;
    material_white_tile._transparency = 1.0;

    apperance_white_tile->addLightSource(light_source);
    apperance_white_tile->setMaterial(material_white_tile);
    apperance_white_tile->finalize();

    apperance_white_tile->updateLightSources();
    _apperance_white_tile =  apperance_white_tile;


    // -------------------------- black tile =---------------------
    GLAppearance* apperance_black_tile = new GLAppearance("../../data/shaders/multi_vertex_lights.vs", "../../data/shaders/multi_vertex_lights.fs");

    GLMaterial material_black_tile;
    material_white_tile._diffuse_material = glm::vec3(0.0, 0.0, 0.0);
    material_white_tile._ambient_material = glm::vec3(0.0, 0.0, 0.0);
    material_white_tile._specular_material = glm::vec3(0.0, 0.0, 0.0);
    material_white_tile._shininess = 12.0;
    material_white_tile._transparency = 1.0;

    apperance_black_tile->addLightSource(light_source);
    apperance_black_tile->setMaterial(material_black_tile);
    apperance_black_tile->finalize();

    apperance_black_tile->updateLightSources();
    _apperance_black_tile =  apperance_black_tile;


}

void ChessGame::draw() {
    for(int i=0; i<_tiles.size(); i++)
    {
        Tile* tile = _tiles[i];
        tile->draw();
    }

    for(int i=0; i<_pieces.size(); i++)
    {
        ChessPiece* piece = _pieces[i];
        piece->draw();
    }

}
