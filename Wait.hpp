#include <iostream>
#include <typeinfo>

#include "State.hpp"

/**
 * Concrete States implement various behaviors, associated with a state of the
 * Context.
 */

class Wait : public State {
 public:
  void Handle1() override;

  void Handle2() override {
    std::cout << "Init handles request2.\n";
  }
};