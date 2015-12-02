/*-----------------------------------------------------------------------------------------
 * Copyright (C) 2013  For the list of authors, see file AUTHORS.
 *
 * This file is part of DENISE.
 *
 * DENISE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2.0 of the License only.
 *
 * DENISE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with DENISE. See file COPYING and/or <http://www.gnu.org/licenses/gpl-2.0.html>.
 -----------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------
 *
 * Joint Inversion
 *
 *
 * Florian Wittkamp 13.10.2015
 *  ----------------------------------------------------------------------*/
#include "fd.h"

/* Declare local functions */


float ** joint_inversion_grad ( float ** gradiant_1,float ** gradiant_2, float alpha, int joint_type) {
    /*
     * Input parameters:
     * - gradiant_1 : first gradiant
     * - gradiant_2 : second gradiant
     * - alpha : value for weighting
     * - joint_type:
     *              1: Normalize both and take the arithmetic mean
     *
     */
    
    /* Define local variables  */
    float ** joint_gradiant; // This will be the merged gradiant, which will be returned
    int i, j;
    float max1=0.0,max2=0.0;
    /* Define extern variables */
    extern int NX, NY, NXG, NYG;
    extern int NPROCX, NPROCY, MYID;
    extern FILE *FP;
    
    
    switch (joint_type) {
        case 1:
            /* joint_type=1: Normalize both and take the arithmetic mean */
            max1=global_maximum(gradiant_1);
            max2=global_maximum(gradiant_2);
            for (j=1;j<=NY;j++){
                for (i=1;i<=NX;i++){
                    gradiant_1[j][i]=((1-alpha)*gradiant_1[j][i]/max1+alpha*gradiant_2[j][i]/max2);
                }
            }
            joint_gradiant=gradiant_1;
            break;
    }
    return joint_gradiant;
};


