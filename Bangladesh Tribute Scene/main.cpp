#include <algorithm>
#include <GL/glut.h>
#include <cmath>
using namespace std;

void DDAline (float x1, float y1, float x2, float y2)
{
    glBegin(GL_POINTS);

    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps;

    if (fabs(dx) > fabs(dy))
    {
        steps = fabs(dx);
    }
    else
    {
        steps = fabs(dy);
    }

    float delx = dx / steps;
    float dely = dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 1; i <= steps; i++)
    {
        glVertex2f(x,y);
        x += delx;
        y += dely;
    }
    glEnd();
}

void BresenhamLine (float x1, float y1, float x2, float y2)
{
    glBegin(GL_POINTS);

    float dx = x2 - x1;
    float dy = y2 - y1;

    float m = dy / dx;

    float x = x1;
    float y = y1;

    //CASE if not steep
    if (fabs(m) <= 1)
    {
        float d;
        if (m < 0)
        {
            d = 2*fabs(dy) + fabs(dx);
        }
        else
        {
            d = 2*dy - dx;
        }

        for (int i = 0; i <= fabs(dx); i++ )
        {
            glVertex2f(x,y);
            if (d <= 0)
            {
                x++;
                d += 2*fabs(dy);
            }
            else
            {
                if (m < 0) //CASE if line is negative slope
                {
                    y--;
                }
                else //CASE if line is positive slope
                {
                    y++;
                }
                 d += 2*(fabs(dy) - fabs(dx));
                x++;
            }
        }
    }
    //CASE if steep
    else
    {
        float d;
        if (m < 0)
        {
            d = 2*dx + dy;
        }
        else
        {
            d = 2*dx - dy;
        }

        for (int i = 0; i <= fabs(dy); i++ )
        {
            glVertex2f(x,y);
            if (d <= 0)
            {
                if (m < 0) //CASE if line is negative slope
                {
                    y--;
                }
                else //CASE if line is positive slope
                {
                    y++;
                }
                d += 2*dx;
            }
            else
            {
                if (m < 0) //CASE if line is negative slope
                {
                    y--;
                    d += 2*(dx + dy);
                }
                else //CASE if line is positive slope
                {
                    y++;
                    d += 2*(dx - dy);
                }
                x++;
            }
        }
    }
    glEnd();
}

