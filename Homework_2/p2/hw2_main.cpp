//
//  main.cpp
//  OpenGL4Test
//
//  Created by Rafael Radkowski on 5/28/15.
//  Copyright (c) 2015 -. All rights reserved.
//

// stl include
#include <iostream>
#include <string>

// GLEW include
#include <GL/glew.h>

// GLM include files
#define GLM_FORCE_INLINE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


// glfw includes
#include <GLFW/glfw3.h>


// include local files
#include "controls.h"
#include "HCI557Common.h"


using namespace std;

static const string vs_string =
"#version 410 core                                                 \n"
"                                                                   \n"
"uniform mat4 projectionMatrix;                                    \n"
"uniform mat4 viewMatrix;                                           \n"
"uniform mat4 modelMatrix;                                          \n"
"in vec3 in_Position;                                               \n"
"                                                                   \n"
"in vec3 in_Color;                                                  \n"
"out vec3 pass_Color;                                               \n"
"                                                                  \n"
"void main(void)                                                   \n"
"{                                                                 \n"
"    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(in_Position, 1.0);  \n"
"    pass_Color = in_Color;                                         \n"
"}                                                                 \n";

// Fragment shader source code. This determines the colors in the fragment generated in the shader pipeline. In this case, it colors the inside of our triangle specified by our vertex shader.
static const string fs_string  =
"#version 410 core                                                 \n"
"                                                                  \n"
"in vec3 pass_Color;                                                 \n"
"out vec4 color;                                                    \n"
"void main(void)                                                   \n"
"{                                                                 \n"
"    color = vec4(pass_Color, 1.0);                               \n"
"}                                                                 \n";




/// Camera control matrices
glm::mat4 projectionMatrix; // Store the projection matrix
glm::mat4 viewMatrix; // Store the view matrix
glm::mat4 modelMatrix; // Store the model matrix




// The handle to the window object
GLFWwindow*         window;


// Define some of the global variables we're using for this sample
GLuint program;







///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Fill this functions with your model code.

// USE THESE vertex array objects to define your objects
unsigned int vaoID[2];




/*!
 ADD YOUR CODE TO CREATE THE TRIANGLE STRIP MODEL TO THIS FUNCTION
 */
