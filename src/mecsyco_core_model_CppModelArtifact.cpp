#include "JModelArtifact.h" // classes mappées de modèle artefact, c'est un décorateur

#include "SimulEvent.h" // type de données SimulEventPtr
#include "Tuple1.h"
#include <cstring> // pour les char * et les chars **

// Le fichier genéré automatiquement par eclipse.
#include "mecsyco_core_model_CppModelArtifact.h"

/**
 * classe qui permet de configurer les paramètres globaux. On a
 * un seul paramètre globale à configurer ici: Les séparateurs des
 * decimaux doit être des points.
 */
class ConfSystem {
public:
  ConfSystem(string params) { std::locale::global(std::locale(params)); }
}; // Fin de la classe ConfSystem

/**
 * configurer le separateur des doubles en "."; la configuration sera
 * independante de la localité
 */

string params("en_US.UTF8");
ConfSystem configurationDuSystem(params);

/**
 * Implémentatipon des méthodes natives nécessaires pour le code java.
 * Le code ici à l'air de ressembler à du C. Mais au fond ce n'est pas
 * du C.
 * Pour chaque objet C++ creé, il y a un seul objet java dans l'ENV
 *correspondant.
 * Les deux objets partagent l'adresse memoire: Pour l'objet C++, c'est la
 *valeur
 * du pointeur et pour l'objet Java, c'est un attribut public
 **/

JNIEXPORT jlong JNICALL
Java_mecsyco_core_model_CppModelArtifact_n_1ModelArtifact(JNIEnv *env,
                                                          jobject thiz) {
  // creer d'un pointeur sur l'objet
  JModelArtifact *jmArt = new JModelArtifact(env, thiz);

  // prendre la valeur du pointeur: c'est la valeur de l'attribut NativeObject
  // de
  // java correspondante
  jlong rv = reinterpret_cast<jlong>(jmArt);

  return rv;
}

JNIEXPORT void JNICALL
Java_mecsyco_core_model_CppModelArtifact_n_1processInternalEvent(JNIEnv *env,
                                                                 jobject thiz,
                                                                 jdouble time) {
  // Ces trois lignes se répètent exactement au début de toutes les fonctions
  // SAUF LA FONCTION
  // DE CREATION DE L'OBJET MAPPÉE.La troisième ligne utilise la valeur de
  // l'attribut
  // NativeObject de la classe java correspondante
  jclass cls = env->GetObjectClass(thiz); // prendre la classe
  jfieldID id = env->GetFieldID(
      cls, "NativeObject",
      "J"); // prendre l'identifiant du champ de l'attribut NativeObject
  jlong pointer = env->GetLongField(thiz, id); // prendre la valeur de
                                               // l'attribut NativeObject, donc
                                               // la valeur du pointeur
  // JModelArtifact *obj= (JModelArtifact *)pointer; // caster le pointeur en
  // l'objet C++ mappée
  JModelArtifact *obj = reinterpret_cast<JModelArtifact *>(pointer);

  obj->processInternalEvent(time);
}

JNIEXPORT jdouble JNICALL
Java_mecsyco_core_model_CppModelArtifact_n_1getNextInternalEventTime(
    JNIEnv *env, jobject thiz) {
  // Ces trois lignes se répètent exactement au début de toutes les fonctions
  // SAUF LA FONCTION
  // DE CREATION DE L'OBJET MAPPÉE.La troisième ligne utilise la valeur de
  // l'attribut
  // NativeObject de la classe java correspondante
  jclass cls = env->GetObjectClass(thiz); // prendre la classe
  jfieldID id = env->GetFieldID(
      cls, "NativeObject",
      "J"); // prendre l'identifiant du champ de l'attribut NativeObject
  jlong pointer = env->GetLongField(thiz, id); // prendre la valeur de
                                               // l'attribut NativeObject, donc
                                               // la valeur du pointeur

  JModelArtifact *obj = reinterpret_cast<JModelArtifact *>(pointer);

  return obj->getNextInternalEventTime();
}
JNIEXPORT jdouble JNICALL
Java_mecsyco_core_model_CppModelArtifact_n_1getLastEventTime(JNIEnv *env,
                                                             jobject thiz) {
  // Ces trois lignes se répètent exactement au début de toutes les fonctions
  // SAUF LA FONCTION
  // DE CREATION DE L'OBJET MAPPÉE.La troisième ligne utilise la valeur de
  // l'attribut
  // NativeObject de la classe java correspondante
  jclass cls = env->GetObjectClass(thiz); // prendre la classe
  jfieldID id = env->GetFieldID(
      cls, "NativeObject",
      "J"); // prendre l'identifiant du champ de l'attribut NativeObject
  jlong pointer = env->GetLongField(thiz, id); // prendre la valeur de
                                               // l'attribut NativeObject, donc
                                               // la valeur du pointeur

  JModelArtifact *obj = reinterpret_cast<JModelArtifact *>(pointer);

  return obj->getLastEventTime();
}

