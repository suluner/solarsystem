#ifndef stars_hpp
#define stars_hpp

#include <GL/glut.h>

class Star{
public:
	GLfloat radius;
	GLfloat speed, selfSpeed;
	GLfloat distance;
	GLfloat rgbaColor[4];
	
	Star* parentStar;
	
	Star(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star* parent);
	void drawStar();
	virtual void draw(){drawStar();}
	virtual void update(long timeSpan);
protected:
	GLfloat alphaSelf, alpha;
};

class Planet:public Star{
public:
	Planet(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star* parent, GLfloat rgbaColor[3]);
	void drawPlanet();
	virtual void draw(){drawPlanet();drawStar();}
};

class LightPlanet:public Planet{
public:
	LightPlanet(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star* parent, GLfloat rgbaColor[]);
	void drawLight();
	virtual void draw(){drawLight();drawPlanet();drawStar();}
};


#endif