unsigned int createTriangleStripModel(void)
{
    // use the vertex array object vaoID[0] for this model representation

    int numVertices = 126;
    float* vertices = new float[numVertices];  // Vertices for our square
    float *colors = new float[numVertices]; // Colors for our vertices
    unsigned int vboID[2]; // Our Vertex Buffer Object
    int i = 0;
    int j = 0;


    // SHADOW PARTS 21 points, 19 triangles
    vertices[i++] = 0.0; vertices[i++] = 2.0; vertices[i++] = 0.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0.0; vertices[i++] = 2.0; vertices[i++] = 1.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0.0; vertices[i++] = 0.0; vertices[i++] = 0.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0.0; vertices[i++] = 0.0; vertices[i++] = 1.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 3.0; vertices[i++] = 0.0; vertices[i++] = 0.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 3.0; vertices[i++] = 0.0; vertices[i++] = 1.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0.0; vertices[i++] = 0.0; vertices[i++] = 1.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 3.0; vertices[i++] = 1.0; vertices[i++] = 1.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0.0; vertices[i++] = 2.0; vertices[i++] = 1.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 3.0; vertices[i++] = 1.0; vertices[i++] = 1.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 1.0; vertices[i++] = 2.0; vertices[i++] = 1.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0.0; vertices[i++] = 2.0; vertices[i++] = 1.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0.0; vertices[i++] = 0.0; vertices[i++] = 1.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 1.0; vertices[i++] = 0.0; vertices[i++] = 1.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0.0; vertices[i++] = 0.0; vertices[i++] = 3.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 1.0; vertices[i++] = 0.0; vertices[i++] = 3.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 1.0; vertices[i++] = 1.0; vertices[i++] = 3.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0.0; vertices[i++] = 0.0; vertices[i++] = 3.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0.0; vertices[i++] = 1.0; vertices[i++] = 3.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0.0; vertices[i++] = 0.0; vertices[i++] = 1.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0.0; vertices[i++] = 1.0; vertices[i++] = 1.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    // NON SHADOW 6 points 4 triangles

    vertices[i++] = 0.0; vertices[i++] = 1.0; vertices[i++] = 1.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 0.0; vertices[i++] = 1.0; vertices[i++] = 3.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 1.0; vertices[i++] = 1.0; vertices[i++] = 1.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 1.0; vertices[i++] = 1.0; vertices[i++] = 3.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 1.0; vertices[i++] = 0.0; vertices[i++] = 1.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 1.0; vertices[i++] = 0.0; vertices[i++] = 3.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    // NON SHADOW 2, 13 points , 11 triangles
    vertices[i++] = 0.0; vertices[i++] = 1.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 1.0; vertices[i++] = 0.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 0.0; vertices[i++] = 2.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 0.0; vertices[i++] = 0.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 1.0; vertices[i++] = 2.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 1.0; vertices[i++] = 0.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 3.0; vertices[i++] = 1.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 3.0; vertices[i++] = 0.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 3.0; vertices[i++] = 0.0; vertices[i++] = 1.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 3.0; vertices[i++] = 1.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 3.0; vertices[i++] = 1.0; vertices[i++] = 1.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 1.0; vertices[i++] = 2.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 1.0; vertices[i++] = 2.0; vertices[i++] = 1.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 0.0; vertices[i++] = 2.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 0.0; vertices[i++] = 2.0; vertices[i++] = 1.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    glGenVertexArrays(2, &vaoID[0]); // Create our Vertex Array Object
    glBindVertexArray(vaoID[0]); // Bind our Vertex Array Object so we can use it


    glGenBuffers(2, vboID); // Generate our Vertex Buffer Object

    // vertices
    glBindBuffer(GL_ARRAY_BUFFER, vboID[0]); // Bind our Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(GLfloat), vertices, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW

    glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(0); // Disable our Vertex Array Object


    //Color
    glBindBuffer(GL_ARRAY_BUFFER, vboID[1]); // Bind our second Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(GLfloat), colors, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW

    glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(1); // Enable the second vertex attribute array

    glBindVertexArray(0); // Disable our Vertex Buffer Object


    delete [] vertices; // Delete our vertices from memory

    return 1;
}

/*!
 ADD YOUR CODE TO CREATE A MODEL USING PRIMITIVES OF YOUR CHOISE TO THIS FUNCTION
 */
