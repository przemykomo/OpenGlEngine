#include "Include/GLES3/gl3.h"
#include "Include/GLFW/glfw3.h"
#include <iostream>
#include <cmath>
#include "Include/Engine/Camera.h"
#include "Include/Engine/Initialization.h"
#include "Include/Engine/CreateObject.h"
#include "Include/Engine/LightObject.h"


// settings
Init init_ref;
Camera camera;
Object object_ref;
point_light light_ref;


// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

int main()
{
    camera.SCR_HEIGHT = SCR_HEIGHT;
    camera.SCR_WIDTH = SCR_WIDTH;
    init_ref.create_window();
    // build and compile our shader zprogram
    // ------------------------------------
    
    Shader ourShader("4.1.texture.vs", "4.1.texture.fs");
    Shader LightShader("basic_lighting.vs", "basic_lighting.fs");
    

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    unsigned int VBO, VAO;
    object_ref.Create_Object(ourShader,VBO, VAO);
    unsigned int LightVAO;
    //light_ref.create_light(LightShader, VBO, LightVAO);


    // load and create a texture 
    // -------------------------
   


    


    // render loop
    // -----------
    while (!glfwWindowShouldClose(init_ref.window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(init_ref.window, deltaTime);

        // render
        // ------
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

        // bind textures on corresponding texture units
        

        
       
       //light_ref.render_light(LightShader, VBO, LightVAO);
       //camera.Camera_render(LightShader);
       object_ref.Render_Object(ourShader,VBO, VAO);
       camera.Camera_render(ourShader);
       
       
       

       

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(init_ref.window);
        glfwPollEvents();
    }

    object_ref.Delete_Object(VBO, VAO);
    light_ref.Delete_Object(VBO, LightVAO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window, float deltaTime)
{
    camera.processInput(window,deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.Process_Mouse_Scroll(yoffset);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    camera.Process_Mouse_Movement(xpos, ypos);
}