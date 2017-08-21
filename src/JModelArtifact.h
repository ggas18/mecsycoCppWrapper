#ifndef JMODELARTIFACT_H
#define JMODELARTIFACT_H

#include <jni.h> // pour la communication avec Java

#include "ModelArtifact.h" // pour heriter du ModelArtifact existant

/**
 * Cette classe represente un modèle artifact pour le wrapping vers java
 */
class JModelArtifact : public mecsyco::ModelArtifact {

private:
  /**
   * objet java appelant une méthode de classe de cette classe c++
   **/
  jobject jObject;
  /**
   * Environnement d'execution depuis lequel il y a eu appel de la
   * méthode c++, on peut voir cet attribut comme une réference à
   * la fonction main utilisant la library dans le cas d'un programme
   * à un seul thread.
   **/
  JNIEnv *env;

  /**
    * Attribut du decorateur pour le modèle artifact.
    **/
  mecsyco::ModelArtifact *modelArtifact;

public:
  // ModelArtifact interface
  void processInternalEvent(double time);
  double getNextInternalEventTime();
  double getLastEventTime();
  void processExternalInputEvent(mecsyco::SimulEventPtr event, string port);
  mecsyco::SimulEventPtr getExternalOutputEvent(string port);
  void initialize();
  void finishSimulation();
  void setInitialParameters(char **args);

  /**
   * Constructeur de la classe appelée depuis java
   **/
  JModelArtifact(JNIEnv *env, jobject jObject);

  /**
  * Pour convertir des jobjectArray char **
  **/
  char **jStringArray2CharChar(JNIEnv *env, jobjectArray stringArray);

  /**
  * Nouvelle fonction pour la conversions des tableaux de chaines jstring
  * en char ** qui n'utilise pas malloc et free
  */
  char **jstrAry2charArAr(JNIEnv *env, jobjectArray stringArray);
};
#endif // JMODELARTIFACT_H
