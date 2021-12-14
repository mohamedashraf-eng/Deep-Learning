
/*
    Author: Mohamed Ashraf (Wx)
    Date: 10/8/2021
    Type: Machine learning DATASET test.
*/
//======== ======== ======== ======== ======== ======== ======== ========

// HEADER GUARDS: ML_H
#ifndef __Wx_ML_NN_STRUCTS_H_H__
#define __Wx_ML_NN_STRUCTS_H_H__

// HEADER LIBRARIES USED:
#include "Wx_ML_NeuralNetwork_H.h"
//==================================================

/*****************************************************
*                    FUNCTION DECLARED               *
******************************************************/
/*--- NN-FUNCTIONS ---*/

// TO INPUT VALUES TO INPUT:

// TO INPUT VALUES TO WEIGHTS:

// TO INPUT VALUES TO BIASES:

// TO INPUT VALUES TO OUTPUT:

/*****************************************************
*                   GLOBAL VARIABLES                 *
******************************************************/

// Defining 2d-Matrix of weights values:
float Weights[2u][2u];
float (*W)[2u][2u] = &Weights;

// Defining 2d-Matrix of biases values:
float Biases[2u];
float (*B)[2u]= &Biases;

// WEIGHT COUNTER VARIABLE
//:: FROM SINGLE LAYER ::
// NUMBER_OF_WEIGHTS = (NUM_INPUT_NEURONS) * (NUM_OUTPUT_NEURONS)
// structs::[NEURON_NUM(PREV_LAYER) * NEURON_NUM(NEXT_LAYER)]
uint16_t NUM_OF_WEIGHTS = 0;

/*****************************************************
*                NN - STRUCTS DECLARATION            *
******************************************************/

// INPUT LAYERS STRUCT: 1 - INPUT LAYER:
// get rid of struct padding.
#pragma pack(1)
typedef struct
{
  uint16_t
        NEURON_NUM; // NUMBER OF INPUT LAYER NEURONS.

  float
      NEURON_DATA[30u]; // ASSIGN DATA TO THE NEURONS FOR THE LAYER.

}wxINPUT_LAYER;

wxINPUT_LAYER input_layer;
wxINPUT_LAYER *i_l = &input_layer;

// HIDDEN LAYERS STRUCT: [0-x] - HIDDEN LAYERS:
// get rid of struct padding.
#pragma pack(1)
typedef struct
{
  uint16_t
        NEURON_NUM, // NUMBER OF HIDDEN LAYER NEURONS.
        H_L_NUM; // NUMBER OF STACKED HIDDEN LAYERS.

  float
      NEURON_DATA[30u],  // ASSIGN DATA TO THE NEURONS FOR THE LAYER.
      NEURON_WEIGHTS[50u][50u],  // ASSIGN WEIGHTS DATA FOR THE LAYER.
      NEURON_BIAS; // ASSIGN BIAS DATA FOR THE LAYER.

}wxHIDDEN_LAYERS;

wxHIDDEN_LAYERS hidden_layers[20];
wxHIDDEN_LAYERS *h_l = hidden_layers;

// OUTPUT LAYER STRUCT: 1 - OUTPUT LAYER:
// get rid of struct padding.
#pragma pack(1)
typedef struct
{
  uint16_t
        NEURON_NUM; // NUMBER OF OUTPUT LAYER NEURONS.

  float
      NEURON_DATA[30u],  // ASSIGN DATA TO THE NEURONS FOR THE LAYER.
      NEURON_WEIGHTS[50u][50u],  // ASSIGN WEIGHTS DATA FOR THE LAYER.
      NEURON_BIAS; // ASSIGN BIAS DATA FOR THE LAYER.

}wxOUTPUT_LAYER;

wxOUTPUT_LAYER output_layer;
wxOUTPUT_LAYER *o_l = &output_layer;

// COST FUNCTION DATA:
// get rid of struct padding.
#pragma pack(1)
typedef struct
{
  uint16_t DATA_NUM;

  float
      SUM,
      COST_DATA[30u],
      EXPECTED_DATA[30u];

}COST_DATA;

COST_DATA cost_data[4u];
COST_DATA *cd = cost_data;

/*****************************************************
*                NN - FUNCTION DECLARATION           *
******************************************************/

// GETTING INPUTS:
void NN_INPUTS()
{


}// end NN_INPUTS.

void NN_WEIGHTS()
{


}// end NN_WEIGHTS.

void NN_BIASES()
{


}// end NN_BIASES.

#endif
