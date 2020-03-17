/** 
 *  \file
 *  AbstractContractor class
 * ----------------------------------------------------------------------------
 *  \date       2020
 *  \author     Simon Rohou
 *  \copyright  Copyright 2020 Simon Rohou
 *  \license    This program is distributed under the terms of
 *              the GNU Lesser General Public License (LGPL).
 */

#ifndef __TUBEX_ABSTRACT_CONTRACTOR_H__
#define __TUBEX_ABSTRACT_CONTRACTOR_H__

#include "ibex_Interval.h"
#include "ibex_IntervalVector.h"
#include "ibex_Ctc.h"
#include "tubex_Tube.h"
#include "tubex_TubeVector.h"
#include "tubex_AbstractDomain.h"
#include "tubex_Ctc.h"

namespace tubex
{
  enum class ContractorType { IBEX, TUBEX };

  class AbstractContractor
  {
    public:

      AbstractContractor(const AbstractContractor& ac);
      explicit AbstractContractor(ibex::Ctc& ctc);
      explicit AbstractContractor(tubex::Ctc& ctc);

      ContractorType type() const;
      bool active() const;
      void set_active(bool active = true);

      void contract();
      double domains_volume() const;

      //std::vector<pair<AbstractDomain*,ContractorType> > m_v_domains;
      std::vector<AbstractDomain*> m_v_domains;


    protected:

      const ContractorType m_type;

      ibex::Ctc& m_ibex_ctc;
      tubex::Ctc& m_tubex_ctc;

      bool m_active = true;
  };
}

#endif