#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
//#include "gtest/gtest.h"

using std::string;
using std::vector;
using std::shared_ptr;
using std::cout;
using std::endl;

int streamcounter;

class Stream{
  private:
    double mass_flow;
    string name;
  public:
    Stream(int s){setName("s"+std::to_string(s));}
    void setName(string s){name=s;}
    string getName(){return name;}
    void setMassFlow(double m){mass_flow=m;}
    double getMassFlow(){return mass_flow;}
    void print(std::ostream& os = cout){
      os<<"Stream "<<getName() << " flow = "<<getMassFlow()<<endl;
    }
};

class Device{
  protected:
    vector<shared_ptr<Stream>> inputs;
    vector<shared_ptr<Stream>> outputs;
  public:
    void addInput(shared_ptr<Stream> s){inputs.push_back(s);}
    void addOutput(shared_ptr<Stream> s){outputs.push_back(s);}
    virtual void updateOutputs() = 0;
};

/**
 * @brief Класс сложного ректора(2 входа 2 выхода).
 * 
 * Является интерфейсным.
 * 
 */

class SophisticatedReactor : Device{
  public:
    using Device :: addInput;
    using Device :: addOutput;
    virtual void updateOutputs(){
      // //check overall input mass:
      // float sum = 0;
      // for(auto i : inputs){
      //   sum += i -> getMassFlow();
      // }
      // shared_ptr<Stream> out_s1(new Stream(1));
      // shared_ptr<Stream> out_s2(new Stream(2));
      // out_s1->setMassFlow(sum / 8);
      // out_s2->setMassFlow(sum * 7 / 8);
      // addOutput(out_s1);
      // addOutput(out_s2);
    }
    // virtual void printOutputs(std::ostream& os = cout){
    //   for(auto i : outputs){
    //     i->print(cout);
    //   }
    // }
};

// TEST(ReactorTesting, UpdatingOutputs){
//   SophisticatedReactor test1;
//   std::stringstream testStream;
//   test1.printOutputs(testStream);
//   ASSERT_EQ("Stream s1 flow = 1.875\nStream s2 flow = 13.125\n", testStream.str());
// }

// TEST(ReactorTesting, PrintingOutputs){
//   SophisticatedReactor test1;
//   std::stringstream testStream;
//   test1.printOutputs(testStream);
//   ASSERT_EQ("Stream s1 flow = 1.875\nStream s2 flow = 13.125\n", testStream.str());
// }


int main(){
  streamcounter=0;
  SophisticatedReactor r1;
  
  shared_ptr<Stream> s1(new Stream(++streamcounter));
  shared_ptr<Stream> s2(new Stream(++streamcounter));
  shared_ptr<Stream> s3(new Stream(++streamcounter));
  s1->setMassFlow(10.0);
  s2->setMassFlow(5.0);

  // r1.addInput(s1);
  // r1.addInput(s2);
  // r1.updateOutputs();
  // cout << "Output Streams:" << endl;
  // r1.printOutputs(cout);
}
