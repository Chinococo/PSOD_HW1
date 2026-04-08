#include <iostream>

#include "Model/gateAND.h"
#include "Model/iPin.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
   for (int i = 0; i < 16; i++) {
      gateAND gateAND ;
      int testSignal = i;
      gateAND.addInputPin(new iPin(testSignal&1));
      testSignal = testSignal>>1;
      gateAND.addInputPin(new iPin(testSignal&1));
      testSignal = testSignal>>1;
      gateAND.addInputPin(new iPin(testSignal&1));
      testSignal = testSignal>>1;
      gateAND.addInputPin(new iPin(testSignal&1));

     cout<< i <<" "<< gateAND.getOutput()[0] << endl;
   }
}