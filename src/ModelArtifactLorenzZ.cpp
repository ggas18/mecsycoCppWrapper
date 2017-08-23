#include "ModelArtifactLorenzZ.h"

#include <memory> // pour les smart_ponter

#include <stdexcept> // pour les exceptions notamment dans la receptions des pas de temps

#include "Tuple1.h" // pour les Tuple1s
#include "Tuple2.h" // pour les Tuple2s
#include "Tuple3.h" // pour les Tuple3s

#include "SimulEvent.h" // pour les SimulEvent

#include <boost/algorithm/string/predicate.hpp> // pour la comparaison des chaînes de caractères.

ModelArtifactLorenzZ::ModelArtifactLorenzZ() {}

void ModelArtifactLorenzZ::initialize() {

  this->X = 1.0;
  this->Y = 1.0;
  this->Z = 4.0;
  this->time = 0.0;
  this->dt = 0.01;
  this->c = 2.67;
  return;
}

void ModelArtifactLorenzZ::processInternalEvent(double aTime) {
  // this->time = this->time + this->dt;
  // std::cout << "Temps :" << aTime << std::endl;
  this->time = aTime;
  this->Z = this->Z + this->dt * (this->X * this->Y - this->c * this->Z);
}
double ModelArtifactLorenzZ::getNextInternalEventTime() {
  // std::cout << "Temps :" << (time + dt) << std::endl;
  return this->time + this->dt;
}
double ModelArtifactLorenzZ::getLastEventTime() {
  return this->time - this->dt;
}
void ModelArtifactLorenzZ::processExternalInputEvent(
    mecsyco::SimulEventPtr event, string port) {

  std::shared_ptr<mecsyco::Tuple1<double>> tuple1;

  tuple1 = std::dynamic_pointer_cast<mecsyco::Tuple1<double>>(event->getData());

  if (port == "X") {
    this->X = tuple1->getItem1();

  } else {
    this->Y = tuple1->getItem1();
  }

  return;
}

mecsyco::SimulEventPtr
ModelArtifactLorenzZ::getExternalOutputEvent(string port) {
  string obs("obs");
  string obs2d("obs2D");
  string obs3d("obs3d");

  mecsyco::SimulDataPtr data;
  if (boost::iequals(obs, port)) {
    data = mecsyco::SimulDataPtr(
        new mecsyco::Tuple2<double, double>(this->X, this->Y));
  } else if (boost::iequals(obs2d, port)) {
    data = mecsyco::SimulDataPtr(
        new mecsyco::Tuple2<double, double>(this->X, this->Y));
  } else if (boost::iequals(obs3d, port)) {
    data = mecsyco::SimulDataPtr(
        new mecsyco::Tuple3<double, double, double>(this->X, this->Y, this->Z));
  } else { // on fait un transfert comme dans la version centrée sur la
           // communication
    data = mecsyco::SimulDataPtr(new mecsyco::Tuple1<double>(this->Z));
  }

  mecsyco::SimulEventPtr event(new mecsyco::SimulEvent(data, this->time));
  return event;
}

void ModelArtifactLorenzZ::finishSimulation() {

  std::cout << "FINISHED: " << std::endl;
  std::cout << "Time: " << this->time << std::endl;
  return;
}

void ModelArtifactLorenzZ::setInitialParameters(char **args) {
  try {
    this->dt =
        std::stod(args[0]); // on convertit en double si c'est bien un real
  } catch (std::invalid_argument e) {
    std::cout << e.what() << std::endl;
  }
  return;
}