JNIEXPORT void JNICALL
Java_mecsyco_core_model_CppModelArtifact_n_1processExternalInputEvent(
    JNIEnv *env, jobject thiz, jstring jstringForSimulData, jdouble time,
    jstring jport) {

  // Ces trois lignes se répètent exactement au début de toutes les fonctions
  // SAUF LA FONCTION
  // DE CREATION DE L'OBJET MAPPÉE.La troisième ligne utilise la valeur de
  // l'attribut
  // NativeObject de la classe java correspondante
  jclass cls = env->GetObjectClass(thiz); // prendre la classe
  jfieldID id = env->GetFieldID(
      cls, "NativeObject",
      "J"); // prendre l'identifiant du champ de l'attribut NativeObject
  jlong pointer = env->GetLongField(thiz, id); // prendre la valeur de
                                               // l'attribut NativeObject, donc
                                               // la valeur du pointeur

  JModelArtifact *obj = reinterpret_cast<JModelArtifact *>(pointer);
  const char *chars1, *chars2;
  chars1 = env->GetStringUTFChars(jstringForSimulData, NULL);
  string NstringForSimulData(chars1);

  chars2 = env->GetStringUTFChars(jport, NULL);
  string Nport(chars2);

  env->ReleaseStringUTFChars(jstringForSimulData, chars1);
  env->ReleaseStringUTFChars(jport, chars2);

  // decltype, cette fonction pourrait être utilisé pour faire evoluer la
  // librairie de sorte qu'il aiguiller les tuples //automatiquement. Ici on
  // suppose qu'on ne recevra que des tuple1s de double
  mecsyco::SimulDataPtr data(new mecsyco::Tuple1<double>());

  data->loadFromJsonStr(NstringForSimulData);
  mecsyco::SimulEventPtr event(new mecsyco::SimulEvent(data, time));

  obj->processExternalInputEvent(event, Nport);
}

JNIEXPORT jobjectArray JNICALL
Java_mecsyco_core_model_CppModelArtifact_n_1getExternalOutputEvent(
    JNIEnv *env, jobject thiz, jstring jStr) {

  // Ces trois lignes se répètent exactement au début de toutes les fonctions
  // SAUF LA FONCTION
  // DE CREATION DE L'OBJET MAPPÉE.La troisième ligne utilise la valeur de
  // l'attribut
  // NativeObject de la classe java correspondante
  jclass cls = env->GetObjectClass(thiz); // prendre la classe
  jfieldID id = env->GetFieldID(
      cls, "NativeObject",
      "J"); // prendre l'identifiant du champ de l'attribut NativeObject
  jlong pointer = env->GetLongField(thiz, id); // prendre la valeur de
                                               // l'attribut NativeObject, donc
                                               // la valeur du pointeur

  JModelArtifact *obj = reinterpret_cast<JModelArtifact *>(pointer);
  const char *chars1;
  chars1 = env->GetStringUTFChars(jStr, NULL);
  string Nport(chars1);
  env->ReleaseStringUTFChars(jStr, chars1);

  mecsyco::SimulEventPtr event = obj->getExternalOutputEvent(Nport);
  int length = 2;

  string *simulEventSerial = new string[length];

  mecsyco::Json jsonObj;
  event->getData()->toJson(jsonObj);

  simulEventSerial[0] = jsonObj.toString();
  simulEventSerial[1] = std::to_string(event->getTime());

  jobjectArray ret =
      env->NewObjectArray(length, env->FindClass("java/lang/String"), 0);

  char *chars3 = new char[simulEventSerial[0].length() + 1];
  std::strcpy(chars3, simulEventSerial[0].c_str());

  jstring str3 = env->NewStringUTF(chars3);
  env->SetObjectArrayElement(ret, 0, str3);
  env->DeleteLocalRef(str3);

  char *chars4 = new char[simulEventSerial[1].length() + 1];
  std::strcpy(chars4, simulEventSerial[1].c_str());

  jstring str4 = env->NewStringUTF(chars4);
  env->SetObjectArrayElement(ret, 1, str4);
  env->DeleteLocalRef(str4);
  // liberation de la memoire allouée pour les deux chaines.
  delete[] chars3;
  delete[] chars4;
  return ret;
}

