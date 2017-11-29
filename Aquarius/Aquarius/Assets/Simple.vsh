#version 330 core

// Uniforms
uniform mat4 u_projection;
uniform mat4 u_view;
uniform mat4 u_model;

// Vertex atributes
in vec3 a_position;
in vec3 a_normal;
in vec2 a_texture;

vec3 u_light_direction = vec3(1.0, 1.0, 1.0);

out vec2 v_texture;
out vec3 v_color;

void main()
{
	vec3 normal = normalize((u_model * vec4(a_normal, 0.0)).xyz);

	vec3 light_dir = normalize(u_light_direction);
	float intensity = max(0.0, dot(normal, light_dir));

	//float intensity = (dot(normal, light_dir) + 1.0) * 0.5;
	v_color = vec3(intensity, intensity, intensity);

	v_texture = a_texture;
	gl_Position = u_projection * u_view * u_model * vec4(a_position, 1.0);
}
