#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec3 rot;
layout(location = 3) in vec2 scale;
layout(location = 4) in vec2 translate;

out vec2 v_TexCoord;

uniform mat4 u_MVP;

vec2 rotate(vec2 v, float a) {
	float s = sin(a);
	float c = cos(a);
	mat2 m = mat2(c, -s, s, c);
	return m * v;
}

mat4 rotationMatrix(vec3 axis, float angle) {
	axis = normalize(axis);
	float s = sin(angle);
	float c = cos(angle);
	float oc = 1.0 - c;

	return mat4(oc * axis.x * axis.x + c, oc * axis.x * axis.y - axis.z * s, oc * axis.z * axis.x + axis.y * s, 0.0,
		oc * axis.x * axis.y + axis.z * s, oc * axis.y * axis.y + c, oc * axis.y * axis.z - axis.x * s, 0.0,
		oc * axis.z * axis.x - axis.y * s, oc * axis.y * axis.z + axis.x * s, oc * axis.z * axis.z + c, 0.0,
		0.0, 0.0, 0.0, 1.0);
}

vec4 rotate(vec4 v, vec3 axis, float angle) {
	mat4 m = rotationMatrix(axis, angle);
	return m * v;
}

void main()
{
	vec4 modded = position;
	modded = rotate(modded, vec3(1, 0, 0), rot.x);
	modded = rotate(modded, vec3(0, 1, 0), rot.y);
	modded = rotate(modded, vec3(0, 0, 1), rot.z);

	modded = vec4(modded.x * scale.x + translate.x,
				  modded.y * scale.y + translate.y,
				  modded.z,
				  modded.w);
	gl_Position = u_MVP * modded;
	v_TexCoord = texCoord;
};
       
#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
	vec4 texColor = texture(u_Texture, v_TexCoord);
	color = texColor;
};