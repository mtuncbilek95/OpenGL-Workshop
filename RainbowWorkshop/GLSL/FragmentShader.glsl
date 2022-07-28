#version 460 core
out vec4 FragColor;

in vec3 UniformColor; 
void main()
{
	FragColor = vec4(UniformColor, 1.0f);
}