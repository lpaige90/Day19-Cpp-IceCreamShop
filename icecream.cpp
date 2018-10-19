#include "icecream.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static void error_callback(int error, const char* description) {
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

//////////////////////////////////////////////////////////////
// Base Class ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void IceCream::setColor(int flav) {
	if (flav == 1) {
		glColor3f(1.0f, 1.0f, 0.8f);
	} else if (flav == 2) {
		glColor3f(0.8f, 0.6f, 0.4f);
	} else if (flav == 3) {
		glColor3f(1.0f, 1.0f, 0.6f);
	} else if (flav == 4) {
		glColor3f(0.95f, 0.9f, 0.85f);
	} else if (flav == 5) {
		glColor3f(1.0f, 0.65f, 0.3f);
	} else {
		glColor3f(1.0f, 0.7f, 0.7f);
	}
}

void IceCream::cone() {
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.88f, 0.7f);
    glVertex2f(0.1732f,-0.1f);
    glVertex2f(-0.1732f,-0.1f);
    glVertex2f(0.0f,-0.6f);
    glEnd();
}

//////////////////////////////////////////////////////////////
// One Scoop /////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

OneScoop::OneScoop() {
	flavor1 = 1;//Default vanilla
}

OneScoop::OneScoop(int flav) {
	flavor1 = flav;
}

void OneScoop::scoopIceCream() {
	glBegin(GL_POLYGON);
    setColor(flavor1);
    for (int i=-30; i<=210; ++i) {
        float degToRad = i*(3.14159/180.0);
        glVertex2f(cos(degToRad)*0.2f,sin(degToRad)*0.2f);
    }
    glEnd();

    cone();
}

void OneScoop::order() {
    GLFWwindow* window;

    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(800, 600, "Ice Cream Shop", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;

        ratio = (float)width / (float)height;

        glfwGetFramebufferSize(window, &width, &height);

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);//Buffer enabled for color writing

        glMatrixMode(GL_PROJECTION);//Projection matrix stack
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.0f, 1.0f, -1.0f, 1.0f);//Projection

        glMatrixMode(GL_MODELVIEW);//Modelview matrix stack
        glLoadIdentity();

        this->scoopIceCream();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}

//////////////////////////////////////////////////////////////
// Two Scoops ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

TwoScoops::TwoScoops() {
	flavor1 = 1;//Default vanilla
	flavor2 = 2;//Default chocolate
}

TwoScoops::TwoScoops(int flav1, int flav2) {
	flavor1 = flav1;
	flavor2 = flav2;
}

void TwoScoops::scoopIceCream() {
	glBegin(GL_POLYGON);
    setColor(flavor1);
    for (int i=-30; i<=210; ++i) {
        float degToRad = i*(3.14159/180.0);
        glVertex2f(cos(degToRad)*0.2f,sin(degToRad)*0.2f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    setColor(flavor2);
    for (int i=-30; i<=210; ++i) {
        float degToRad = i*(3.14159/180.0);
        glVertex2f(cos(degToRad)*0.2f,0.2+sin(degToRad)*0.2f);
    }
    glEnd();

    cone();
}

void TwoScoops::order() {
    GLFWwindow* window;

    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(800, 600, "Ice Cream Shop", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;

        ratio = (float)width / (float)height;

        glfwGetFramebufferSize(window, &width, &height);

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);//Buffer enabled for color writing

        glMatrixMode(GL_PROJECTION);//Projection matrix stack
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.0f, 1.0f, -1.0f, 1.0f);//Projection

        glMatrixMode(GL_MODELVIEW);//Modelview matrix stack
        glLoadIdentity();

        this->scoopIceCream();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}

//////////////////////////////////////////////////////////////
// Three Scoops //////////////////////////////////////////////
//////////////////////////////////////////////////////////////

ThreeScoops::ThreeScoops() {
	flavor1 = 1;//Default vanilla
	flavor2 = 2;//Default chocolate
	flavor3 = 6;//Default cherry
}

ThreeScoops::ThreeScoops(int flav1, int flav2, int flav3) {
	flavor1 = flav1;
	flavor2 = flav2;
	flavor3 = flav3;
}

void ThreeScoops::scoopIceCream() {
	glBegin(GL_POLYGON);
    setColor(flavor1);
    for (int i=-30; i<=210; ++i) {
        float degToRad = i*(3.14159/180.0);
        glVertex2f(cos(degToRad)*0.2f,sin(degToRad)*0.2f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    setColor(flavor2);
    for (int i=-30; i<=210; ++i) {
        float degToRad = i*(3.14159/180.0);
        glVertex2f(cos(degToRad)*0.2f,0.2+sin(degToRad)*0.2f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    setColor(flavor3);
    for (int i=-30; i<=210; ++i) {
        float degToRad = i*(3.14159/180.0);
        glVertex2f(cos(degToRad)*0.2f,0.4+sin(degToRad)*0.2f);
    }
    glEnd();

    cone();
}

void ThreeScoops::order() {
    GLFWwindow* window;

    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(800, 600, "Ice Cream Shop", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;

        ratio = (float)width / (float)height;

        glfwGetFramebufferSize(window, &width, &height);

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);//Buffer enabled for color writing

        glMatrixMode(GL_PROJECTION);//Projection matrix stack
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.0f, 1.0f, -1.0f, 1.0f);//Projection

        glMatrixMode(GL_MODELVIEW);//Modelview matrix stack
        glLoadIdentity();

       	this->scoopIceCream();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}