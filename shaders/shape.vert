#version 430

layout (location = 0) in vec2 pos;
layout (location = 1) in vec2 texCoord;

out vec2 TexCoord;

uniform mat4 transform;
uniform mat4 projection;

void main() {
    gl_Position = projection * transform * vec4(pos, -4.0, 1.0);
    TexCoord = texCoord;
}