JNIEXPORT void JNICALL Java_mecsyco_core_model_CppModelArtifact_n_1initialize(
    JNIEnv *env, jobject thiz) {

  // Ces trois lignes se répètent exactement au début de toutes les fonctions
  // SAUF LA FONCTION
  // DE CREATION DE L'OBJET MAPPÉE.La troisième ligne utilise la valeur de
  // l'attribut
  // NativeObject de la classe java correspondante
  jclass cls = env->GetObjectClass(thiz); // prendre la classe
  jfieldID id = env->GetFieldID(
      cls, "NativeObject",
      "J"); // prendre l'identifiant du champ de l'attribut NativeObject
  jlong pointer = env->GetLongField(thiz, id); // prendre la valeur de
                                               // l'attribut NativeObject, donc
                                               // la valeur du pointeur

  JModelArtifact *obj = reinterpret_cast<JModelArtifact *>(pointer);

  obj->initialize();
}

JNIEXPORT void JNICALL
Java_mecsyco_core_model_CppModelArtifact_n_1finishSimulation(JNIEnv *env,
                                                             jobject thiz) {

  // Ces trois lignes se répètent exactement au début de toutes les fonctions
  // SAUF LA FONCTION
  // DE CREATION DE L'OBJET MAPPÉE.La troisième ligne utilise la valeur de
  // l'attribut
  // NativeObject de la classe java correspondante
  jclass cls = env->GetObjectClass(thiz); // prendrSimulDataPtre la classe
  jfieldID id = env->GetFieldID(
      cls, "NativeObject",
      "J"); // prendre l'identifiant du champ de l'attribut NativeObject
  jlong pointer = env->GetLongField(thiz, id); // prendre la valeur de
                                               // l'attribut NativeObject, donc
                                               // la valeur du pointeur

  JModelArtifact *obj = reinterpret_cast<JModelArtifact *>(pointer);

  obj->finishSimulation();
}

JNIEXPORT void JNICALL
Java_mecsyco_core_model_CppModelArtifact_n_1setInitialParameters(
    JNIEnv *env, jobject thiz, jobjectArray jstringArray) {

  // Ces trois lignes se répètent exactement au début de toutes les fonctions
  // SAUF LA FONCTION
  // DE CREATION DE L'OBJET MAPPÉE.La troisième ligne utilise la valeur de
  // l'attribut
  // NativeObject de la classe java correspondante
  jclass cls = env->GetObjectClass(thiz); // prendre la classe
  jfieldID id = env->GetFieldID(
      cls, "NativeObject",
      "J"); // prendre l'identifiant du champ de l'attribut NativeObject
  jlong pointer = env->GetLongField(thiz, id); // prendre la valeur de
                                               // l'attribut NativeObject, donc
                                               // la valeur du pointeur
  JModelArtifact *obj =
      reinterpret_cast<JModelArtifact *>(pointer); // caster le pointeur en
  // l'objet C++ mappée reinterpret_cast
  char **args = obj->jstrAry2charArAr(env, jstringArray);

  obj->setInitialParameters(args);
  int stringCount = env->GetArrayLength(jstringArray);
  // liberattion de la memoire allouée dans la fonction jstrAry2charArAr
  for (int i = 0; i < stringCount; i++) {
    delete[] args[i];
  }
  delete[] args;
}
