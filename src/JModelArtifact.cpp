#include "JModelArtifact.h"
#include <jni.h> // pour la communication avec Java

#include "ModelArtifactLorenzCoord.h"
JModelArtifact::JModelArtifact(JNIEnv *env, jobject jObject) {

  this->jObject = env->NewGlobalRef(jObject);
  this->env = env;
  this->modelArtifact = new ModelArtifactLorenzCoord();
}

char **JModelArtifact::jStringArray2CharChar(JNIEnv *env,
                                             jobjectArray stringArray) {

  jlong stringCount = env->GetArrayLength(stringArray);
  long unsigned int unsignedStringCount = (long unsigned int)stringCount;
  char **rawString = (char **)malloc(unsignedStringCount * sizeof(char *));

  for (int i = 0; i < stringCount; i++) {

    jstring jString = (jstring)(env->GetObjectArrayElement(stringArray, i));
    jlong ii = (jlong)env->GetStringUTFLength(jString);
    long unsigned int uu = (long unsigned int)ii;
    rawString[i] = (char *)malloc(uu * (sizeof(char) + 1));
    rawString[i] = const_cast<char *>(env->GetStringUTFChars(jString, NULL));

    env->DeleteLocalRef(jString);
  }
  return rawString;
}

char **JModelArtifact::jstrAry2charArAr(JNIEnv *env, jobjectArray stringArray) {

  int arLenth = env->GetArrayLength(stringArray);

  char **rawString = new char *[arLenth];

  for (int i = 0; i < arLenth; i++) {

    jstring jString = (jstring)(env->GetObjectArrayElement(stringArray, i));
    int strLength = env->GetStringUTFLength(jString);

    rawString[i] = new char[strLength];
    rawString[i] = const_cast<char *>(env->GetStringUTFChars(jString, NULL));

    env->DeleteLocalRef(jString);
  }
  return rawString;
}

void JModelArtifact::processInternalEvent(double time) {

  (this->modelArtifact)->processInternalEvent(time);
}
double JModelArtifact::getNextInternalEventTime() {

  return (this->modelArtifact)->getNextInternalEventTime();
}
double JModelArtifact::getLastEventTime() {

  return (this->modelArtifact)->getLastEventTime();
}
void JModelArtifact::processExternalInputEvent(mecsyco::SimulEventPtr event,
                                               string port) {

  (this->modelArtifact)->processExternalInputEvent(event, port);
}
mecsyco::SimulEventPtr JModelArtifact::getExternalOutputEvent(string port) {

  return (this->modelArtifact)->getExternalOutputEvent(port);
}
void JModelArtifact::initialize() { (this->modelArtifact)->initialize(); }

void JModelArtifact::setInitialParameters(char **args) {

  (this->modelArtifact)->setInitialParameters(args);
}

void JModelArtifact::finishSimulation() {

  (this->modelArtifact)->finishSimulation();
}