void BresenhamCircle(int xcenter, int ycenter, int r)
{
    glBegin(GL_POINTS);

    int d = 1 - r;
    int x = 0;
    int y = r;

    while (x <= y)
    {
        glVertex2f(xcenter + x, ycenter + y);
        glVertex2f(xcenter - x, ycenter + y);
        glVertex2f(xcenter + x, ycenter - y);
        glVertex2f(xcenter - x, ycenter - y);

        glVertex2f(xcenter + y, ycenter + x);
        glVertex2f(xcenter - y, ycenter + x);
        glVertex2f(xcenter + y, ycenter - x);
        glVertex2f(xcenter - y, ycenter - x);

        if (d <= 0)
        {
            d += 2*x + 3;
        }
        else
        {
            d += 2*(x - y) + 5;
            y--;
        }

        x++;
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // --------------------- PART A: Bangladesh Flag ------------------------
    //Rectangle flag frame
    glPointSize(15.0f);
    glColor3f(0.0f, 0.404f, 0.278f);
    BresenhamLine(-400,450,-250,450);
    BresenhamLine(-400,375,-250,375);
    BresenhamLine(-400,375,-400,450);
    BresenhamLine(-250,375,-250,450);
        BresenhamLine(-385,375,-385,450);  //filler
        BresenhamLine(-370,375,-370,450);  //filler
        BresenhamLine(-355,375,-355,450);  //filler
        BresenhamLine(-340,375,-340,450);  //filler
        BresenhamLine(-325,375,-325,450);  //filler
        BresenhamLine(-310,375,-310,450);  //filler
        BresenhamLine(-295,375,-295,450);  //filler
        BresenhamLine(-280,375,-280,450);  //filler
        BresenhamLine(-265,375,-265,450);  //filler


    //Flagpole
    glPointSize(7.0f);
    glColor3f(0.42f, 0.408f, 0.404f);
    DDAline(-405,50,-405,450);

    //Red circle
    glPointSize(8.0f);
    glColor3f(0.855f, 0.161f, 0.11f);
    BresenhamCircle(-340,412,20);
        BresenhamCircle(-340,412,12); //filler
        BresenhamCircle(-340,412,4); //filler

    // --------------------- PART C: Extra Elements ------------------------
    //Sun rays
    glPointSize(9.0f);
    glColor3f(1.0f,0.608f,0.271f);
    DDAline(0,200,0,490);

        //right
        DDAline(0,200,145,400);
        DDAline(0,200,350,300);
        DDAline(0,200,300,100);

        //left
        DDAline(0,200,-145,450);
        DDAline(0,200,-300,270);
        DDAline(0,200,-370,100);

    //Cloud
    glPointSize(5.0f);
    glColor3f(0.898f,0.914f,0.98f);
    BresenhamCircle(-300,300,20);
        BresenhamCircle(-300,300,15); //filler
        BresenhamCircle(-300,300,10); //filler
        BresenhamCircle(-300,300,5); //filler
        BresenhamCircle(-300,300,1); //filler

    BresenhamCircle(-255,295,20);
        BresenhamCircle(-255,295,10); //filler
        BresenhamCircle(-255,295,15); //filler
        BresenhamCircle(-255,295,5); //filler
        BresenhamCircle(-255,295,1); //filler

    BresenhamCircle(-210,300,20);
        BresenhamCircle(-210,300,10); //filler
        BresenhamCircle(-210,300,15); //filler
        BresenhamCircle(-210,300,5); //filler
        BresenhamCircle(-210,300,1); //filler

    BresenhamCircle(-280,325,20);
        BresenhamCircle(-280,325,10); //filler
        BresenhamCircle(-280,325,15); //filler
        BresenhamCircle(-280,325,5); //filler
        BresenhamCircle(-280,325,1); //filler

    BresenhamCircle(-235,325,20);
        BresenhamCircle(-235,325,10); //filler
        BresenhamCircle(-235,325,15); //filler
        BresenhamCircle(-235,325,5); //filler
        BresenhamCircle(-235,325,1); //filler



    BresenhamCircle(280,400,20);
        BresenhamCircle(280,400,10); //filler
        BresenhamCircle(280,400,15); //filler
        BresenhamCircle(280,400,5); //filler
        BresenhamCircle(280,400,1); //filler

    BresenhamCircle(325,395,20);
        BresenhamCircle(325,395,10); //filler
        BresenhamCircle(325,395,15); //filler
        BresenhamCircle(325,395,5); //filler
        BresenhamCircle(325,395,1); //filler

    BresenhamCircle(370,400,20);
        BresenhamCircle(370,400,10); //filler
        BresenhamCircle(370,400,15); //filler
        BresenhamCircle(370,400,5); //filler
        BresenhamCircle(370,400,1); //filler

    BresenhamCircle(300,425,20);
        BresenhamCircle(300,425,10); //filler
        BresenhamCircle(300,425,15); //filler
        BresenhamCircle(300,425,5); //filler
        BresenhamCircle(300,425,1); //filler

    BresenhamCircle(345,425,20);
        BresenhamCircle(345,425,10); //filler
        BresenhamCircle(345,425,15); //filler
        BresenhamCircle(345,425,5); //filler
        BresenhamCircle(345,425,1); //filler



    // --------------------- PART B: Shaheed Minar ------------------------

    //Sun
    glPointSize(15.0f);
    glColor3f(0.835f,0.271f,0.106f);
    BresenhamCircle(0,200,85);
    //added extra circles to fill in the sun
        BresenhamCircle(0,200,70); //filler
        BresenhamCircle(0,200,55); //filler
        BresenhamCircle(0,200,40); //filler
        BresenhamCircle(0,200,25); //filler
        BresenhamCircle(0,200,10); //filler

    //Third (Centre) Pillar
    glPointSize(20.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    BresenhamLine(0,62,0,350);
    BresenhamLine(60,62,60,275);
    BresenhamLine(-60,62,-60,275);
    BresenhamLine(-95,350,95,350);
    BresenhamLine(60,275,95,350);
    BresenhamLine(-95,350,-60,275);

    //Second Pillar
    BresenhamLine(-185,62,-185,240);
    BresenhamLine(-125,62,-125,220);
    BresenhamLine(-185,240,-125,230);

    //First Pillar
    BresenhamLine(-245,62,-245,150);
    BresenhamLine(-305,62,-305,170);
    BresenhamLine(-305,170,-245,150);

    //Fourth Pillar
    BresenhamLine(185,62,185,240);
    BresenhamLine(125,62,125,220);
    BresenhamLine(125,220,185,240);

    //Fifth Pillar
    BresenhamLine(245,62,245,150);
    BresenhamLine(305,62,305,170);
    BresenhamLine(245,150,305,170);

    //Base Platform
    glPointSize(10.0f);
    glColor3f(0.322f, 0.11f, 0.051f);
    DDAline(-450,50,450,50);
    DDAline(-450,25,450,25);
    DDAline(-450,25,-450,50);
    DDAline(450,25,450,50);

    glPointSize(25.0f);        //filler
    DDAline(-440,37,440,37);

    glFlush();
}

void init()
{
    glClearColor(0.643f, 0.824f, 0.969f, 0.1f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, 0, 500);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,500);
    glutInitWindowPosition(480,270);
    glutCreateWindow("Bangladesh Tribute Scene by - Andrea Deeanne Nicolas (24-56465-1)");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