unsigned int createMyModel(void)
{
    // use the vertex array object vaoID[1] for this model representation
    int numVertices = 108;
    float* vertices = new float[numVertices];  // Vertices for our square
    float *colors = new float[numVertices]; // Colors for our vertices
    unsigned int vboID[2]; // Our Vertex Buffer Object

    int i = 0;
    int j = 0;

    // FIRST FAN - BOTTOM LEFT OF FRONT -SHADOW
    vertices[i++] = 0.0; vertices[i++] = 0.0; vertices[i++] = 3.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0.0; vertices[i++] = 0.0; vertices[i++] = 1.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0.0; vertices[i++] = 1.0; vertices[i++] = 1.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0.0; vertices[i++] = 1.0; vertices[i++] = 3.0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 1; vertices[i++] = 1; vertices[i++] = 3;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 1; vertices[i++] = 0; vertices[i++] = 3;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 1; vertices[i++] = 0; vertices[i++] = 1;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0; vertices[i++] = 0; vertices[i++] = 1;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    // SECOND FAN - MIDDLE of shadow start at 8
    vertices[i++] = 0; vertices[i++] = 0; vertices[i++] = 1;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0; vertices[i++] = 2; vertices[i++] = 1;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0; vertices[i++] = 2; vertices[i++] = 0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0; vertices[i++] = 0; vertices[i++] = 0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 3; vertices[i++] = 0; vertices[i++] = 0;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 3; vertices[i++] = 0; vertices[i++] = 1;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 3; vertices[i++] = 1; vertices[i++] = 1;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 1; vertices[i++] = 2; vertices[i++] = 1;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    vertices[i++] = 0; vertices[i++] = 2; vertices[i++] = 1;
    colors[j++] = 0.14; colors[j++] = 0.25; colors[j++] = 0.51;

    // TOP RIGHT OF FRONT OBJECT NON SHADOW
    vertices[i++] = 1.0; vertices[i++] = 1.0; vertices[i++] = 3.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 0.0; vertices[i++] = 1.0; vertices[i++] = 3.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 0.0; vertices[i++] = 1.0; vertices[i++] = 1.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 1.0; vertices[i++] = 1.0; vertices[i++] = 1.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 1.0; vertices[i++] = 0.0; vertices[i++] = 1.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 1.0; vertices[i++] = 0.0; vertices[i++] = 3.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    // BACK AND FRONT OF NONT SHADOW, 9 vertices

    vertices[i++] = 1.0; vertices[i++] = 2.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 0.0; vertices[i++] = 2.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 0.0; vertices[i++] = 2.0; vertices[i++] = 1.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 1.0; vertices[i++] = 2.0; vertices[i++] = 1.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 3.0; vertices[i++] = 1.0; vertices[i++] = 1.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 3.0; vertices[i++] = 1.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 3.0; vertices[i++] = 0.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 0.0; vertices[i++] = 0.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 0.0; vertices[i++] = 2.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    // FINAL FRONT, 4 vetices

    vertices[i++] = 3.0; vertices[i++] = 0.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 3.0; vertices[i++] = 1.0; vertices[i++] = 0.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 3.0; vertices[i++] = 1.0; vertices[i++] = 1.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    vertices[i++] = 3.0; vertices[i++] = 0.0; vertices[i++] = 1.0;
    colors[j++] = 0.31; colors[j++] = 0.49; colors[j++] = 0.79;

    glGenVertexArrays(2, &vaoID[1]); // Create our Vertex Array Object
    glBindVertexArray(vaoID[1]); // Bind our Vertex Array Object so we can use it


    glGenBuffers(2, vboID); // Generate our Vertex Buffer Object

    // vertices
    glBindBuffer(GL_ARRAY_BUFFER, vboID[0]); // Bind our Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(GLfloat), vertices, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW

    glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(0); // Disable our Vertex Array Object


    //Color
    glBindBuffer(GL_ARRAY_BUFFER, vboID[1]); // Bind our second Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(GLfloat), colors, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW

    glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(1); // Enable the second vertex attribute array

    glBindVertexArray(0); // Disable our Vertex Buffer Object

    delete [] vertices; // Delete our vertices from memory

    return 1;
}



/*!
 ADD YOUR CODE TO RENDER THE TRIANGLE STRIP MODEL TO THIS FUNCTION
 */
void renderTriangleStripModel(void)
{
    // Bind the buffer and switch it to an active buffer
    glBindVertexArray(vaoID[0]);

    // Draw the triangles
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 41);
}

/*!
 ADD YOUR CODE TO RENDER YOUR MODEL TO THIS FUNCTION
 */
