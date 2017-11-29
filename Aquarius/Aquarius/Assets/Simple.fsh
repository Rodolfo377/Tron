#version 330

in vec3 o_color;
in vec2 o_texture;

uniform sampler2D u_texture;

out vec4 fragColor;

void main()
{  
  //fragColor = texture(u_texture, o_texture) * vec4(o_color, 1.0);
  //fragColor = vec4(o_color, 1.0);

  fragColor = vec4(1.0, 0.0, 1.0, 1.0);

  // fragColor = vec4(o_color, 1.0);
  // fragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
