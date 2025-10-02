#include <iostream> 
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void error_callback(int error, const char* description)
{
    std::cerr << "Error: " << description << std::endl;
}

int main()
{
    glfwSetErrorCallback(error_callback); //just incase of errors
    //Initialize GLFW, check it initialized and return error if failed
    if(!glfwInit()){
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1; 
    }
    //create an 640x480 window called Space indvaders saved into window
    GLFWwindow* window = glfwCreateWindow(640, 480, "Space Invaders", nullptr, nullptr);
    if (!window) //checking window was created correctly
    {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); //tells OpenGL to render into window


    if(glewInit() != GLEW_OK) //initialize GLEW to use latest OpenGL version and check it loaded
    {
        std::cerr << "Could not load GLEW" << std::endl;
        glfwTerminate();
        return -1;
    }
    glClearColor(1.0, 0.0, 4.0, 1); //sets background to opaque red every time a frame refreshes
    while(!glfwWindowShouldClose(window)) //while user has NOT pressed X to close the window
    {
        glClear(GL_COLOR_BUFFER_BIT); //clear the color buffer to what we set GLclear to be
        glfwSwapBuffers(window); //display the frame that was just drawn (swap back buffer and front buffer)
        glfwPollEvents(); //check for user inputs
    }

    //deleting the created windows and clearing resources
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}