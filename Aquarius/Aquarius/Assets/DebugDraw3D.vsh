#version 430 core
in vec3 a_position;
in vec4 a_color;
out vec4 v_color;
uniform mat4 u_worldviewproj;

void main()
{
    v_color = a_color;
    gl_Position = u_worldviewproj * vec4(a_position, 1.0);
}
