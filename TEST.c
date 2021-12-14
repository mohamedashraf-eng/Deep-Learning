#include "Wx_ML_NeuralNetwork_H.h"
#include "Wx_ML_NN_STRUCTS_H.h"
#include <math.h>

/*
        TRUTH-TABLE
  * XOR   --> (0, 1, 1, 0)
  * XNOR  --> (1, 0, 0, 1)
  * OR    --> (1, 1, 1, 0)
  * AND   --> (0, 0, 0, 1)
*/
int main(void)
{
  // EXPECTED_DATA for GATE: (OR)
  (cd[0].EXPECTED_DATA[0] = 1.0); // Output Neuron[0]
  (cd[0].EXPECTED_DATA[1] = 0.0); // Output Neuron[1]
  (cd[0].EXPECTED_DATA[2] = 0.0); // Output Neuron[2]
  (cd[0].EXPECTED_DATA[3] = 0.0); // Output Neuron[3]

  // EXPECTED_DATA for GATE: (NOR)
  (cd[1].EXPECTED_DATA[0] = 0.0); // Output Neuron[0]
  (cd[1].EXPECTED_DATA[1] = 1.0); // Output Neuron[1]
  (cd[1].EXPECTED_DATA[2] = 0.0); // Output Neuron[2]
  (cd[1].EXPECTED_DATA[3] = 0.0); // Output Neuron[3]

  // EXPECTED_DATA for GATE: (XOR)
  (cd[2].EXPECTED_DATA[0] = 0.0); // Output Neuron[0]
  (cd[2].EXPECTED_DATA[1] = 0.0); // Output Neuron[1]
  (cd[2].EXPECTED_DATA[2] = 1.0); // Output Neuron[2]
  (cd[2].EXPECTED_DATA[3] = 0.0); // Output Neuron[3]

  // EXPECTED_DATA for GATE: (XNOR)
  (cd[3].EXPECTED_DATA[0] = 0.0);
  (cd[3].EXPECTED_DATA[1] = 0.0);
  (cd[3].EXPECTED_DATA[2] = 0.0);
  (cd[3].EXPECTED_DATA[3] = 1.0);

  //settings const values:
  (i_l->NEURON_NUM) = 4;
  (h_l[(h_l->H_L_NUM)].H_L_NUM)    = 1;
  (h_l[(h_l->H_L_NUM)].NEURON_NUM) = 4;
  (o_l->NEURON_NUM) = 4;

  //setting data:
  printf("\n--------------------INPUT_DATA-------------------\n");
  //printf("\n Enter the output truth table:\n");
  for(uint16_t i = 0; i < (i_l->NEURON_NUM); i++)
  {
    // Automatic input:
    (i_l->NEURON_DATA[i]) = (rand()%20/105.5);

    // Manual input:
    //printf(" (%d): ",(i+1));
    //scanf("%f",&(i_l->NEURON_DATA[i]));

   printf(" %.3f\r\n",(i_l->NEURON_DATA[i]));
  }

  printf("\n--------------------H[0]_WEIGHTS_DATA-------------------\n");
  NUM_OF_WEIGHTS += (i_l->NEURON_NUM) * (h_l[(h_l->H_L_NUM)].NEURON_NUM);

  for(uint16_t j = 0; j < (i_l->NEURON_NUM); j++)
  {
    for(uint16_t k = 0; k < (h_l[(h_l->H_L_NUM)].NEURON_NUM); k++)
    {
      (h_l[0].NEURON_WEIGHTS[j][k]) = (rand()%105/205.564);
      (h_l[0].NEURON_BIAS)          = (rand()%14/15.579);
      printf(" %.3f\t",h_l[0].NEURON_WEIGHTS[j][k]);
    }
    printf("\n");
  }

  printf("\n H_L[0] bias: %.3f",h_l[0].NEURON_BIAS);
  printf("\n--------------------OL_WEIGHTS_DATA-------------------\n");

  NUM_OF_WEIGHTS += (o_l->NEURON_NUM) * (h_l[(h_l->H_L_NUM)].NEURON_NUM);

  for(uint16_t j = 0; j < (o_l->NEURON_NUM); j++)
  {
    for(uint16_t k = 0; k < (h_l[(h_l->H_L_NUM)].NEURON_NUM); k++)
    {
      (o_l->NEURON_WEIGHTS[j][k]) = (rand()%100/400.16);
      (o_l->NEURON_BIAS)          = (rand()%200/300.16);
      printf(" %.3f\t",o_l->NEURON_WEIGHTS[j][k]);
    }
    printf("\n");
  }
  printf("\n O_L bias: %.2f ",(o_l->NEURON_BIAS));
  printf("\n--------------------WS(B)+aF>H[0]-------------------\n");

  float sum = 0.0;

  for(uint16_t j = 0; j < 4; j++)
  {
    for(uint16_t k = 0; k < 4; k++)
    {
      sum += (h_l[0].NEURON_WEIGHTS[j][k]) * (i_l->NEURON_DATA[k]);
    }
    (h_l[0].NEURON_DATA[j]) = Wx_SIGMOID('0', (sum + (h_l[0].NEURON_BIAS)) );
    //(h_l[0].NEURON_DATA[j]) = Wx_ReLU( (sum + (h_l[0].NEURON_BIAS)) );
    sum = 0;
  }

  for(uint16_t j = 0; j < 4; j++)
  {
    printf(" %.6f\n",(h_l[0].NEURON_DATA[j]));
  }
 printf("\n--------------------WS(B)+aF>OL-------------------\n");

 sum = 0;
 float _SM = 0.0;

 for(uint16_t i = 0; i < 4; i++)
 {
   for(uint16_t j = 0; j < 4; j++)
   {
     sum += ( (o_l->NEURON_WEIGHTS[i][j]) * (h_l[0].NEURON_DATA[j]) );
   }
   (o_l->NEURON_DATA[i]) = Wx_SIGMOID('0', (sum + (o_l->NEURON_BIAS)) );
   //(o_l->NEURON_DATA[i]) = Wx_ReLU( (sum + (o_l->NEURON_BIAS)) );
   _SM += exp( (o_l->NEURON_DATA[i]) );
   sum = 0;
 }

 for(uint16_t j = 0; j < 4; j++)
 {
   printf(" %.6f\n",(o_l->NEURON_DATA[j]));
 }
 printf("\n expSUM: %.3f ",_SM);
 printf("\n--------------------OL SoftMax-------------------\n");

 float sum1 = 0.0;
 float CEL  = 0.0;

 for(uint16_t j = 0; j < 4; j++)
 {
   (o_l->NEURON_DATA[j]) = (exp((o_l->NEURON_DATA[j])) /_SM);

   // CEL FOR EXPECTED_DATA = OR GATE.
   CEL += ( (cd[0].EXPECTED_DATA[j]) * (log((o_l->NEURON_DATA[j]))) );

   printf(" %.6f\n",(o_l->NEURON_DATA[j]));
   sum1 += (o_l->NEURON_DATA[j]);
 }
 CEL = -CEL; // set CEL to ( - SUM(Log(COST)) ).
 printf("\n--------------------COST FUNCTION-------------------\n");

 for(uint16_t i = 0; i < 4; i++)
 {
   (cd->SUM) += pow( ((o_l->NEURON_DATA[i]) - (cd->EXPECTED_DATA[i])), 2 );
 }
 printf(" COST: %.3f\n",(cd->SUM)/4);

 printf("\n CEL: %.3f",CEL);
 printf("\n--------------------END-------------------\n");
  /*
   printf("\n OUTPUT '%%'");
   printf("\n XOR  : %.3f%%", (o_l->NEURON_DATA[0]) * 100);
   printf("\n XNOR : %.3f%%", (o_l->NEURON_DATA[1]) * 100);
   printf("\n OR   : %.3f%%", (o_l->NEURON_DATA[2]) * 100);
   printf("\n AND  : %.3f%%", (o_l->NEURON_DATA[3]) * 100);
   */
  //printf("\n TOTAL WEIGHTS USED: %d\n",NUM_OF_WEIGHTS);

 return 0;
}
