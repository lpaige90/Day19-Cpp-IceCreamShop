#ifndef ICECREAM_H
#define ICECREAM_H
#include <GLFW/glfw3.h>

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

class IceCream {
	protected:
		void setColor(int flav);
		void cone();
		virtual void scoopIceCream() = 0;

	public:
		virtual void order() = 0;
};

class OneScoop : public IceCream {
	int flavor1;

	virtual void scoopIceCream();

	public:
		OneScoop();
		OneScoop(int flav);
		virtual void order();
};

class TwoScoops : public IceCream {
	int flavor1;
	int flavor2;

	virtual void scoopIceCream();

	public:
		TwoScoops();
		TwoScoops(int flav1, int flav2);
		virtual void order();
};

class ThreeScoops : public IceCream {
	int flavor1;
	int flavor2;
	int flavor3;

	virtual void scoopIceCream();

	public:
		ThreeScoops();
		ThreeScoops(int flav1, int flav2, int flav3);
		virtual void order();
};

#endif