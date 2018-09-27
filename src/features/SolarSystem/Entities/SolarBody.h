#pragma once

#include <glew.h>

#include <glm/glm.hpp>
using glm::vec3;
using glm::mat4;

#include <vector>
#include <string>
using namespace std;

#include <OGLProgram.h>

class SolarBody
{

private:
   typedef struct
   {
      GLuint textureId;
      GLenum textureUnit;
   } Texture;

public:

   typedef struct
   {
      float scale;
      float rotation_speed;

      vec3 axis;
      float revolution_radius;
      float revolution_speed;

      string texture_file;
      GLenum textureUnit;
      bool mipmap;
   } SolarData;

   SolarBody(const SolarData& data);
   ~SolarBody();

   static bool Initialize();
   static void Uninitialize();

   const mat4& GetModelMatrix();
   void SetTexture(const string& textureFile, GLenum activeTextureUnit, bool mipmaps);
   unsigned int GetDiffuseTextureId();

   bool AddSatellite(const SolarData& data);
   void Render(OGLProgram& program, mat4& projectionMatrix, mat4 viewMatrix, const mat4& offsetMatrix = mat4(1.0));

public:
   const vec3& RotateAroundAxis(vec3 axis, float radius, float angle);
   float m_rotateSpeed, m_rotateAngle;
   float m_revolveSpeed, m_revolveAngle, m_revolveRadius;
   vec3 m_axis;

   float m_scale;
private:
   static GLuint m_vertexBuffer, m_normalBuffer, m_textureBuffer, m_tangentBuffer, m_vao;
   static bool m_isInitialized;
   static size_t m_count;

   unsigned int m_diffuseTextureId;
   
  
   vector<Texture> m_textures;
   mat4 m_modelMatrix;
   vector<SolarBody*> m_satellites;

   OGLProgram* m_lastProgram; // only for uniforms optimization
};
