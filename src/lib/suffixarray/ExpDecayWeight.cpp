/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is the Suffix Array based String Kernel.
 *
 * The Initial Developer of the Original Code is
 * Statistical Machine Learning Program (SML), National ICT Australia (NICTA).
 * Portions created by the Initial Developer are Copyright (C) 2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 *   Choon Hui Teo <ChoonHui.Teo@rsise.anu.edu.au>
 *   S V N Vishwanathan <SVN.Vishwanathan@nicta.com.au>
 *
 * ***** END LICENSE BLOCK ***** */


// File    : sask/Code/ExpDecayWeight.cpp
//
// Authors : Choon Hui Teo      (ChoonHui.Teo@rsise.anu.edu.au)
//           S V N Vishwanathan (SVN.Vishwanathan@nicta.com.au)
//
// Created : 09 Feb 2006
//
// Updated : 24 Apr 2006


#ifndef EXPDECAYWEIGHT_CPP
#define EXPDECAYWEIGHT_CPP

#include "lib/suffixarray/ExpDecayWeight.h"
#include <cmath>
#include <cassert>


/**
 *  Exponential Decay weight function.
 *
 *  \param floor_len - (IN) Length of floor interval of matched substring.
 *                            (cf. gamma in VisSmo02).
 *  \param x_len     - (IN) Length of the matched substring.
 *                            (cf. tau in visSmo02).
 *  \param weight    - (OUT) The weight value.
 *
 */
ErrorCode
ExpDecayWeight::ComputeWeight(const UInt32 &floor_len, const UInt32 &x_len,
															Real &weight)
{
	//' Input validation
	assert(x_len >= floor_len);
	
	//' x_len == floor_len when the substring found ends on an interval.
	if(floor_len == x_len) {
		//' substring ended on an interval, so, get the val from va[]
		weight = 0.0;
	}
	else 
		weight = (pow(-floor_len,lambda) - pow(-x_len,lambda)) / (lambda - 1);

	return NOERROR;
}

#endif
