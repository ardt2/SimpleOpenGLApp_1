#include "OpenGLApp_1.h"
// ============================================================================
// Реализация для https://habr.com/ru/post/311808/


// ------------------------------------------------------------------
using namespace std;



// ============================================================================
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
					  _In_opt_ HINSTANCE hPrevInstance,
					  _In_ LPWSTR lpCmdLine,
					  _In_ int nShowCmd)
{
	int res = 0;

	try
	{

		// --------------------------------------------------------------------
		int res = glfwInit();
			MY_ASSERT(res != GLFW_FALSE, "glfwInit returned 0.", "GLFW error");

		// ----------------------------------------------------------
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
			MY_ASSERT(window != nullptr, "glfwCreateWindow returned 0.", "GLFW error");

			glfwMakeContextCurrent(window);


		// --------------------------------------------------------------------
		glewExperimental = GL_TRUE;

		res = glewInit();
			MY_ASSERT(res == GLEW_OK, "glewInit returned 0.", "GLEW error");


		// --------------------------------------------------------------------
		int width, height;

		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);


		// ====================================================================
		GLint success;
		GLchar infolog[512];

		// ----------------------------------------------------------
		GLuint vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
			glGetShaderInfoLog(vertexShader, 512, NULL, infolog);
			MY_ASSERT(success, infolog, "Vertex shader error");

		// ----------------------------------------------------------
		GLuint fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
			glGetShaderInfoLog(fragmentShader, 512, NULL, infolog);
			MY_ASSERT(success, infolog, "Fragment shader error");

		// ----------------------------------------------------------
		GLuint shaderProgram;
		shaderProgram = glCreateProgram();

		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
			glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
			MY_ASSERT(success, infolog, "Link shaders error");

		// ----------------------------------------------------------
		glDeleteShader(vertexShader);	// Исходные тексты можно удалить
		glDeleteShader(fragmentShader);	// после компиляции.




		// ====================================================================
		GLuint VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// ----------------------------------------------------------
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		// --------------------------------------------------------------------
		GLuint VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);
		// 2. Копируем наш массив вершин в буфер для OpenGL
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		// 3. Устанавливаем указатели на вершинные атрибуты 
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		//4. Отвязываем VAO
		glBindVertexArray(0);


		// ====================================================================
//		glfwSetKeyCallback(window, key_callback);


		// ====================================================================
		while (!glfwWindowShouldClose(window))
		{


			glfwPollEvents();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

				// --------------------------------------------------
				glUseProgram(shaderProgram);

				glBindVertexArray(VAO);
				glDrawArrays(GL_TRIANGLES, 0, 3);
				glBindVertexArray(0);

				//// ------------------------------------------------
				//glUseProgram(shaderProgram2);



			glfwSwapBuffers(window);
		}

		res = 0;
	}
	catch (const TException & exc)
	{
		MessageBoxA(NULL, exc.Text.c_str(), exc.Caption.c_str(), MB_OK);
		res = -1;
	}

	glfwTerminate();

	return res;
}



/*
class Int
{
	public:
		int x = 0;

		Int(int v) : x(v) {}

		// operator int() const { return x; }
		operator int() & { return x; }

		Int& operator +=(const Int& r) { x += r.x; return *this; }

		operator std::string() { return std::string() }
};

// inline operator string(int x) {}

inline string ToString(int x)
{
	string str;
	ostringstream stream(str);
	stream << x;

	return str;
}

inline void My_Assert(bool condition, const std::string& caption, const std::string& text)
{

}

Rcc.&lt;GPort::A, GPort::B, GPort::C&gt;PortOn();

PortA.SetupPins
&lt;GPin::P6, GPin::P7, GPin::P8,
 GPin::P9, GPin::P10, GPin::P11, GPin::P12, GPin::P13, GPin::P14, GPin::P15&gt;
(PinMode1::Input, PinFunct1::AnalogInput);

PortA.SetupPins
&lt;GPin::P0, GPin::P1, GPin::P2, GPin::P3, GPin::P4, GPin::P5&gt;
(PinMode2::Out2MHz, PinFunct2::OpenDrain);


<textarea cols="89" rows="13" readonly="readonly" style="border:0px;color:#000075;
font-family:Courier;font-size:0.9em;">

Rcc.<GPort::A, GPort::B, GPort::C>PortOn();

PortA.SetupPins
<GPin::P6, GPin::P7, GPin::P8,
 GPin::P9, GPin::P10, GPin::P11, GPin::P12, GPin::P13, GPin::P14, GPin::P15>
(PinMode1::Input, PinFunct1::AnalogInput);

PortA.SetupPins
<GPin::P0, GPin::P1, GPin::P2, GPin::P3, GPin::P4, GPin::P5>
(PinMode2::Out2MHz, PinFunct2::OpenDrain);
</textarea>

 Специально не буду инициализировать, чтобы если на каком-либо пути исполнения забуду, то компилятор ругнется.


*/

