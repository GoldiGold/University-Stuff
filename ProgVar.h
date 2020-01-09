//
// Created by yoavst22 on 06/01/2020.
//

#ifndef ADVANCED1_HW3__PROGVAR_H_
#define ADVANCED1_HW3__PROGVAR_H_
#include <string>
class ProgVar {
  double value;
	std::string sim;
 public:
  ProgVar(double val, std::string simulator);
  virtual ~ProgVar() {}
   std::string &GetSim()  {return sim;}
  double GetValue()  {return value;}
  void SetValue(double value) {ProgVar::value = value;}
  void SetSim(const std::string &sim) {ProgVar::sim = sim;}
};
#endif //ADVANCED1_HW3__PROGVAR_H_
