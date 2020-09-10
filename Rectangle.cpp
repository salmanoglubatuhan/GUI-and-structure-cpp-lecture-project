#include "Rectangle.h"
#include<iostream>
#include <GL/glut.h>
#include "Circle.h"
#include <cmath>
#include<string>
 void Rect::draw()
	{
		// Do NOT modify this function 
		if (m_bMarked)
			glColor4f(0.0f, 0.0f, 0.0f,0.5f);
		else
			glColor4f(m_col.r, m_col.g, m_col.b, 0.5f);
		glRectf(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y);
		
	}


 void Rect::drawBbox(Shape* pshape)
 {
	 
	 Rect * ptest=dynamic_cast<Rect *>(pshape);
	float leftBottomx, leftBottomy, rightUpperx, rightUppery;
	if(this->intersects(pshape))
	{
		if(this->m_pos.x<ptest->getPos().x)
			leftBottomx=this->m_pos.x;
		else
			leftBottomx=ptest->getPos().x;
		if(this->m_pos.y<ptest->getPos().y)
			leftBottomy=this->m_pos.y;
		else
			leftBottomy=ptest->getPos().y;
		if(this->m_pos.x+this->m_size.x>ptest->getPos().x+ptest->getSize().x)
			rightUpperx=this->m_pos.x+this->m_size.x;
		else
			rightUpperx=ptest->getPos().x+ptest->getSize().x;
		if(this->m_pos.y+this->m_size.y>ptest->getPos().y+ptest->getSize().y)
			rightUppery=this->m_pos.y+this->m_size.y;
		else
			rightUppery=ptest->getPos().y+ptest->getSize().y;

		// TODO: calculate leftBottomx, leftBottomy, rightUpperx, rightUppery points for surrounding bounding box

	}	
	
	//Do NOT change this part
	glColor3f(1.0,0.0,0.0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(leftBottomx,leftBottomy);
	glVertex2f(rightUpperx,leftBottomy);
	glVertex2f(rightUpperx,rightUppery);
	glVertex2f(leftBottomx,rightUppery);
	glEnd();
			
		
 }
 
 bool Rect::intersects(Shape* pshape)
	{
		int flag=0;
		Rect * ptest=dynamic_cast<Rect *>(pshape);
		if(ptest)
		{
			if(this->m_pos.x<ptest->getPos().x)
			{
				if(ptest->getPos().x-this->m_pos.x<this->m_size.x)
					flag+=1;
			}
			else
			{
				if(this->m_pos.x-ptest->getPos().x<ptest->getSize().x)
					flag+=1;
			}
			if(this->m_pos.y<ptest->getPos().y)
			{
				if(ptest->getPos().y-this->m_pos.y<this->m_size.y)
					flag+=1;
			}
			else
			{
				if(this->m_pos.y-ptest->getPos().y<ptest->getSize().y)
					flag+=1;
			}
		}
		if(flag==2)
		return true;
		// TODO: write the implementation for this function

		return false;
	}
