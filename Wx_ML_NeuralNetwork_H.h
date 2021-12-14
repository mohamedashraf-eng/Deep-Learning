
/*
    Author: Mohamed Ashraf (Wx)
    Date: 10/8/2021
    Type: Machine learning DATASET test.
*/
//======== ======== ======== ======== ======== ======== ======== ========

// HEADER GUARDS: ML_H
#ifndef __Wx_ML_NerualNetwork_H_H__s
#define __Wx_ML_NerualNetwork_H_H__

// HEADER LIBRARIES USED:
#include "Wx_ML_H.h"
#include <math.h>
//==================================================

/*****************************************************
*                    FUNCTION DECLARED               *
******************************************************/
/*--- NN-FUNCTIONS ---*/

// TO INPUT VALUES TO INPUT:

// TO INPUT VALUES TO WEIGHTS:

// TO INPUT VALUES TO BIASES:

// TO INPUT VALUES TO OUTPUT:

/*--- ACTIVATION-FUNCTIONS ---*/

// ACTIVATION LAYER LINEAR:
float Wx_LINEAR(double);

// ACTIVATION LAYER RE_LINEAR UNIT:
float Wx_ReLU(double);

// ACTIVATION LAYER SIGMOID:
float Wx_SIGMOID(char, double);

// TO CALCULATE HYPERBOLIC TANGENT of NUM:
float Wx_TANH(char, double);

// SOFTMAX FUNCTION -> (NORMAL DISTRBITION FOR OUTPUTS):
float  Wx_SoftMax(float *);
// PART OF SOFTMAX FUNCTION -> (EXPO SUM):
float _Wx_SoftMax(float *);

// CATEGO CROSS ENTROPY LOSS FUNCTION:
float CROSS_ENTROPY_LOSS(uint16_t ,float, float *);

/*--- SUB-FUNCTIONS ---*/

// TO CALUCLATE POWER of NUM:
float Wx_POWER(double, uint16_t);

// TO CALCULATE EXPONENTIAL of NUM:
float Wx_EXP(char, double);

// TO CALCULATE FACTOIRAL of NUM:
uint32_t Wx_FACTOIRAL(uint16_t);


/*****************************************************
*                NN - ACTIVATION FUNCTIONS           *
******************************************************/
// FROM EASY -> COMPLEX.

// ACTIVATION  LINEAR Unit:
float Wx_LINEAR(double wxbase)
{
    /*
        x = y
    */

  return wxbase;
} // end Wx_ReLU.

// ACTIVATION FUNCTION Rectifed Linear Unit:
float Wx_ReLU(double wxbase)
{
    /*
      MAX(x) =
              {
                [a. IF(X > 0)  : x]
                [b. IF(X <= 0) : 0]
                [c. IF(!X(VALIDITY))    : -1]  >ERROR HANDLE.
              }
    */

  if(wxbase >= 0U)
  {
    return wxbase;
  }
  else if(wxbase < 0U)
  {
    return 0U;
  }
  else
  {
    return -1;
  }

} // end Wx_ReLU.

// ACTIVATION FUNCTION SIGMOID:
float Wx_SIGMOID(char drevodr, double wxbase)
{
    /*
      SIGMOID(x)   = [1/ ( 1-e^(-x) )].
      SIGMOID'(x)  = [SIGMOID(x) * (1 - SIGMOID(x))].
      SIGMOID''(x) = [SIGMOID'(x) * 2(0.5 - SIGMOID(x))].
    */

   float gain = 1.0;
   float SIGMOID  =  (1 / (1 + exp((- gain * wxbase))));
   float SIGMOID1 = 1.0;
   float SIGMOID2 = 1.0;

   switch(drevodr)
   {
     case '1': SIGMOID1 = gain * SIGMOID * (1 - SIGMOID);
               return (SIGMOID1);
      break;

     case '2': SIGMOID2 = pow(gain,2) * SIGMOID *
                          (1 - SIGMOID) * (1 - (2 * SIGMOID));
               return (SIGMOID2);
      break;

     default: break;
   }//end switch.

   return SIGMOID;
} // end Wx_SIGMOID.

