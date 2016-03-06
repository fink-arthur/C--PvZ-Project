#include "Strip.h"
#include "GraphicPrimitives.h"
#include "Environment.h"

Strip::Strip() {

}

Strip::~Strip() {

}

/* This function sets the selection to a new value */
void Strip::setSelection(int newValue) {
	selection = newValue;
}

/* This function draws the strip with all the info on the game, the turrets and the selected turret, */
void Strip::draw() {
	float posX;
	float posY;

	posX = -0.60 + (selection * 0.20f);
	posY = 0.6f;
	GraphicPrimitives::drawFillRect2D(posX, posY, 0.20f, 0.40f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawFillRect2D(posX + 0.01f, posY + 0.01f, 0.18f, 0.38f, 0.0f, 0.0f, 0.0f);

	char moneyBuffer [50];
	sprintf (moneyBuffer,"Money: %d", Environment::money);
	GraphicPrimitives::drawText2D(moneyBuffer,-0.95f,0.85f,0.0f,0.0f, 1.0f);

	char healthBuffer [50];
	sprintf (healthBuffer,"Health: %d", Environment::health);
	GraphicPrimitives::drawText2D(healthBuffer,-0.95f,0.75f,0.0f,0.0f, 1.0f);

	char waveBuffer [50];
	sprintf (waveBuffer,"Wave: %d", Environment::wave);
	GraphicPrimitives::drawText2D(waveBuffer,-0.95f,0.65f,0.0f,0.0f, 1.0f);

	posX = -0.55f;
	posY = 0.92f;
	GraphicPrimitives::drawFillTriangle2D(posX, posY + 0.5 * 0.1f, posX + 0.1f, posY, posX, posY - 0.5 * 0.1f, 0.2f, 0.8f, 1.0f);
	char turret1AtSpBuffer [75];
	sprintf (turret1AtSpBuffer,"sp: 1.0");
	GraphicPrimitives::drawText2D(turret1AtSpBuffer,posX - 0.02f,posY - 0.12f,0.0f,0.0f, 1.0f);
	char turret1DamageBuffer [75];
	sprintf (turret1DamageBuffer,"dmg: 20");
	GraphicPrimitives::drawText2D(turret1DamageBuffer,posX - 0.03f,posY - 0.2f,0.0f,0.0f, 1.0f);
	char turret1CostBuffer [75];
	sprintf (turret1CostBuffer,"cst: 20");
	GraphicPrimitives::drawText2D(turret1CostBuffer,posX - 0.02f,posY - 0.28f,0.0f,0.0f, 1.0f);

	posX = -0.35f;
	posY = 0.92f;
	GraphicPrimitives::drawFillTriangle2D(posX, posY + 0.5 * 0.1f, posX + 0.1f, posY, posX, posY - 0.5 * 0.1f, 0.4f, 1.0f, 0.6f);
	char turret2AtSpBuffer [75];
	sprintf (turret2AtSpBuffer,"sp: 1.0");
	GraphicPrimitives::drawText2D(turret2AtSpBuffer,posX - 0.02f,posY - 0.12f,0.0f,0.0f, 1.0f);
	char turret2DamageBuffer [75];
	sprintf (turret2DamageBuffer,"dmg: 40");
	GraphicPrimitives::drawText2D(turret2DamageBuffer,posX - 0.03f,posY - 0.2f,0.0f,0.0f, 1.0f);
	char turret2CostBuffer [75];
	sprintf (turret2CostBuffer,"cst: 40");
	GraphicPrimitives::drawText2D(turret2CostBuffer,posX - 0.02f,posY - 0.28f,0.0f,0.0f, 1.0f);

	posX = -0.15f;
	posY = 0.92f;
	GraphicPrimitives::drawFillTriangle2D(posX, posY + 0.5 * 0.1f, posX + 0.1f, posY, posX, posY - 0.5 * 0.1f, 0.6f, 0.2f, 0.4f);
	char turret3AtSpBuffer [75];
	sprintf (turret3AtSpBuffer,"sp: 2.0");
	GraphicPrimitives::drawText2D(turret3AtSpBuffer,posX - 0.02f,posY - 0.12f,0.0f,0.0f, 1.0f);
	char turret3DamageBuffer [75];
	sprintf (turret3DamageBuffer,"dmg: 10");
	GraphicPrimitives::drawText2D(turret3DamageBuffer,posX - 0.03f,posY - 0.2f,0.0f,0.0f, 1.0f);
	char turret3CostBuffer [75];
	sprintf (turret3CostBuffer,"cst: 20");
	GraphicPrimitives::drawText2D(turret3CostBuffer,posX - 0.02f,posY - 0.28f,0.0f,0.0f, 1.0f);

	posX = 0.05f;
	posY = 0.92f;
	GraphicPrimitives::drawFillTriangle2D(posX, posY + 0.5 * 0.1f, posX + 0.1f, posY, posX, posY - 0.5 * 0.1f, 0.4f, 0.2f, 0.6f);
	char turret4AtSpBuffer [75];
	sprintf (turret4AtSpBuffer,"sp: 2.0");
	GraphicPrimitives::drawText2D(turret4AtSpBuffer,posX - 0.02f,posY - 0.12f,0.0f,0.0f, 1.0f);
	char turret4DamageBuffer [75];
	sprintf (turret4DamageBuffer,"dmg: 20");
	GraphicPrimitives::drawText2D(turret4DamageBuffer,posX - 0.03f,posY - 0.2f,0.0f,0.0f, 1.0f);
	char turret4CostBuffer [75];
	sprintf (turret4CostBuffer,"cst: 40");
	GraphicPrimitives::drawText2D(turret4CostBuffer,posX - 0.02f,posY - 0.28f,0.0f,0.0f, 1.0f);

	posX = 0.25f;
	posY = 0.92f;
	GraphicPrimitives::drawFillRect2D(posX, posY - 0.05f, 0.1f, 0.1f, 1.0f, 1.0f, 1.0f);
	char turret5Buffer [75];
	sprintf (turret5Buffer,"4 mon/s");
	GraphicPrimitives::drawText2D(turret5Buffer,posX - 0.03f,posY - 0.12f,0.0f,0.0f, 1.0f);
	char turret5CostBuffer [75];
	sprintf (turret5CostBuffer,"cst: 70");
	GraphicPrimitives::drawText2D(turret5CostBuffer,posX - 0.02f,posY - 0.28f,0.0f,0.0f, 1.0f);

	posX = 0.45f;
	posY = 0.92f;
	GraphicPrimitives::drawFillTriangle2D(posX, posY + 0.5 * 0.1f, posX + 0.1f, posY, posX, posY - 0.5 * 0.1f, 0.5f, 0.5f, 1.0f);
	char turret6AtSpBuffer [75];
	sprintf (turret6AtSpBuffer,"sp: 2.0");
	GraphicPrimitives::drawText2D(turret6AtSpBuffer,posX - 0.02f,posY - 0.12f,0.0f,0.0f, 1.0f);
	char turret6DamageBuffer [75];
	sprintf (turret6DamageBuffer,"slows a");
	GraphicPrimitives::drawText2D(turret6DamageBuffer,posX - 0.03f,posY - 0.2f,0.0f,0.0f, 1.0f);
	char turret6CostBuffer [75];
	sprintf (turret6CostBuffer,"cst: 30");
	GraphicPrimitives::drawText2D(turret6CostBuffer,posX - 0.02f,posY - 0.28f,0.0f,0.0f, 1.0f);


	GraphicPrimitives::drawFillRect2D(0.6f,0.6f,0.4f,0.4f,1.0f,1.0f,1.0f,1.0f);
	char launchBuffer [50];
	sprintf (launchBuffer,"Launch");
	GraphicPrimitives::drawText2D(launchBuffer,0.75f,0.8f,0.0f,0.0f, 1.0f);
}
