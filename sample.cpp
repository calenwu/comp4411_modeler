// The sample model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"

// To make a SampleModel, we inherit off of ModelerView
class SampleModel : public ModelerView 
{
public:
    SampleModel(int x, int y, int w, int h, char *label) 
        : ModelerView(x, y, w, h, label) { }

    virtual void draw();
};

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView* createSampleModel(int x, int y, int w, int h, char *label)
{ 
    return new SampleModel(x, y, w, h, label); 
}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void SampleModel::draw()
{
	// This call takes care of a lot of the nasty projection 
	// matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
	ModelerView::draw();

	// draw the floor
	setAmbientColor(.1f,.1f,.1f);
	setDiffuseColor(COLOR_RED);
	glPushMatrix();
		glTranslated(-5,0,-5);
		drawBox(10,0.01f,10);
	glPopMatrix();

	// draw the sample model
	setAmbientColor(.1f,.1f,.1f);
	setDiffuseColor(COLOR_GREEN);
	glPushMatrix();
		glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
		glRotated(-90, 1, 0, 0);
		glPushMatrix();
			// torso
			glRotated(VAL(ROTATE), 0.0, 0.0, 1.0);
			glTranslated(-1.5, -0.5, 3.75);
			drawBox(3, 1, 4);

			// neck
			glPushMatrix();
				glTranslated(1.5, 0.5, 4);
				drawCylinder(0.75, 0.375, 0.375);
				// head
				glPushMatrix();
					glTranslated(0, 0, 0.75 + 0.75);
					drawSphere(0.75);
				glPopMatrix();
			glPopMatrix();
			
			// arms
			// left arm
			glPushMatrix();
				// upper arm
				glTranslated(-0.375, 0.125 + 0.375, 4 - 0.375);
				drawSphere(0.375);
					glPushMatrix();
						glTranslated(0, 0, -1.5);
						drawCylinder(1.5, 0.375, 0.375);
						glPushMatrix();
							drawSphere(0.375);
							// lower arm
							glTranslated(0, 0, -0.75);
							drawSphere(0.375);
								glPushMatrix();
									glTranslated(0, 0, -1.5);
									drawCylinder(1.5, 0.375, 0.375);
									glPushMatrix();
									glTranslated(0, 0, 0);
										drawSphere(0.375);
										// fingers
										// left finger
										glPushMatrix();
											glRotated(20, 0, 1, 0);
											glTranslated(-0.1, 0, -0.4 - 0.375);
											drawCylinder(0.4, 0.1, 0.1);
										glPopMatrix();
										// right finger
										glPushMatrix();
											glRotated(-20, 0, 1, 0);
											glTranslated(0.1, 0, -0.4 - 0.375);
											drawCylinder(0.4, 0.1, 0.1);
										glPopMatrix();
									glPopMatrix();
								glPopMatrix();
						glPopMatrix();
					glPopMatrix();
			glPopMatrix();

			// right arm
			glPushMatrix();
				// upper arm
				glTranslated(3 + 0.375, 0.125 + 0.375, 4 - 0.375);
				drawSphere(0.375);
					glPushMatrix();
						glTranslated(0, 0, -1.5);
						drawCylinder(1.5, 0.375, 0.375);
						glPushMatrix();
							drawSphere(0.375);
							// lower arm
							glTranslated(0, 0, -0.75);
							drawSphere(0.375);
								glPushMatrix();
									glTranslated(0, 0, -1.5);
									drawCylinder(1.5, 0.375, 0.375);
									glPushMatrix();
									glTranslated(0, 0, 0);
										drawSphere(0.375);
										// fingers
										// left finger
										glPushMatrix();
											glRotated(20, 0, 1, 0);
											glTranslated(-0.1, 0, -0.4 - 0.375);
											drawCylinder(0.4, 0.1, 0.1);
										glPopMatrix();
										// right finger
										glPushMatrix();
											glRotated(-20, 0, 1, 0);
											glTranslated(0.1, 0, -0.4 - 0.375);
											drawCylinder(0.4, 0.1, 0.1);
										glPopMatrix();
									glPopMatrix();
								glPopMatrix();
						glPopMatrix();
					glPopMatrix();
			glPopMatrix();

			// legs
			// left leg
			glPushMatrix();
				glTranslated(0.25 + 0.375, 0.125 + 0.375, -0.375);
				drawSphere(0.375);
				glPushMatrix();
					glTranslated(0, 0, -3);
					drawCylinder(3, 0.375, 0.375);
					glPushMatrix();
						drawSphere(0.375);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
			// right leg
			glPushMatrix();
				glTranslated(0.25 + 2 * 0.375 + 1 + 0.375, 0.125 +0.375, -0.375);
				drawSphere(0.375);
				glPushMatrix();
					glTranslated(0, 0, -3);
					drawCylinder(3, 0.375, 0.375);
					glPushMatrix();
						drawSphere(0.375);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();

		glPopMatrix();
		

		// glPushMatrix();
		// 	glTranslated(-1.5, 0, 0);
		// 	drawCylinder(5, 1, 1);
		// glPopMatrix();
		// glPushMatrix();
		// 	glTranslated(1.5, 0, 0);
		// 	drawCylinder(5, 1, 1);
		// glPopMatrix();

		// draw box
		// glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
		// glPushMatrix();
		// 	glTranslated(-1.5, 0, -2);
		// 	drawBox(3, 1, 4);
		// glPopMatrix();

		// draw cannon
		// glPushMatrix();
		// 	glRotated(VAL(ROTATE), 0.0, 1.0, 0.0);
		// 	glRotated(-90, 1.0, 0.0, 0.0);
		// 	drawCylinder(VAL(HEIGHT), 0.1, 0.1);

		// 	glTranslated(0.0, 0.0, VAL(HEIGHT));
		// 	drawCylinder(1, 1.0, 0.9);

		// 	glTranslated(0.0, 0.0, 0.5);
		// 	glRotated(90, 1.0, 0.0, 0.0);
		// 	drawCylinder(4, 0.1, 0.2);
		// glPopMatrix();
	glPopMatrix();
}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
    ModelerControl controls[NUMCONTROLS];
    controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
    controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
    controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);
    controls[HEIGHT] = ModelerControl("Height", 1, 2.5, 0.1f, 1);
		controls[ROTATE] = ModelerControl("Rotate", -135, 135, 1, 0);

    ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS);
    return ModelerApplication::Instance()->Run();
}
