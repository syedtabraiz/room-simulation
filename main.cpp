#define GL_SILENCE_DEPRECATION
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

GLboolean redFlag = true, fanSwitch = false;
double windowHeight=800, windowWidth=600;
double eyeX=7.0, eyeY=2.0, eyeZ=15.0, refX = 0, refY=0,refZ=0;
double theta = 180.0, y = 1.36, z = 7.97888, a=2;
int flag=0;

static GLfloat v_cube[8][3] =
{
    {0.0, 0.0, 0.0}, //0
    {0.0, 0.0, 3.0}, //1
    {3.0, 0.0, 3.0},  //2
    {3.0, 0.0, 0.0}, //3
    {0.0, 3.0, 0.0},  //4
    {0.0, 3.0, 3.0}, //5
    {3.0, 3.0, 3.0}, //6
    {3.0, 3.0, 0.0}  //7
};

static GLubyte quadIndices[6][4] =
{
    {0, 1, 2, 3}, //bottom
    {4, 5, 6, 7}, //top
    {5, 1, 2, 6}, //front
    {0, 4, 7, 3}, // back is clockwise
    {2, 3, 7, 6}, //right
    {1, 5, 4, 0}  //left is clockwise
};


static GLfloat colors[6][3] =
{
    {0.4, 0.1, 0.0}, //bottom
    {0.6, 0.0, 0.7}, //top
    {0.0, 1.0, 0.0},
    {0.0, 1.0, 1.0},
    {0.8, 0.0, 0.0},
    {0.3, 0.6, 0.7}
};



void drawCube()
{
    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);
    }
    glEnd();
}

static GLfloat v_pyramid[5][3] =
{
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 2.0},
    {2.0, 0.0, 2.0},
    {2.0, 0.0, 0.0},
    {1.0, 4.0, 1.0}
};

static GLubyte p_Indices[4][3] =
{
    {4, 1, 2},
    {4, 2, 3},
    {4, 3, 0},
    {4, 0, 1}
};

static GLubyte PquadIndices[1][4] =
{
    {0, 3, 2, 1}
};

void drawpyramid()
{
    glBegin(GL_TRIANGLES);
    for (GLint i = 0; i <4; i++)
    {
        glVertex3fv(&v_pyramid[p_Indices[i][0]][0]);
        glVertex3fv(&v_pyramid[p_Indices[i][1]][0]);
        glVertex3fv(&v_pyramid[p_Indices[i][2]][0]);
    }
    glEnd();

    glBegin(GL_QUADS);
    for (GLint i = 0; i <1; i++)
    {
        glVertex3fv(&v_pyramid[PquadIndices[i][0]][0]);
        glVertex3fv(&v_pyramid[PquadIndices[i][1]][0]);
        glVertex3fv(&v_pyramid[PquadIndices[i][2]][0]);
        glVertex3fv(&v_pyramid[PquadIndices[i][3]][0]);
    }
    glEnd();

}

void polygon()
{
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(6,0);
    glVertex2f(5.8,1);
    glVertex2f(5.2,2);
    glVertex2f(5, 2.2);
    glVertex2f(4, 2.8);
    glVertex2f(3,3);
    glVertex2f(2, 2.8);
    glVertex2f(1, 2.2);
    glVertex2f(0.8, 2);
    glVertex2f(0.2,1);
    //glVertex2f(0,0);

    glEnd();
}

void polygonLine()
{
    glBegin(GL_LINE_STRIP);
    glVertex2f(0,0);
    glVertex2f(6,0);
    glVertex2f(5.8,1);
    glVertex2f(5.2,2);
   glVertex2f(5, 2.2);
    glVertex2f(4, 2.8);
    glVertex2f(3,3);
    glVertex2f(2, 2.8);
    glVertex2f(1, 2.2);
    glVertex2f(0.8, 2);
    glVertex2f(0.2,1);
    glVertex2f(0,0);

    glEnd();
}

