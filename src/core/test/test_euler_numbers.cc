// GNU General Public License Agreement
// Copyright (C) 2004-2010 CodeCogs, Zyba Ltd, Broadwood, Holford, TA5 1DU, England.
//
// This program is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by CodeCogs. 
// You must retain a copy of this licence in all copies. 
//
// This program is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
// PARTICULAR PURPOSE. See the GNU General Public License for more details.
// ---------------------------------------------------------------------------------
//! Calculates Euler numbers by means of recurrent relation


#ifndef MATHS_NUMBERTHEORY_EULER_H
#define MATHS_NUMBERTHEORY_EULER_H

#include <math.h>
#include <float.h>

namespace Maths
{

namespace Discrete
{

namespace NumberTheory
{

//! Calculates Euler numbers by means of recurrent relation

void EulerA( int iMax, double* daEuler )
{
  daEuler[0] = 1.0;

  // odd index elements
   for( int j = 1; j <= iMax; j += 2 )
    daEuler[j] = 0.0;

  // recurrent relation for even index elements
  for( int n = 1; n <= iMax/2; n++ )
  {
    double dSum = 0.0;
    long lBinom = 1;            // type should be long
                                // for intermediate results not fail
                                // if sizeof(int) == 2

    for( int r = 0; r < n; r++ )
    {
      double dItem = daEuler[2*r];

      dItem *= (double)lBinom;
      dSum += dItem;

      // binomial coefficient calculated recurrently
      lBinom *= (2*n-2*r-1)*(n-r);
      lBinom /= (r+1)*(2*r+1);
    }
    daEuler[2*n] = -dSum;
  }
}

//! Calculates Euler numbers using the series expansion

void EulerB( int iMax, double* daEuler )
{
  // odd index elements
  //
  for( int j = 1; j <= iMax; j += 2 )
    daEuler[j] = 0.0;

  // computer dependent value
  // ultimate calculation accuracy
  //
  double eps = DBL_EPSILON;     // minimal eps such that 1.0 + eps != 1.0

  // Euler numbers with even index
  //
  const double TwoByPi = 0.63661977236758134308;  // 2/Pi
  double dCoeff = 2.0 * TwoByPi;

  for( int n = 0; n <= iMax/2; n++ )
  {
    double      g1 = 1.0,               // single terms initialization
                g2 = 1.0;

    for( int j = 0; j < n; j++ )
    {
      g1 *= 9.0;
      g2 *= 25.0;
    }
    g1 *= 3.0;   // 3^(2n+1)
    g2 *= 5.0;   // 5^(2n+1)

    double S0 = 1.0,    // partial sums initialization
           S1 = S0 - 1.0/g1,
           S2 = S1 + 1.0/g2,
           S3;

    // Aitken transformation to speed up convergence
    //
    double T1 = S1 + 1.0/(g2 + g1), // transformed partial sum,
           T2;

    long r = 3;
    double s = -1.0;                    // current term sign
    int nSuccess = 0;

    while( !nSuccess )
    {
      // (2r+1)^(2n+1)
      //
      double r2 = double(2*r+1);
      double g3 = 1.0;

      for( int j = 0; j < n; j++ )
      {
        g3 *= r2*r2;
      }
      g3 *= r2;

      // next partial sum
      //
      S3 = S2 + s/g3;
      T2 = S2 + s/(g3 + g2);

      if( fabs(1.0-T1/T2) > eps )       // continue with next term
      {
        g2 = g3;
        S2 = S3;
        T1 = T2;
        s = -s;
        r++;
      }
      else                              // convergence
        nSuccess = 1;

    }
    daEuler[2*n] = dCoeff * T2;
    dCoeff *= -double((2*n+1)*(2*n+2)) * (TwoByPi * TwoByPi);
  }
}

}

}

}

#endif

