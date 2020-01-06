//
// Created by yoavst22 on 03/01/2020.
//

using namespace std;
#include <string>
#include <list>
//#include <hash_map>
class ProgVar {
  double value;
  string sim;
 public:
  ProgVar(double val, string simulator) {
    this->value = val;
    this->sim = simulator;
  }
  virtual ~ProgVar() {
  }
  const string &GetSim() const {
    return sim;
  }
  double GetValue() const {
    return value;
  }
  void SetValue(double value) {
    ProgVar::value = value;
  }
  void SetSim(const string &sim) {
    ProgVar::sim = sim;
  }
};