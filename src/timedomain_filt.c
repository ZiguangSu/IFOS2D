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
 *   Filter seismograms in time domain with a Butterworth filter
 *   Lowpass or highpass filtering can be applied                                  
 *   last update 14/06/11, L. Rehor
 *  ----------------------------------------------------------------------*/
#include "fd.h"
#include "segy.h"
#include "cseife.h"

void  timedomain_filt(float ** data, float fc, int order, int ntr, int ns, int method){

	/* 
	data	: 	2-dimensional array containing seismograms (
	fc	:	corner frequency in Hz
	order	:	order of filter
	ntr	:	number of traces
	ns	:	number of samples
	method	:	definition of filter
			1: lowpass filter
			2: highpass filter
	*/

	/* declaration of extern variables */
	extern float DT, F_HP;
	extern int ZERO_PHASE, NT,MYID;
	
	/* declaration of local variables */
	int itr, j, ns_reverse;
	double *seismogram, *seismogram_reverse, T0;
	double *seismogram_hp, *seismogram_reverse_hp, T0_hp;
	
	seismogram = dvector(1,ns);
	if (ZERO_PHASE==1) seismogram_reverse = dvector(1,ns);
	
	seismogram_hp = dvector(1,ns);
	if (ZERO_PHASE==1) seismogram_reverse_hp = dvector(1,ns);
	
	T0=1.0/(double)fc;
	if(F_HP)
		T0_hp=1.0/(double)F_HP;
	if(method==2)
		T0_hp=1.0/(double)fc;
		
	if (method==1){    /* lowpass filter */
		for (itr=1;itr<=ntr;itr++){
			for (j=1;j<=ns;j++){
				seismogram[j]=(double)data[itr][j];
			}
			
			seife_lpb(seismogram,ns+1,DT,T0,order); /* ns+1 because vector[0] is also allocated and otherwise seife_lpb does not filter the last sample */
			
			if (ZERO_PHASE==1){
			ns_reverse=ns;
				for (j=1;j<=ns;j++) {
					seismogram_reverse[ns_reverse]=seismogram[j];
					ns_reverse--;}
			seife_lpb(seismogram_reverse,ns+1,DT,T0,order);
			ns_reverse=ns; 
				for (j=1;j<=ns;j++) {
					seismogram[ns_reverse]=seismogram_reverse[j];
					ns_reverse--;}
			}

			for (j=1;j<=ns;j++){
				data[itr][j]=(float)seismogram[j];
			}
		}
	} /* end of itr<=ntr loop */

	if ((method==2)||(F_HP)){   /*highpass filter*/
		for (itr=1;itr<=ntr;itr++){
			for (j=1;j<=ns;j++){
				seismogram_hp[j]=(double)data[itr][j];
			}
			
			seife_hpb(seismogram_hp,ns+1,DT,T0_hp,order);
			
			if (ZERO_PHASE==1){
			ns_reverse=ns;
				for (j=1;j<=ns;j++) {
					seismogram_reverse_hp[ns_reverse]=seismogram_hp[j];
					ns_reverse--;}
			seife_hpb(seismogram_reverse_hp,ns+1,DT,T0_hp,order);
			ns_reverse=ns;
				for (j=1;j<=ns;j++) {
					seismogram_hp[ns_reverse]=seismogram_reverse_hp[j];
					ns_reverse--;}
			}
			for (j=1;j<=ns;j++){
				data[itr][j]=(float)seismogram_hp[j];
			}
		}
	} /* end of itr<=ntr loop */
	
	free_dvector(seismogram,1,ns);
	if (ZERO_PHASE==1) free_dvector(seismogram_reverse,1,ns);

	free_dvector(seismogram_hp,1,ns);
	if (ZERO_PHASE==1) free_dvector(seismogram_reverse_hp,1,ns);

} /* end of function */