void cupboard()
{
        //cupboard
        glColor3f(0.6,0.1,0.0);
        glPushMatrix();
        glTranslatef(4,0,4.4);
        glScalef(0.5, 1, 0.5);
        drawCube();
        glPopMatrix();

        //cupboard's 1st vertical stripline
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(4,1,5.9);
        glScalef(0.5, 0.01, 0.0001);
        drawCube();
        glPopMatrix();

        //cupboard's 2nd vertical stripline
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(4,0.5,5.9);
        glScalef(0.5, 0.01, 0.0001);
        drawCube();
        glPopMatrix();

        //cupboard's last stripline
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(4,0,5.9);
        glScalef(0.5, 0.01, 0.0001);
        drawCube();
        glPopMatrix();

        //cupboard's lst horizontal stripline
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(5.5,0,5.9);
        glScalef(0.01, 1, 0.0001);
        drawCube();
        glPopMatrix();

        //cupboard's right side horizontal stripline
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(4.75,1,5.9);
        glScalef(0.01, 0.67, 0.0001);
        drawCube();
        glPopMatrix();

        //cupboard's left side horizontal stripline
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(4,0,5.9);
        glScalef(0.01, 1, 0.0001);
        drawCube();
        glPopMatrix();

        //cupboard's handle right
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(5,1.4,5.9);
        glScalef(0.02, 0.18, 0.0001);
        drawCube();
        glPopMatrix();

        //cupboard's handle left
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(4.5,1.4,5.9);
        glScalef(0.02, 0.18, 0.01);
        drawCube();
        glPopMatrix();

        //cupboard's drawer's 1st handle
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(4.5,0.7,5.9);
        glScalef(0.16, 0.02, 0.01);
        drawCube();
        glPopMatrix();

        //cupboard's drawer's 2nd handle
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(4.5,0.25,5.9);
        glScalef(0.16, 0.02, 0.01);
        drawCube();
        glPopMatrix();
}

void bedsideTable()
{
      //side drawer
      glColor3f(0.2,0.1,0.1);
      glPushMatrix();
      glTranslatef(0.5,-0.1,8.7);
      glScalef(0.12, 0.2, 0.23);
      drawCube();
      glPopMatrix();

      //side drawer's drawer
      glColor3f(0.3,0.2,0.2);
      glPushMatrix();
      glTranslatef(0.88,0,8.8);
      //glRotatef(22, 0,0,1);
      glScalef(0.0001, 0.11, 0.18);
      drawCube();
      glPopMatrix();

      //side drawer's knob
      glColor3f(0.3, 0.1, 0.0);
      glPushMatrix();
      glTranslatef(0.9,0.1,9);
      //glRotatef(22, 0,0,1);
      glScalef(0.0001, 0.04, 0.04);
      drawCube();
      glPopMatrix();
}

void bed()
{
    //bed headboard
    glColor3f(0.5,0.2,0.2);
    glPushMatrix();
    glScalef(0.1, 0.5, 0.9);
    glTranslatef(-2,-0.5,6);
    drawCube();
    glPopMatrix();

    //bed body
    glColor3f(0.824, 0.706, 0.549);
    glPushMatrix();
    glScalef(1, 0.2, 0.9);
    glTranslatef(0,-0.5,6.2);
    drawCube();
    glPopMatrix();

    //pillow right far
    glColor3f(0.627, 0.322, 0.176);
    glPushMatrix();
    glTranslatef(0.5,0.5,6);
    glRotatef(20, 0,0,1);
    glScalef(0.1, 0.15, 0.28);
    drawCube();
    glPopMatrix();

    //pillow left near
    glColor3f(0.627, 0.322, 0.176);
    glPushMatrix();
    glTranslatef(0.5,0.5,7.2);
    glRotatef(22, 0,0,1);
    glScalef(0.1, 0.15, 0.28);
    drawCube();
    glPopMatrix();

    //blanket
    glColor3f(0.627, 0.322, 0.176);
    glPushMatrix();
    glTranslatef(1.4,0.45,5.5);
    glScalef(0.5, 0.05, 0.95);
    drawCube();
    glPopMatrix();

    //blanket side left part
    glColor3f(0.627, 0.322, 0.176);
    glPushMatrix();
    glTranslatef(1.4,-0.3,8.15);
    glScalef(0.5, 0.25, 0.05);
    drawCube();
    glPopMatrix();

}

void lamp()
{
        //lamp base
        glColor3f(0,0,1);
        glPushMatrix();
        glTranslatef(.6,0.5,9.1);
        glScalef(0.07, 0.02, 0.07);
        drawCube();
        glPopMatrix();

        //lamp stand
        glColor3f(1,0,0);
        glPushMatrix();
        glTranslatef(.7,0.35,9.2);
        glScalef(0.01, 0.2, 0.01);
        drawCube();
        glPopMatrix();

        //lamp shade
        glColor3f(0, 0, 0.48);
        glPushMatrix();
        glTranslatef(.7,0.9,9.2);
        glScalef(0.08, 0.09, 0.08);
        drawCube();
        glPopMatrix();

}

