// Vertex Shader

// Matrices
uniform mat4 u_Projection;
uniform mat4 u_Viewing;

// Passed Attributes
attribute vec3 a_Position;
attribute vec3 a_Normal;
attribute vec2 a_TexCoord;

// Fragment Passed variables
varying vec2 v_TexCoord;
varying vec3 v_Normal;
varying vec3 v_FragPos;

void main()
{
    gl_Position = u_Projection * u_Viewing * vec4(a_Position.x, a_Position.y, a_Position.z - 10.0, 1.0);
    
    v_TexCoord = a_TexCoord;
    v_Normal = normalize(mat3(1.0) * a_Normal); // REPLACE 1.0 in mat3() -> u_Model
    v_FragPos = vec3(mat4(1.0) * vec4(a_Position, 1.0)); // REPLACE MAT4(1.0) -> u_Model
}