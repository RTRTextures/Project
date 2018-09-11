//#include <fstream>
//#include <gl\glew.h>
//#include <gl\GL.h>
//#include <gl\GLU.h>
//#include <Windows.h>
//
//#define MAX_INFO_LOG_SIZE 1024
//
//unsigned int getFileLength(std::ifstream& file)
//{
//
//    if (!file.good()) return 0;
//
//    unsigned long pos = (unsigned long)file.tellg();
//    file.seekg(0, std::ios::end);
//    unsigned long len = (unsigned long)file.tellg();
//    file.seekg(std::ios::beg);
//
//    return len;
//}
//
//GLubyte* loadShaderFromFile(char* shaderFilePath)
//{
//    std::ifstream shaderFile;
//
//    GLubyte *shaderSource;
//
//    shaderFile.open(shaderFilePath, std::ios::in);
//    if (!shaderFile)
//        return NULL;
//
//    unsigned long shaderFileLen = getFileLength(shaderFile);
//
//    shaderSource = (GLubyte*) new char[shaderFileLen + 1];
//    if (shaderSource == 0)
//        return NULL;
//
//    unsigned int i = 0;
//    while (shaderFile.good())
//    {
//        shaderSource[i] = shaderFile.get();
//        if (!shaderFile.eof())
//            i++;
//    }
//    shaderSource[i] = 0;
//    shaderFile.close();
//
//    return shaderSource;
//}
//
//int compileShader(GLubyte* source, GLenum shaderType, GLuint *shader)
//{
//    const char *shaderStringPtr[1];
//    GLint success;
//
//    // Create shader objects and specify shader text
//    *shader = glCreateShader(shaderType);
//
//    shaderStringPtr[0] = (char*)source;
//    glShaderSource(*shader, 1, shaderStringPtr, NULL);
//
//    // Compile shaders and check for any errors
//    glCompileShader(*shader);
//    glGetShaderiv(*shader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        char infoLog[MAX_INFO_LOG_SIZE];
//        char errorMsg[1024];
//        glGetShaderInfoLog(*shader, MAX_INFO_LOG_SIZE, NULL, infoLog);
//        sprintf_s(errorMsg, 1024, "%s", infoLog);
//        MessageBoxA(NULL, infoLog, "ERROR", MB_OK);
//        return -1;
//    }
//
//    return 0;
//}
//
//int linkShader(GLuint progObj)
//{
//    GLint success;
//
//    glLinkProgram(progObj);
//    glGetProgramiv(progObj, GL_LINK_STATUS, &success);
//    if (!success)
//    {
//        char infoLog[MAX_INFO_LOG_SIZE];
//        glGetProgramInfoLog(progObj, MAX_INFO_LOG_SIZE, NULL, infoLog);
//        return 0;
//    }
//    return 0;
//}
//
//int VSIUtilLoadShaders(
//    char* vsFilePath,
//    char* fsFilePath
//)
//{
//    int retVal;
//    GLubyte* vertexShaderSource;
//    GLubyte* fragmentShaderSource;
//    GLuint progObj;
//    GLuint vertexShader;
//    GLuint fragmentShader;
//
//    if (!GLEW_VERSION_2_0 && (!GLEW_ARB_vertex_shader ||
//        !GLEW_ARB_fragment_shader ||
//        !GLEW_ARB_shader_objects ||
//        !GLEW_ARB_shading_language_100 ||
//        !GLEW_ARB_tessellation_shader))
//    {
//        // Required functionality not present. Returning error.
//        return -1;
//    }
//
//    vertexShaderSource = loadShaderFromFile(vsFilePath);
//    if (!vertexShaderSource)
//        return -1;
//
//    fragmentShaderSource = loadShaderFromFile(fsFilePath);
//    if (!fragmentShaderSource)
//        return -1;
//
//    retVal = compileShader(vertexShaderSource, GL_VERTEX_SHADER, &vertexShader);
//    if (retVal == -1)
//        return -1;
//
//    retVal = compileShader(fragmentShaderSource, GL_FRAGMENT_SHADER, &fragmentShader);
//    if (retVal == -1)
//        return -1;
//
//    // Create program object, attach shaders, then link
//    progObj = glCreateProgram();
//
//    glAttachShader(progObj, vertexShader);
//    glAttachShader(progObj, fragmentShader);
//    linkShader(progObj);
//
//    return progObj;
//}