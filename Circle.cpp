#include "Circle.h"
#include <cmath>

#include<GL/glut.h>
#include "Rectangle.h"

void Circ::draw()
{
	// Do NOT modify this function
	if (m_bMarked)
		glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
	else
		glColor4f(m_col.r, m_col.g, m_col.b, 0.5f);


	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i < 50; i++)
	{
		float theta = i * (2.0f * (float)3.14159 / 50);
		float x = m_rad * cos(theta);
		float y = m_rad * sin(theta);
		glVertex2f(x + m_pos.x, y + m_pos.y);
	}
	glEnd();

}
void Circ::drawBbox(Shape* pshape)
{	
	Circ * ptest=dynamic_cast<Circ *>(pshape);
	float leftBottomx, leftBottomy, rightUpperx, rightUppery;

	if(this->intersects(pshape))
	{
		if(this->m_pos.x-this->m_rad<ptest->getPos().x-ptest->getRad())
			leftBottomx=this->m_pos.x-this->m_rad;
		else
			leftBottomx=ptest->getPos().x-ptest->m_rad;
		if(this->m_pos.y-this->m_rad<ptest->getPos().y-ptest->getRad())
			leftBottomy=this->m_pos.y-this->m_rad;
		else
			leftBottomy=ptest->getPos().y-ptest->getRad();
		if(this->m_pos.x+this->m_rad>ptest->getPos().x+ptest->getRad())
			rightUpperx=this->m_pos.x+this->m_rad;
		else
			rightUpperx=ptest->getPos().x+ptest->m_rad;	
		if(this->m_pos.y+this->m_rad>ptest->getPos().y+ptest->getRad())
			rightUppery=this->m_pos.y+this->m_rad;
		else
			rightUppery=ptest->getPos().y+ptest->getRad();
		// TODO: calculate leftBottomx, leftBottomy, rightUpperx, rightUppery points for surrounding bounding box

	}	

	//Do NOT change this part
	glColor3f(0.0,0.0,1.0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(leftBottomx,leftBottomy);
	glVertex2f(rightUpperx,leftBottomy);
	glVertex2f(rightUpperx,rightUppery);
	glVertex2f(leftBottomx,rightUppery);
	glEnd();			
}
bool Circ::intersects(Shape* pshape)
{
	int flag=0;
	Circ * ptest=dynamic_cast<Circ *>(pshape);
	if(ptest)
	{

			if(pow(fabs(ptest->getPos().x-this->m_pos.x),2)+pow(fabs(ptest->getPos().y-this->m_pos.y),2)<pow(this->m_rad+ptest->getRad(),2))
			flag=2;		
	}
	if(flag==2)
	return true;
	// TODO: write the implementation for this function
	
	return false;
}
