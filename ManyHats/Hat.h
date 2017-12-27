#include "InGameObj.h"
class Hat : InGameObj{
public:
	virtual int getHatType() = 0;// pure virtual function providing interface framework.

	Hat(const int baseDamage,const double damageModifier,const double fallSpeed,const double launchSpeed,double (&hitBox)[2])
		:baseDamage(baseDamage),damageModifier(damageModifier),fallSpeedModifier(fallSpeed), launchVelocity(launchSpeed), InGameObj(hitBox)
	{};

	~Hat() {
		delete & baseDamage;
		delete & damageModifier;
		delete & fallSpeedModifier;
		delete & launchVelocity;
	};

	int getBaseDamage() {//returns the baseDamage of the hat
		return this->baseDamage;
	};

	double getDamageModifier() {//returns the damage modifier of the hat
		return this->damageModifier;
	};

	double getFallSpeed() {// returns the fallspead of the hat
		return this->fallSpeedModifier;
	};

	double getLaunchVelocity() {// returns the launch velocity of the hat
		return this->launchVelocity;
	};

	virtual void launch(double xDir,double yDir) = 0;// launches the hat with given direction!
	
private:
	const int baseDamage;//the base damage of the hat

	const double damageModifier;// damage modifier of the hat
	
	const double fallSpeedModifier;//fall speed of the hat (when it's airborne)
	
	const double launchVelocity;//launch velocity of the hat
};