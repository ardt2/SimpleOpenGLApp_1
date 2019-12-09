#ifndef _MY_CONSTSHADERS_1_HPP_
#define _MY_CONSTSHADERS_1_HPP_
// ============================================================================


// ==================================================================
	//	#version 330 core
	//	layout(location = 0) in vec3 position;
	//	void main()
	//	{
	//		gl_Position = vec4(position.x, position.y, position.z, 1.0);
	//	}
const GLchar * const vertexShaderSource =
	"\
	#version 330 core\n						\
	layout(location = 0) in vec3 position;	\
	void main()								\
	{	\
		gl_Position = vec4(position.x, position.y, position.z, 1.0);	\
	}	\
	";


// ==================================================================
	//	#version 330 core
	//	out vec4 color;
	//	void main()
	//	{
	//		color = vec4(1.0f, 0.5f, 0.2f, 1.0f);
	//	}

const GLchar * const fragmentShaderSource =
	"\
	#version 330 core\n	\
	out vec4 color;		\
	void main()			\
	{	\
		color = vec4(1.0f, 0.5f, 0.2f, 1.0f);	\
	}	\
	";




#endif