// FUNCTION TO CALCULATE THE tanh & its drev's:
float Wx_TANH(char dervodr,double wxx)
{
  /*
    Filtering Neuron value between: Range (-1, 1) X:X
    tanh(x)   = [(1-(2*e^-x))/(e^x + e^-x)].
    tanh'(x)  = [(1 - (tanh(x))^2)].
    tanh''(x) = [(-2*tanh(x)) * (tanh'(x))].
  */

  float _TANH  = 0.0;
  float _TANH1 = 0.0;
  float _TANH2 = 0.0;

  float _TEMP  = 0.0;
  float _TEMP1 = 0.0;

// tanh drev's calculate:
  _TEMP  = (exp(wxx) + exp(-wxx));
  _TEMP1 = 1 - ((2 * exp(-wxx)) / _TEMP);

  _TANH = _TEMP1;

  switch(dervodr)
  {
    case '1': _TANH1 = 1 - pow(_TANH,2);
              return(_TANH1);
          break;

    case '2': _TANH2 = (-2 * _TANH) * (_TANH1);
              return (_TANH2);
          break;

    default: break;
  }// end switch.

  // Default resturn function drev: (0)
  return _TANH;
} // end Wx_TANH.

// SoftMax FUNCTION PROBABLITIES:
float Wx_SoftMax(float *output)
{
  static float Prob = 0.0;

  // Calculating the probability of the output:
  //Prob = (exp(*output) / _Wx_SoftMax(output));
  Prob = ( exp(*output) );
  //printf("\n Prob of output[%d]: %.4f",i,Prob);

  return (Prob);
}// end Wx_SoftMax

// SUB FUNCTION TO SoftMAX (expSUM):
float _Wx_SoftMax(float *output)
{
  static float sum  = 0.0;

  // Calculating the exponential sum of numbers:
  sum += exp(*output);
 //printf("\n ==>SUM: %.3f:",sum); // TEST purbose

  return sum;
}

//FUNCTION FOR CATIGO-CROSS-ENTROPY-LOSS:
float CROSS_ENTROPY_LOSS(uint16_t n,float Activated,float *data)
{
  static float sum = 0.0;

  for(uint16_t i = 0; i < n; i++)
  {
    sum +=  log(*data);
  }

  return (-sum);
}// end CROSS_ENTROPY_LOSS.

/*****************************************************
*                SUB - FUNCTIONS DECLARATION         *
******************************************************/

// FUNCTION TO CALCULATE THE POWER:
float Wx_POWER(double wxbase, uint16_t wxpower)
{
  static float result = 1.0;

  for(uint16_t i = 0; (i < (wxpower)); i++)
  {
    result *= (wxbase);
  }

  return (result);
} // end Wx_POWER.


// FUNCTION TO CALCULATE THE FACTOIRAL:
uint32_t Wx_FACTOIRAL(uint16_t NUM)
{
  static uint32_t result = 1;

  while(NUM != 0)
  {
    result *= NUM--;

  } //end while.

  return result;
} //end Wx_FACTOIRAL


// FUNCTION TO CALCULATE THE EXPONENTIAL:
float Wx_EXP(char LZEROA,double ePOW)
{
  static uint8_t counter = 0;
  static double expOfx   = 0.0;

  // Actiave (<= (^x) calculator:
  if(LZEROA == 'A')
  {
    if(ePOW <= 0) return 0;
  }
  // 15 DIGITS Of Taylor's Series for 'e^x':
  while(counter < (10U))
  {
    expOfx += ( Wx_POWER(ePOW, counter)/(Wx_FACTOIRAL(counter)) );

    counter++;
  }

  return (expOfx);
} // end Wx_EXP.


//------------------ END.
#endif
//------------------ END.
