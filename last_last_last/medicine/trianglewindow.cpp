#include "trianglewindow.h"

TriangleWindow::TriangleWindow()
    : m_program(0)
    , m_frame(0)
{
}


//! [3]
static const char *vertexShaderSource =
    "attribute highp vec4 posAttr;\n"
    "attribute lowp vec4 colAttr;\n"
    "varying lowp vec4 col;\n"
    "uniform highp mat4 matrix;\n"
    "void main() {\n"
    "   col = colAttr;\n"
    "   gl_Position = matrix * posAttr;\n"
    "}\n";

static const char *fragmentShaderSource =
    "varying lowp vec4 col;\n"
    "void main() {\n"
    "   gl_FragColor = col;\n"
    "}\n";


GLuint TriangleWindow::loadShader(GLenum type, const char *source)
{
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, 0);
    glCompileShader(shader);
    return shader;
}

void TriangleWindow::initialize()
{
    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    m_program->link();
    m_posAttr = m_program->attributeLocation("posAttr");
    m_colAttr = m_program->attributeLocation("colAttr");
    m_matrixUniform = m_program->uniformLocation("matrix");
}



void TriangleWindow::render()
{
    glViewport(0, 0, width(), height());

    glClear(GL_COLOR_BUFFER_BIT);

    m_program->bind();

    QMatrix4x4 matrix;
    matrix.perspective(120, 4.0/3.0, 0.1, 100.0);
    matrix.translate(0, 0, -2);
//    matrix.rotate(100.0f * m_frame / screen()->refreshRate(), 0, 1, 0);

    m_program->setUniformValue(m_matrixUniform, matrix);    

    int n = 125;
//    glColorMask(255,255,255,0);
    GLfloat vertices[] = {
        //1 ряд
        -3.5f, 1.1f,  -3.5f, 0.6f,  -3.0f, 1.1f,  -3.0f, 0.6f, -2.5f, 1.1f,  -2.5f, 0.6f, -2.0f, 1.1f, -2.0f, 0.6f,
        -1.5f, 1.1f,  -1.5f, 0.6f,  -1.0f, 1.1f,  -1.0f, 0.6f, -0.5f, 1.1f,  -0.5f, 0.6f, 0.0f, 1.1f,  0.0f, 0.6f,
        0.5f, 1.1f,   0.5f, 0.6f,   1.0f, 1.1f,    1.0f, 0.6f, 1.5f, 1.1f,   1.5f, 0.6f,  2.0f, 1.1f,  2.0f, 0.6f,
        2.5f, 1.1f,   2.5f, 0.6f,   3.0f, 1.1f,    3.0f, 0.6f, 3.5f, 1.1f,   3.5f, 0.6f,  4.0f, 1.1f,  4.0f, 0.6f,
        //переход
        4.0f, 0.1f,

        //2 ряд
        3.5f, 0.6f,   3.5f, 0.1f,     3.0f, 0.6f,     3.0f, 0.1f,   2.5f, 0.6f,   2.5f, 0.1f,   2.0f, 0.6f,   2.0f, 0.1f,
        1.5f, 0.6f,   1.5f, 0.1f,     1.0f, 0.6f,     1.0f, 0.1f,   0.5f, 0.6f,   0.5f, 0.1f,   0.0f, 0.6f,   0.0f, 0.1f,
       -0.5f, 0.6f,  -0.5f, 0.1f,    -1.0f, 0.6f,    -1.0f, 0.1f,  -1.5f, 0.6f,  -1.5f, 0.1f,  -2.0f, 0.6f,  -2.0f, 0.1f,
       -2.5f, 0.6f,  -2.5f, 0.1f,    -3.0f, 0.6f,    -3.0f, 0.1f,  -3.5f, 0.6f,  -3.5f, 0.1f,

        //переход
        -3.5f, -0.4f,


       //3 ряд
        -3.0f, 0.1f,    -3.0f, -0.4f,    -2.5f, 0.1f,   -2.5f, -0.4f,  -2.0f, 0.1f, -2.0f, -0.4f,  -1.5f, 0.1f, -1.5f, -0.4f,
        -1.0f, 0.1f,    -1.0f, -0.4f,    -0.5f, 0.1f,   -0.5f, -0.4f,   0.0f, 0.1f,  0.0f, -0.4f,   0.5f, 0.1f,  0.5f, -0.4f,
         1.0f, 0.1f,     1.0f, -0.4f,     1.5f, 0.1f,    1.5f, -0.4f,   2.0f, 0.1f,  2.0f, -0.4f,   2.5f, 0.1f,  2.5f, -0.4f,
         3.0f, 0.1f,     3.0f, -0.4f,     3.5f, 0.1f,    3.5f, -0.4f,   4.0f, 0.1f,  4.0f, -0.4f,


        //переход
        4.0f, -0.9f,

        //4ряд
         3.5f, -0.4f,   3.5f, -0.9f,  3.0f, -0.4f,   3.0f, -0.9f,   2.5f, -0.4f,   2.5f, -0.9f,  2.0f, -0.4f, 2.0f, -0.9f,
         1.5f, -0.4f,   1.5f, -0.9f,  1.0f, -0.4f,   1.0f, -0.9f,   0.5f, -0.4f,   0.5f, -0.9f,  0.0f, -0.4f, 0.0f, -0.9f,
        -0.5f, -0.4f,  -0.5f, -0.9f, -1.0f, -0.4f,  -1.0f, -0.9f,  -1.5f, -0.4f,  -1.5f, -0.9f, -2.0f, -0.4f, -2.0f, -0.9f,
        -2.5f, -0.4f,  -2.5f, -0.9f, -3.0f, -0.4f,  -3.0f, -0.9f,  -3.5f, -0.4f,  -3.5f, -0.9f







    };

   GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,//1
        0.0f, 1.0f, 0.0f,//2
        0.0f, 0.0f, 1.0f,//3
        0.0f, 0.0f, 1.0f,//4
        0.0f, 1.0f, 0.0f,//5
        1.0f, 0.0f, 0.4f,//6
        1.0f, 0.0f, 0.0f,//7
        0.0f, 1.0f, 0.0f,//8
        0.0f, 0.0f, 1.0f,//9
        0.0f, 1.0f, 0.0f,//10
        0.0f, 1.0f, 0.0f,//11
        1.0f, 0.0f, 0.5f,//12
        1.0f, 0.0f, 0.0f,//13
        0.5f, 0.7f, 0.3f,//14
        1.0f, 0.0f, 0.0f,//15
        0.0f, 0.0f, 1.0f,//16
        0.0f, 1.0f, 0.0f,//17
        0.1f, 0.5f, 0.8f,//18
        0.2f, 0.0f, 0.0f,//19
        0.2f, 1.0f, 0.4f,//20
        0.0f, 0.0f, 1.0f,//21
        1.0f, 0.0f, 0.0f,//22
        0.1f, 0.5f, 0.8f,//23
        1.0f, 0.0f, 0.0f,//24
        1.0f, 0.0f, 0.4f,//25
        0.0f, 0.0f, 1.0f,//26
        0.0f, 0.0f, 1.0f,//27
        0.0f, 1.0f, 0.0f,//28
        0.0f, 1.0f, 0.0f,//29
        0.0f, 0.7f, 0.0f,//30
        1.0f, 0.0f, 0.0f,//31
        0.0f, 1.0f, 0.0f,//32
        0.0f, 0.0f, 1.0f,//33
        0.0f, 0.7f, 0.0f,//34
        0.0f, 1.0f, 0.0f,//35
        0.0f, 1.0f, 0.0f,//36
        0.0f, 1.0f, 0.0f,//37
        0.0f, 0.0f, 1.0f,//38
        1.0f, 0.0f, 0.0f,//39
        1.0f, 0.0f, 0.0f,//40
        1.0f, 0.0f, 0.5f,//41
        1.0f, 0.0f, 0.0f,//42
        0.0f, 1.0f, 0.0f,//43
        0.2f, 1.0f, 0.4f,//44
        1.0f, 0.0f, 0.4f,//45
        0.1f, 0.5f, 0.8f,//46
        1.0f, 0.0f, 0.4f,//47
        0.0f, 0.0f, 1.0f,//48
        0.1f, 0.5f, 0.8f,//49
        0.5f, 0.7f, 0.3f,//50
        0.1f, 0.5f, 0.8f,//51
        1.0f, 0.0f, 0.5f,//52
        0.0f, 0.0f, 1.0f,//53
        0.0f, 1.0f, 0.0f,//54
        0.0f, 0.0f, 1.0f,//55
        0.0f, 1.0f, 0.0f,//56
        0.0f, 0.0f, 1.0f,//57
        1.0f, 0.0f, 0.4f,//58
        0.0f, 1.0f, 0.0f,//59
        0.0f, 0.0f, 1.0f,//60
        1.0f, 1.0f, 0.0f,//61
        0.0f, 1.0f, 0.0f,//62
        0.0f, 1.0f, 0.5f,//63
        1.0f, 0.0f, 0.0f,//64
        1.0f, 1.0f, 0.0f,//65
        0.5f, 0.7f, 0.3f,//66
        0.0f, 1.0f, 0.0f,//67
        0.1f, 0.5f, 0.8f,//68
        0.0f, 0.0f, 1.0f,//69
        0.0f, 1.0f, 0.0f,//70
        0.0f, 0.0f, 1.0f,//71
        0.5f, 0.7f, 0.3f,//72
        0.0f, 0.0f, 1.0f,//73
        1.0f, 0.0f, 0.5f,//74
        0.1f, 0.5f, 0.8f,//75
        0.1f, 0.5f, 0.8f,//76
        0.1f, 0.5f, 0.8f,//77
        0.5f, 0.7f, 0.3f,//78
        1.0f, 0.0f, 0.4f,//79
        1.0f, 0.0f, 0.0f,//80
        1.0f, 0.0f, 0.4f,//81
        0.1f, 0.5f, 0.8f,//82
        0.0f, 1.0f, 0.0f,//83
        0.1f, 0.5f, 0.8f,//84
        1.0f, 0.0f, 0.5f,//85
        1.0f, 0.0f, 0.4f,//86
        1.0f, 0.0f, 0.0f,//87
        1.0f, 0.0f, 0.4f,//88
        0.0f, 1.0f, 0.0f,//89
        0.1f, 0.5f, 0.8f,//90
        0.0f, 1.0f, 0.0f,//91
        0.0f, 1.0f, 0.0f,//92
        0.0f, 0.0f, 1.0f,//93
        0.5f, 0.7f, 0.3f,//94
        0.0f, 0.0f, 1.0f,//95
        0.0f, 1.0f, 0.0f,//96
        1.0f, 0.0f, 0.0f,//97
        0.1f, 0.5f, 0.8f,//98
        0.0f, 0.0f, 1.0f,//99
        1.0f, 0.0f, 0.4f,//100
        0.1f, 0.5f, 0.8f,//101
        1.0f, 0.0f, 0.4f,//102
        0.0f, 1.0f, 0.0f,//103
        0.1f, 0.5f, 0.8f,//104
        0.5f, 0.7f, 0.3f,//105
        0.1f, 0.5f, 0.8f,//106
        1.0f, 0.0f, 0.5f,//107
        1.0f, 0.0f, 0.0f,//108
        0.0f, 1.0f, 0.0f,//109
        0.5f, 0.7f, 0.3f,//110
        0.5f, 0.7f, 0.3f,//111
        0.1f, 0.5f, 0.8f,//112
        1.0f, 0.0f, 0.4f,//113
        1.0f, 0.0f, 0.5f,//114
        0.0f, 0.0f, 1.0f,//115
        0.5f, 0.7f, 0.3f,//116
        0.1f, 0.5f, 0.8f,//117
        0.0f, 1.0f, 0.0f,//118
        1.0f, 0.0f, 0.0f,//119
        0.1f, 0.5f, 0.8f,//120
        0.0f, 0.0f, 1.0f,//121
        0.5f, 0.7f, 0.3f,//122
        0.1f, 0.5f, 0.8f,//123
        1.0f, 0.0f, 0.0f,//124
        1.0f, 0.0f, 0.0f,//125
        1.0f, 0.0f, 1.0f,//126
        0.5f, 0.7f, 0.3f,//127
        0.1f, 0.5f, 0.8f,//128
        1.0f, 0.0f, 0.5f,//129
        1.0f, 0.0f, 0.0f,//130
        0.0f, 1.0f, 0.0f,//131
        0.0f, 0.0f, 1.0f,//132
        0.5f, 0.7f, 0.3f,//133
        0.1f, 0.5f, 0.8f,//134
        1.0f, 0.0f, 0.4f,//135
        0.0f, 1.0f, 0.0f,//136
        0.0f, 0.0f, 1.0f,//137
        0.5f, 0.7f, 0.3f,//138
        0.1f, 0.5f, 0.8f,//139
        1.0f, 0.0f, 0.5f,//139
        1.0f, 0.0f, 0.0f,//140
        0.0f, 1.0f, 0.0f,//141
        0.0f, 0.0f, 1.0f,//142
        0.5f, 0.7f, 0.3f,//143
        0.1f, 0.5f, 0.8f,//144
        1.0f, 0.0f, 0.4f,//145
        0.0f, 1.0f, 0.0f,//146
        0.0f, 0.0f, 1.0f,//147
        0.5f, 0.7f, 0.3f,//148
        0.1f, 0.5f, 0.8f,//149
        1.0f, 0.0f, 0.5f,//150
        1.0f, 0.0f, 0.0f,//151
        0.0f, 1.0f, 0.0f,//152
        0.0f, 0.0f, 1.0f,//153
        0.5f, 0.7f, 0.3f,//154
        0.1f, 0.5f, 0.8f,//155
        0.7f, 0.7f, 0.2f,//156
        0.0f, 0.9f, 0.0f,//157
        0.7f, 0.7f, 0.2f,//158
        0.0f, 0.9f, 0.0f//159


    };


    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);

    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

   glDrawArrays(GL_TRIANGLE_STRIP, 0, n);

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    m_program->release();

     ++m_frame;
}