void base()
{
    // right wall
    glColor3f(1, 0.8, 0.5);
    glPushMatrix();
    glTranslatef(-1.5,-1,.5);
    glScalef(5, 2, 0.1);
    drawCube();
    glPopMatrix();

    // left wall
    glColor3f(1, 0.8, 0.7);
    glPushMatrix();
    glTranslatef(-4.5,-1,0);
    glScalef(1, 2, 5);
    drawCube();
    glPopMatrix();

   //ceiling
    glColor3f(1.0, 0.9, 0.8);
    glPushMatrix();
    glTranslatef(-2,5.1,0);
    glScalef(5, 0.1, 7);
    drawCube();
    glPopMatrix();
}

void floor()
{
      glColor3f(0.5, 0.1, 0.0);
      glPushMatrix();
      glScalef(5, 0.1, 7);
      glTranslatef(-1,-5,0);
      drawCube();
      glPopMatrix();
}

void wardrobe()
{
        //wardrobe
       glColor3f(0.3,0.1,0);
       glPushMatrix();
       glTranslatef(0,0,4);
       glScalef(0.12, 0.6, 0.4);
       drawCube();
       glPopMatrix();

       //wardrobe's 1st drawer
      glColor3f(0.5,0.2,0.2);
       glPushMatrix();
       glTranslatef(0.36,1.4,4.05);
        glScalef(0.0001, 0.11, 0.38);
       drawCube();
       glPopMatrix();

       //wardrobe's 2nd drawer
       glColor3f(0.5,0.2,0.2);
       glPushMatrix();
       glTranslatef(0.36,1,4.05);
       glScalef(0.0001, 0.11, 0.38);
       drawCube();
       glPopMatrix();

       //wardrobe's 3rd drawer
       glColor3f(0.5,0.2,0.2);
       glPushMatrix();
       glTranslatef(0.36,0.6,4.05);
       glScalef(0.0001, 0.11, 0.38);
       drawCube();
       glPopMatrix();

       //wardrobe's 4th drawer
       glColor3f(0.5,0.2,0.2);
       glPushMatrix();
       glTranslatef(0.36,0.2,4.05);
       glScalef(0.0001, 0.11, 0.38);
       drawCube();
       glPopMatrix();

       //wardrobe's 1st drawer handle
       glColor3f(0.3,0.1,0);
       glPushMatrix();
       glTranslatef(0.37,1.5,4.3);
       glScalef(0.0001, 0.03, 0.2);
       drawCube();
       glPopMatrix();

       //wardrobe's 2nd drawer handle
       glColor3f(0.3,0.1,0);
       glPushMatrix();
       glTranslatef(0.37,1.1,4.3);
       glScalef(0.0001, 0.03, 0.2);
       drawCube();
       glPopMatrix();

       //wardrobe's 3rd drawer handle
       glColor3f(0.3,0.1,0);
       glPushMatrix();
       glTranslatef(0.37,0.7,4.3);
       glScalef(0.0001, 0.03, 0.2);
       drawCube();
       glPopMatrix();

       //wardrobe's 4th drawer handle
       glColor3f(0.3,0.1,0);
       glPushMatrix();
       glTranslatef(0.37,0.3,4.3);
       glScalef(0.0001, 0.03, 0.2);
       drawCube();
       glPopMatrix();

       //wardrobe left stripline
       glColor3f(0.5,0.2,0.2);
       glPushMatrix();
       glTranslatef(0.35,0,5.3);
       glScalef(0.01, 0.6, 0.0001);
       drawCube();
       glPopMatrix();
}

