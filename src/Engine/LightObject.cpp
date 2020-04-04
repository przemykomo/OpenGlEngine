#include "Engine/LightObject.h"
point_light::point_light()
{
    Object();
}
void point_light::render_light(Shader shader) {
    // be sure to activate shader when setting uniforms/drawing objects
    shader.use();
    shader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
    shader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
    shader.setVec3("lightPos", WorldPos);
    

    // world transformation
    glm::mat4 model = glm::mat4(1.0f);
    shader.setMat4("model", model);

    // render the cube
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

point_light::~point_light() {
    //TODO: Move this to deconstructor
    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
