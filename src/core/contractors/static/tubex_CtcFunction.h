/** 
 *  \file
 *  CtcFunction class
 * ----------------------------------------------------------------------------
 *  \date       2020
 *  \author     Simon Rohou
 *  \copyright  Copyright 2020 Simon Rohou
 *  \license    This program is distributed under the terms of
 *              the GNU Lesser General Public License (LGPL).
 */

#ifndef __TUBEX_CTCFUNCTION_H__
#define __TUBEX_CTCFUNCTION_H__

#include <string>
#include "ibex_Function.h"
#include "ibex_Ctc3BCid.h"
#include "ibex_Domain.h"
#include "tubex_TubeVector.h"

namespace tubex
{
  /**
   * \class CtcFunction
   * \brief Generic static \f$\mathcal{C}\f$ that contracts a box \f$[\mathbf{x}]\f$ or a tube \f$[\mathbf{x}](\cdot)\f$
   *        according to the constraint \f$\mathbf{f}(\mathbf{x})=\mathbf{0}\f$ or \f$\mathbf{f}(\mathbf{x})\in[\mathbf{y}]\f$.
   *        It stands on the CtcFwdBwd of IBEX (HC4Revise) combined with a Ctc3BCid.
   */
  class CtcFunction : public ibex::Ctc3BCid
  {
    public:

      CtcFunction(const char* x1, const char* f);
      CtcFunction(const char* x1, const char* x2, const char* f);
      CtcFunction(const char* x1, const char* x2, const char* x3, const char* f);
      CtcFunction(const char* x1, const char* x2, const char* x3, const char* x4, const char* f);
      CtcFunction(const char* x1, const char* x2, const char* x3, const char* x4, const char* x5, const char* f);
      CtcFunction(const char* x1, const char* x2, const char* x3, const char* x4, const char* x5, const char* x6, const char* f);
      CtcFunction(const ibex::Function& f, const ibex::Domain& y);
      CtcFunction(const ibex::Function& f, const ibex::Interval& y);
      CtcFunction(const ibex::Function& f, const ibex::IntervalVector& y);
      
      /**
       * \brief \f$\mathcal{C}\big([\mathbf{x}]\big)\f$
       *
       * \param x the n-dimensional box \f$[\mathbf{x}]\f$ to be contracted
       */
      void contract(ibex::IntervalVector& x);
      
      /**
       * \brief \f$\mathcal{C}\big([\mathbf{x}](\cdot)\big)\f$
       *
       * \param x the n-dimensional tube \f$[\mathbf{x}](\cdot)\f$ to be contracted
       */
      void contract(TubeVector& x);

      /**
       * \brief \f$\mathcal{C}\big([x_1](\cdot)\big)\f$
       *
       * \param x1 the scalar tube \f$[x_1](\cdot)\f$ to be contracted
       */
      void contract(Tube& x1);

      /**
       * \brief \f$\mathcal{C}\big([x_1](\cdot),[x_2](\cdot)\big)\f$
       *
       * \param x1 the scalar tube \f$[x_1](\cdot)\f$ to be contracted
       * \param x2 the scalar tube \f$[x_2](\cdot)\f$ to be contracted
       */
      void contract(Tube& x1, Tube& x2);

      /**
       * \brief \f$\mathcal{C}\big([x_1](\cdot),[x_2](\cdot),[x_3](\cdot)\big)\f$
       *
       * \param x1 the scalar tube \f$[x_1](\cdot)\f$ to be contracted
       * \param x2 the scalar tube \f$[x_2](\cdot)\f$ to be contracted
       * \param x3 the scalar tube \f$[x_3](\cdot)\f$ to be contracted
       */
      void contract(Tube& x1, Tube& x2, Tube& x3);

      /**
       * \brief \f$\mathcal{C}\big([x_1](\cdot),[x_2](\cdot),[x_3](\cdot),[x_4](\cdot)\big)\f$
       *
       * \param x1 the scalar tube \f$[x_1](\cdot)\f$ to be contracted
       * \param x2 the scalar tube \f$[x_2](\cdot)\f$ to be contracted
       * \param x3 the scalar tube \f$[x_3](\cdot)\f$ to be contracted
       * \param x4 the scalar tube \f$[x_4](\cdot)\f$ to be contracted
       */
      void contract(Tube& x1, Tube& x2, Tube& x3, Tube& x4);

      /**
       * \brief \f$\mathcal{C}\big([x_1](\cdot),[x_2](\cdot),[x_3](\cdot),[x_4](\cdot),[x_5](\cdot)\big)\f$
       *
       * \param x1 the scalar tube \f$[x_1](\cdot)\f$ to be contracted
       * \param x2 the scalar tube \f$[x_2](\cdot)\f$ to be contracted
       * \param x3 the scalar tube \f$[x_3](\cdot)\f$ to be contracted
       * \param x4 the scalar tube \f$[x_4](\cdot)\f$ to be contracted
       * \param x5 the scalar tube \f$[x_5](\cdot)\f$ to be contracted
       */
      void contract(Tube& x1, Tube& x2, Tube& x3, Tube& x4, Tube& x5);

      /**
       * \brief \f$\mathcal{C}\big([x_1](\cdot),[x_2](\cdot),[x_3](\cdot),[x_4](\cdot),[x_5](\cdot),[x_6](\cdot)\big)\f$
       *
       * \param x1 the scalar tube \f$[x_1](\cdot)\f$ to be contracted
       * \param x2 the scalar tube \f$[x_2](\cdot)\f$ to be contracted
       * \param x3 the scalar tube \f$[x_3](\cdot)\f$ to be contracted
       * \param x4 the scalar tube \f$[x_4](\cdot)\f$ to be contracted
       * \param x5 the scalar tube \f$[x_5](\cdot)\f$ to be contracted
       * \param x6 the scalar tube \f$[x_6](\cdot)\f$ to be contracted
       */
      void contract(Tube& x1, Tube& x2, Tube& x3, Tube& x4, Tube& x5, Tube& x6);

      /**
       * \brief Contracts an array of slices (representing a slice vector)
       *
       * Propagates the contractions to the next slices
       *
       * \param v_x_slices the slices to be contracted
       */
      void contract(Slice **v_x_slices);


    protected:

      static const std::string parse_f(const char* f);
  };
}


#endif