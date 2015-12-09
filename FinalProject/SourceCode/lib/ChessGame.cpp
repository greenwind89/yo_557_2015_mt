
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
    int sizeOfTile = 5;

    // list board along x then goes up to z
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {

            Tile* t = new Tile(2.5 + j*sizeOfTile, 2.5 + i*sizeOfTile, 0, sizeOfTile, sizeOfTile);

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
    ChessPiece* pawn = PieceFactory::get("pawn");

    pawn->setApperance(*_apperance_default);
    pawn->init();

    glm::mat4 tranform = glm::scale(glm::vec3(5.0, 5.0f, 5.0f));
    pawn->setMatrix(tranform);

    _pieces.push_back(pawn);

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
