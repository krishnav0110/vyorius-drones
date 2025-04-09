#version 430

layout (binding = 0) uniform sampler2D tex1;

in vec2 TexCoord;

out vec4 FragColor;

const vec3 color = vec3(1.0f, 0.0f, 0.0f);

void main() {
    FragColor = texture(tex1, TexCoord) + vec4(color, 1.0f);
}