void renderMyModel(void)
{

    // Bind the buffer and switch it to an active buffer
    glBindVertexArray(vaoID[1]);

    // Draw the triangles
    glDrawArrays(GL_TRIANGLE_FAN, 0, 8);
    glDrawArrays(GL_TRIANGLE_FAN, 8, 9);
    glDrawArrays(GL_TRIANGLE_FAN, 17, 6);
    glDrawArrays(GL_TRIANGLE_FAN, 23, 9);
    glDrawArrays(GL_TRIANGLE_FAN, 32, 4);

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*!
 This function creates the two models
 */
void setupScene(void) {

    createTriangleStripModel();
    createMyModel();

}


/*!
 This function updates the virtual camera
 */
bool updateCamera()
{
    // Compute the MVP matrix from keyboard and mouse input
    computeMatricesFromInputs();
    viewMatrix =  getViewMatrix(); // get the current view matrix

    return true;
}





int main(int argc, const char * argv[])
{

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// Init glfw, create a window, and init glew

    // Init the GLFW Window
    window = initWindow();


    // Init the glew api
    initGlew();

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// The Shader Program starts here

    // Vertex shader source code. This draws the vertices in our window. We have 3 vertices since we're drawing an triangle.
    // Each vertex is represented by a vector of size 4 (x, y, z, w) coordinates.
    static const string vertex_code = vs_string;
    static const char * vs_source = vertex_code.c_str();

    // Fragment shader source code. This determines the colors in the fragment generated in the shader pipeline. In this case, it colors the inside of our triangle specified by our vertex shader.
    static const string fragment_code = fs_string;
    static const char * fs_source = fragment_code.c_str();

    // This next section we'll generate the OpenGL program and attach the shaders to it so that we can render our triangle.
    program = glCreateProgram();

    // We create a shader with our fragment shader source code and compile it.
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fs_source, NULL);
    glCompileShader(fs);

    // We create a shader with our vertex shader source code and compile it.
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vs_source, NULL);
    glCompileShader(vs);

    // We'll attach our two compiled shaders to the OpenGL program.
    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);

    // We'll specify that we want to use this program that we've attached the shaders to.
    glUseProgram(program);

    //// The Shader Program ends here
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /// IGNORE THE NEXT PART OF THIS CODE
    /// IGNORE THE NEXT PART OF THIS CODE
    /// IGNORE THE NEXT PART OF THIS CODE
    // It controls the virtual camera

    // Set up our green background color
    static const GLfloat clear_color[] = { 0.6f, 0.7f, 1.0f, 1.0f };
    static const GLfloat clear_depth[] = { 1.0f, 1.0f, 1.0f, 1.0f };


    projectionMatrix = glm::perspective(1.1f, (float)800 / (float)600, 0.1f, 100.f);
    modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)); // Create our model matrix which will halve the size of our model
    viewMatrix = glm::lookAt(glm::vec3(1.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    int projectionMatrixLocation = glGetUniformLocation(program, "projectionMatrix"); // Get the location of our projection matrix in the shader
    int viewMatrixLocation = glGetUniformLocation(program, "viewMatrix"); // Get the location of our view matrix in the shader
    int modelMatrixLocation = glGetUniformLocation(program, "modelMatrix"); // Get the location of our model matrix in the shader


    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &projectionMatrix[0][0]); // Send our projection matrix to the shader
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]); // Send our view matrix to the shader
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]); // Send our model matrix to the shader


    glBindAttribLocation(program, 0, "in_Position");
    glBindAttribLocation(program, 1, "in_Color");

    //// The Shader Program ends here
    //// START TO READ AGAIN
    //// START TO READ AGAIN
    //// START TO READ AGAIN
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    // this creates the scene
    setupScene();



    // Enable depth test
    // ignore this line, it allows us to keep the distance value after we proejct each object to a 2d canvas.
    glEnable(GL_DEPTH_TEST);

    // This is our render loop. As long as our window remains open (ESC is not pressed), we'll continue to render things.
    while(!glfwWindowShouldClose(window))
    {

        // Clear the entire buffer with our green color (sets the background to be green).
        glClearBufferfv(GL_COLOR , 0, clear_color);
        glClearBufferfv(GL_DEPTH , 0, clear_depth);


        // update the virtual camera
        // ignore this line since we did not introduced cameras.
        updateCamera();


        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //// This generate the object
        // Enable the shader program
        glUseProgram(program);

        // this changes the camera location
        glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]); // send the view matrix to our shader

        // This moves the model to the right
        modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(2.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]); // Send our model matrix to the shader

        renderTriangleStripModel();

        // This moves the model to the left
        modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-2.0f, -0.0f, 0.0f));
        glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]); // Send our model matrix to the shader

        renderMyModel();


        glUseProgram(0);
        //// This generate the object
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        // Swap the buffers so that what we drew will appear on the screen.
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    // Program clean up when the window gets closed.
    glDeleteVertexArrays(2, vaoID);
    glDeleteProgram(program);
}
