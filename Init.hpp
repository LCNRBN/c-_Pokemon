#include <iostream>
#include <typeinfo>

#include "State.hpp"
#include "Wait.hpp"
#include "Context.hpp"

class Init : public State{

 public:
  void Handle1() override {
    std::cout << "Init handles request1.\n";
  }
  void Handle2() override {
    std::cout << "Init handles request2.\n";
    std::cout << "Init wants to change the state of the context.\n";
    this->context_->TransitionTo(new Wait);
  }
};

void Wait::Handle1() {
  {
    std::cout << "Wait handles request1.\n";
    std::cout << "Wait wants to change the state of the context.\n";

    this->context_->TransitionTo(new Init);
  }
}

/**
 * The client code.
 */
void ClientCode() {
  Context *context = new Context(new Wait);
  context->Request1();
  context->Request2();
  delete context;
}