#ifndef _MY_OPENGLAPP_1_CALLBACKS_HPP_
#define _MY_OPENGLAPP_1_CALLBACKS_HPP_
// ============================================================================


// ============================================================================
inline void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// ����� ������������ �������� ESC, �� ������������� �������� WindowShouldClose � true, 
	// � ���������� ����� ����� ���������
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}



// ----------------------------------------------------------------------------
#endif _MY_OPENGLAPP_1_CALLBACKS_HPP_
