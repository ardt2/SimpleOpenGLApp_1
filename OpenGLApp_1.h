#ifndef _MY_OPENGLAPP_1_HPP_
#define _MY_OPENGLAPP_1_HPP_
// ============================================================================
// ���������� ��� https://habr.com/ru/post/311808/


// ============================================================================
// ����� ���������� Windows
#include <SDKDDKVer.h>
// ��������� ����� ������������ ���������� �� ���������� Windows
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// ------------------------------------------------------------------
// C++
#include <string>
#include <ostream>
#include <sstream>

#include <exception>
#include <stdexcept>
#include <assert.h>


// ------------------------------------------------------------------
// ����� ���������� GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// ------------------------------------------------------------------
// ����� ���������� GLFW
#include <GLFW\glfw3.h>


// ������ ���������� � ASSERT
// ============================================================================
#include "Exception.h"


// �������� ������ ��� glfwSetKeyCallback
// ============================================================================
#include "CallBacks.h"


// ============================================================================
// ������� ��� ������������ ������.
#include "ConstShaders.h"

// ------------------------------------------------------------------
// ����������� ��������� (�����������, �������������)...
#include "ConstPrimitives.h"



// ============================================================================
#endif
