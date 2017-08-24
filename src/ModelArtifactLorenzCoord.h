#ifndef MODELARTIFACTLORENZZ_H
#define MODELARTIFACTLORENZZ_H

#include "ModelArtifact.h"

class ModelArtifactLorenzCoord : public mecsyco::ModelArtifact {

private:
  double X; // La valeur de l'état en X
  double Y; // La valeur de l'état en Y
  double Z; // La valeur de l'état en Z

  double time; // Temps interne du simulateur

  double dt; // Pas de temps de la simulation

  // paramètre du systeme du Lorenz
  double b;

public:
  ModelArtifactLorenzCoord();
  // ModelArtifact interface
public:
  void processInternalEvent(double aTime);
  double getNextInternalEventTime();
  double getLastEventTime();
  void processExternalInputEvent(mecsyco::SimulEventPtr event, string port);
  mecsyco::SimulEventPtr getExternalOutputEvent(string port);
  void initialize();
  void finishSimulation();
  void setInitialParameters(char **args);
};

#endif // MOdELEARTIFACTLORENZZ_H
