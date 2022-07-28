#version 460 core

out vec4 FragColor;

in vec3 UniColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D UniTexture;

void main()
{
	FragColor = texture(UniTexture, TexCoord);
}