#version 430 core
layout(location = 0) in vec in_position;

void main() {
	gl_Position = vec4(in_position);
}