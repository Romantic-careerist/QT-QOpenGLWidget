#version 330 core
out vec4 FragColor;
in vec4 vertexColor;
in vec2 TexCoord;
uniform sampler2D textureWall;
uniform sampler2D textureLe;
void main(){
    FragColor=mix(texture(textureLe,TexCoord),texture(textureWall,TexCoord),0.5)*vertexColor;
}