void fan()
{
    glPushMatrix();
    glTranslatef(3,4,8);

    //stand
    glColor3f(0.2,0.1,0.1);
    glPushMatrix();
    glTranslatef(0.1,0,0.09);
    glScalef(0.01,0.4,0.01);
    drawCube();
    glPopMatrix();

    //fan cube
    glColor3f(0.5,0.2,0.2);
    glPushMatrix();
    glScalef(0.1,0.05,0.1);
    glTranslatef(-1.5,-1.5,-1.5);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glRotatef(a, 0,1,0);

    //blade 1 blue
    glColor3f(0.8,0.6,0.4);
    glPushMatrix();
    glScalef(0.5,0.01,0.1);
    glTranslatef(-1.5,-1.5,-1.5);
    drawCube();
    glPopMatrix();

    //blade 2 purple
    glColor3f(0.8,0.6,0.4);
    glPushMatrix();
    glScalef(0.1,0.01,0.5);
    glTranslatef(-1.5,-1.5,-1.5);
    drawCube();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void dressingtable()
{
        //dressing table left body
        glColor3f(0.545, 0.271, 0.075);
        glPushMatrix();
        glTranslatef(5.9,0,4.6);
        glScalef(0.2, 0.2, 0.2);
        drawCube();
        glPopMatrix();

        //dressing table left body left stripe
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(5.9,0,5.2);
        glScalef(0.01, 0.3, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table left body right stripe
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(6.5,0,5.2);
        glScalef(0.01, 0.2, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table left body bottom stripe
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(5.9,0,5.2);
        glScalef(0.2, 0.01, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table right body
        glColor3f(0.545, 0.271, 0.075);
        glPushMatrix();
        glTranslatef(7,0,4.6);
        glScalef(0.2, 0.2, 0.2);
        drawCube();
        glPopMatrix();

        //dressing table right body left stripe
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(7,0,5.2);
        glScalef(0.01, 0.2, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table right body right stripe
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(7.6,0,5.2);
        glScalef(0.01, 0.3, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table right body bottom stripe
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(7,0,5.2);
        glScalef(0.2, 0.01, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table upper body
        glColor3f(0.545, 0.271, 0.075);
        glPushMatrix();
        glTranslatef(5.9,0.6,4.6);
        glScalef(0.57, 0.1, 0.2);
        drawCube();
        glPopMatrix();

        //dressing table upper body bottom stripe
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(5.9,0.6,5.2);
        glScalef(0.57, 0.01, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table upper body upper stripe
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(5.9,0.9,5.2);
        glScalef(0.57, 0.01, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table upper body handle
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(6.5,0.75,5.2);
        glScalef(0.16, 0.02, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table left body handle
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(6.4,0.1,5.2);
        glScalef(0.02, 0.13, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table right body handle
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(7.1,0.1,5.2);
        glScalef(0.02, 0.13, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table main mirror
        glColor3f(0.690, 0.878, 0.902);
        glPushMatrix();
        glTranslatef(6.2,0.9,4.7);
        glScalef(0.36, 0.5, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table left mirror
        glColor3f(0.690, 0.878, 0.902);
        glPushMatrix();
        glTranslatef(5.92,0.9,4.7);
        glScalef(0.1, 0.48, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table left mirror left stripe
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(5.92,0.9,4.71);
        glScalef(0.019, 0.48, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table left mirror left stripe
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(6.17,0.9,4.71);
        glScalef(0.019, 0.48, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table mirror  stripe
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(5.92,0.9,4.71);
        glScalef(0.55, 0.019, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table left mirror upper stripe
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(5.92,2.3,4.71);
        glScalef(0.1, 0.019, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table right mirror
        glColor3f(0.690, 0.878, 0.902);
        glPushMatrix();
        glTranslatef(7.25,0.9,4.7);
        glScalef(0.1, 0.48, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table left mirror upper stripe
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(7.25,2.3,4.71);
        glScalef(0.1, 0.019, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table right mirror left stripe
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(7.25,0.9,4.71);
        glScalef(0.019, 0.48, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table right mirror right stripe
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(7.5,0.9,4.71);
        glScalef(0.019, 0.48, 0.0001);
        drawCube();
        glPopMatrix();

        //dressing table main mirror polygon part
        glColor3f(0.690, 0.878, 0.902);
        glPushMatrix();
        glTranslatef(6.2,2.4,4.7);
        glScalef(0.18, 0.18, 2);
        polygon();
        glPopMatrix();

        //dressing table upper round srtipe
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(6.2,2.4,4.71);
        glScalef(.18, .18, 1);
        polygonLine();
        glPopMatrix();
}

void Clock()
{
        //clock body
        glColor3f(0.545, 0.271, 0.075);
        glPushMatrix();
        glTranslatef(-0.9,1.8,7.87);
        glScalef(0.08, 0.25, 0.1);
        drawCube();
        glPopMatrix();

        //clock body white
        glColor3f(1.000, 0.894, 0.710);
        glPushMatrix();
        glTranslatef(-0.83,1.9,7.9);
        glScalef(0.06, 0.2, 0.08);
        drawCube();
        glPopMatrix();

        //clock hour handle
        glColor3f(0,0,0); //0.2,0.1,0.1
        glPushMatrix();
        glTranslatef(-0.65,2.18,8.01);
        glRotatef(45, 1,0,0);
        glScalef(0.0001, 0.01, 0.04);
        drawCube();
        glPopMatrix();

       //clock minute handle
        glColor3f(0,0,0); //0.2,0.1,0.1
        glPushMatrix();
        glTranslatef(-0.65,2.18,8.01);
        glRotatef(90, 1,0,0);
        glScalef(0.0001, 0.012, 0.08);
        drawCube();
        glPopMatrix();

        //clock body bottom strip
        glColor3f(0.2,0.1,0.1); //0.2,0.1,0.1
        glPushMatrix();
        glTranslatef(-0.66,1.8,7.89);
        glScalef(0.001, 0.01, 0.1);
        drawCube();
        glPopMatrix();

        //clock body right strip
        glColor3f(0.0,0.0,0.0); //0.2,0.1,0.1
        glPushMatrix();
        glTranslatef(-0.66,1.8,7.89);
        glScalef(0.005, 0.25, 0.01);
        drawCube();
        glPopMatrix();

        //clock body left strip
        glColor3f(0.2,0.1,0.1); //0.2,0.1,0.1
        glPushMatrix();
        glTranslatef(-0.65,1.8,8.2);
        glScalef(0.0001, 0.25, 0.01);
        drawCube();
        glPopMatrix();

        //clock top pyramid
        glColor3f(0.5, 0.2, 0);
        glPushMatrix();
        glTranslatef(-0.9,2.5,7.87);
        glScalef(0.2, 0.1, 0.2);
        drawpyramid();
        glPopMatrix();
}
void drawstring(int x, int y,int z, char *s)
{
	char *c;
	glRasterPos3i(x, y,z);
	for (c = s; *c != '\0'; *c++)
    {
        glColor3i(1,1,1);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

}
void drawlargestring(int x, int y,int z, char *s)
{
	char *c;
	glRasterPos3i(x, y,z);
	for (c = s; *c != '\0'; *c++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);

}

void page()
{

	glColor3f(1,1,1);
	glLineWidth(10);
	glBegin(GL_LINE_LOOP);
        glVertex3d(25, 450,0);
        glVertex3d(475, 450,0);
        glVertex3d(475, 300,0);
        glVertex3d(25, 300,0);
	glEnd();



	drawlargestring(125, 420,0, "SIMULATION OF A ROOM ");

	glBegin(GL_LINES);
        glVertex3d(125,415,0);
        glVertex3d(310,415,0);
    glEnd();




	drawstring(30, 380,0, "INSTRUCTIONS: ");
	drawstring(125, 380,0, "1. Press a,w,s,d,i,o to Move Eye Point");
	drawstring(135, 360,0, "2. Press b,j,n,m,l,k to Move Camera Point");
	drawstring(135, 340,0, "3. Press q to move to default position");
	drawstring(135, 320,0, "4. Press f to turn ON/OFF the fan");


    /*glBegin(GL_LINES);
        glVertex3d(220,400,0);
        glVertex3d(220, 335,0);
    glEnd();*/

	drawstring(100, 270,0, "Subject: Computer Graphics and Visualization");
	drawstring(100, 250,0, "Subject Code: 18CS62");
	drawstring(100, 230,0, "Subject Teacher: Prof. Shankar R.");



	glBegin(GL_LINE_LOOP);
	glVertex3d(55, 75,0);
	glVertex3d(405, 75,0);
	glVertex3d(405, 205,0);
	glVertex3d(55, 205,0);
	glEnd();

	/*glBegin(GL_LINES);
        glVertex3d(165, 75,0);
        glVertex3d(165, 205,0);
    glEnd();
    glBegin(GL_LINES);
        glVertex3d(275, 75,0);
        glVertex3d(275, 205,0);6666666666666666666666666666666
    glEnd();*/


    drawstring(60, 175,0, "NAME : Shravani V");
	drawstring(60, 150,0, "USN : 1BY19CS144");
	drawstring(60, 125,0, "SEM : VI");

	drawstring(180, 175,0, "Syed Tabraiz");
	drawstring(180, 150,0, "1BY19CS165");
	drawstring(180, 125,0, "VI");

	drawstring(260, 175,0, "Vishal Hanuman");
	drawstring(260, 150,0, "1BY19CS182");
	drawstring(260, 125,0, "VI");

	glFlush();
}



void display(void)
{
    if (flag==0)
    {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
         page();
        glutPostRedisplay();
        glutSwapBuffers();

    }

    else if(flag==1){


        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glMatrixMode( GL_PROJECTION );
        glLoadIdentity();
        gluPerspective(60,1,1,100);

        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();

        gluLookAt(eyeX,eyeY,eyeZ,  refX,refY,refZ,  0,1,0);

        glViewport(0, 0, 1540, 870);

            base();
            bedsideTable();
            bed();
            cupboard();
            lamp();
            floor();
            wardrobe();
            fan();
            dressingtable();
            Clock();
            glFlush();
            glutSwapBuffers();
        }
        glFlush();

}

void myKeyboardFunc( unsigned char key, int x, int y )
{
    if(key==13)
    {
        flag=1;
    }
    else if(key=='g')
    {
        flag=0;

      // glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
       //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
      //  page();
       //glutSwapBuffers();
    }


    else{
        switch ( key )
    {
    case 'w': //move eye point upwards along Y axis
        eyeY+=1.0;
        break;
    case 's': //move eye point downwards in Y axis
        eyeY-=1.0;
        break;
    case 'a': // move eye point left along X axis
        eyeX-=1.0;
        break;
    case 'd': //move eye point right along X axis
        eyeX+=1.0;
        break;
    case 'o':  //zoom out
        eyeZ+=1;
        break;
    case 'i': //zoom in
        eyeZ-=1;
        break;
    case 'q': //back to default eye point and ref point
            eyeX=7.0; eyeY=2.0; eyeZ=15.0;
            refX=0.0; refY=0.0; refZ=0.0;
        break;
    case 'j': // move ref point upwards along Y axis
        refY+=1.0;
        break;
    case 'n': // move ref point downwards along Y axis
        refY-=1.0;
        break;
    case 'b': // move ref point left along X axis
        refX-=1.0;
        break;
    case 'm': // move eye point right along X axis
        refX+=1.0;
        break;
    case 'k':  //move ref point away from screen/ along z axis
        refZ+=1;
        break;
    case 'l': //move ref point towards screen/ along z axis
        refZ-=1;
        break;
        case 'f': //turn on/off fan
            if(fanSwitch == false) {
                fanSwitch = true; break;
            }
            else{
                fanSwitch = false; break;
            }
    case 27:    // Escape key
        exit(1);
    }
    }

   glutPostRedisplay();
}

void animate()
{
   if(fanSwitch == true){
    a+= 3;
            if(a > 360)
                a -= 360;
    }
    else{
        a = a;
    }

    glutPostRedisplay();

}
void myinit()
{
	glClearColor(1 ,0.6 ,0.2,1.0);

	glPointSize(1.0);
	gluOrtho2D(0.0,499.0,0.0,499.0);
}
int main (int argc, char **argv)
{
    glutInit(&argc, argv);

    std::cout<<"To move Eye point:"<< std::endl;
    std::cout<<"w: up"<<std::endl;
    std::cout<<"s: down"<<std::endl;
    std::cout<<"a: left"<<std::endl;
    std::cout<<"d: right"<<std::endl;
    std::cout<<"i: zoom in"<<std::endl;
    std::cout<<"o: zoom out"<<std::endl;
    std::cout<<"      "<<std::endl;
    std::cout<<"To move Camera point:"<< std::endl;
    std::cout<<"j: up"<<std::endl;
    std::cout<<"n: down"<<std::endl;
    std::cout<<"b: left"<<std::endl;
    std::cout<<"m: right"<<std::endl;
    std::cout<<"l: move nearer"<<std::endl;
    std::cout<<"k: move far"<<std::endl;
    std::cout<<"      "<<std::endl;
    std::cout<<"Press q to move to default position"<<std::endl;
    std::cout<<"      "<<std::endl;
    std::cout<<"f: to turn on/off fan     "<<std::endl;

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("CGV Mini Project");
    glutFullScreen();
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboardFunc);
    myinit();
    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );

    glutIdleFunc(animate);
    glutMainLoop();
    return 0;
}
