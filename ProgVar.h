//
// Created by yoavst22 on 06/01/2020.
//

#ifndef ADVANCED1_HW3__PROGVAR_H_
#define ADVANCED1_HW3__PROGVAR_H_
using namespace std;
#include <string>
class ProgVar {
  double value;
  string sim;
 public:
  ProgVar(double val, string simulator);
  virtual ~ProgVar() {}
  const string &GetSim() const {return sim;}
  double GetValue() const {return value;}
  void SetValue(double value) {ProgVar::value = value;}
  void SetSim(const string &sim) {ProgVar::sim = sim;}
};
#endif //ADVANCED1_HW3__PROGVAR_H_
