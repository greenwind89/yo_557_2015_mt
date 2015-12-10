#include "ChessGame.h"

void ChessGame::setup_light_and_material() {
    // create an apperance object.

    _default_light_source._lightPos = glm::vec4(20.0,20.0,20.0, 1.0);
    _default_light_source._ambient_intensity = 0.2;
    _default_light_source._specular_intensity = 5.5;
    _default_light_source._diffuse_intensity = 2.0;
    _default_light_source._attenuation_coeff = 0.0;

    // add the light to this apperance object
    
    //Spot light
    _spot_light_source._lightPos = glm::vec4(10.0,10.0,10.0, 1.0);
    _spot_light_source._ambient_intensity = 0.3;
    _spot_light_source._specular_intensity = 1.0;
    _spot_light_source._diffuse_intensity = 10.0;
    _spot_light_source._attenuation_coeff = 0.01;
    _spot_light_source._cone_angle = 30;
    _spot_light_source._cone_direction = glm::vec3(5.0, 5.0, 5.0);

    // Create a material object
    _default_material._diffuse_material = glm::vec3(1.0, 0.0, 0.2);
    _default_material._ambient_material = glm::vec3(1.0, 0.0, 0.2);
    _default_material._specular_material = glm::vec3(1.0, 1.0, 1.0);
    _default_material._shininess = 12.0;
    _default_material._transparency = 1.0;

    // Add the material to the apperance object

    // -------------------------- white tile =---------------------


    _white_tile_material._diffuse_material = glm::vec3(1.0, 1.0, 1.0);
    _white_tile_material._ambient_material = glm::vec3(1.0, 1.0, 1.0);
    _white_tile_material._specular_material = glm::vec3(1.0, 1.0, 1.0);
    _white_tile_material._shininess = 12.0;
    _white_tile_material._transparency = 1.0;


    // -------------------------- black tile =---------------------

    _black_tile_material._diffuse_material = glm::vec3(0.0, 0.0, 0.0);
    _black_tile_material._ambient_material = glm::vec3(0.0, 0.0, 0.0);
    _black_tile_material._specular_material = glm::vec3(0.0, 0.0, 0.0);
    _black_tile_material._shininess = 12.0;
    _black_tile_material._transparency = 1.0;

}

GLAppearance* ChessGame::getDefaultAppearance() {
    GLAppearance* appearance = new GLAppearance("../../data/shaders/multi_vertex_lights_ext.vs", "../../data/shaders/multi_vertex_lights.fs");

    appearance->addLightSource(_default_light_source);
    appearance->addLightSource(_spot_light_source);
    appearance->setMaterial(_default_material);
    appearance->finalize();

    // If you want to change appearance parameters after you init the object, call the update function
    appearance->updateLightSources();

    return appearance;

}
GLAppearance* ChessGame::getWhiteTileAppearance() {
    GLAppearance* appearance = new GLAppearance("../../data/shaders/multi_vertex_lights_ext.vs", "../../data/shaders/multi_vertex_lights.fs");

    appearance->addLightSource(_default_light_source);
    appearance->addLightSource(_spot_light_source);
    appearance->setMaterial(_white_tile_material);
    appearance->finalize();

    // If you want to change appearance parameters after you init the object, call the update function
    appearance->updateLightSources();

    return appearance;

}
GLAppearance* ChessGame::getBlackTileAppearance() {
    GLAppearance* appearance = new GLAppearance("../../data/shaders/multi_vertex_lights_ext.vs", "../../data/shaders/multi_vertex_lights.fs");

    appearance->addLightSource(_default_light_source);
    appearance->addLightSource(_spot_light_source);
    appearance->setMaterial(_black_tile_material);
    appearance->finalize();

    // If you want to change appearance parameters after you init the object, call the update function
    appearance->updateLightSources();

    return appearance;

}
