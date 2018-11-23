#shader vertex
#version 330 core

layout(location = 0) in vec4 position;

uniform mat4 pr_matrix = mat4(1.0);
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 ml_matrix = mat4(1.0);

void main() 
{
	gl_Position = pr_matrix * vw_matrix * ml_matrix * position;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

void main()
{
	color = vec4(0.2, 0.5, 0.8, 0.0);
};