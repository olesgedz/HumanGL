#version 410 core

in vec2 vTexCoord;
in vec3 vNormal;
in vec3 vFragPos;
in vec3 PosRef;

struct Material {
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
	float constant;
	float linear;
	float quadratic;
};

uniform	int lightNumb;
uniform Light light;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform Material material;
uniform samplerCube skybox;

out vec4 fColor;
void main()
{
//	vec3 result = vec3(0.0f, 0.0f, 0.0f);
//
//
//		float distance = length(lightPos - vFragPos);
//		float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
//
//		vec3 ambient = material.diffuse * light.ambient;
//		ambient *= attenuation;
//		result += ambient;
//
//		vec3 norm = normalize(vNormal);
//		vec3 lightDir = normalize(lightPos - vFragPos);
//		float diff = max(dot(norm, lightDir), 0.0);
//		vec3 diffuse = material.diffuse * diff *  light.diffuse;
//		diffuse *= attenuation;
//		result += diffuse;
//
//		vec3 viewDir = normalize(viewPos - vFragPos);
//		vec3 reflectDir = reflect(-lightDir, norm);
//		float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
//		vec3 specular = material.specular * spec * light.specular;
//		specular *= attenuation;
//
//
//		vec3 I = normalize(Position - cameraPos);
//		vec3 R = reflect(I, normalize(Normal));
//		FragColor = vec4(texture(skybox, R).rgb, 1.0);
//		result += specular;
//
//	fColor = //vec4(result, 1.0f);
    vec3 norm = normalize(vNormal);
	vec3 I = normalize(PosRef - viewPos);
	vec3 R = reflect(I, normalize(norm));
	fColor = vec4(texture(skybox, R).rgb, 1.0);

}