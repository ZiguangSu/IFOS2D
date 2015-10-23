/*! \file tools.h
 * \brief tools and utilities (prototypes)
 * 
 * \ingroup tools
 * ----------------------------------------------------------------------------
 * 
 * $Id: tools.h 4027 2011-06-24 17:27:50Z tforb $
 * \author Thomas Forbriger
 * \date 28/05/2011
 * 
 * tools and utilities (prototypes)
 * 
 * Copyright (c) 2011 by Thomas Forbriger (BFO Schiltach) 
 *
 * ----
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version. 
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 * ----
 *
 * 
 * REVISIONS and CHANGES 
 *  - 28/05/2011   V1.0   Thomas Forbriger
 * 
 * ============================================================================
 */

// include guard
#ifndef STFINV_TOOLS_H_VERSION

#define STFINV_TOOLS_H_VERSION \
  "STFINV_TOOLS_H   V1.0   "
#define STFINV_TOOLS_H_CVSID \
  "$Id: tools.h 4027 2011-06-24 17:27:50Z tforb $"

namespace stfinv {

  namespace tools {

    /*! \brief function to compare doubles
     * \ingroup tools
     * \param a a double value
     * \param b a double value
     * \param eps relative residual allowed for \c a and \c b
     * \return true if relative residual between \c a and \c b is smaller than
     *         \p eps
     */
    bool sameineps(const double &a, const double& b, const double& eps=1.e-8);
    
  } // namespace tools

} // namespace stfinv

#endif // STFINV_TOOLS_H_VERSION (includeguard)

/* ----- END OF tools.h ----- */
